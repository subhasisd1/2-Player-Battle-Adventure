#include <iostream>
using namespace std;


class GameIntro {

public:
GameIntro()
{
  
  cout << endl << endl;
  cout << "!! Welcome To 2-Player-Battle-Adventure Game !!" << endl << endl<< endl;
  cout << endl << endl;

  cout << "Instructions :" << endl;
  cout << "1) Each player has one choice at a time." << endl;
  cout << "2) The player can either attack or heal." << endl;
  cout << "3) The player who's health goes below 0, will die and loose the game." << endl;
  cout << "4) Press 'H' to heal and 'A' to attack." << endl;
  cout << "5) Each special ability has 20% probability." << endl << endl << endl;

  cout << "Game Player types " << endl;
  cout << "***************** " << endl << endl;

  cout << "1) Pubg Player     - High Health, Low Heal, Low Base Damage, Low Additional Damage" << endl;
  cout << "   Special Ability - Huge Heal" << endl;
  cout << "                   - Double Attack" << endl << endl;

  cout << "2) Enemy Player    - Average Health, High Heal, Average Base Damage, Average Additional Damage" << endl;
  cout << "   Special Ability - Attack Blocker" << endl;
  cout << "                   - Heal + Damage in single turn" << endl << endl;

  cout << "3) Zombie Player   - Low Health, Very High Heal, High Base Damage, High Additional Damage" << endl;
  cout << "   Special Ability - Rage (Damage increases when close to death)" << endl;
  cout << "                   - Critical Hit" << endl;

  cout << endl << endl;

}
};
