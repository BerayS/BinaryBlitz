#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

string decToBinary(int n)
{
    // String to store binary number
    string bits;

    // Counter for binary array
    int i = 0;
    while (n > 0) {
        bits.append(to_string(n % 2));
        n /= 2;
        i++;
    }

    reverse(bits.begin(), bits.end());
    return bits;
}

int random, randomTA, points = 0;

void decimalToBinary() {
    while (true) {
        random = rand() % 255;

        cout << "Q: What is the binary equal of " << random << " ? (0 for end)" << endl;
        string ans = decToBinary(random);

        string res;
        cin >> res;

        if (res == "0") {
            for (int i = 0; i < 60; i++) cout << "-";
            cout << endl << "Your points: " << points << endl << "Congratulations!" << endl;
            break;
        }

        if (res == ans) {
            cout << "Correct!" << endl;
            points++;
            cout << "Current Points: " << points << endl << endl;
        }
        else cout << "Wrong!" << endl << endl;
    }
}

void binaryToDecimal() {
    while (true) {
        random = rand() % 255;
        string ans = decToBinary(random);

        cout << "What is the decimal equivalent of " << ans << " ? (0 for end)" << endl;

        int res;
        cin >> res;

        if (res == 0) {
            for (int i = 0; i < 60; i++) cout << "-";
            cout << endl << "Your points: " << points << endl << "Congratulations!" << endl;
            break;
        }
        if (res == random) {
            cout << "Correct!" << endl;
            points++;
            cout << "Current Points: " << points << endl << endl;
        }
        else cout << "Wrong!" << endl << endl;
    }
}

void randomGuess() {
    while (true) {
        randomTA = rand() % 5;

        if (randomTA >= 2) {
            random = rand() % 255;

            cout << "Q: What is the binary equal of " << random << " ? (0 for end)" << endl;
            string ans = decToBinary(random);

            string res;
            cin >> res;

            if (res == "0") {
                for (int i = 0; i < 60; i++) cout << "-";
                cout << endl << "Your points: " << points << endl << "Congratulations!" << endl;
                break;
            }

            if (res == ans) {
                cout << "Correct!" << endl;
                points++;
                cout << "Current Points: " << points << endl << endl;
            }
            else cout << "Wrong!" << endl << endl;
        }
        else {
            random = rand() % 255;
            string ans = decToBinary(random);

            cout << "What is the decimal equivalent of " << ans << " ? (0 for end)" << endl;

            int res;
            cin >> res;

            if (res == 0) {
                for (int i = 0; i < 60; i++) cout << "-";
                cout << endl << "Your points: " << points << endl << "Congratulations!" << endl;
                break;
            }
            if (res == random) {
                cout << "Correct!" << endl;
                points++;
                cout << "Current Points: " << points << endl << endl;
            }
            else cout << "Wrong!" << endl << endl;
        }
    }
}

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
    srand((unsigned)time(NULL));

    cout << "Welcome to Binary Blitz! Developed by: Beray Tyuleolu " << endl;
    for (int i = 0; i < 60; i++) cout << "-";
    cout << endl;

    cout << "1: Guess binary equivalent of a decimal value." << endl 
    << "2: Guess decimal equivalent of a binaty value." << endl 
    << "3: Random." << endl << "0: Exit" << endl;
    
    int n;
    cin >> n;

    cout << endl;

    if (n == 1) decimalToBinary();
    else if (n == 2) binaryToDecimal();
    else if (n == 3) randomGuess();
    else if (n == 0) {
        cout << "Thank you for playing!" << endl;
        return 1;
    }
}