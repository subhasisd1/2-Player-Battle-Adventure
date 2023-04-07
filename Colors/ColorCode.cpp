#include <iostream>
using namespace std;

class Colors{

public:
string blue = "\33[0;34m";
string green = "\33[0;92m";
string red = "\33[0;31m";
string yellow = "\33[0;93m";
string pink = "\33[0;95m";
string white = "\33[0;37m";

public:
string getRed()
{
  return red;
}

string getBlue()
{
  return blue;
}

string getYellow()
{
  return yellow;
}

string getPink()
{
  return pink;
}

string getGreen()
{
  return green;
}


string getWhite()
{
  return white;
}
};