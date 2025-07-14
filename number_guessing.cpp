#include <iostream>
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    int numberToGuess, userGuess, attempts = 0;
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 100;

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));
    numberToGuess = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;

    cout << "[*] Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a number between " << LOWER_BOUND << " and " << UPPER_BOUND << "." << endl;
    cout << "Can you guess it? Let's find out!" << endl;

    do {
        cout << "\nEnter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < numberToGuess) {
            cout << "[!] Too low! Try a higher number." << endl;
        } else if (userGuess > numberToGuess) {
            cout << "[!] Too high! Try a lower number." << endl;
        } else {
            cout << "[✓] Congratulations! You guessed it right in " << attempts << " attempt(s)!" << endl;
        }

    } while (userGuess != numberToGuess);

    cout << "Thanks for playing!" << endl;
    return 0;
}
