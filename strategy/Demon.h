#pragma once
#include <iostream>
#include <cstdlib>
//strategy
class DemonStrategy {
public:
    virtual char attack(char *data) const = 0;
};

//concrete strategies
class Random : DemonStrategy {
    char attack(char *data) const override {
        auto i = std::rand() % 3;
        char moves[] = { 'r', 'p', 's'};
        return moves[i];
    }
};


class Rock : DemonStrategy {
    char attack(char *data) const override {
        return 'p';
    }
};

class Mirror : DemonStrategy {
    char attack(char *data) const override {
        return data == nullptr ? 'p' : data[2];
    }
};

template <typename T>
T maximum(T a, T b, T c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}


class MeanCounter : DemonStrategy {
char attack(char *data) const override {
        auto nb_p = 0;
        auto nb_s = 0;
        auto nb_r = 0;
        while (data != nullptr) {
            switch (*data)
            {
            case 'r':
                nb_r += 1;
                break;
            case 'p':
                nb_p += 1;
                break;
            case 's':
                nb_p += 1;
                break;
            }
            data++;
        }
        if (nb_p > nb_r && nb_s)
            return 's';
        else if (nb_r > nb_s)
            return 'p';
        else
            return 'r';
        
    }
};


class Demon {
public:
    Demon(); // Constructor

private:
    int _hp;
};