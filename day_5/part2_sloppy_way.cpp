/*--- Part Two ---

Realizing the error of his ways, Santa has switched to a better model of determining whether a string is naughty or nice. None of the old rules apply, as they are all clearly ridiculous.

Now, a nice string is one with all of the following properties:

It contains a pair of any two letters that appears at least twice in the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but not like aaa (aa, but it overlaps).
It contains at least one letter which repeats with exactly one letter between them, like xyx, abcdefeghi (efe), or even aaa.
For example:

qjhvhtzxzqqjkmpb is nice because is has a pair that appears twice (qj) and a letter that repeats with exactly one letter between them (zxz).
xxyxx is nice because it has a pair that appears twice and a letter that repeats with one between, even though the letters used by each rule overlap.
uurcxstgmygtbstg is naughty because it has a pair (tg) but no repeat with a single letter between them.
ieodomkazucvgmuy is naughty because it has a repeating letter with one between (odo), but no pair that appears twice.
How many strings are nice under these new rules?*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pair {
    char p;
    int index;
};

bool containPair(const string &value)
{
    for(int i = 0; i < (int)value.size(); i++) {
        if(value[i] == value[i+2])
            return true;
    }

    return false;
}

bool containDouble(const string &value)
{
    Pair pairs[2];
    int i = 0;


    while(i <= (int)value.size()) {
        pairs[0].p = value[i];
        pairs[0].index = i;
        pairs[1].p = value[i+1];
        pairs[1].index = i+1;

        for(int x = 0; x < (int)value.size(); x++) {
            if((value[x] == pairs[0].p) && (x != pairs[0].index)) {
                if((value[x+1] == pairs[1].p)) {
                    if((value[x] != value[x+2])) {
                        return true;

                    }
                }
            }
        }

        i++;
    }

    return false;
}

int main()
{

    ifstream input("input.txt");
    string line;

    size_t counter{0};

    while(getline(input,line)) {
        if((containDouble(line)) && (containPair(line)))
            counter++;
    }

    cout << "coutner: " << counter << endl;

    return 0;
}
