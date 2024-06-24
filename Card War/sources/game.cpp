#include "game.hpp"
#include <vector>
#include <random>
#include <iostream>
#include "player.hpp"
#include <array>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2)
{
    if (player1.getCurrentState() || player2.getCurrentState())
    {
        throw std::runtime_error("one of the players are already in game.");
    }
    this->w1 = 0;
    this->w2 = 0;
    this->drawscnt = 0;
    this->endturn = true;
    this->takes = 0;
    this->str = "";
    this->turns = 0;
    createDeckAndDealCards(player1, player2);
    player1.setState(true);
    player2.setState(true);
}
void Game::createDeckAndDealCards(Player &player1, Player &player2)
{
    // Create deck of cards
    std::vector<Card> deck;
    std::vector<Card> deck1;
    std::vector<Card> deck2;
    for (int i = 1; i <= 13; i++)
    {
        deck.push_back(Card(i, "hearts"));
        deck.push_back(Card(i, "diamonds"));
        deck.push_back(Card(i, "clubs"));
        deck.push_back(Card(i, "spades"));
    }

    // random generator from <algorithm> library
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(deck.begin(), deck.end(), rng);

    // Deal cards
    const size_t numCardsPerPlayer = 26;
    for (size_t i = 0; i < numCardsPerPlayer; i++)
    {
        deck1.push_back(deck[i]);
        deck2.push_back(deck[i + numCardsPerPlayer]);
    }
    player1.setDeck(deck1);
    player2.setDeck(deck2);
}
void Game::playTurn()
{
    if (&player1 == &player2)
    {
        throw std::invalid_argument("illegal, player can`t play against himself.");
        return;
    }
    if (player1.stacksize() == 0 || player2.stacksize() == 0)
    {
        throw std::runtime_error("no cards left");
        return;
    }
    if (this->endturn == true)
    {
        this->str = "";
    }
    this->turns++;
    Card player1Card = player1.playCard();
    Card player2Card = player2.playCard();
    this->str = player1.getName() + " played: " + player1Card.printCard() + ", " + player2.getName() + " played: " + player2Card.printCard() + ", ";
    this->takes = this->takes + 2;
    int compareResult = player1Card.compareTo(player2Card);
    if (compareResult == 1)
    {
        player1.takeCards(this->takes);
        this->str += player1.getName() + " Wins";
        this->takes = 0;
        log.push_back(this->str);
        this->w1++;
        this->endturn = true;
    }
    else if (compareResult == -1)
    {
        player2.takeCards(this->takes);
        this->takes = 0;
        this->str += player2.getName() + " Wins";
        log.push_back(this->str);
        this->w2++;
        this->endturn = true;
    }
    else
    {
        this->drawscnt = this->drawscnt + 1;
        if (player1.stacksize() == 0 || player2.stacksize() == 0)
        {
            player1.takeCards((this->takes) / 2);
            player2.takeCards((this->takes) / 2);
            this->takes = 0;
            this->str += " Draw";
            log.push_back(this->str);
            return;
        }
        player1.addturnedCard();
        player2.addturnedCard();
        this->takes = this->takes + 2;
        str += " Draw";
        log.push_back(str);
        if (player1.stacksize() == 0 || player2.stacksize() == 0)
        {
            player1.takeCards((this->takes) / 2);
            player2.takeCards((this->takes) / 2);
            return;
        }
        this->endturn = false;
        playTurn();
    }
};
void Game::printLastTurn()
{
    cout << log.back() << endl;
}
void Game::playAll()
{
    while (player1.stacksize() > 0 || player2.stacksize() > 0)
        playTurn();
}
void Game::printWiner()
{
    if (player1.stacksize() != 0 || player2.stacksize() != 0)
        cout << "The game not done yet." << endl;
    if (player1.cardesTaken() == player2.cardesTaken())
        cout << "TIE" << endl;
    else if (player1.cardesTaken() < player2.cardesTaken())
        cout << player2.getName() + " is the WINNER" << endl;
    else
        cout << player1.getName() + " is the WINNER" << endl;
}
void Game::printLog()
{
    for (const auto &entry : log)
    {
        cout << entry << endl;
    }
}
void Game ::printStats()
{
    cout << player1.getName() + ": "
         << "Number of wins: " << +this->w1 << " WINRATE: " << +((float)(this->w1) / (this->turns)) << endl;
    cout << player1.getName() + ": "
         << "Cardstaken: " << +player1.cardesTaken() << endl;
    cout << player2.getName() + ": "
         << "Number of wins: " << +this->w2 << " WINRATE: " << +((float)(this->w2) / (this->turns)) << endl;
    cout << player2.getName() + ": "
         << "Cardstaken: " << +player2.cardesTaken() << endl;
    cout << "Number of Draws: " << +this->drawscnt << " DRAWRATE: " << +((float)(this->drawscnt) / (this->turns)) << endl;
}
