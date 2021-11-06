#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <iostream>
#include <cstdlib>

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

  //root node (where we start)
  tile* root;

  //goal node (where we finish)
  tile* goalTile;

  

  //functions of the Puzzle class to use private members
  public:

};

#endif /* _PUZZLE_H_ */
