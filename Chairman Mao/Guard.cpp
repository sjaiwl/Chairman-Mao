#include "Guard.h"
#include "GuardOwnedStates.h"


bool Guard::HandleMessage(const Telegram& msg)
{
  return g_pStateMachine->HandleMessage(msg);
}

Guard::Guard(int id):BaseGameEntity(id)
                                                                  
{
	g_pStateMachine = new StateMachine<Guard>(this);
    g_pStateMachine->SetCurrentState(GuardGlobleState::Instance());
	g_pStateMachine->SetPreviousState(GuardGlobleState::Instance());
}


void Guard::Update()
{
 
  if (g_pStateMachine)
  {
    g_pStateMachine->Update();
  }
}


//-----------------------------------------------------------------------------
