// The MIT License (MIT)
// Copyright (c) 2013 fun-things Contributors

#include <cstdlib>
#include "deck-manager.h"

DeckManager::DeckManager()
{
  int card = 0;
  for (int suit = 0; suit < 4; suit++) {
    for (int cardValue = 0; cardValue < 13; cardValue++) {
     deck.push_back(new Card(cardValue, suit));
    }
  }
  drawHand();
}

DeckManager::~DeckManager()
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

string DeckManager::displayHand()
{
  string h = "You have in your hand:\n";
  int count = 1;
  for (vector<Card*>::iterator it = hand.begin(); it != hand.end(); ++it) {
    h += to_string(count++) + "  The " + (*it)->toString() + "\n";
  }
  return h;
}

void DeckManager::newCard(int place)
{
  discarded.push_back(hand[place]);
  hand[place] = drawCard();
}

Card* DeckManager::drawCard()
{
  int place = rand() % deck.size();
  Card* c = deck[place];
  deck.erase(deck.begin() + place);
  return c;
}

void DeckManager::drawHand()
{
  for (int i = 0; i < 5; i++) {
    hand.push_back(drawCard());
  }
}
