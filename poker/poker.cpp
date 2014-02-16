#include <ctime>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Suit
{
private:
  static const string SuitString[4];
public:
  int mValue;

  Suit(int aValue)
  {
    mValue = aValue;
  }

  string toString()
  {
    return SuitString[mValue];
  }
};

const string Suit::SuitString[4] =
{
  "Hearts",
  "Spades",
  "Clubs",
  "Diamonds"
};

class Card
{
private:
  static const string CardString[13];
public:
  Suit mSuit;
  int mValue;

  Card(int aValue, int aSuiteValue)
    : mSuit(aSuiteValue)
  {
    mValue = aValue;
  }

  string toString()
  {
    return CardString[mValue] + " of " + mSuit.toString();
  }
};

const string Card::CardString[13] =
{
  "One",
  "Two",
  "Three",
  "Four",
  "Five",
  "Six",
  "Seven",
  "Eight",
  "Nine",
  "Jack",
  "Queen",
  "King",
  "Ace"
};

class DeckManager {
public:
  vector<Card*> deck;
  vector<Card*> hand;
  vector<Card*> discarded;

private:
  Card* drawCard()
  {
    int place = rand() % deck.size();
    Card* c = deck[place];
    deck.erase(deck.begin() + place);
    return c;
  }

  void drawHand()
  {
    for (int i = 0; i < 5; i++) {
      hand.push_back(drawCard());
    }
  }

public:

  DeckManager()
  {
    int card = 0;
    for (int suit = 0; suit < 4; suit++) {
      for (int cardValue = 0; cardValue < 13; cardValue++) {
       deck.push_back(new Card(cardValue, suit));
      }
    }
    drawHand();
  }

  ~DeckManager()
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

  string displayHand()
  {
    string h = "You have in your hand:\n";
    int count = 1;
    for (vector<Card*>::iterator it = hand.begin(); it != hand.end(); ++it) {
      h += to_string(count++) + "  The " + (*it)->toString() + "\n";
    }
    return h;
  }

  void newCard(int place)
  {
    discarded.push_back(hand[place]);
    hand[place] = drawCard();
  }
};

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
