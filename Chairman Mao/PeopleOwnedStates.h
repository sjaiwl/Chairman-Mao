#ifndef PEOPLE_OWNED_STATES_H
#define PEOPLE_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   PeopleOwnedStates.h
//
//  Desc:   All the states that can be assigned to the People class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "State.h"
struct Telegram;

class People;


//------------------------------------------------------------------------
//
//  In this state the People will walk to a goldmine and pick up a nugget
//  of gold. If the People already has a nugget of gold he'll change state
//  to WaveHandToMaoToMao. If he gets thirsty he'll change state
//  to GiveEggsToMao
//------------------------------------------------------------------------
class LookAtMao : public State<People>
{
private:

  LookAtMao(){}

  //copy ctor and assignment should be private
  LookAtMao(const LookAtMao&);
  LookAtMao& operator=(const LookAtMao&);

public:

  //this is a singleton
  static LookAtMao* Instance();
  
  virtual void Enter(People* people);

  virtual void Execute(People* people);

  virtual void Exit(People* people);
  virtual bool OnMessage(People* agent, const Telegram& msg);
};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  People is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class GiveEggsToMao : public State<People>
{
private:

  GiveEggsToMao(){}

  //copy ctor and assignment should be private
  GiveEggsToMao(const GiveEggsToMao&);
  GiveEggsToMao& operator=(const GiveEggsToMao&);
  
public:

  //this is a singleton
  static GiveEggsToMao* Instance();

  virtual void Enter(People* people);

  virtual void Execute(People* people);

  virtual void Exit(People* people);
  virtual bool OnMessage(People* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  People will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class WaveHandToMao : public State<People>
{
private:

  WaveHandToMao(){}

    //copy ctor and assignment should be private
  WaveHandToMao(const WaveHandToMao&);
  WaveHandToMao& operator=(const WaveHandToMao&);

public:

  //this is a singleton
  static WaveHandToMao* Instance();

  virtual void Enter(People* people);

  virtual void Execute(People* people);

  virtual void Exit(People* people);
  virtual bool OnMessage(People* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
class ShakeHandWithMao : public State<People>
{
private:
  
  ShakeHandWithMao(){}

  //copy ctor and assignment should be private
  ShakeHandWithMao(const ShakeHandWithMao&);
  ShakeHandWithMao& operator=(const ShakeHandWithMao&);

public:

  //this is a singleton
  static ShakeHandWithMao* Instance();

  virtual void Enter(People* people);

  virtual void Execute(People* people);

  virtual void Exit(People* people);
  virtual bool OnMessage(People* agent, const Telegram& msg);
};


#endif