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

        inmem += 2;
        for(int i = 0; i < line.length(); i++) {
            if(line[i] == '\\') {
                if(line[i+1] =='\\' || line[i+1] == '\"') {
                    inmem++;
                    i++;
                }
                else {
                    inmem += 3;
                    i += 3;
                }
            }
        }
    }

    //ans 1371

    cout << "in mem:" << inmem << endl;
    cout << "symbols: " << symbols << endl;
    cout << "result: " << symbols - inmem << endl;

    return 0;
}
