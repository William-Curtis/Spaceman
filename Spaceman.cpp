#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void clearScreen() {
#ifdef _WIN32 // For Windows
    system("cls");
#else // For Unix-based systems
    system("clear");
#endif
}

void printrocket(int wrongAttempts) {
        cout << " - - - - - - - - - - - - - - S P A C E M A N - - - - - - - - - - - - - - \n";
    if (wrongAttempts == 7) {
        cout << " /\\/\\/\\                            /  \\               \n";
        cout << "| \\  / |                         /      \\               \n";
        cout << "|  \\/  |                       /          \\             \n";
    }
    else {
        cout << " /\\/\\/\\\n";
        cout << "| \\  / | \n";
        cout << "|  \\/  | \n";
    }
    if (wrongAttempts >= 6) {
        cout << "|  /\\  |----------------------|     /\\     |            \n";
        cout << "| /  \\ |                      |    /  \\    |            \n";
        cout << "|/    \\|                      |   /    \\   |            \n";
    }
    else {
        cout << "|  /\\  |\n";
        cout << "| /  \\ |\n";
        cout << "|/    \\|\n";
    }
    if (wrongAttempts >= 5) {
        cout << "|\\    /|                      |  | (  ) |  |             \n";
        cout << "| \\  / |                      |  | (  ) |  |             \n";
        cout << "|  \\/  |                 /\\   |  |      |  |   /\\      \n";
    }
    else {
        cout << "|\\    /|\n";
        cout << "| \\  / |\n";
        cout << "|  \\/  |\n";
    }
    if (wrongAttempts >= 4) {
        cout << "|  /\\  |                /  \\  |  |      |  |  /  \\     \n";
        cout << "| /  \\ |               |----| |  |      |  | |----|      \n";
        cout << "|/    \\|---------------|    | | /|   .  |\\ | |    |     \n";
    }
    else {
        cout << "|  /\\  |\n";
        cout << "| /  \\ |\n";
        cout << "|/    \\|\n";
    }
    if (wrongAttempts >= 3) {
        cout << "|\\    /|               |    | /  |   .  |  \\ |    |     \n";
        cout << "| \\  / |               |    /    |   .  |    \\    |     \n";
        cout << "|  \\/  |               |  /      |   .  |      \\  |     \n";
    }
    else {
        cout << "|\\    /|\n";
        cout << "| \\  / |\n";
        cout << "|  \\/  |\n";
    }
    if (wrongAttempts >= 2) {
        cout << "|  /\\  |---------------|/        |   .  |        \\|     \n";
        cout << "| /  \\ |              /          |   .  |          \\    \n";
        cout << "|/    \\|              (          |      |           )    \n";
    }
    else {
        
        cout << "|  /\\  |\n";
        cout << "| /  \\ |\n";
        cout << "|/    \\|\n";
    }
    if (wrongAttempts >= 1) {
        cout << "|/\\/\\/\\|               |    | |--|      |--| |    |    \n";
        cout << "                        /  \\     /  \\/  \\     /  \\    \n";
        cout << "                        \\\\//     \\\\//\\\\//     \\\\//\n";
        cout << "                         \\/       \\/  \\/       \\/     \n";
    }
    else {
        cout << "|/\\/\\/\\|\n";
        cout << "           \n";
        cout << "           \n";
        cout << "           \n";
    }
    cout << "\n";
}

int main() {
    bool end = false;
    bool foundLetter;
    int wrongAttempts = 0;
    string word;
    string tmpWord = " ";
    string guess;
    string wordBank[1022];
    string line;
    int i = 0;

    // Create and open a text file
    ifstream file("words.txt");

    for (int i = 0; i < sizeof(wordBank) / sizeof(wordBank[0]); ++i) {
        file >> wordBank[i];
    }

    // Close the file
    file.close();

    cout << "Spaceman is a variant to the classic game, Hangman. The rules are the same.\n\n";
    cout << "A random word will be secretly chosen and it is your job to try and figure it out.\n\n";
    cout << "You will be shown a series of '_', each indicates a concealed letter in the hidden word.\n";
    cout << "You can guess either a single letter or the whole word.\n";
    cout << " - If you guess a single letter, all instances of that letter in the hidden word will be revealed.\n";
    cout << " - If you correctly guess the hidden word, the hidden word will be revealed.\n\n";
    cout << "You win if the whole word gets revealed.\n";
    cout << "Conversely, you lose if you make 7 incorrect guesses.\n\n";

    cout << "\nEnter anything to start: ";
    cin >> guess;

    clearScreen();
    printrocket(wrongAttempts);

    srand(time(NULL));
    word = wordBank[rand() % 1022];
    // cout << "The word is: " << word << "\n";
    tmpWord = tmpWord.replace(0, 1, word.length(), '_');
    while (!end) {
        if (7 - wrongAttempts == 1) {
            cout << "You have 1 guess left.\n";
        }
        else {
            cout << "You have " << 7 - wrongAttempts << " guesses left.\n";
        }
        cout << "\n" << tmpWord << "\n\n";
        cout << "Enter your guess: ";
        cin >> guess;
        cout << "\n";
        clearScreen();
        if (guess.length() == 1) {
            foundLetter = false;
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == guess[0]) {
                    tmpWord[i] = word[i];
                    foundLetter = true;
                }
            }
            if (!foundLetter) {
                wrongAttempts++;
                printrocket(wrongAttempts);
                cout << "The word doesn't contain the letter " << guess << "\n";
            }
            else {
                printrocket(wrongAttempts);
            } 
        }
        else if (guess.compare(word) == 0) {
            tmpWord = word;
            printrocket(wrongAttempts);
        }
        else {
            wrongAttempts++;
            printrocket(wrongAttempts);
            cout << guess << " is not the word\n";
        }
        if (word.compare(tmpWord) == 0 || wrongAttempts == 7) {
            end = true;
        }
        






    
    }
    if (wrongAttempts < 7) {
        cout << "Congratulations! The word is " << word << "\n";
    }
    else {
        cout << "You are out of guesses. The word is " << word << "\n";
    }
    cout << "\nEnter anything to quit: ";
    cin >> guess;
    return 0;
}