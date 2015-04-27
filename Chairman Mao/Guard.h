#ifndef GUARD_H
#define GUARD_H
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
#include "Telegram.h"
#include "StateMachine.h"

class Guard : public BaseGameEntity
{
private:

  StateMachine<Guard>*  g_pStateMachine;

public:

  Guard(int id);
  ~Guard(){delete g_pStateMachine;}
  //this must be implemented
  void Update();

  //this method changes the current state to the new state. It first
  //calls the Exit() method of the current state, then assigns the
  //new state to m_pCurrentState and finally calls the Entry()
  //method of the new state.
  StateMachine<Guard>*  GetFSM()const{return g_pStateMachine;}
  virtual bool  HandleMessage(const Telegram& msg);
};

#endif
