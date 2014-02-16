// The MIT License (MIT)
// Copyright (c) 2014 fun-things Contributors

#include "suit.h"

const string Suit::SuitString[4] =
{
  "Hearts",
  "Spades",
  "Clubs",
  "Diamonds"
};

Suit::Suit(int aValue)
{
  mValue = aValue;
}

string Suit::toString()
{
  return SuitString[mValue];
}
