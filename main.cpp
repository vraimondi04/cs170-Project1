//
//  main.cpp
//  cs170-project-1
//
//
//

#include <iostream>
#include <queue>
#include "puzzle.hpp"

using namespace std; 

int main() {

  Puzzle p;
  int userChoice = 0;

  cout << "Welcome to my 8-puzzle solver!" << endl;
  cout << "Enter 0 to use the default puzzle, and enter 1 to create your own:" << endl;
  cin >> userChoice;

  p.makePuzzle(userChoice);

  return 0;
}
