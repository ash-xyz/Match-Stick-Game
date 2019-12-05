#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void game();
int removalAlgorithim(int matches);
bool firstMoveWin(int matches);
bool playerPreference(bool win);
void playAgain();
int randomMatches();

int main()
{
    game();
    return 0;
}

void game()
{
    //Generates a random a pile of matches to play the game with.
    int matches = randomMatches();
    //Introduction
    cout << "Here's the stick human, there's a pile of matches with " << matches << " matches in it." << endl;
    cout << "You can remove either 1,2 or 5 matches." << endl;
    cout << "You win when I can't remove any more matches, otherwise ya lose!" << endl;
    cout << endl;

    //Determines whether the player is going first or not
    bool playerTurn;
    playerTurn = playerPreference(firstMoveWin(matches));

    /*Actual Game*/
    while (matches != 0)
    {
        if (playerTurn)
        {
            int reduce;
            cout << "Reduce the number of matchsticks by 1,2 or 5: ";
            cin >> reduce;

            /*A few statements to catch some integer based errors*/
            if (reduce != 2 && reduce != 1 && reduce != 5)
            {
                cout << "Stop wasting my time petty human, you know the rules... you can only remove 1,2 or 5 matches." << endl;
                continue;
            }
            if (matches < 5 && reduce > 2)
            {
                cout << "Foolish human, you can't remove more matches than there are in this pile of mine! " << endl;
                continue;
            }
            if (matches < 2 && reduce > 1)
            {
                cout << "There is only 1 match left, hence you can only remove ONE MATCH!" << endl;
                cout << "You are clearly not worth the oxygen it costs to keep you alive..." << endl;
                continue;
            }
            matches -= reduce;
            playerTurn = false;
        }
        else
        {
            int reduce = removalAlgorithim(matches);
            cout << "My Turn!!!" << endl;
            cout << "I am going to remove " << reduce << " matches" << endl;

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
        cout << endl;
    }
    else
    {
        cout << "Looks like you win, guess you got lucky!";
        cout << endl;
    }

    playAgain();
}

//Generates a random set of matches between 10-20
int randomMatches()
{
    srand(time(NULL));

    return (rand() % 10) + 20;
}

//Algorithm Computer uses to guarantee the highest chance of winning
int removalAlgorithim(int matches)
{
    /*Blissful Loss, assuming the human plays it properly*/
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
    /*We're Winning!!!*/
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

//Determines Whether the first move can win in a perfect game
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

    //Computer knows the first move wins
    if (win)
    {
        cout << "I hope you extend me the courtesy of letting me go first (Y/N):";
        cin >> answer;
        cout << endl;

        if (toupper(answer) == 'Y')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    //Computer knows first move loses
    else
    {
        cout << "By all means, please go first! (Y/N):";
        cin >> answer;
        cout << endl;
        if (toupper(answer) == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void playAgain()
{
    char answer;
    cout << "Do you want to play again? (Y/N)" << endl;
    cin >> answer;

    if (toupper(answer) == 'Y')
    {
        game();
    }
}