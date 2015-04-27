#include "MaoOwnedStates.h"
#include "PeopleOwnedStates.h"
#include "People.h"
#include "State.h"
#include "Mao.h"
#include "EntityNames.h"
#include "Telegram.h"
#include "misc/ConsoleUtils.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "misc/CrudeTimer.h"
#include <iostream>
using std::cout;

//define this to output to a file






//--------------------------------------methods for WalkOnRoad
MaoGlobleState* MaoGlobleState::Instance()
{
  static MaoGlobleState instance;

  return &instance;
}
void MaoGlobleState::Enter(Mao* pMao)
{  

 // pMao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  
}
void MaoGlobleState::Execute(Mao* pMao)
{  

 //pMao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  
}
void MaoGlobleState::Exit(Mao* pMao)
{  

 // pMao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  
}
bool MaoGlobleState::OnMessage(Mao* pMao, const Telegram& msg)
{
	switch(msg.Msg)
  {
	  case Msg_GetReport:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(pMao->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(pMao->ID()) << 
          ":ChairMao,report to you! ";

     pMao->GetFSM()->ChangeState(GetReport::Instance());
	return true;
   }
  return false;
}
}

WalkOnRoad* WalkOnRoad::Instance()
{
  static WalkOnRoad instance;

  return &instance;
}

void WalkOnRoad::Enter(Mao* pMao)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "I Walk on the Road";

}


void WalkOnRoad::Execute(Mao* pMao)
{  
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "I look at people,walk on road";
  
}


void WalkOnRoad::Exit(Mao* pMao)
{
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " 
       << "I go on walking on road";
}
bool WalkOnRoad::OnMessage(Mao* pMao, const Telegram& msg)
{
	switch(msg.Msg)
  {
	  case Msg_PeopleGiveEggsToMao:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(pMao->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(pMao->ID()) << 
          ": People, thank for your eggs! ";

     pMao->GetFSM()->ChangeState(StopAtRoad::Instance());
	return true;
   }

     case Msg_PeopleShakeHandWithMao:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(pMao->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(pMao->ID()) << 
          ": Hello People£¬shake hand with you!";

     pMao->GetFSM()->ChangeState(ShakeHand::Instance());
	return true;
   }


     case Msg_PeopleWaveHandToMao:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(pMao->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

    cout << "\n" << GetNameOfEntity(pMao->ID()) << 
          ": Hello People,wave hand to you! ";

     pMao->GetFSM()->ChangeState(WaveHand::Instance());
	 return true;
   }

   
  }
  return false;
}


//----------------------------------------methods for StopAtRoad

StopAtRoad* StopAtRoad::Instance()
{
  static StopAtRoad instance;

  return &instance;
}


void StopAtRoad::Enter(Mao* pMao)
{  
 SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "I will stop to receive eggs";

   pMao->GetFSM()->RevertToPreviousState();
}


void StopAtRoad::Execute(Mao* pMao)
{
SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " 
       << "I receive eggs from people";

}


void StopAtRoad::Exit(Mao* pMao)
{
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "I get eggs from people";
}
bool StopAtRoad::OnMessage(Mao* pMao, const Telegram& msg)
{
	
  return false;
}

//----------------------------------------methods for WaveHand

WaveHand* WaveHand::Instance()
{
  static WaveHand instance;

  return &instance;
}

void WaveHand::Enter(Mao* pMao)
{
 
    SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "People wave hand to me";
	pMao->GetFSM()->RevertToPreviousState();
     
  
}

void WaveHand::Execute(Mao* pMao)
{ 
  //if Mao is not fatigued start to dig for nuggets again.
 
  
    SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " 
          << "I wave hand to people";
	
    
}

void WaveHand::Exit(Mao* pMao)
{ 
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "I stop waving hands";
}
bool WaveHand::OnMessage(Mao* pMao, const Telegram& msg)
{
		

  //send msg to global message handler
  return false;
}



//------------------------------------------------methods for ShakeHand

ShakeHand* ShakeHand::Instance()
{
  static ShakeHand instance;

  return &instance;
}

void ShakeHand::Enter(Mao* pMao)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "People want to shake hands with me";
  pMao->GetFSM()->RevertToPreviousState();
}

void ShakeHand::Execute(Mao* pMao)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
     cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "I go to shake hands with the man";
	
}

void ShakeHand::Exit(Mao* pMao)
{ 
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "The man leave,stop shaking hand";
}
bool ShakeHand::OnMessage(Mao* pMao, const Telegram& msg)
{

  //send msg to global message handler
  return false;
}

GetReport* GetReport::Instance()
{
  static GetReport instance;

  return &instance;
}

void GetReport::Enter(Mao* pMao)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "Guard have some information to tell me";
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pMao->ID(),        //ID of sender
                              ent_Guard,            //ID of recipient
                              Msg_GoCollect,   //the message
                              NO_ADDITIONAL_INFO); 
    pMao->GetFSM()->RevertToPreviousState();
}

void GetReport::Execute(Mao* pMao)
{
	SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "I get information from guard";
	
}

void GetReport::Exit(Mao* pMao)
{ 
  SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pMao->ID()) << ": " << "The guard leave,I go on";
}
bool GetReport::OnMessage(Mao* pMao, const Telegram& msg)
{

  //send msg to global message handler
  return false;
}
