#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream fileInput;

    fileInput.open("input.txt");

    char buff[5];
    char next;
    string strBuff;
    bool noMatch = true;
    int counter = 4;

    // Get first four characters of input
    fileInput.get(buff, 5);

    cout << "1st buff is " << buff << endl;

    while ( fileInput.get(next) && noMatch)  {

        strBuff = buff;

        size_t found = strBuff.find_first_of(strBuff);

        if (found == std::string::npos )
            noMatch = false;

        if (noMatch) {
           for (int i = 0; i <=2; i++) {
                buff[i] = buff[i+1];
            }
           buff[3] = next;
           counter++;
        }
        
        //cout << "next is: " << next << endl;
        //cout << "buff is " << buff << endl;
        
    }
    cout << "found at postion " << counter << endl;
        
}