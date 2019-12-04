#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void game();
int removalAlgorithim(int matches);
bool firstMoveWin(int matches);
bool playerPreference(bool win);
int randomMatches();

int main()
{
    game();
    return 0;
}

void game()
{
    int matches = randomMatches();
    bool playerTurn;
    cout << "Here's the stick, there are " << matches << " matches." << endl;
    cout << "You can remove either 1,2 or 5 matches." << endl;
    cout << "You win when I can't remove any more matches, otherwise ya lose!" << endl;

    //Determines whether the player is going first or not
    playerTurn = playerPreference(firstMoveWin(matches));

    /*Actual Game*/
    while (matches != 0)
    {
        if (playerTurn)
        {
            int reduce;
            cout << "Reduce the number of matchsticks by 1,2 or 5: ";
            cin >> reduce;
            matches -= reduce;
            playerTurn = false;
        }
        else
        {
            int reduce = removalAlgorithim(matches);
            cout<<"I am going to remove "<<reduce<<" matches"<<endl;

            matches -= reduce;
            playerTurn = true;
        }
        cout << "Remaining Matches are: " << matches << endl;
        cout << endl;
    }

    /*Determines Winner*/
    if (playerTurn)
    {
        cout << "Ha!, I win!";
    }
    else
    {
        cout << "Looks like you win, guess you got lucky!";
    }
}

int randomMatches()
{
    srand(time(NULL));

    //Generates a random number between 50 and 100
    return (rand() % 10) + 10;
}

int removalAlgorithim(int matches)
{
    /*Blissful Loss*/
    if (matches % 3 == 0)
    {
        if (matches >= 2)
        {
            return 2;
        }
        if (matches >= 1)
        {
            return 1;
        }
    }
    /*We're Winning*/
    if (matches % 3 != 0)
    {
        if (matches % 3 == 1)
        {
            return 1;
        }
        if (matches % 3 == 2)
        {
            return 2;
        }
    }
    return 1;
}

//Determines Whether the first move can win algorithmically
bool firstMoveWin(int matches)
{
    if (matches % 3 == 0)
    {
        return false;
    }
    return true;
}

bool playerPreference(bool win)
{
    /*Decides Who Goes First*/
    char answer;

    if (win)
    {
        cout << "I hope you extend me the courtest of letting me go first (Y/N):";
        cin >> answer;

        if (answer == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        cout << "By all means, please go first! (Y/N):";
        cin >> answer;

        if (answer == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}