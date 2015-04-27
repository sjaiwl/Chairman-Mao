#include "Mao.h"
#include "MaoOwnedStates.h"


bool Mao::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}

Mao::Mao(int id):BaseGameEntity(id)
                                                                  
{
	m_pStateMachine = new StateMachine<Mao>(this);
    m_pStateMachine->SetCurrentState(WalkOnRoad::Instance());
	m_pStateMachine->SetPreviousState(WalkOnRoad::Instance());
	m_pStateMachine->SetGlobalState(MaoGlobleState::Instance());
}


void Mao::Update()
{
 
  if (m_pStateMachine)
  {
    m_pStateMachine->Update();
  }
}


//-----------------------------------------------------------------------------
