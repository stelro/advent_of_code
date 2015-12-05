#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int checkVowels(const string &value)
{
    char vowels[5] = {'a','e','i','o','u'};
    int ithas = 0;

    for(int i = 0; i < (int)value.size(); i++) {
        for(int j = 0; j < 5; j++) {
            if(value[i] == vowels[j])
                ithas++;
        }
    }
    return ithas;
}

bool containsPair(const string &value)
{
    for (int i = 0; i < (int)value.size(); i++) {
        for(int j = 1; j < (int)value.size(); j++) {
            if(value[i] == value[j])
                return true;
        }
    }

    return false;
}

int main()
{
    ifstream input("input.txt");
    string line;

    while(getline(input,line)) {
       if(checkVowels(line) >= 3)
          cout << " true " << endl;
      else
         cout << "false " << endl;
    }

    return 0;
}
