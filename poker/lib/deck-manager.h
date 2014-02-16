// The MIT License (MIT)
// Copyright (c) 2013 fun-things Contributors

#include <vector>
#include "card.h"

using namespace std;

class DeckManager {
private:
  Card* drawCard();
  void drawHand();

public:
  vector<Card*> deck;
  vector<Card*> hand;
  vector<Card*> discarded;

  DeckManager();
  ~DeckManager();

  string displayHand();
  void newCard(int place);
};
