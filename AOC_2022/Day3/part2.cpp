#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <stack>

using namespace std;

int getScore(char, string);

int getPriority(char);

int main() {

    int prioritySum = 0, found, itemCharVal, itemPriority, inventorySize;
    ifstream input;
    string first, second, third;
    char item;

    stack<string> inventory;

    string inputLine;
    
    input.open("input.txt", std::istream::in);

    // Load file intro string stack
    while ( std::getline(input, inputLine) )
    {
        inventory.push(inputLine);
    }
    
    inventorySize = inventory.size();

    int i = 0;

    while ( i < inventorySize) {

         first = inventory.top();
         inventory.pop();
         second = inventory.top();
         inventory.pop();
         third = inventory.top();
         inventory.pop();
         i +=3;

         //cout << first << endl;
         //cout << second << endl;
         //cout << third << endl;
         //cout << "group " << i << endl;

        // find first matching character
         found = first.find_first_of(second);

         while (third.find_first_of(first[found]) == string::npos) {

            found = first.find_first_of(second, found+1);

         }
         //cout << "match was " << first[found] << endl;

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