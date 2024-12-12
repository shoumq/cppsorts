#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Domino {
public:
    int side1;
    int side2;

    Domino(int s1, int s2) : side1(s1), side2(s2) {}

    void display() const {
        std::cout << "[" << side1 << "|" << side2 << "]";
    }
};

class Player {
public:
    std::vector<Domino> hand;

    void draw(const Domino& domino) {
        hand.push_back(domino);
    }

    void displayHand() const {
        for (const auto& domino : hand) {
            domino.display();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
};

class Game {
private:
    std::vector<Domino> stock;
    std::vector<Domino> board;
    Player player1, player2;
    int currentPlayer;

public:
    Game() : currentPlayer(1) {
        // Инициализация домино
        for (int i = 0; i <= 6; ++i) {
            for (int j = i; j <= 6; ++j) {
                stock.emplace_back(i, j);
            }
        }
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        std::random_shuffle(stock.begin(), stock.end());

        // Раздача по 7 плиток каждому игроку
        for (int i = 0; i < 7; ++i) {
            player1.draw(stock.back());
            stock.pop_back();
            player2.draw(stock.back());
            stock.pop_back();
        }
    }

    void displayStatus() {
        std::cout << "Игрок 1: ";
        player1.displayHand();
        std::cout << "Игрок 2: ";
        player2.displayHand();
        std::cout << "На доске: ";
        for (const auto& domino : board) {
            domino.display();
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    void play() {
        while (true) {
            displayStatus();
            Player& current = (currentPlayer == 1) ? player1 : player2;

            if (current.hand.empty()) {
                std::cout << "Игрок " << currentPlayer << " выиграл!" << std::endl;
                break;
            }

            // Простой ввод для выбора плитки
            std::cout << "Игрок " << currentPlayer << ", выберите плитку (0-" << current.hand.size() - 1 << "): ";
            int choice;
            std::cin >> choice;

            if (choice < 0 || choice >= current.hand.size()) {
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                continue;
            }

            // Добавление плитки на доску
            Domino chosen = current.hand[choice];
            current.hand.erase(current.hand.begin() + choice);
            board.push_back(chosen);

            // Смена игрока
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
