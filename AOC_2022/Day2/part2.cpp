#include <iostream>
#include <fstream>

using namespace std;

int getScore(char);

int main() {

    char human, elf;
    int opponent, player, totalScore = 0, line = 0;
    ifstream input;
    

    input.open("input.txt", std::istream::in);

    while (input >> elf >> human ) {

        opponent = getScore(elf);
        player = getScore(human);

        //cout << "Elf :" << elf << " Score: " << opponent << endl;
        //cout << "Human :" << human << " Score: " << player << endl;

        // player needs to lose
        if (elf == 'A' && human == 'X')
            totalScore += (getScore('Z'));
        // player needs draw
        else if (elf == 'A' && human == 'Y' ) 
            totalScore += (getScore('X') + 3);
        // player needs to win
        else if (elf == 'A' && human == 'Z') 
             totalScore += (getScore('Y')+ 6);
        // player needs to lose
        else if (elf == 'B' && human == 'X' )
             totalScore += player;
        // player needs to draw
        else if (elf == 'B' && human == 'Y') 
             totalScore += (player+ 3);
        // Player needs to win
        else if (elf == 'B' && human == 'Z' )
             totalScore += (player + 6);
        // player needs to lose
         else if (elf == 'C' && human == 'X' )
             totalScore += (getScore('Y'));
        // player needs to draw
        else if (elf == 'C' && human == 'Y') 
             totalScore += (getScore('Z') + 3);
        // player needs to win
        else if (elf == 'C' && human == 'Z' )
             totalScore += (getScore('X') + 6);

        line++;
        
        cout << "Total score: " << totalScore << endl;
        
    }

    cout << "The total score is: " << totalScore << " for " << line << " results";
    
    
    return 0;
}

int getScore(char choice) {

    int score;

    // Rock
    if (choice == 'A' || choice == 'X') 
        score = 1;
    // paper
    else if (choice == 'B' || choice == 'Y') 
        score = 2;
    //scissors
    else if (choice == 'C' || choice == 'Z') 
        score = 3;
    // error
    else {
        score = 0;
        cout << "Error: " << choice << endl;
        exit(-1);
    }

    return score;
}