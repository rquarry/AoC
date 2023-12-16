#include <fstream>
#include <iostream>
#include <string.h>
#include "crates.h"

using namespace std;

void stringShifter(int, string&, string&);

int main() {

    ifstream input;
    string inputDiscard;
    int mvNum, from, to;

    // Load crates into stacks from head file
    crateStacks.push_back(one);
    crateStacks.push_back(two);
    crateStacks.push_back(three);
    crateStacks.push_back(four);
    crateStacks.push_back(five);
    crateStacks.push_back(six);
    crateStacks.push_back(seven);
    crateStacks.push_back(eight);
    crateStacks.push_back(nine);
    
    input.open("input.txt", std::istream::in);

    while ( input >> inputDiscard >> mvNum >> inputDiscard >> from >> inputDiscard >> to )
    {
    
        
        //cout << mvNum << ":" << from << ":" << to << endl;
       
        stringShifter(mvNum, crateStacks[from-1], crateStacks[to-1]);

        //cout << "crates are: " << crateStacks[0] << endl << crateStacks[1] << endl << crateStacks[2] << endl;




    }

    cout << "Final result: " << crateStacks[0] << endl << crateStacks[1] << endl << crateStacks[2] << endl \ 
    << crateStacks[3] << endl << crateStacks[4] << endl << crateStacks[5] << endl << crateStacks[6] << endl \
    << crateStacks[7] << endl << crateStacks[8];

    return 0;
}

void stringShifter(int shiftNum, string& from, string& to) {

    for ( int i = 1; i <= shiftNum ; i++) {
        to.push_back(from[from.size()-i]);
    }
    
    from = from.substr(0, from.size()-shiftNum);
    
    

}