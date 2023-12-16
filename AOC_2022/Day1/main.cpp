#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

int main() {

    ifstream input;
    string fileLine;
    int fileNum;
    int elf = 1;
    list<int> mylist;
    
    input.open("input.txt", std::istream::in);

    while ( !(input.eof() ) ) {

        int totalCals = 0;

        getline(input, fileLine); // get the first line

        while ( fileLine != "") {
            //cout << "Found cals!" << endl;
            totalCals += stoi(fileLine);
            getline(input, fileLine);

        }
        //cout << "Elf: " << elf++ << " Cals: " << totalCals << endl;
        mylist.push_front(totalCals);

    }

    mylist.sort();
    cout << "list front: " << mylist.back() << endl;

    int topThree = mylist.back();
    //mylist.pop_back();
    mylist.pop_back();
    //topThree += mylist.pop_back();
    topThree += mylist.back();
     mylist.pop_back();
    topThree += mylist.back();

    cout << "top three: " << topThree;



    return 0;
}