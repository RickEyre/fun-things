// The MIT License (MIT)
// Copyright (c) 2013 fun-things Contributors

#include "card.h"

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

Card::Card(int aValue, int aSuiteValue)
    : mSuit(aSuiteValue)
  {
    mValue = aValue;
  }

string Card::toString()
{
  return CardString[mValue] + " of " + mSuit.toString();
}
