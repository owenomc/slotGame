#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
using namespace std;

// Function to generate a random number between 0 and 9 for the slot machine
int spinSlotMachine() {
    return rand() % 10;
}

void displaySlotMachine(int slot1, int slot2, int slot3) {
    cout << " _______     _______     _______" << endl;
    cout << "|       |   |       |   |       |" << endl;
    cout << "|   " << slot1 << "   |   |   " << slot2 << "   |   |   " << slot3 << "   |" << endl;
    cout << "|_______|   |_______|   |_______|" << endl;
}

int credits = 100; // Starting coins
int bet = 0;
int round = 1;

// Numbers in machine
int slot1 = spinSlotMachine();
int slot2 = spinSlotMachine();
int slot3 = spinSlotMachine();

int main() {
    // Random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "WELCOME TO SUPERIOR SLOTS" << endl;
    _sleep(500);
    cout << "Thank you for joining us" << endl;
    _sleep(500);
    cout << "You have " << credits << " credits" << endl;
    _sleep(500);

    // Picks slot machine
    int slot;
    cout << "Enter slot machine Dragon Souls (1) or Space Quest (2): " << endl;
    cin >> slot;

    _sleep(500);

    switch (slot) {
        case 1: {
            cout << "Welcome to Dragon Souls Slot Machine" << endl;
            break;
        }
        case 2: {
            cout << "Welcome to Space Quest Slot Machine" << endl;
            break;
        }
        default: {
            cout << "WRONG ENTRY" << endl;
            break;
        }
    }

    _sleep(500);

    while (credits > 0) {
        cout << "Place your bet (1-" << credits << "): " << endl;
        cin >> bet;

        if (bet < 1 || bet > credits) {
            cout << "Invalid bet. Please bet between 1 and " << credits << "." << endl;
            continue;
        }

        displaySlotMachine(slot1, slot2, slot3);

        if (slot1 == slot2 && slot2 == slot3) {
            int bonusCoins = 10 * bet;
            credits += bonusCoins;
            cout << "Jackpot! You won " << bonusCoins << " bonus coins!" << endl;
        } else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3) {
            int winCoins = 2 * bet;
            credits += winCoins;
            cout << "You won " << winCoins << " credits!" << endl;
        } else {
            credits -= bet;
            cout << "You lost " << bet << " credits." << endl;
        }

        cout << "You have " << credits << " credits." << endl;
        round++;

        if (credits <= 0) {
            cout << "You're out of credits" << endl;
        } else {
            char restart;
            cout << "Enter 1 to play again, or 2 to quit: " << endl;
            cin >> restart;
            if (restart == '1') {

                _sleep(500);
            }

            if (restart == '2') {
                cout << "Thanks for playing!" << endl;
                break;
            }
        }
    }

    return 0;
}
