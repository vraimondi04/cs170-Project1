#include "puzzle.hpp"

//constructor for puzzle class
Puzzle::Puzzle() {

  //first defined as null, will be assigned later (the '*' tile)
  root = NULL;
}

//creates default or user generated puzzle
void Puzzle::makePuzzle(int userInput) {

  //new '*' tile
  tile* t = NULL;
  t -> neighbor1 = NULL;
  t -> neighbor2 = NULL;
  t -> neighbor3 = NULL;
  t -> neighbor4 = NULL;
  t -> previousNode = NULL;

  t -> heuristicVal = 0;
  t -> movementCost = 0;

  //initial state of puzzle
  goalState = false;
  nodesExpanded = 0;
  nodesInQueue = 0;

  //puzzle tiles - think of adjacency matrix but with vectors
  vector<char> row1;
  vector<char> row2;
  vector<char> row3;
  char val1, val2, val3;

  if (userInput == 0) {
    cout << "The default puzzle:" << endl; //depth 2
    row1.push_back('1');
    row1.push_back('2');
    row1.push_back('3');

    row2.push_back('4');
    row2.push_back('5');
    row2.push_back('6');

    row3.push_back('*');
    row3.push_back('7');
    row3.push_back('8');

    //CHECK IF MINHEAP IS WORKING WITH THE GREATER<TILE*>
    root = t;
    minHeap.push(root);

    currPuzzle.push_back(row1);
    currPuzzle.push_back(row2);
    currPuzzle.push_back(row3);

    visitedPuzzles.push_back(currPuzzle);
  }
  else if (userInput == 1) {
    cout << "Enter your puzzle below, use * to represent the blank tile:" << endl;
    cout << "Enter the first row with spaces in between values:" << endl;
    cin >> val1 >> val2 >> val3;
    row1.push_back(val1);
    row1.push_back(val2);
    row1.push_back(val3);

    cout << "Enter the second row with spaces in between values:" << endl;
    cin >> val1 >> val2 >> val3;
    row2.push_back(val1);
    row2.push_back(val2);
    row2.push_back(val3);

    cout << "Enter the third row with spaces in between values:" << endl;
    cin >> val1 >> val2 >> val3;
    row3.push_back(val1);
    row3.push_back(val2);
    row3.push_back(val3);

    //CHECK IF MINHEAP IS WORKING WITH THE GREATER<TILE*>
    root = t;
    minHeap.push(root);

    currPuzzle.push_back(row1);
    currPuzzle.push_back(row2);
    currPuzzle.push_back(row3);

    visitedPuzzles.push_back(currPuzzle);
  }

}


