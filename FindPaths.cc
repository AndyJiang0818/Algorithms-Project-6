// Xihao Jiang
// CSCI 335
// HW 6
// 5/10/21

#include <iostream>
#include <vector>
#include <string>

#include "graph.h"

using namespace std;

int findPathDriver(int argc, char **argv)
{

  //Begin your code here. Feel free to add any helper functions or classes you need,
  //as long as we only have to call this function to run the specified assignment.

  Graph g;
  g.loadGraph(argv[1]);
  g.findPath(atoi(argv[2]));

  return 0;
}

// Do not modify anything below this line

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    cout << "Usage: " << argv[0] << " <GRAPH_FILE>"
         << "<STARTING_VERTEX>" << endl;
    return 0;
  }

  findPathDriver(argc, argv);

  return 0;
}
