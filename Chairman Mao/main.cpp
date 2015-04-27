#include "Mao.h"
#include "People.h"
#include "Guard.h"
#include "EntityNames.h"
#include "misc/ConsoleUtils.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include <windows.h>
#include <iostream>
using std::cout;
int main()
{
  Mao* mao=new Mao(ent_Chair_Mao);
  People* people=new People(ent_People);
  Guard* guard=new Guard(ent_Guard);

  EntityMgr->RegisterEntity(mao);
  EntityMgr->RegisterEntity(people);
  EntityMgr->RegisterEntity(guard);
  //simply run the miner through a few Update calls
  for(int i=0;i<15;i++)
  {
	people->Update();
	mao->Update();
	guard->Update();

	Dispatch->DispatchDelayedMessages();
	Sleep(800);
	//std::cout<<"\n";
 }

  //wait for a keypress before exiting
   PressAnyKeyToContinue();
   return 0;
}