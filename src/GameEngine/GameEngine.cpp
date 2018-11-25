#include "GameEngine.h"

#include <iostream>
using namespace std;

#ifdef NDEBUG
#define PRINT_MOVEMENT(player, arr, pos)
#define PRINT_SEQUENCE(arr)
#else
#define PRINT_MOVEMENT(player, arr, pos) printMovement(player, arr, pos)
#define PRINT_SEQUENCE(arr) printSequence(arr)
#endif // NDEBUG

namespace binary_game {
#ifndef NDEBUG
    void printSequence(const BinaryArray& arr);
    void printMovement(Player* player, const BinaryArray& arr, BinaryPos pos);
#endif


    ///
    /// GameEngine default contructor
    ///
    GameEngine::GameEngine() {

    }

    ///
    /// GameEngine destructor
    ///
    GameEngine::~GameEngine() {

    }

    ///
    /// add a player
    /// @params: player -> intance of a player
    ///
    void GameEngine::addPlayer(const PlayerRef& player) {
        players_.push_back(player);
    }

    ///
    /// add a sequence
    /// @params: sequence -> Sequence of binary number
    ///
    void GameEngine::addGame(const SequenceRef& sequence) {
        gameSequences_.push_back(sequence);
    }

    ///
    /// run a game
    /// @params: gameSequence -> Sequence of binary number
    /// @return: game result
    ///
    GameResultItem GameEngine::runAGame(SequenceRef gameSequence) {
        if (players_.size() < 2) {
            throw std::exception("Players should be more than one");
        }
        GameResultItem gameResultItem;
        auto pit = players_.begin();
        auto prevIt = players_.end();
        --prevIt;
        while (true)
        {
            if (pit == players_.end()) {
                pit = players_.begin();
            }
            // get current player and request it to take the turn
            auto player = *pit;
            auto pickupPosition = player->takeTurn(*gameSequence);

            PRINT_MOVEMENT(player.get(), *gameSequence, pickupPosition);

            // pickup element at the position
            try {
                pickup(*gameSequence, pickupPosition);
                PRINT_SEQUENCE(*gameSequence);
            }
            catch (std::exception&) {
                // cannot pickup at the position that choosen by the player
                // it means that the player break the rule or cannot take a turn
                // So, the game is over
                gameResultItem.winner(*prevIt);
                break;
            }

            prevIt = pit;
            ++pit;
        }

        return gameResultItem;
    }

    ///
    /// loop all games and run each game sequential
    /// @return: list of game result
    ///
    std::shared_ptr<GameResult> GameEngine::run() {
        auto gameResult = std::make_shared<GameResult>();
        for (auto it = gameSequences_.begin(); it != gameSequences_.end(); it++) {
            auto gameResultItem = runAGame(*it);
            gameResult->addResult(gameResultItem);
        }

        return gameResult;
    }

#ifndef NDEBUG
    void printSequence(const BinaryArray& arr) {
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            cout << (int)*it << " ";
        }
        cout << endl;
    }

    void printMovement(Player* player, const BinaryArray& arr, BinaryPos pos) {
        auto index = std::distance(arr.begin(), pos);
        cout << player->name() << " take element at " << index << endl;
        printSequence(arr);
    }
#endif
}