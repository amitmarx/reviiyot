//
// Created by amitmarx on 26/11/16.
//

#include "../../include/Player.h"

Player::Player(string n, int loc):name(n),location(loc),playerToAsk(0) {
}


string Player::getName() {
    return name;
}

void Player::increaseLocationToAskByOne() {
        playerToAsk++;
}

Player::Player(const Player &p):Hand(p),name(p.name),location(p.location),playerToAsk(p.playerToAsk) {
}





