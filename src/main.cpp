#include <iostream>
#include "GameEngine/GameEngine.h"

using namespace std;
using namespace binary_game;

int main(int argc, char* argv[]) {
    GameEngine gameEngine;

    gameEngine.addPlayer(make_shared<Player>("Alice"));
    gameEngine.addPlayer(make_shared<Player>("Bob"));

    try {
        int nGame = 0;
        string str;
        std::getline(cin, str);
        nGame = atoi(str.c_str());
        for (int i = 0; i < nGame; ++i) {
            BinarySequence binarySequence;
            binarySequence.load(cin);

            gameEngine.addGame(binarySequence.asList());
        }
    }
    catch (const exception& e) {
        cout << "load data failed due to:" << e.what() << endl;
        return -1;
    }

    try {
        auto gameResult = gameEngine.run();
        gameResult->present();
    }
    catch (const exception&e) {
        cout << "fail to run game due to:" << e.what() << endl;
        return -1;
    }

    return 0;
}