// Xihao Jiang
// CSCI 335
// HW 6
// 5/10/21

#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outside those statements
class Path
{
public:
    vector<int> paths;
    double weight;
    Path()
    {
        weight = 0;
    }

    Path(const Path &p)
    {
        paths = vector<int>(p.paths);
        weight = p.weight;
    }

    bool insert(int node)
    {
        if (find(paths.begin(), paths.end(), node) != paths.end())
        {
            return false;
        }
        paths.push_back(node);
        return true;
    }

    int getBack()
    {
        return paths.back();
    }

    bool operator<(const Path &p) const
    {
        return weight < p.weight;
    }

    Path operator=(const Path &p)
    {
        paths = vector<int>(p.paths);
        weight = p.weight;
        return *this;
    }
};

class Graph
{
public:
    void loadGraph(const char *filename)
    {
        ifstream infile(filename);
        string line;
        int vertexCount;
        getline(infile, line);
        vertexCount = atoi(line.c_str());
        for (int i = 0; i < vertexCount; i++)
        {
            getline(infile, line);
            istringstream iss(line);
            int vertex, neighbour;
            double weight;
            iss >> vertex;
            map<int, double> pair;
            while (iss >> neighbour >> weight)
            {
                pair[neighbour] = weight;
            }
            edges[vertex] = pair;
        }
        infile.close();
    }

    void query(const char *filename)
    {
        ifstream infile(filename);
        int from, to;
        while (infile >> from >> to)
        {
            if (edges.find(from) != edges.end())
            {
                if (edges[from].find(to) != edges[from].end())
                {
                    cout << from << " " << to << ": connected " << edges[from][to] << endl;
                }
                else
                {
                    cout << from << " " << to << ": not_connected" << endl;
                }
            }
            else
            {
                cout << from << " " << to << ": not_connected" << endl;
            }
        }
        infile.close();
    }

    void findPath(int from)
    {
        for (auto it = edges.begin(); it != edges.end(); it++)
        {
            findPath(from, it->first);
        }
    }

    void findPath(int from, int to)
    {
        Path p;
        p.insert(from);
        BinaryHeap<Path> heap;
        heap.insert(p);
        cout << to << ":";
        while (!heap.isEmpty())
        {
            heap.deleteMin(p);
            int back = p.getBack();
            if (back == to)
            {
                for (unsigned int i = 0; i < p.paths.size(); i++)
                {
                    cout << " " << p.paths[i];
                }
                cout << " cost: " << p.weight << endl;
                return;
            }
            if (edges.find(back) != edges.end())
            {
                for (auto it = edges[back].begin(); it != edges[back].end(); it++)
                {
                    int next = it->first;
                    double weight = it->second;
                    Path pn(p);
                    if (pn.insert(next) == true)
                    {
                        pn.weight += weight;
                        heap.insert(pn);
                    }
                }
            }
        }
        cout << " not_possible" << endl;
    }

private:
    map<int, map<int, double>> edges;
};

#endif
