/*--- Day 5: Doesn't He Have Intern-Elves For This? ---

Santa needs help figuring out which strings in his text file are naughty or nice.

A nice string is one with all of the following properties:

It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements.
For example:

ugknbfddgicrmopn is nice because it has at least three vowels (u...i...o...), a double letter (...dd...), and none of the disallowed substrings.
aaa is nice because it has at least three vowels and a double letter, even though the letters used by different rules overlap.
jchzalrnumimnmhp is naughty because it has no double letter.
haegwjzuvuyypxyu is naughty because it contains the string xy.
dvszwmarrgswjxmb is naughty because it contains only one vowel.
How many strings are nice?*/

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
