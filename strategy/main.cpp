#include <cstddef>
#include <iostream>
#include "Player.h"
#include "Demon.h"
#include <memory>

inline char Read_Move() {
  char move;
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
      move = 0;
      break;
  }
  return move;
}


size_t First_Four_Demons (Player *p) {
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
    move = Read_Move();
    incorrect_move = move == 0;
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
        std::cout <<  "You have beaten the demon! A new one appears.\n";
      }
    }
  }
  return defeated_demons;
}

int main(void) {
  Player *p = new Player();
  char move;
  char incorrect_move;
  size_t defeated_demons = First_Four_Demons(p);
  
  if (defeated_demons == 4) {
    bool is_defeated = false;
    Demon d1(std::make_unique<Mirror>());
    Demon d2(std::make_unique<MeanCounter>());
    while (defeated_demons < 6 and !is_defeated) {
        move = Read_Move();
        incorrect_move = move == 0;
        if (incorrect_move) {
          is_defeated = p->Take_Damage();
        }
        else {
          switch (defeated_demons) {
            case 4 :
              !(d1.Is_defeated(move,p->Get_Last_Move())) ? incorrect_move = true : defeated_demons += 1;
              break;
            case 5 :
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
            std::cout <<  "You have beaten the demon!" << (defeated_demons == 6 ? "\nAll foes have been vanquished.\n" : "The final demon appears.\n");
          }
        }
      }
  }
  std::cout << (defeated_demons != 6 ? "you lose.\n" : "you win !\n");
  return 0;
}
