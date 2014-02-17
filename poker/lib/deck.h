// The MIT License (MIT)
// Copyright (c) 2014 fun-things Contributors

#include <vector>
#include "card.h"

using namespace std;

class Deck {
private:
  Card* drawCard();
  void drawHand();

public:
  vector<Card*> deck;
  vector<Card*> hand;
  vector<Card*> discarded;

  Deck();
  ~Deck();

  string displayHand();
  void newCard(int place);
};
