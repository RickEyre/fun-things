// The MIT License (MIT)
// Copyright (c) 2013 fun-things Contributors

#include <string>
#include "suit.h"

using namespace std;

class Card
{
private:
  static const string CardString[13];
public:
  Suit mSuit;
  int mValue;

  Card(int aValue, int aSuiteValue);
  string toString();
};
