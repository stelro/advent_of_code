/*--- Part Two ---

Now, given the same instructions, find the position of the first character that causes him to enter the basement (floor -1). The first character in the instructions has position 1, the second character has position 2, and so on.

For example:

) causes him to enter the basement at character position 1.
()()) causes him to enter the basement at character position 5.
What is the position of the character that causes Santa to first enter the basement?*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.txt");

    char ch;
    size_t counter{0};
    int possition{0};

    while(input >> noskipws >> ch) {

        possition++;

        if(ch == '(')
            counter++;
        if(ch == ')')
            counter--;

        if(counter == (-1))
            cout << "basement: " << possition << endl;
    }

    cout << "floor: " << counter << endl;

    input.close();

    return 0;
}
