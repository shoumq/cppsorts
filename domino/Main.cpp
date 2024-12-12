#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Domino {
public:
    int side1;
    int side2;

    Domino(int s1, int s2) : side1(s1), side2(s2) {}

    void display() const {
        cout << "[" << side1 << "|" << side2 << "]";
    }
};

class Player {
public:
    vector<Domino> hand;

    void draw(const Domino& domino) {
        hand.push_back(domino);
    }

    void displayHand() const {
        for (const auto& domino : hand) {
            domino.display();
            cout << " ";
        }
        cout << endl;
    }
};

class Game {
private:
    vector<Domino> stock;
    vector<Domino> board;
    Player player1, player2;
    int currentPlayer;

public:
    Game() : currentPlayer(1) {
        for (int i = 0; i <= 6; ++i) {
            for (int j = i; j <= 6; ++j) {
                stock.emplace_back(i, j);
            }
        }
        srand(static_cast<unsigned int>(time(nullptr)));
        random_shuffle(stock.begin(), stock.end());

        for (int i = 0; i < 7; ++i) {
            player1.draw(stock.back());
            stock.pop_back();
            player2.draw(stock.back());
            stock.pop_back();
        }
    }

    void displayStatus() {
        cout << "Игрок 1: ";
        player1.displayHand();
        cout << "Игрок 2: ";
        player2.displayHand();
        cout << "На доске: ";
        for (const auto& domino : board) {
            domino.display();
            cout << " ";
        }
        cout << endl;
    }

    void play() {
        while (true) {
            displayStatus();
            Player& current = (currentPlayer == 1) ? player1 : player2;

            if (current.hand.empty()) {
                cout << "Игрок " << currentPlayer << " выиграл!" << endl;
                break;
            }

            cout << "Игрок " << currentPlayer << ", выберите плитку (0-" << current.hand.size() - 1 << "): ";
            int choice;
            cin >> choice;

            if (choice < 0 || choice >= current.hand.size()) {
                cout << "Неверный выбор. Попробуйте снова." << endl;
                continue;
            }

            Domino chosen = current.hand[choice];
            current.hand.erase(current.hand.begin() + choice);
            board.push_back(chosen);

            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Game game;
    game.play();
    return 0;
}
