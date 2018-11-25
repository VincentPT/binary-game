#ifndef BINARY_GAME_PLAYER
#define BINARY_GAME_PLAYER

#include "algorithms.h"
#include <string>

namespace binary_game {

    ///
    /// class declaration of player
    ///
    class Player {
        // don't allow use copy constructor for GameEngine
        Player(const Player&) = delete;
        const Player& operator=(const Player&) = delete;
    public:
        Player(const std::string& name);
        virtual ~Player();

        ///
        /// take a turn for looking up a optimal move
        /// @param: arr -> Binary Sequence
        /// @return: position for picking up
        ///
        virtual BinaryPos takeTurn(const BinaryArray& arr);

        ///
        /// name setter
        ///
        virtual void name(const std::string& name);

        ///
        /// name getter
        ///
        virtual std::string name() const;

    private:
        std::string name_;
    };

    typedef std::shared_ptr <Player> PlayerRef;
}

#endif //BINARY_GAME_PLAYER