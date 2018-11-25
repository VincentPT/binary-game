#include "GameResult.h"
#include <iostream>

using namespace std;

namespace binary_game {
    GameResultItem::GameResultItem() {

    }
    GameResultItem::GameResultItem(PlayerRef winner) {

    }
    GameResultItem::~GameResultItem() {

    }

    void GameResultItem::present() {
        if (!_winner) throw std::exception("winer is null");
        cout << _winner->name();
    }

    void GameResultItem::winner(PlayerRef winner) {
        _winner = winner;
    }

    PlayerRef GameResultItem::winner() const {
        return _winner;
    }

    GameResult::GameResult() {

    }

    GameResult::~GameResult() {

    }

    void GameResult::present() {
        for (auto it = results_.begin(); it != results_.end(); ++it) {
            it->present();
            cout << endl;
        }
    }

    void GameResult::addResult(const GameResultItem& item) {
        results_.push_back(item);
    }
}