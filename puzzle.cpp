#include "puzzle.hpp"

//constructor for puzzle class
Puzzle::Puzzle() {

  //first defined as null, will be assigned later (the '*' tile)
  root = NULL;
}

//creates default or user generated puzzle
void Puzzle::makePuzzle(int userInput) {
  
  //new '*' tile
  tile* t = new tile;
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

void Puzzle::selectAlgorithm(int userAlgo) {
  userSearch = userAlgo;

  //root is a private member of puzzle, so begin recursive call here
  searchPuzzle(root, currPuzzle);
}

//recursive function that determines where blank tile is and starts tree / moves blank tile to neighbors
void Puzzle::searchPuzzle(tile* blankTile, vector<vector<char> > currentPuzzle) {

  int i, j, blankTileIndex = 0;

  //find blank tile
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      if (currentPuzzle[i][j] != '*') {
        blankTileIndex++;
      }
    }
  }

  //check if puzzle is goal state
  if (checkPuzzle(currentPuzzle)) {
    goalState = true;
    goalTile = blankTile;
  }
  else {
    minHeap.pop();
  }

  //swap blank tile with one of its neighboring tiles
  swapTile(blankTile, currentPuzzle, blankTileIndex);

  //add goal state display text and path from root to goal tile if current puzzle is goal state

}

bool Puzzle::checkPuzzle(vector<vector<char> > currentPuzzle) {
  //hard code the values of the solved puzzle to compare to the current puzzle
  vector<vector<char> > solvedPuzzle;
  vector<char> row1 = {1, 2, 3};
  vector<char> row2 = {4, 5, 6};
  vector<char> row3 = {7, 8, '*'};
  solvedPuzzle.push_back(row1);
  solvedPuzzle.push_back(row2);
  solvedPuzzle.push_back(row2);

  if (currentPuzzle == solvedPuzzle) {
    return true;
  }
  else {
    return false;
  }
}

void Puzzle::swapTile(tile* blankTile, vector<vector<char> > currentPuzzle, int blankTileIndex) {

  //create tempPuzzles for each neightbor of blank tile
  vector<vector<char> > tempPuzzle1 = currentPuzzle;
  vector<vector<char> > tempPuzzle2 = currentPuzzle;
  vector<vector<char> > tempPuzzle3 = currentPuzzle;
  vector<vector<char> > tempPuzzle4 = currentPuzzle;

  //Swap tiles and make new puzzles for each option of where the '*' tile is
  if (blankTileIndex == 0) {
    swap(tempPuzzle1[0][0], tempPuzzle1[0][1]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle2[0][0], tempPuzzle2[1][0]);
    newPuzzle(blankTile, currentPuzzle, 1);
  } 
  else if (blankTileIndex == 1) {
    swap(tempPuzzle1[0][1], tempPuzzle1[0][0]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[0][1], tempPuzzle1[0][2]);
    newPuzzle(blankTile, currentPuzzle, 2);

    swap(tempPuzzle1[0][1], tempPuzzle1[1][1]);
    newPuzzle(blankTile, currentPuzzle, 3);
  }
  else if (blankTileIndex == 2) {
    swap(tempPuzzle1[0][2], tempPuzzle1[0][1]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[0][2], tempPuzzle1[1][2]);
    newPuzzle(blankTile, currentPuzzle, 2);
  }
  else if (blankTileIndex == 3) {
    swap(tempPuzzle1[1][0], tempPuzzle1[0][0]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[1][0], tempPuzzle1[1][1]);
    newPuzzle(blankTile, currentPuzzle, 2);

    swap(tempPuzzle1[1][0], tempPuzzle1[2][0]);
    newPuzzle(blankTile, currentPuzzle, 3);
  }
  else if (blankTileIndex == 4) {
    swap(tempPuzzle1[1][1], tempPuzzle1[0][1]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[1][1], tempPuzzle1[1][0]);
    newPuzzle(blankTile, currentPuzzle, 2);

    swap(tempPuzzle1[1][1], tempPuzzle1[1][2]);
    newPuzzle(blankTile, currentPuzzle, 3);

    swap(tempPuzzle1[1][1], tempPuzzle1[2][1]);
    newPuzzle(blankTile, currentPuzzle, 4);
  }
  else if (blankTileIndex == 5) {
    swap(tempPuzzle1[1][2], tempPuzzle1[0][2]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[1][2], tempPuzzle1[1][1]);
    newPuzzle(blankTile, currentPuzzle, 2);

    swap(tempPuzzle1[1][2], tempPuzzle1[2][2]);
    newPuzzle(blankTile, currentPuzzle, 3);
  }
  else if (blankTileIndex == 6) {
    swap(tempPuzzle1[2][0], tempPuzzle1[1][0]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[2][0], tempPuzzle1[2][1]);
    newPuzzle(blankTile, currentPuzzle, 2);
  }
  else if (blankTileIndex == 7) {
    swap(tempPuzzle1[2][1], tempPuzzle1[1][1]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[2][1], tempPuzzle1[2][0]);
    newPuzzle(blankTile, currentPuzzle, 2);

    swap(tempPuzzle1[2][1], tempPuzzle1[2][2]);
    newPuzzle(blankTile, currentPuzzle, 3);
  }
  else if (blankTileIndex == 8) {
    swap(tempPuzzle1[2][2], tempPuzzle1[1][2]);
    newPuzzle(blankTile, currentPuzzle, 1);

    swap(tempPuzzle1[2][2], tempPuzzle1[2][1]);
    newPuzzle(blankTile, currentPuzzle, 2);
  }
}

void Puzzle::newPuzzle(tile* blankTile, vector<vector<char> > currentPuzzle, int neighbor) {
  tile* tempTile = new tile;

  if (goalState) {
    return;
  }

  //if we have seen this puzzle before
  if (checkHistory(currentPuzzle)) {
    if (neighbor == 1) {
      blankTile -> neighbor1 = NULL;
    }
    else if (neighbor == 2) {
      blankTile -> neighbor2 = NULL;
    }
    else if (neighbor == 3) {
      blankTile -> neighbor3 = NULL;
    }
    else if (neighbor == 4) {
      blankTile -> neighbor4 = NULL;
    }
  }
  //if not seen before, add to list of visited puzzles and update travel
  else if (!checkHistory(currentPuzzle)) {
    visitedPuzzles.push_back(currentPuzzle);

    tempTile -> movementCost = blankTile -> movementCost + 1;
    tempTile -> heuristicVal = heuristicAlgo(currentPuzzle);
    currPuzzle = currentPuzzle;

    if (neighbor == 1) {
      blankTile -> neighbor1 = tempTile;
      blankTile -> neighbor1 -> previousNode = blankTile;
      minHeap.push(blankTile -> neighbor1);
    }
    else if (neighbor == 2) {
      blankTile -> neighbor2 = tempTile;
      blankTile -> neighbor2 -> previousNode = blankTile;
      minHeap.push(blankTile -> neighbor2);
    }
    else if (neighbor == 3) {
      blankTile -> neighbor3 = tempTile;
      blankTile -> neighbor3 -> previousNode = blankTile;
      minHeap.push(blankTile -> neighbor3);
    }
    else if (neighbor == 4) {
      blankTile -> neighbor4 = tempTile;
      blankTile -> neighbor4 -> previousNode = blankTile;
      minHeap.push(blankTile -> neighbor4);
    }
    nodesExpanded++;
    getNodesInQueue();

    if (checkPuzzle(currentPuzzle)) {
      goalState = true;
      goalTile = tempTile;
      return;
    }
  }

}

//function to check if we've encountered this puzzle before
bool Puzzle::checkHistory(vector<vector<char> > puzzle) {
  
  bool verdict = false;
  for (int i = 0; i < visitedPuzzles.size(); ++i) {
    if (puzzle == visitedPuzzles[i]) {
      verdict = true;
    }
  }
  return verdict;
}

//update the member value of nodesInQueue
void Puzzle::getNodesInQueue() {
  if (minHeap.size() > nodesInQueue) {
    nodesInQueue = minHeap.size();
  }
}

int Puzzle::heuristicAlgo(vector<vector<char> > currentPuzzle) {

  int heuristic = 0;

  //hard code the values of the solved puzzle - taken from checkPuzzle function above
  vector<vector<char> > solvedPuzzle;
  vector<char> row1 = {1, 2, 3};
  vector<char> row2 = {4, 5, 6};
  vector<char> row3 = {7, 8, '*'};
  solvedPuzzle.push_back(row1);
  solvedPuzzle.push_back(row2);
  solvedPuzzle.push_back(row2);

  //uniform cost search
  if (userSearch == 1) {
    heuristic = 0;
  }
  //A* with Misplaced Tile Heuristic
  else if (userSearch == 2) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (currentPuzzle[i][j] != solvedPuzzle[i][j]) {
          ++heuristic;
        }
      }
    }
  }
  //A* with Manhattan Distance Hueristic
  else if (userSearch == 3) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int x = 0; x < 3; ++x) {
          for (int y = 0; y < 3; ++y) {
            if (solvedPuzzle[i][j] == currentPuzzle[x][y]) {
              heuristic += abs(i - x);
              heuristic += abs(j - y);
            }
          }
        }
      }
    }
  }
  return heuristic;
}



