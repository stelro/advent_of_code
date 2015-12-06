#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int main()
{
    ifstream input("input.txt");

    regex p1("(..).*\\1");
    regex p2("(.).\\1");

    string line;
    size_t counter{0};

    while(getline(input, line)) {
        if(regex_search(line,p1) && regex_search(line,p2))
            counter++;
    }

    cout << "counter: " << counter << endl;

    return 0;
}
