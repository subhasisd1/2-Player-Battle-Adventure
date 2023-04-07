#include "PlayerType.cpp" 

class BasePlayer {

  protected:           //Used For Every Child Classes Can Use It.
  int PlayerHealth;
  int PlayerDamage;
  int AdditionalDamage;
  int HealingCapacity;
  int MaxHealth;
  PlayerType player;

  //Using Setter And Getter For Every Player
  public:
  virtual PlayerType const GetPlayerType() = 0;
  virtual int const GetPlayerHealth() = 0;
  virtual void SetPlayerHealth(int value) = 0;
  virtual int const GetPlayerDamage() = 0;
  virtual void SetPlayerDamage(int value) = 0;
  virtual int const GetAdditionalDamage() = 0;
  virtual void SetAdditionalDamage(int value) = 0;
  virtual int const GetHealingCapacity() = 0;
  virtual void SetHealingCapacity(int value) = 0;
  virtual int const GetMaxHealth() = 0;

  virtual void TakeDamage(int damage) = 0;
  virtual void HealPlayer(int health) = 0;
  virtual int const GetTotalDamage() = 0;

  virtual void RandomizeAdditionalDamage() = 0;
  virtual void RandomizeHealingCapacity() = 0;

  virtual void ApplyDamage(BasePlayer *otherPlayer) = 0;
  virtual void ApplyHealing(BasePlayer *otherPlayer) = 0;
  virtual void MaximumHealthCheck() = 0;

  virtual ~BasePlayer() = 0;
};


