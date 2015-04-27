#ifndef PEOPLE_H
#define PEOPLE_H
//------------------------------------------------------------------------
//
//  Name:   Miner.h
//
//  Desc:   A class defining a goldminer.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Telegram.h"

class People : public BaseGameEntity
{
private:

  StateMachine<People>*  p_pStateMachine;

public:

  People(int id);
  ~People(){delete p_pStateMachine;}
  //this must be implemented
  void Update();

  //this method changes the current state to the new state. It first
  //calls the Exit() method of the current state, then assigns the
  //new state to p_pCurrentState and finally calls the Entry()
  //method of the new state.
 
  StateMachine<People>*  GetFSM()const{return p_pStateMachine;}
  virtual bool  HandleMessage(const Telegram& msg);
};




#endif
