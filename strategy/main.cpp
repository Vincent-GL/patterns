#include <cstddef>
#include <iostream>
#include "Player.h"
#include "Demon.h"
#include <memory>

bool First_Four_Demons (Player *p) {
  char move;
  Demon d1(std::make_unique<Paper>());
  Demon d2(std::make_unique<Rock>());
  Demon d3(std::make_unique<Scissors>());
  Demon d4(std::make_unique<Random>());
  size_t defeated_demons = 0;
  bool incorrect_move;
  bool is_defeated = false;
  std::cout << "The first demon appears ! Be aware that you can't match a demon's strength.\n";
  while (defeated_demons < 4 and !is_defeated) {
    incorrect_move = false;
    std::cout << "Choose : R(ock), P(aper) or S(cissors)";
    std::cin >> move;
    if (move == 'R' || move == 'P' || move == 'S') {
      move += 'a' - 'A';
    }
    switch (move) {
      case 'r':
        std::cout << "You use rock!\n";
        break;
      case 'p':
        std::cout << "You use paper!\n";
        break;
      case 's':
        std::cout << "You use scissors!\n";
        break;
      default:
        std::cout << "No valid move chosen, you lose this round.\n";
        incorrect_move = true;
        break;
    }
    if (incorrect_move) {
      is_defeated = p->Take_Damage();
    }
    else {
      switch (defeated_demons) {
        case 0 :
          !(d1.Is_defeated(move,nullptr)) ? incorrect_move = true : defeated_demons += 1;
          break;
        case 1 :
          !(d2.Is_defeated(move,nullptr)) ? incorrect_move = true : defeated_demons += 1;
          break;
        case 2 :
          !(d3.Is_defeated(move,nullptr)) ? incorrect_move = true : defeated_demons += 1;
          break;
        case 3 :
          !(d4.Is_defeated(move,nullptr)) ? incorrect_move = true : defeated_demons += 1;
          break;
        default :
          break;
      }
      p->Set_Last_Move(move);
      if (incorrect_move) {
        std::cout << "you didn't win; The demon attacks you.\n";
        is_defeated = p->Take_Damage();
      }
      else {
        std::cout <<  "You have beaten the demon! A new one appears;\n";
      }
    }
  }
  return is_defeated;
}

int main(void) {
  Player *p = new Player();
  char move;
  char incorrect_move;
  size_t defeated_demons = 0;
  bool is_defeated = First_Four_Demons(p);
  if (!is_defeated) {
    Demon d1(std::make_unique<Mirror>());
    Demon d2(std::make_unique<MeanCounter>());
    while (defeated_demons < 2 and !is_defeated) {
      std::cout << defeated_demons << '\n';
        incorrect_move = false;
        std::cout << "Choose : R(ock), P(aper) or S(cissors)";
        std::cin >> move;
        if (move == 'R' || move == 'P' || move == 'S') {
          move += 'a' - 'A';
        }
        switch (move) {
          case 'r':
            std::cout << "You use rock!\n";
            break;
          case 'p':
            std::cout << "You use paper!\n";
            break;
          case 's':
            std::cout << "You use scissors!\n";
            break;
          default:
            std::cout << "No valid move chosen, you lose this round.\n";
            incorrect_move = true;
            break;
        }
        if (incorrect_move) {
          is_defeated = p->Take_Damage();
        }
        else {
          switch (defeated_demons) {
            case 0 :
              !(d1.Is_defeated(move,p->Get_Last_Move())) ? incorrect_move = true : defeated_demons += 1;
              break;
            case 1 :
              !(d2.Is_defeated(move,p->Get_Last_Move())) ? incorrect_move = true : defeated_demons += 1;
              break;
            default :
              break;
          }
          p->Set_Last_Move(move);
          if (incorrect_move) {
            std::cout << "you didn't win; The demon attacks you.\n";
            is_defeated = p->Take_Damage();
          }
          else {
            std::cout <<  "You have beaten the demon! A new one appears;\n";
          }
        }
      }
  }
  std::cout << (is_defeated ? "you lose.\n" : "you win !\n");
  return 0;
}
