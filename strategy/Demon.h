#pragma once
#include <iostream>
#include <cstdlib>
#include <memory>
#define Player_moves_nb 3

//strategy
class DemonStrategy {
public:
    virtual char attack(char *data) const = 0;
};

//concrete strategies
class Random : public DemonStrategy {
    char attack(char *data) const override {
        auto i = std::rand() % 3;
        char moves[] = { 'r', 'p', 's'};
        return moves[i];
    }
};

class Paper : public DemonStrategy {
    char attack(char *data) const override {
        return 'p';
    }
};

class Scissors : public DemonStrategy {
    char attack(char *data) const override {
        return 's';
    }
};

class Rock : public DemonStrategy {
    char attack(char *data) const override {
        return 'r';
    }
};

class Mirror : public DemonStrategy {
    char attack(char *data) const override {
        return data == nullptr ? 'p' : data[2];
    }
};


class MeanCounter : public DemonStrategy {
char attack(char *data) const override {
        auto nb_p = 0;
        auto nb_s = 0;
        auto nb_r = 0;
        int i = 0;
        while (i != Player_moves_nb) {
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
            i++;
        }
        if (nb_p > nb_r && nb_s)
            return 's';
        else if (nb_r > nb_s)
            return 'p';
        else
            return 'r';
        
    }
};

inline void Display_move(char move) {
  switch (move) {
    case 'r' :
      std::cout << "The demon plays Rock!\n";
      break;
    case 'p' :
      std::cout << "The demon plays Paper\n";
      break;
    case 's' :
      std::cout << "The demon plays Scissors!\n";
      break;
    default:
      break;
  }
}


class Demon {
public:
    Demon(std::unique_ptr<DemonStrategy> S); // Constructor
    bool Is_defeated(char p_move, char *p_data);
private:
    std::unique_ptr<DemonStrategy> _strategy;
    
};
