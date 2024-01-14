#include <iostream>
#include <windows.h>
using namespace std;

class Player1 {
public:
    int points = 100;
    int bet = 0;
    int guess = 0;
};

void betInform(int points1, int points2) {
    cout << "Очки первого игрока: " << points1 << "\n";
    cout << "Очки второго игрока: " << points2 << "\n";
    cout << "Делайте ваши ставки, господа\n\n";
}

int playerBet(int number, int points) {
    int bet;
    cout << "P" << number << " cделайте ставку: ";
    cin >> bet;
    if (points < bet) {
        cout << "P" << number << ", пожалуйста, следите за вашим счётом\n";
        playerBet(number, points);
    }
    else {
        return bet;
    }
}



int main(){
    setlocale(LC_ALL, "rus");
    Player1 player1; 
    Player1 player2;
    int randNum;
    int gener;

    cout << "Выберите генерацию цифр: ";
    cin >> gener;
    cout << "----------------------------------------\n";
    srand(gener);//меняем число для генерации новых чисел

    while ((player1.points < 500 && player1.points != 0) && (player2.points < 500 && player2.points != 0)) {
        betInform(player1.points, player2.points);

        player1.bet = playerBet(1, player1.points);
        cout << "Введите 0 - Чётная или 1 - нечётная: ";
        cin >> player1.guess;

        player2.bet = playerBet(2, player2.points);
        cout << "Введите 0 - Чётная или 1 - нечётная: ";
        cin >> player2.guess;

        cout << "Ставки сделаны, ставок больше нет" << "\n\n";
        Sleep(360 * 6);
        randNum = 2 + rand() % 11;
        
        cout << "----------------------------------------\n";
        if (randNum % 2 == player1.guess) {
            player1.points = (player1.points - player1.bet) + (player1.bet * 2);
            cout << "Поздравляю P1! Выпало: " << randNum << "\n";
            cout << "----------------------------------------\n";
        }
        else {
            player1.points -= player1.bet;
            cout << "Сожалею P1, выпало: " << randNum << "\n";
            cout << "----------------------------------------\n";
        }

        if (randNum % 2 == player2.guess) {
            player2.points = (player2.points - player2.bet) + (player2.bet * 2);
            cout << "Поздравляю P2! Выпало: " << randNum << "\n";
            cout << "----------------------------------------\n\n";
        }
        else {
            player2.points -= player2.bet;
            cout << "Сожалею P2, выпало: " << randNum << "\n";
            cout << "----------------------------------------\n\n";
        }
    }

    if (player1.points >= 500 || player2.points == 0) {
        cout << "Первый игрок победил!\n";
    }
    if (player2.points >= 500 || player1.points == 0) {
        cout << "Второй игрок победил!\n";
    }
    
    return 0;
}
