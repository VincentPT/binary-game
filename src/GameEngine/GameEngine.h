#ifndef BINARY_GAME_GAME_ENGINE
#define BINARY_GAME_GAME_ENGINE

#include "BinarySequence.h"
#include "Player.h"
#include "GameResult.h"

namespace binary_game {
    typedef std::shared_ptr<SequenceList> SequenceRef;

    ///
    /// Game engine class
    ///
    class GameEngine final {
        // don't allow use copy constructor for GameEngine
        GameEngine(const GameEngine&) = delete;
        const GameEngine& operator=(const GameEngine&) = delete;
    public:
        ///
        /// GameEngine default contructor
        ///
        GameEngine();
        ///
        /// GameEngine destructor
        ///
        ~GameEngine();

        ///
        /// loop all games and run each game sequential
        /// @return: list of game result
        ///
        std::shared_ptr<GameResult> run();

        ///
        /// add a player
        /// @params: player -> intance of a player
        ///
        void addPlayer(const PlayerRef& player);

        ///
        /// add a sequence
        /// @params: sequence -> Sequence of binary number
        ///
        void addGame(const SequenceRef& sequence);

    protected:
        ///
       /// run a game
       /// @params: gameSequence -> Sequence of binary number
       /// @return: game result
       ///
        GameResultItem runAGame(SequenceRef gameSequence);

    private:
        std::list < PlayerRef > players_;
        std::list < SequenceRef > gameSequences_;
    };
}


#endif //BINARY_GAME_GAME_ENGINE