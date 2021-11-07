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
  int userAlgo = 0;

  cout << "Welcome to my 8-puzzle solver!" << endl;
  cout << "Enter 0 to use the default puzzle, and enter 1 to create your own:" << endl;
  cin >> userChoice;

  p.makePuzzle(userChoice);

  cout << "Please select your choice of algorithm:" << endl;
  cout << "1. Uniform Cost Search / 2. A* with Misplaced Tile Heuristic / 3. A* with Manhattan Distance Heuristic" << endl;
  cin >> userAlgo;

  p.selectAlgorithm(userAlgo);

  return 0;
}
