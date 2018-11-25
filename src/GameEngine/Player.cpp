#include "Player.h"

namespace binary_game {
    ///
    /// Player contructor
    /// @param: name -> name of the player
    ///
    Player::Player(const std::string& name) : name_(name) {}

    ///
    /// Player destructor
    ///
    Player::~Player(){}

    ///
    /// name setter
    ///
    void Player::name(const std::string& name) {
        name_ = name;
    }

    ///
    /// name getter
    ///
    std::string Player::name() const {
        return name_;
    }

    ///
    /// take a turn for looking up a optimal move
    /// @param: arr -> Binary Sequence
    /// @return: position for picking up
    ///
    BinaryPos Player::takeTurn(const BinaryArray& arr) {
        return zeroFirstLookup(arr);
    }
}