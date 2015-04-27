#ifndef MAO_H
#define MAO_H
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

class Mao : public BaseGameEntity
{
private:

  StateMachine<Mao>*  m_pStateMachine;

public:

  Mao(int id);
  ~Mao(){delete m_pStateMachine;}
  //this must be implemented
  void Update();

  //this method changes the current state to the new state. It first
  //calls the Exit() method of the current state, then assigns the
  //new state to m_pCurrentState and finally calls the Entry()
  //method of the new state.
  StateMachine<Mao>*  GetFSM()const{return m_pStateMachine;}
  virtual bool  HandleMessage(const Telegram& msg);
};

#endif
