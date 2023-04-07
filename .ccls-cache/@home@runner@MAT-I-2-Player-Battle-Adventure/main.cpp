#include "Intro/GameIntro.cpp"
#include "Player/BasePlayer.cpp"
#include <iostream>

using namespace std;

BasePlayer::~BasePlayer() {} //

class Player : public BasePlayer {
public:
  Player(int PlayerHealth, int PlayerDamage, int AdditionalDamage,
         int HealingCapacity, PlayerType Player) {

    this->PlayerHealth = PlayerHealth;
    this->PlayerDamage = PlayerDamage;
    this->AdditionalDamage = AdditionalDamage;
    this->HealingCapacity = HealingCapacity;
    this->MaxHealth = PlayerHealth;
    this->player = Player;
  }

  PlayerType const GetPlayerType() { return player; }

  int const GetPlayerHealth() { return PlayerHealth; }

  void SetPlayerHealth(int value) { PlayerHealth = value; }

  int const GetPlayerDamage() { return PlayerDamage; }

  void SetPlayerDamage(int value) { PlayerDamage = value; }

  int const GetAdditionalDamage() { return AdditionalDamage; }

  void SetAdditionalDamage(int value) { AdditionalDamage = value; }

  int const GetHealingCapacity() { return HealingCapacity; }

  void SetHealingCapacity(int value) { HealingCapacity = value; }

  int const GetMaxHealth() { return MaxHealth; }

  void TakeDamage(int damage) { PlayerHealth -= damage; }

  void HealPlayer(int health) { PlayerHealth += health; }

  int const GetTotalDamage() { return PlayerDamage + AdditionalDamage; }

  virtual void RandomizeAdditionalDamage() {
    SetAdditionalDamage(8 + (rand() % 15));
  }

  virtual void RandomizeHealingCapacity() {
    SetHealingCapacity(10 + (rand() % 17));
  }

  void ApplyDamage(BasePlayer *otherPlayer);
  void ApplyHealing(BasePlayer *otherPlayer);
  void MaximumHealthCheck();
};

class BarbarianPlayer : public Player {
public:
  BarbarianPlayer(int PlayerHealth, int PlayerDamage, int AdditionalDamage,
                  int HealingCapacity)
      : Player(PlayerHealth, PlayerDamage, AdditionalDamage, HealingCapacity,
               PlayerType::Barbarian) {}

  void
  RandomizeAdditionalDamage() { // Random Damage And Healing For BarbarianPlayer
    SetAdditionalDamage(12 + (rand() % 18));
  }

  void RandomizeHealingCapacity() { SetHealingCapacity(14 + (rand() % 20)); }
};

class PaladinPlayer : public Player {
public:
  PaladinPlayer(int PlayerHealth, int PlayerDamage, int AdditionalDamage,
                int HealingCapacity)
      : Player(PlayerHealth, PlayerDamage, AdditionalDamage, HealingCapacity,
               PlayerType::Paladin) {}

  void
  RandomizeAdditionalDamage() { // Random Damage And Healing For PaladinPlayer
    SetAdditionalDamage(10 + (rand() % 15));
  }

  void RandomizeHealingCapacity() { SetHealingCapacity(20 + (rand() % 30)); }
};

class SorceressPlayer : public Player {
public:
  SorceressPlayer(int PlayerHealth, int PlayerDamage, int AdditionalDamage,
                  int HealingCapacity)
      : Player(PlayerHealth, PlayerDamage, AdditionalDamage, HealingCapacity,
               PlayerType::Sorceress) {}

  void
  RandomizeAdditionalDamage() { // Random Damage And Healing For SorceressPlayer
    SetAdditionalDamage(8 + (rand() % 10));
  }

  void RandomizeHealingCapacity() { SetHealingCapacity(15 + (rand() % 10)); }
};

// Intitial Stats Of Players
void ShowInitialStats(BasePlayer *player, int index) {
  switch (index) {
  case 1:
    cout << "\33[0;34m"
            "Barbarian - Born for fight !"
         << endl;
    break;
  case 2:
    cout << "\33[0;93m"
            "Paladin - The Armor !"
         << endl;
    break;
  case 3:
    cout << "\33[0;95m"
            "Sorceress - Dark Magician !"
         << endl;
    break;
  }

  cout << "Player health : " << player->GetPlayerHealth() << endl;
  cout << "Base Damage : " << player->GetPlayerDamage() << endl;

  switch (index) {
  case 1:
    cout << "\33[0;34m"
            "Additional Damage : 8 - 15"
         << endl;
    cout << "Healing Capacity : 10 - 17"
            "\33[0;37m"
         << endl
         << endl;
    break;
  case 2:
    cout << "Additional Damage : 12 - 18" << endl;
    cout << "Healing Capacity : 14 - 20"
            "\33[0;37m"
         << endl
         << endl;
    break;
  case 3:
    cout << "Additional Damage : 15 - 22" << endl;
    cout << "Healing Capacity : 20 - 30"
            "\33[0;37m"
         << endl
         << endl;
    break;
  }
}

// Health Of Two Player Who Will Fight
void ShowPlayerStats(BasePlayer *player1, BasePlayer *player2) {
  cout << "Player 1 : Health = " << player1->GetPlayerHealth() << endl;
  cout << "Player 2 : Health = " << player2->GetPlayerHealth() << endl
       << endl
       << endl;
}

void ActionCalling(BasePlayer *player1, BasePlayer *player2) {
  char playerAction;

  cin >> playerAction;

  if (playerAction == 'a' || playerAction == 'A') {

    player2->ApplyDamage(player1);
  }

  else if (playerAction == 'h' || playerAction == 'H') {

    if (!(player1->GetPlayerHealth() >= player1->GetMaxHealth())) {

      player1->ApplyHealing(player2);
      cout << "Total heal = " << player1->GetHealingCapacity() << endl;
    } else {
      cout << "Your health is full. Try Take Some Damage Yourself From Enemy."
           << endl;
    }
  }
}

// Battle Begin With Two Player
void BattleBegin(BasePlayer *player1, BasePlayer *player2) {
  int playerAction = 1;
  string player1Color = "";
  string player2Color = "";

  // cout << player1->GetPlayerType() << endl;
  // cout << player2->GetPlayerType() << endl;
  // PlayerColor(player1);
  // PlayerColor(player2);

  cout << "! Battle Started !" << endl;

  while (true) {

    if (player1->GetPlayerHealth() <= 0) {
      cout << "!! Player 2 won !!" << endl << endl;
      break;
    } else if (player2->GetPlayerHealth() <= 0) {
      cout << "!! Player 1 won !!" << endl << endl;
      break;
    }

    cout << "Player " << playerAction << " : Enter ("
         << "\33[0;31m"
         << "A"
         << "\33[0;37m"
         << ") To "
         << "\33[0;31m"
         << " Attack "
         << "\33[0;37m"
         << " or (H) To "
         << "\33[0;92m"
         << "Heal"
         << "\33[0;37m" << endl;
    cout << "Player " << playerAction << " : ";

    if (playerAction == 1) {
      ActionCalling(player1, player2);
      ShowPlayerStats(player1, player2);
      playerAction++;
    }

    else {
      ActionCalling(player2, player1);
      ShowPlayerStats(player1, player2);
      playerAction--;
    }
  }
}

string PlayerColor(BasePlayer *player) {
  string color;
  cout << player->GetPlayerType();

  switch (player->GetPlayerType()) {
  case Barbarian:
    break;
  }

  return color;
}

void Player::ApplyDamage(BasePlayer *otherPlayer) {
  otherPlayer->RandomizeAdditionalDamage();

  switch (otherPlayer->GetPlayerType()) {

  case Barbarian:
    if ((GetPlayerType() == Barbarian) && (rand() % 4 == 0)) {
      cout << "Special Ability Used By Opponent - Attack Blocker" << endl;
      cout << "Damage given = 0" << endl;
      break;
    }

    if (rand() % 4 == 0) {
      otherPlayer->SetAdditionalDamage(2 * otherPlayer->GetAdditionalDamage());
      otherPlayer->SetPlayerDamage(2 * otherPlayer->GetPlayerDamage());
      TakeDamage(otherPlayer->GetTotalDamage());

      cout << "Special Ability Used - Double Attack" << endl;
      cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;

      otherPlayer->SetPlayerDamage(otherPlayer->GetPlayerDamage() / 2);
      break;
    } else {
      TakeDamage(otherPlayer->GetTotalDamage());
      cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
    }
    break;

  case Paladin:
    if (rand() % 4 == 0) {
      cout << "Special Ability Used - Heal + Damage" << endl;

      otherPlayer->ApplyHealing(otherPlayer);
      TakeDamage(otherPlayer->GetTotalDamage());

      cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
      cout << "Total heal = " << otherPlayer->GetHealingCapacity() << endl;
    }

    else {
      TakeDamage(otherPlayer->GetTotalDamage());
      cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
    }
    break;

  case Sorceress:
    if ((GetPlayerType() == Sorceress) && (rand() % 4 == 0)) {
      cout << "Special Ability Used By Opponent - Attack Blocker" << endl;
      cout << "Damage given = 0" << endl;
      break;
    }

    if ((GetPlayerHealth() <= 0.3 * GetMaxHealth())) {
      otherPlayer->SetPlayerDamage((otherPlayer->GetPlayerDamage() +
                                    100 / (otherPlayer->GetPlayerHealth())));
      cout << "Special Ability Used - Rage" << endl;

      if ((rand() % 4 == 0)) {
        otherPlayer->SetAdditionalDamage(1.5 *
                                         otherPlayer->GetAdditionalDamage());
        otherPlayer->SetPlayerDamage(1.5 * otherPlayer->GetPlayerDamage());
        TakeDamage(otherPlayer->GetTotalDamage());

        cout << "Special Ability Used - Critical Hit" << endl;
        cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;

        otherPlayer->SetPlayerDamage(otherPlayer->GetPlayerDamage() / 2);
        break;
      }

      else {
        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
      }
    }

    else {
      TakeDamage(otherPlayer->GetTotalDamage());
      cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
    }
    break;
  }

  if (GetPlayerHealth() <= 0) {
    SetPlayerHealth(0);
  }
}

// Apply Healing For Players
void Player::ApplyHealing(BasePlayer *otherPlayer) {

  RandomizeHealingCapacity(); // To randomize healing capacity

  switch (GetPlayerType()) {

  case Barbarian:
    if (rand() % 4 == 0) {

      cout << "Special Ability Used - Huge Heal" << endl;
      SetHealingCapacity(2 * GetHealingCapacity());
      MaximumHealthCheck();
    } else {
      MaximumHealthCheck();
    }
    break;

  case Paladin:
    MaximumHealthCheck();
    break;

  case Sorceress:
    MaximumHealthCheck();
    break;
  }
}

// For Checking Health Of Players Must Not Exceed From Given Values
void Player::MaximumHealthCheck() {
  if (GetPlayerHealth() + GetHealingCapacity() > GetMaxHealth()) {
    SetHealingCapacity(GetMaxHealth() - GetPlayerHealth());
    SetPlayerHealth(GetPlayerHealth() + GetHealingCapacity());
  } else {
    SetPlayerHealth(GetPlayerHealth() + GetHealingCapacity());
  }
}

// Creation Of Players
BasePlayer *CreatePlayerOfType(int value) {

  switch (value) {
  case 1: {
    BasePlayer *powerPlayer = new BarbarianPlayer(200, 10, 0, 0);
    ShowInitialStats(powerPlayer, 1);
    return powerPlayer;
  } break;

  case 2: {
    BasePlayer *skilledPlayer = new PaladinPlayer(150, 20, 0, 0);
    ShowInitialStats(skilledPlayer, 2);
    return skilledPlayer;
  } break;

  case 3: {
    BasePlayer *ragedPlayer = new SorceressPlayer(100, 30, 10, 0);
    ShowInitialStats(ragedPlayer, 3);
    return ragedPlayer;
  } break;

  Default:
    return nullptr;
    break;
  }
  return nullptr;
}

// Player Selection From User
BasePlayer *SelectPlayerType(int value) {
  int playerChoice = 0;

  cout << endl;
  cout << "Select Player " << value << " :  " << enum_str[Barbarian] << ", "
       << enum_str[Paladin] << ", " << enum_str[Sorceress] << endl;

  //  (1, 2, 3)" << endl;
  cout << "Player Type : ";

  while (true) {
    cin >> playerChoice;
    cout << endl;

    if (!cin ||
        !(playerChoice == 1 || playerChoice == 2 || playerChoice == 3)) {
      cin.clear();
      // cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "Please select correct player type" << endl;
      cout << "Player Type : ";
      continue;
    } else {
      break;
    }
  }
  return CreatePlayerOfType(playerChoice);
}

int main() {

  GameIntro *intro = new GameIntro();
  ;

  char restart; // Used Restarting Of Game

  while (true) {

    BasePlayer *player1 = SelectPlayerType(1);
    BasePlayer *player2 = SelectPlayerType(2);

    BattleBegin(player1, player2);

    delete player1;
    delete player2;

    cout << "Press 'E' To Play Again" << endl;
    cin >> restart;

    if (!(restart == 'e' || restart == 'E')) {
      cout << "Well Played!  See you Again :)" << endl;
      break;
    }
  }
  return 0;
}