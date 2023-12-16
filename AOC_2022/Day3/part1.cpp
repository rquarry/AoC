#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

int getScore(char, string);

int getPriority(char);

int main() {

    int prioritySum = 0, found, itemCharVal, itemPriority;
    ifstream input;
    string first, second;
    char item;

    string inputLine;
    
    input.open("input.txt", std::istream::in);

    while ( std::getline(input, inputLine) )
    {
        int lineSize = inputLine.size();

        //cout << "Line " << counter << " is " << lineSize << " characters long " << inputLine << endl;
        //cout << "first half " << inputLine.substr(0, lineSize/2) << "\t" << "second half: " << inputLine.substr(lineSize/2) << endl;

        first = inputLine.substr(0, lineSize/2);
        second = inputLine.substr(lineSize/2);

        // get position value in string of first common character
        found = first.find_first_of(second);

        item = first[found];

        itemCharVal = int(first[found]);
    

        if ( isupper(item) ) {
            itemPriority = itemCharVal -  38;
            cout << "char: " << itemCharVal << " priority: " << itemPriority << endl;
        }
        else {
            itemPriority = itemCharVal -  96;
            cout << "char: " << itemCharVal << "priority: " << itemPriority << endl;
        }
        //cout << "Common letter is: " << itemCharVal << endl;

        prioritySum += itemPriority;


    }
    cout << "Sum is: " << prioritySum;

    return 0;

}

int getPriority(char letter) {


}