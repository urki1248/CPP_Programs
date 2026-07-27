#include <iostream>

using namespace std;

int main() {

    srand48(time(0));
    short money = 150;
    short cooldown_counter = 0;
    short cooldown = 0;
    short a = 0;
    int random_number = 0;
    int guess = 0;
    int b = 0;
    int score = 0;
    
    while (a == 0) {
        cout << "Your score is: " << score << endl;
        cout << "Your money is " << money << "€" << endl;
        b = 0;
        cout << "Enter a number: " << endl;
        cout << "1. gamble mode easy" << endl;
        cout << "2. gamble mode medium" << endl;
        cout << "3. gamble mode hard" << endl;
        cout << "4. slot machine" << endl;
        cout << "5. exit" << endl;
        cin >> b;

        if (cooldown_counter > 50) {
            cooldown += 25;
            cooldown_counter = 0;
        }

        if (cooldown > 0) {
            cout <<"Cooldown is" << cooldown << endl;
            cout << "Play 1, 2 or 3 to reduce cooldown";
        }

        if (b == 1) {
            cout << "You chose gamble mode easy" << endl;
            random_number = rand() % 10 + 1;
            cout << "Guess a number between 1 and 10: " << endl;
            cin >> guess;
            money -= 1;

            if (guess == random_number) {
                cout << "You guessed the number!" << endl;
                score++;
                cooldown -= 1;
            }
            else {
                cout << "You did not guess the number. The number was: " << random_number << endl;
                cooldown -= 1;
            }

        }
        else if (b == 2) {
            cout << "You chose gamble mode medium" << endl;
            random_number = rand() % 20 + 1;
            cout << "Guess a number between 1 and 20: " << endl;
            cin >> guess;
            money -= 1;

            if (guess == random_number) {
                cout << "You guessed the number!" << endl;
                score = score + 2;
                cooldown -= 1;
            }
            else {
                cout << "You did not guess the number. The number was: " << random_number << endl;
                cooldown -= 1;
            }
        }
        else if (b == 3) {
            cout << "You chose gamble mode hard" << endl;
            random_number = rand() % 100 + 1;
            cout << "Guess a number between 1 and 100: " << endl;
            cin >> guess;
            money -= 1;

            if (guess == random_number) {
                cout << "You guessed the number!" << endl;
                score += 5;
                cooldown -= 1;
            }
            else {
                cout << "You did not guess the number. The number was: " << random_number << endl;
                cooldown -= 1;
            }

        }
        else if (b == 4) {
            if (cooldown > 0) {
                continue;
            }

            money -= 2;

            cout << "You chose slot machine" << endl;
            int slot_1 = rand() % 9 + 1;
            int slot_2 = rand() % 9 + 1;
            int slot_3 = rand() % 9 + 1;
            cout << "The slot machine rolled: " << slot_1 << " " << slot_2 << " " << slot_3 << endl;

            if (slot_1 == slot_2 && slot_2 == slot_3) {
                cout << "You won the jackpot!" << endl;
                score += 10;
                cooldown_counter += 5;
                money -= 1;
            }
            else if (slot_1 == slot_2 || slot_2 == slot_3 || slot_1 == slot_3) {
                cout << "You won a small prize!" << endl;
                score += 5;
                cooldown_counter += 10;
            }
            else {
                cout << "You did not win anything." << endl;
            }
        }
        else if (b == 5) {
                cout << "You chose to exit" << endl;
                cout << "Your score is: " << score << endl;
                a = 1;

            }
        
        else if (b == 88) {
            money = money + 100;
        }

        else if (b == 98) {
            money = money + 500;
        }

        else {
            cout << "Incorect input";
        }
    }
    return 0;
}