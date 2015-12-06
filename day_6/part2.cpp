/*You just finish implementing your winning light pattern when you realize you mistranslated Santa's message from Ancient Nordic Elvish.

The light grid you bought actually has individual brightness controls; each light can have a brightness of zero or more. The lights all start at zero.

The phrase turn on actually means that you should increase the brightness of those lights by 1.

The phrase turn off actually means that you should decrease the brightness of those lights by 1, to a minimum of zero.

The phrase toggle actually means that you should increase the brightness of those lights by 2.

What is the total brightness of all lights combined after following Santa's instructions?

For example:

turn on 0,0 through 0,0 would increase the total brightness by 1.
toggle 0,0 through 999,999 would increase the total brightness by 2000000.*/

//sorry , this is sloppy way to do it

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

#define SIZE 1000

int lights[SIZE][SIZE];

void initialize()
{
    for(int x = 0; x < SIZE; x++) {
        for(int y = 0; y < SIZE; y++) {
            lights[x][y] = 0;
        }
    }
}

void turnOnLights(int f_x, int f_y, int to_x, int to_y)
{
    for(int x = f_x; x <= to_x; x++) {
        for(int y = f_y; y <= to_y; y++) {
            //cout << "x: " << x << "Y; " << y << endl;
            lights[x][y] += 1;
        }
    }
}

void turnOffLights(int f_x, int f_y, int to_x, int to_y)
{
    for(int x = f_x; x <= to_x; x++) {
        for(int y = f_y; y <= to_y; y++) {
            if(lights[x][y] != 0)
                lights[x][y] -= 1;
        }
    }
}

void toggleLights(int f_x, int f_y, int to_x, int to_y)
{
    for(int x = f_x; x <= to_x; x++) {
        for(int y = f_y; y <= to_y; y++) {
                lights[x][y] += 2;
        }
    }
}


int main()
{
    ifstream input("input.txt");
    string line;

    initialize();

    while(getline(input,line)) {
        replace(line.begin(), line.end(), ',', ' ');
        istringstream iss(line);

        string s1,s2,s3,s4,s5,s6,s7;

        if(!(iss >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7)) {
            iss >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
            if(s1 == "toggle") {
                toggleLights(stoi(s2),stoi(s3),stoi(s5),stoi(s6));

            }
        }
        else {

            if(s2 == "on")
                turnOnLights(stoi(s3), stoi(s4), stoi(s6), stoi(s7));
            if(s2 == "off")
                turnOffLights(stoi(s3), stoi(s4), stoi(s6), stoi(s7));
        }
    }

    int counter = 0;

    for(int x = 0; x < SIZE; x++) {
        for(int y = 0; y < SIZE; y++) {
            counter += lights[x][y];
        }
    }

    cout << "counter: " << counter << endl;

    return 0;
}
