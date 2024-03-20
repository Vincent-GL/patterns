#include "Player.h"

Player::Player() {
    _hp = 3;
    for (auto i = 0; i < 3; i++) {
        _moves[i] = ' ';
    }
}

char* Player::Get_Last_Move() {
    return _moves;
}

void Player::Set_Last_Move(char c) {
    _moves[0] = _moves[1];
    _moves[1] = _moves[2];
    _moves[2] = c;
}
