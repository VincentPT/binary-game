#ifndef BINARY_GAME_GAME_RESULT
#define BINARY_GAME_GAME_RESULT

#include "Player.h"

namespace binary_game {

    ///
    /// class declaration of game result of each game
    ///
    class GameResultItem {
    public:
        GameResultItem(PlayerRef winner);
        GameResultItem();
        virtual ~GameResultItem();
        virtual void present();
        void winner(PlayerRef winner);
        PlayerRef winner() const;
    private:
        
        PlayerRef _winner;
    };

    ///
    /// class declaration of game result of all games
    ///
    class GameResult {
    public:
        GameResult();
        virtual ~GameResult();

        virtual void present();
        void addResult(const GameResultItem& item);
    private:
        std::list<GameResultItem> results_;
    };
}

#endif //BINARY_GAME_GAME_RESULT