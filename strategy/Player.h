#pragma once

class Player {
public:
    Player(); // Constructor

    char* Get_Last_Move();
    void Set_Last_Move(char c);

private:
    int _hp;
    char _moves[3];
};