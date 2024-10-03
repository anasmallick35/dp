/*Kochouseph Chittilappilly went to Dhruv Zplanet , a gaming space, with his friends and played a game called “Guess the Word”.
Rules of games are –
Computer displays some strings on the screen and the player should pick one string / word if this word matches with the random word that the computer picks then the player is declared as Winner.
Kochouseph Chittilappilly’s friends played the game and no one won the game. This is Kochouseph Chittilappilly’s turn to play and he decided to must win the game.
What he observed from his friend’s game is that the computer is picking up the string whose length is odd and also that should be maximum. Due to system failure computers sometimes cannot generate odd length words. In such cases you will lose the game anyways and it displays “better luck next time”. He needs your help. Check below cases for better understand

Sample input 0:
5 → number of strings
Hello Good morning Welcome you
Sample output 0:
morning

Explanation:

Hello → 5
Good → 4
Morning → 7
Welcome → 7
You → 3
First word that is picked by computer is morning

Sample input 1:
3
Go to hell
Sample output 1:
Better luck next time
Explanation: 
Here no word with odd length so computer confuses and gives better luck next time*/



#include<iostream>
#include<string>
using namespace std;


/*int main(){
    int n;
    cin >> n;

    string word, result = "Better Luck next time";
    int maxLength = 0;

    for(int i = 0;i<n;i++){
        cin >> word;

        if(word.length()%2 == 1){
            if(word.length() > maxLength){
                maxLength = word.length();
                result = word;
            }
        }
    }
    cout << result;
    return 0;
}*/


#include <iostream>
#include <string>
using namespace std;

string resultString(int n) {
    int maxLength = 0;
    string result = "Better luck next time";
    
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        
        if (word.length() % 2 == 1) {

            if (word.length() > maxLength) {
                maxLength = word.length();
                result = word;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    cout << resultString(n) << endl;
    
    return 0;
}
