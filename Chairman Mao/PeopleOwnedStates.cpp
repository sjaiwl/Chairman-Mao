#include "PeopleOwnedStates.h"
#include "People.h"
#include "EntityNames.h"
#include "misc/ConsoleUtils.h"
#include <stdlib.h>
#include <iostream>
#include "Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "misc/CrudeTimer.h"
using std::cout;

//define this to output to a file


//--------------------------------------methods for LookAtMao
//Mao *mao=new Mao(ent_Chair_Mao);
LookAtMao* LookAtMao::Instance()
{
  static LookAtMao instance;

  return &instance;
}

void LookAtMao::Enter(People* pPeople)
{
	SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People see Mao off";

}


void LookAtMao::Execute(People* pPeople)
{  
  SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People look at Mao";
 // mao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  int i=rand()%10;
  if(i>=0&&i<=3){
	  pPeople->GetFSM()->ChangeState(LookAtMao::Instance());
	  //mao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  }
  if(i==4||i==5){
	  pPeople->GetFSM()->ChangeState(GiveEggsToMao::Instance());
	 // mao->GetFSM()->ChangeState(StopAtRoad::Instance());
  }
  if(i==6||i==7){
	  pPeople->GetFSM()->ChangeState(WaveHandToMao::Instance());
	 // mao->GetFSM()->ChangeState(WaveHand::Instance());
  }
  if(i==8||i==9){
	  pPeople->GetFSM()->ChangeState(ShakeHandWithMao::Instance());
	 // mao->GetFSM()->ChangeState(ShakeHand::Instance());
  }

}


void LookAtMao::Exit(People* pPeople)
{
 SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " 
       << "People look Mao walking on road(stop LookAtMao)";
}
bool LookAtMao::OnMessage(People* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}


//----------------------------------------methods for GiveEggsToMao

GiveEggsToMao* GiveEggsToMao::Instance()
{
  static GiveEggsToMao instance;

  return &instance;
}


void GiveEggsToMao::Enter(People* pPeople)
{  
    SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People want to give some eggs to Chair People";
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pPeople->ID(),        //ID of sender
                              ent_Chair_Mao,            //ID of recipient
                              Msg_PeopleGiveEggsToMao,   //the message
                              NO_ADDITIONAL_INFO); 
 
}


void GiveEggsToMao::Execute(People* pPeople)
{
	SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " 
       << "People give eggs to Mao ";
  //mao->GetFSM()->ChangeState(StopAtRoad::Instance());
  	int j=rand()%10;
  if(j>=0&&j<=3){
	  pPeople->GetFSM()->ChangeState(LookAtMao::Instance());
	  //mao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  }
  if(j==4||j==5){
	  pPeople->GetFSM()->ChangeState(GiveEggsToMao::Instance());
	 // mao->GetFSM()->ChangeState(StopAtRoad::Instance());
  }
  if(j==6||j==7){
	  pPeople->GetFSM()->ChangeState(WaveHandToMao::Instance());
	 // mao->GetFSM()->ChangeState(WaveHand::Instance());
  }
  if(j==8||j==9){
	  pPeople->GetFSM()->ChangeState(ShakeHandWithMao::Instance());
	  //mao->GetFSM()->ChangeState(ShakeHand::Instance());
  }
}


void GiveEggsToMao::Exit(People* pPeople)
{
  SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People leave Mao after giving eggs(stop GiveEggsToMao)";

 
}
bool GiveEggsToMao::OnMessage(People* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}

//----------------------------------------methods for WaveHandToMao

WaveHandToMao* WaveHandToMao::Instance()
{
  static WaveHandToMao instance;

  return &instance;
}

void WaveHandToMao::Enter(People* pPeople)
{
 
    SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People want to wave hand with Mao ";
    Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pPeople->ID(),        //ID of sender
                              ent_Chair_Mao,            //ID of recipient
                              Msg_PeopleWaveHandToMao,   //the message
                              NO_ADDITIONAL_INFO); 
  
}

void WaveHandToMao::Execute(People* pPeople)
{ 
	SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  //if People is not fatigued start to dig for nuggets again.
    cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " 
          << "People wave hand with Mao";
	//mao->GetFSM()->ChangeState(WaveHand::Instance());
  int m=rand()%10;
  if(m>=0&&m<=3){
	  pPeople->GetFSM()->ChangeState(LookAtMao::Instance());
	  //mao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  }
  if(m==4||m==5){
	  pPeople->GetFSM()->ChangeState(GiveEggsToMao::Instance());
	 // mao->GetFSM()->ChangeState(StopAtRoad::Instance());
  }
  if(m==6||m==7){
	  pPeople->GetFSM()->ChangeState(WaveHandToMao::Instance());
	 // mao->GetFSM()->ChangeState(WaveHand::Instance());
  }
  if(m==8||m==9){
	  pPeople->GetFSM()->ChangeState(ShakeHandWithMao::Instance());
	  //mao->GetFSM()->ChangeState(ShakeHand::Instance());
  }
    
}

void WaveHandToMao::Exit(People* pPeople)
{ 
  SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People leave after waving hands(stop WaveHandToMao)";
     
}
bool WaveHandToMao::OnMessage(People* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}



//------------------------------------------------methods for ShakeHandWithMao

ShakeHandWithMao* ShakeHandWithMao::Instance()
{
  static ShakeHandWithMao instance;

  return &instance;
}

void ShakeHandWithMao::Enter(People* pPeople)
{
	SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People want to shake hands with Mao";
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pPeople->ID(),        //ID of sender
                              ent_Chair_Mao,            //ID of recipient
                              Msg_PeopleShakeHandWithMao,   //the message
                              NO_ADDITIONAL_INFO); 
}

void ShakeHandWithMao::Execute(People* pPeople)
{
	SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
     cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People shake hands with Mao";
	// mao->GetFSM()->ChangeState(ShakeHand::Instance());
  int n=rand()%10;
  if(n>=0&&n<=3){
	  pPeople->GetFSM()->ChangeState(LookAtMao::Instance());
	  //mao->GetFSM()->ChangeState(WalkOnRoad::Instance());
  }
  if(n==4||n==5){
	  pPeople->GetFSM()->ChangeState(GiveEggsToMao::Instance());
	 // mao->GetFSM()->ChangeState(StopAtRoad::Instance());
  }
  if(n==6||n==7){
	  pPeople->GetFSM()->ChangeState(WaveHandToMao::Instance());
	 // mao->GetFSM()->ChangeState(WaveHand::Instance());
  }
  if(n==8||n==9){
	  pPeople->GetFSM()->ChangeState(ShakeHandWithMao::Instance());
	  //mao->GetFSM()->ChangeState(ShakeHand::Instance());
  }
}

void ShakeHandWithMao::Exit(People* pPeople)
{ 
 SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pPeople->ID()) << ": " << "People leave Mao after shaking hand with Mao(stop ShakeHandWithMao)";
    
}
bool ShakeHandWithMao::OnMessage(People* pMiner, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}
