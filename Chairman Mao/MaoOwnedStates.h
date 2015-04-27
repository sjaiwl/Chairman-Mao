#ifndef MAO_OWNED_STATES_H
#define MAO_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MaoOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Mao class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "State.h"
struct Telegram;

class Mao;


//------------------------------------------------------------------------
//
//  In this state the Mao will walk to a goldmine and pick up a nugget
//  of gold. If the Mao already has a nugget of gold he'll change state
//  to StopAtRoad. If he gets thirsty he'll change state
//  to ShakeHand
//------------------------------------------------------------------------
class MaoGlobleState : public State<Mao>
{
private:

  MaoGlobleState(){}

  //copy ctor and assignment should be private
  MaoGlobleState(const MaoGlobleState&);
  MaoGlobleState& operator=(const MaoGlobleState&);

public:

  //this is a singleton
  static MaoGlobleState* Instance();
  
  virtual void Enter(Mao* mao);

  virtual void Execute(Mao* mao);

  virtual void Exit(Mao* mao);
  virtual bool OnMessage(Mao* agent, const Telegram& msg);
};

class WalkOnRoad : public State<Mao>
{
private:

  WalkOnRoad(){}

  //copy ctor and assignment should be private
  WalkOnRoad(const WalkOnRoad&);
  WalkOnRoad& operator=(const WalkOnRoad&);

public:

  //this is a singleton
  static WalkOnRoad* Instance();
  
  virtual void Enter(Mao* mao);

  virtual void Execute(Mao* mao);

  virtual void Exit(Mao* mao);
  virtual bool OnMessage(Mao* agent, const Telegram& msg);
};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  Mao is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class StopAtRoad : public State<Mao>
{
private:

  StopAtRoad(){}

  //copy ctor and assignment should be private
  StopAtRoad(const StopAtRoad&);
  StopAtRoad& operator=(const StopAtRoad&);
  
public:

  //this is a singleton
  static StopAtRoad* Instance();

  virtual void Enter(Mao* mao);

  virtual void Execute(Mao* mao);

  virtual void Exit(Mao* mao);
  virtual bool OnMessage(Mao* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  Mao will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class WaveHand : public State<Mao>
{
private:

  WaveHand(){}

    //copy ctor and assignment should be private
  WaveHand(const WaveHand&);
  WaveHand& operator=(const WaveHand&);

public:

  //this is a singleton
  static WaveHand* Instance();

  virtual void Enter(Mao* mao);

  virtual void Execute(Mao* mao);

  virtual void Exit(Mao* mao);
  virtual bool OnMessage(Mao* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
class ShakeHand : public State<Mao>
{
private:
  
  ShakeHand(){}

  //copy ctor and assignment should be private
  ShakeHand(const ShakeHand&);
  ShakeHand& operator=(const ShakeHand&);

public:

  //this is a singleton
  static ShakeHand* Instance();

  virtual void Enter(Mao* mao);

  virtual void Execute(Mao* mao);

  virtual void Exit(Mao* mao);
  virtual bool OnMessage(Mao* agent, const Telegram& msg);
};

class GetReport : public State<Mao>
{
private:

  GetReport(){}

  //copy ctor and assignment should be private
  GetReport(const GetReport&);
  GetReport& operator=(const GetReport&);

public:

  //this is a singleton
  static GetReport* Instance();
  
  virtual void Enter(Mao* mao);

  virtual void Execute(Mao* mao);

  virtual void Exit(Mao* mao);
  virtual bool OnMessage(Mao* agent, const Telegram& msg);
};

#endif