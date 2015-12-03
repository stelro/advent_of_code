/*--- Part Two ---

The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.

This year, how many houses receive at least one present?

For example:

^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
^v^v^v^v^v now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.
*/

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
    int xaxis_r = 0;
    int yaxis_r = 0;

    pair<int,int> p;

    bool flag = false;

    while(input >> noskipws >> ch) {

        if(flag == false) {

            //ded moroz
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

        if(flag == true) {

            //robot
            if(ch == '^') {
                yaxis_r += 1;
                p = make_pair(yaxis_r,xaxis_r);
                addVisited(p);
            }

            if(ch =='>') {
                xaxis_r += 1;
                p = make_pair(yaxis_r,xaxis_r);
                addVisited(p);
            }

            if(ch == '<') {
                xaxis_r += -1;
                p = make_pair(yaxis_r,xaxis_r);
                addVisited(p);
            }

            if(ch == 'v') {
                yaxis_r += -1;
                p = make_pair(yaxis_r,xaxis_r);
                addVisited(p);
            }

        }

        //everything goes on this implementation
        flag = !flag;

    }

    cout << "map size: " << visitedPoints.size() << endl;

    input.close();

    return 0;
}
