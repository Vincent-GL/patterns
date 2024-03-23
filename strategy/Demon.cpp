#include "Demon.h"


Demon::Demon(std::unique_ptr<DemonStrategy> S) {
  _strategy = std::move(S);
}

bool Demon::Is_defeated(char p_move, char *p_data) {
  char d_move = _strategy->attack(p_data);
  std::cout << "The demon uses " << d_move <<'\n';
  switch (p_move)
  {
  case 'r':
    return d_move == 's';
    break;
  case 'p':
    return d_move == 'r';
    break;
  case 's':
    return d_move == 'p';
    break;
    default:
    return false;
    break;
  }
}
