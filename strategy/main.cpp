#include <iostream>
#include "Player.h"

int main(void) {
  Player *p = new Player();
  char move;
  auto i = 0;
  while(i < 3){
    std::cout << "Choose : R(ock), P(aper) or S(cissors)";
    std::cin >> move;
    switch (move) {
      case 'R':
      case 'r':
        std::cout << "You use rock!\n";
        p->Set_Last_Move('r');
        break;
      case 'P':
      case 'p':
        std::cout << "You use paper!\n";
        p->Set_Last_Move('p');
        break;
      case 'S':
      case 's':
        std::cout << "You use scissors!\n";
        p->Set_Last_Move('s');
        break;
      default:
        std::cout << "No valid move chosen\n";
        break;
    }
    i ++;
  }
  std::cout << p->Get_Last_Move()<<'\n';
}
