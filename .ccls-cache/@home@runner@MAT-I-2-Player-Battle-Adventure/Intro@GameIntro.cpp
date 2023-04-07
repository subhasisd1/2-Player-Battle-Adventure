#include <iostream>
#include "../Colors/ColorCode.cpp"
using namespace std;

class GameIntro {

 Colors *clrs = new Colors();


 
public:
GameIntro()
{

  
  
  cout << endl << endl;
  cout << "!! Welcome To 2 Player Battle Game !!" << endl << endl<< endl;

  cout << "Instructions :" << endl;
  cout << "1) The player can either attack or heal." << endl;
  cout << "2) Press (H) to heal and (A) to attack." << endl;
  cout << "3) Each Player has special ability." << endl << endl << endl;

  cout << "Game Players " << endl;
  cout << "------------ " << endl << endl;

  cout << "1) " << clrs->getBlue()<<  "Barbarian"<<clrs->getWhite()
  
  
   <<"  - High Health, Low(Heal, Base Damage, Addn. Damage)" << endl;
  cout << "   Special Ability - Huge Heal" << endl;
  cout << "                   - Double Axe Attack" << endl << endl;


  cout << "2) "<< clrs->getYellow()<<"Paladin"<< clrs->getWhite()  <<  "  -  High Heal, Avg.( Health, Base Damage, Addn. Damage)" << endl;
  cout << "   Special Ability - Super Shield Blocker" << endl;
  cout << "                   - Damage and Heal at once" << endl << endl;

   cout << "2) "<< clrs->getPink()<<"Sorceress"<< clrs->getWhite()  <<  "    - Low Health, High (Heal, Base Damage, Addn. Damage)" << endl;
  cout << "   Special Ability - Rage Spell (increase Damage by 20%)" << endl;
  cout << "                   - Critical Hit" << endl;

  cout << endl << endl;

}
};
