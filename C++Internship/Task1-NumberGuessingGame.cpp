// Task 1
// Number Guessing Game
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main()
{
    int n, guess, turns;
    bool a;
    turns = 1;
    srand(time(0));
    n = rand() % 101; // I am limiting the random no. upto 100 using rand()%101
    cout << "Welcome to my game!" << endl;
    cout << "Guess the number! (from 0 to 100) " << endl;

    do
    {

        
            cout << "Enter your guess:";
            cin >> guess;
            a = cin.fail();
            if (a)
            {
                cout << "Please enter valid input!" << endl;
                cin.clear();
            }
       

        if (guess < 0 || guess > 100)
        {
            cout << "Invalid Input!Enter any number from 1 to 100.";
            
        }
        else if (guess < n)
        {
            cout << "Your guess is lower than the number. Guess again!" << endl;
        }
        else if (guess > n)
        {cin.clear();
            cout << "Your guess is higher than the number. Guess again!" << endl;
        }
        else
        {
            cout << "Congratulations!You guessed the right number i.e. " << n << " in " << turns << " turns." << endl;
        }
        turns++;
    } while (guess != n);
    return 0;
}
