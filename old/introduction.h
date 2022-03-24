// Libraries
#include <iostream>

// Namespace
using namespace std;


// Introduction to the game including insturctions on how to play

// Introduction Class
// This class will have player names, player score, and tell insturctions to the player
class Introduction{
    private:
        string playerName;
        int playerStackScore;
    public:
        // Constuctor
        // Purpose: Link playername to input and set score at the start of game
        Introduction(string userInputName, int defaultScore=0){};

        // Deconstructor
        // Purpose: Print player name and associated score
        ~Introduction(){};

        // Insturctions
        void insturctions(){};
};

// Introduction Constuctor
Introduction(string setname, int setscore = 0)
{
    name = setname;
    score = setscore;
};

// Introduction Deconstructor
~Introduction(){
    cout << "Player " << name << " ends with a score of " << score << "\n";
};

// Insturctions
// Purpose: Print how to play
void Insturctions(){
    cout "Welcome ___ This is how you play."
};

