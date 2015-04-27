#ifndef GUARD_OWNED_STATES_H
#define GUARD_OWNED_STATES_H

#include "State.h"
struct Telegram;

class Guard;
class GuardGlobleState : public State<Guard>
{
private:

  GuardGlobleState(){}

  //copy ctor and assignment should be private
  GuardGlobleState(const GuardGlobleState&);
  GuardGlobleState& operator=(const GuardGlobleState&);

public:

  //this is a singleton
  static GuardGlobleState* Instance();
  
  virtual void Enter(Guard* guard);

  virtual void Execute(Guard* guard);

  virtual void Exit(Guard* guard);
  virtual bool OnMessage(Guard* agent, const Telegram& msg);
};

class CollectInformation : public State<Guard>
{
private:

  CollectInformation(){}

  //copy ctor and assignment should be private
  CollectInformation(const CollectInformation&);
  CollectInformation& operator=(const CollectInformation&);

public:

  //this is a singleton
  static CollectInformation* Instance();
  
  virtual void Enter(Guard* guard);

  virtual void Execute(Guard* guard);

  virtual void Exit(Guard* guard);
  virtual bool OnMessage(Guard* agent, const Telegram& msg);
};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  Guard is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class ReportToMao : public State<Guard>
{
private:

  ReportToMao(){}

  //copy ctor and assignment should be private
  ReportToMao(const ReportToMao&);
  ReportToMao& operator=(const ReportToMao&);
  
public:

  //this is a singleton
  static ReportToMao* Instance();

  virtual void Enter(Guard* guard);

  virtual void Execute(Guard* guard);

  virtual void Exit(Guard* guard);
  virtual bool OnMessage(Guard* agent, const Telegram& msg);
};

#endif