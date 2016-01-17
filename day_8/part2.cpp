#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    ifstream input("input.txt");
    string line;

    size_t symbols = 0;
    size_t inmem = 0;

    while(getline(input,line)) {
        symbols += line.length();
        inmem += 2;
        for(int i = 0; i < line.length(); i++) {
            if (line[i] == '"' || line[i] == '\\')
                inmem += 1;
        }
    }

    //ans 2117

    cout << "in mem:" << inmem << endl;
    cout << "symbols: " << symbols << endl;
    cout << "result: " << symbols - inmem << endl;

    return 0;
}
