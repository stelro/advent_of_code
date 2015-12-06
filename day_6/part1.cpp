/*--- Day 6: Probably a Fire Hazard ---

Because your neighbors keep defeating you in the holiday house decorating contest year after year, you've decided to deploy one million lights in a 1000x1000 grid.

Furthermore, because you've been especially nice this year, Santa has mailed you instructions on how to display the ideal lighting configuration.

Lights in your grid are numbered from 0 to 999 in each direction; the lights at each corner are at 0,0, 0,999, 999,999, and 999,0. The instructions include whether to turn on, turn off, or toggle various inclusive ranges given as coordinate pairs. Each coordinate pair represents opposite corners of a rectangle, inclusive; a coordinate pair like 0,0 through 2,2 therefore refers to 9 lights in a 3x3 square. The lights all start turned off.

To defeat your neighbors this year, all you have to do is set up your lights by doing the instructions Santa sent you in order.

For example:

turn on 0,0 through 999,999 would turn on (or leave on) every light.
toggle 0,0 through 999,0 would toggle the first line of 1000 lights, turning off the ones that were on, and turning on the ones that were off.
turn off 499,499 through 500,500 would turn off (or leave off) the middle four lights.
After following the instructions, how many lights are lit?
*/

//sorry , this is sloppy way to do it

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

#define SIZE 1000

bool lights[SIZE][SIZE];

void initialize()
{
    for(int x = 0; x < SIZE; x++) {
        for(int y = 0; y < SIZE; y++) {
            lights[x][y] = false;
        }
    }
}

void turnOnLights(int f_x, int f_y, int to_x, int to_y)
{
    for(int x = f_x; x <= to_x; x++) {
        for(int y = f_y; y <= to_y; y++) {
            //cout << "x: " << x << "Y; " << y << endl;
            lights[x][y] = true;
        }
    }
}

void turnOffLights(int f_x, int f_y, int to_x, int to_y)
{
    for(int x = f_x; x <= to_x; x++) {
        for(int y = f_y; y <= to_y; y++) {
            lights[x][y] = false;
        }
    }
}

void toggleLights(int f_x, int f_y, int to_x, int to_y)
{
    for(int x = f_x; x <= to_x; x++) {
        for(int y = f_y; y <= to_y; y++) {
            if(lights[x][y] == false)
                lights[x][y] = true;
            else
                lights[x][y] = false;
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

    size_t counter = 0;

    for(int x = 0; x < SIZE; x++) {
        for(int y = 0; y < SIZE; y++) {
            if(lights[x][y] == true)
                counter++;
        }
    }

    cout << "counter: " << counter << endl;

    return 0;
}
