#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

//the relationship between tile and puzzle classes are similar to the card and deck classes from cs12/14, reference those for later for ideas for functions / private variables

//reference concepts of dynamic programming from cs141 to compare to A* and the use of the different heuristic values / methods (how are we keeping puzzles we've already seen, etc.)

struct tile {
  
  //g(n) and h(n) should be calculated in the tile class over the puzzle class (problem space revolves around the blank tile rather than the entire puzzle itself)
  int movementCost;
  int heuristicVal;

  //tile pointers to its neighbors and parent node (previous tile the blank was at)
  tile* neighbor1;
  tile* neighbor2;
  tile* neighbor3;
  tile* neighbor4;
  tile* previousNode;

};

class Puzzle {
  
  //variables / ADTs used in relation to the puzzle and its tiles
  private:

  //representation of puzzle
  vector<vector<char> > currPuzzle;

  //root node (where we start)
  tile* root;

  //goal node (where we finish)
  tile* goalTile;

  //check if we reached the goal state / finished puzzle
  bool goalState;

  //user input for search method / heuristic
  int userSearch;

  //total nodes expanded in the search space
  int nodesExpanded;

  //total nodes in the priority queue
  int nodesInQueue;

  //priorty queue to access the lowest heuristic + movementCost node (reference minHeap from cs141 - hw3a
  //may need to change greater<tile*> with something else that can compare the g(n)+h(n) of different tiles
  priority_queue<tile*, vector<tile*>, greater<tile*>> minHeap; 
  
  //list of all puzzles to compare repeat states (could try to swap out with an array)
  vector<vector<vector<char>>> visitedPuzzles;
  
  //functions of the Puzzle class to use private members
  public:
  Puzzle();

  void makePuzzle(int userInput);
  void selectAlgorithm(int userAlgo);
  void searchPuzzle(tile* blankTile, vector<vector<char> > currPuzzle);
  bool checkPuzzle(vector<vector<char> > currPuzzle);
  void swapTile(tile* blankTile, vector<vector<char> > currPuzzle, int blankTileIndex);
  void newPuzzle(tile* blankTile, vector<vector<char> > currPuzzle);
  bool checkHistory(vector<vector<char> > puzzle);

};

#endif /* _PUZZLE_H_ */
