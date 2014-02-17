// The MIT License (MIT)
// Copyright (c) 2014 fun-things Contributors

#include <cstdlib>
#include "deck.h"

Deck::Deck()
{
  int card = 0;
  for (int suit = 0; suit < 4; suit++) {
    for (int cardValue = 0; cardValue < 13; cardValue++) {
     deck.push_back(new Card(cardValue, suit));
    }
  }
  drawHand();
}

Deck::~Deck()
{
  for (vector<Card*>::iterator it = deck.begin(); it != deck.end(); ++it) {
    delete *it;
  }
  for (vector<Card*>::iterator it = hand.begin(); it != hand.end(); ++it) {
    delete *it;
  }
  for (vector<Card*>::iterator it = discarded.begin(); it != discarded.end(); ++it) {
    delete *it;
  }
}

string Deck::displayHand()
{
  string h = "You have in your hand:\n";
  int count = 1;
  for (vector<Card*>::iterator it = hand.begin(); it != hand.end(); ++it) {
    h += to_string(count++) + "  The " + (*it)->toString() + "\n";
  }
  return h;
}

void Deck::newCard(int place)
{
  discarded.push_back(hand[place]);
  hand[place] = drawCard();
}

Card* Deck::drawCard()
{
  int place = rand() % deck.size();
  Card* c = deck[place];
  deck.erase(deck.begin() + place);
  return c;
}

void Deck::drawHand()
{
  for (int i = 0; i < 5; i++) {
    hand.push_back(drawCard());
  }
}
