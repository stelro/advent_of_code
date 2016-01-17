#include <iostream>
using namespace std;

void fun(string input, int times);

int main()
{

    fun("1211",1);

    return 0;
}

void fun(string input, int times)
{
    int x = 0;
    string value;
    int count = 0;
    string newstring;

    for(int i = 0; i < input.size(); i++) {
        x = i;
        count = 0;
        do {
            x++;
            count++;
        }while(input[i] != input[x]);

        newstring += x += input[i];
    }
    
    cout << newstring << endl;
}
