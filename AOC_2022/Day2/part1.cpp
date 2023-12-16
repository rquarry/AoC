#include <iostream>
#include <fstream>

using namespace std;

int getScore(char, string);

int main() {

    char human, elf;
    int opponent, player, totalScore = 0, line = 0;
    ifstream input;
    

    input.open("input.txt", std::istream::in);

    while (input >> elf >> human ) {

        opponent = getScore(elf, "elf");
        player = getScore(human, "human");

        //cout << "Elf :" << elf << " Score: " << opponent << endl;
        //cout << "Human :" << human << " Score: " << player << endl;

        // Both rock = draw 
        if (elf == 'A' && human == 'X')
            totalScore += (player + 3);
        // player paper beats elf rock
        else if (elf == 'A' && human == 'Y' )
            totalScore += (player + 6);
        // Elf rock beats player scissors
        else if (elf == 'A' && human == 'Z') 
            totalScore += player;
        // Draw on paper
        else if (elf == 'B' && human == 'Y' )
            totalScore += (player + 3);
        // player scissors beats elf paper
        else if (elf == 'B' && human == 'Z') 
            totalScore += (player +6);
        // elf paper covers rock
        else if (elf == 'B' && human == 'X' )
            totalScore += (player);
        // elf scissors beat paper
         else if (elf == 'C' && human == 'Y' )
            totalScore += (player);
        // draw on scissors
        else if (elf == 'C' && human == 'Z') 
            totalScore += (player +3);
        // player scissors beats rock
        else if (elf == 'C' && human == 'X' )
            totalScore += (player +6 );

        line++;
        
        cout << "Total score: " << totalScore << endl;
        
    }

    cout << "The total score is: " << totalScore << " for " << line << " results";
    
    
    return 0;
}

int getScore(char choice, string player) {

    int score;

    // Rock
    if (choice == 'A' || choice == 'X') {
        score = 1;
        cout << player << " picked Rock" << endl;
    }
    // paper
    else if (choice == 'B' || choice == 'Y') {
        score = 2;
        cout << player << " picked paper" << endl;
    }
        
    //scissors
    else if (choice == 'C' || choice == 'Z') {
        score = 3;
        cout << player << " picked scissors" << endl;
    }
    // error
    else {
        score = 0;
        cout << "Error: " << choice << endl;
        exit(-1);
    }

    return score;
}