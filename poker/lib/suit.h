// The MIT License (MIT)
// Copyright (c) 2013 fun-things Contributors

#include <string>
using namespace std;

class Suit
{
private:
  static const string SuitString[4];
public:
  int mValue;

  Suit(int aValue);
  string toString();
};
