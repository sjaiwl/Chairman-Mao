#include "People.h"
#include "PeopleOwnedStates.h"

People::People(int id):BaseGameEntity(id)
                                                                  
{
	p_pStateMachine = new StateMachine<People>(this);
    
    p_pStateMachine->SetCurrentState(LookAtMao::Instance());
}

//-----------------------------------------------------------------------------
void People::Update()
{
 
  
  if (p_pStateMachine)
  {
    p_pStateMachine->Update();
  }
}

bool People::HandleMessage(const Telegram& msg)
{
  return p_pStateMachine->HandleMessage(msg);
}

//-----------------------------------------------------------------------------
