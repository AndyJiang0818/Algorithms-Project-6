# Graph Algorithms

## Overview
1. For each vertex, there is a list of the adjacent vertices with positive edge weights. For instance, vertex 1 is connected to vertex 2 (edge weight 0.2), to vertex 4 (edge weight
10.1) and to vertex 5 (edge weight 0.5). Vertex 2 is connected to vertex 1 (edge weight 1.5), vertex 4
has no outgoing edges, etc

2. Implement Dijkstra’s Algorithm, using a priority queue (i.e. heap). 

3. The first number is the target vertex. (aka: the last line beginning with 7: is the shortest path from
the input starting vertex 1, to the target vertex 7.)

4. If a vertex does not point to any other vertex, and that vertex is used as the starting vertex argument,
your program should output not_possible for every path, besides the path to itself.

## Thoughts
1. Within the “CreateGraphAndTest.cc” file, 
state the “graph”, then declare “loadgraph” and “query”. 

2. Within the “graph.h” file,  
write the “graph” class, then create the “loadgraph” and “query” methods. 
The purpose of the “loadgraph” method is to read and open the text file. 
The purpose of the “query” method is to print the weight of the edges. 

3. Within the “FindPaths.cc” file, 
state the “graph”, then declare “loadgraph” and “findPath”. 

4. Within the “graph.h” file,  
create two “findPath” methods inside the “graph” class. 
One of the “findPath” method is to print the cost of the paths. 
The second “findPath” method is to show the output of “not_possible” paths. 
Write the path class on top of the code before creating the second findPath method, 
in order to clarify the “not_possible” situations. 

## Run
- To compile on terminal type:
1. make clean
2. make all

- To delete executables and object file type:
1. make clean

- To run with a given file that is redirected to standard input:
1. ./CreateGraphAndTest Graph1.txt AdjacencyQueries1.txt
2. ./CreateGraphAndTest Graph2.txt AdjacencyQueries2.txt
3. ./FindPaths Graph2.txt 1
4. ./FindPaths Graph1.txt 3
5. ./FindPaths Graph2.txt 3
