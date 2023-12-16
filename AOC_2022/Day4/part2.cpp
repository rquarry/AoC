#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

int getScore(char, string);

int getPriority(char);

int main() {

    int sumPairs = 0, delim, firstLower, firstUpper, secondLower, secondUpper, counter =0;
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
        

        delim = inputLine.find_first_of(",");

        first = inputLine.substr(0, delim);
        second = inputLine.substr(delim+1);

        //cout << "First: " << first << endl;
        //cout << "Second " << second << endl;

        delim = first.find_first_of("-");

        firstLower = stoi(first.substr(0, delim));
        firstUpper = stoi(first.substr(delim+1));

        delim = second.find_first_of("-");
        secondLower = stoi(second.substr(0, delim));
        secondUpper = stoi(second.substr(delim+1));

        cout << "first lower and upper: " << firstLower << " : " << firstUpper << endl;
        cout << "second lower and upper: " << secondLower << " : " << secondUpper << endl;

        if (firstUpper <= secondUpper && firstUpper >= secondLower) {
                sumPairs++;
                cout << "Match! first upper is inside range" << endl;
        }
        else if (secondUpper <= firstUpper && secondUpper >= firstLower) {
                sumPairs++;
                cout << "Match! 2nd upper is inside the first pair" << endl;
            
        }
       

       counter++;
    }

    cout << "Pairs = " << sumPairs << endl;

     return 0;

}