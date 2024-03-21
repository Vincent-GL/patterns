#include "Demon.h"


Demon::Demon(std::unique_ptr<DemonStrategy> S) {
  _strategy = std::move(S);
}

bool Demon::Is_defeated(char p_move, char d_move) {
  switch (p_move)
  {
  case 'r':
    return d_move == 's';
    break;
  case 'p':
    return d_move == 'r';
    break;
  default:
    return d_move == 'p';
    break;
  }
}