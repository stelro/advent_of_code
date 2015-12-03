/*--- Day 3: Perfectly Spherical Houses in a Vacuum ---

Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next. Moves are always exactly one house to the north (^), south (v), east (>), or west (<). After each move, he delivers another present to the house at his new location.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once. How many houses receive at least one present?

For example:

> delivers presents to 2 houses: one at the starting location, and one to the east.
^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<pair<int,int>,bool> visitedPoints;

bool checkVisited(pair<int,int> &coords)
{
    return visitedPoints.find(coords) != visitedPoints.end();
}

void addVisited(pair<int,int> &coords)
{
    if(!checkVisited(coords))
        visitedPoints[coords] = true;
}

int main()
{
    ifstream input("input.txt");

    char ch;

    int xaxis = 0;
    int yaxis = 0;

    pair<int,int> p;

    while(input >> noskipws >> ch) {

        if(ch == '^') {
            yaxis += 1;
            p = make_pair(yaxis,xaxis);
            addVisited(p);
        }

        if(ch =='>') {
            xaxis += 1;
            p = make_pair(yaxis,xaxis);
            addVisited(p);
        }

        if(ch == '<') {
            xaxis -= 1;
            p = make_pair(yaxis,xaxis);
            addVisited(p);
        }

        if(ch == 'v') {
            yaxis -= 1;
            p = make_pair(yaxis,xaxis);
            addVisited(p);
        }
    }

    cout << "map size: " << visitedPoints.size() << endl;

    input.close();

    return 0;
}
