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

    for(int i = 0; i < (int)value.size(); i++) {
        if(value[i] == value[i+1])
            return true;
    }

    return false;
}

bool notThisString(const string &value)
{
    char a_array[4] = {'a','c','p','x'};
    char b_array[4] = {'b','d','q','y'};

    for(int i = 0; i < (int)value.size(); i++) {
        for(int j = 0; j < 4; j++) {
            if(value[i] == a_array[j]) {
                if(value[i+1] == b_array[j])
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    ifstream input("input.txt");
    string line;

    size_t nice{0};


    while(getline(input,line)) {
        if(!notThisString(line)) {
            if((containsPair(line)) && (checkVowels(line) >= 3))
                nice++;
        }
    }

    cout << "nice: " << nice << endl;

    input.close();
    return 0;
}
