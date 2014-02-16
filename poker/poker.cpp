// The MIT License (MIT)
// Copyright (c) 2014 fun-things Contributors

#include <ctime>
#include <string>
#include <iostream>

#include "lib/deck-manager.h"

using namespace std;

void promptUser(DeckManager &deckManager, int &draw)
{
  cout << "Enter the number of the card you would like to redraw. 0 to quit." << endl;
  cin >> draw;
  cout << endl;
}

int main() {
  srand(time(NULL));

  DeckManager deckManager;
  int draw = -1;
  cout << deckManager.displayHand() << endl;
  promptUser(deckManager, draw);

  while (draw != 0) {
    if (draw < 1 || draw > 5) {
      cout << "You must enter a number between 0 and 5." << endl << endl;
    } else {
      deckManager.newCard(draw - 1);
      cout << deckManager.displayHand() << endl;
    }
    promptUser(deckManager, draw);
  }
}
