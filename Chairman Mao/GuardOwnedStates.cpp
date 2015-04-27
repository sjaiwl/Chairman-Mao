#include "GuardOwnedStates.h"
#include "State.h"
#include "Guard.h"
#include "EntityNames.h"
#include "Telegram.h"
#include "misc/ConsoleUtils.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "misc/CrudeTimer.h"
#include <iostream>
using std::cout;

//define this to output to a file

//----------------------------------------methods for CollectInformation

GuardGlobleState* GuardGlobleState::Instance()
{
  static GuardGlobleState instance;

  return &instance;
}
void GuardGlobleState::Enter(Guard* pGuard)
{  
  
}
void GuardGlobleState::Execute(Guard* pGuard)
{  

 pGuard->GetFSM()->ChangeState(CollectInformation::Instance());
  
}
void GuardGlobleState::Exit(Guard* pGuard)
{  
  
}

CollectInformation* CollectInformation::Instance()
{
  static CollectInformation instance;

  return &instance;
}
bool GuardGlobleState::OnMessage(Guard* pGuard, const Telegram& msg)
{

  return false;

}

void CollectInformation::Enter(Guard* pGuard)
{  
    SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " << "I will go to collect information";
	Dispatch->DispatchMessage(1.5,                  //time delay
                              pGuard->ID(),           //sender ID
                              pGuard->ID(),           //receiver ID
                              Msg_ReportToMao,        //msg
                              NO_ADDITIONAL_INFO);  
}


void CollectInformation::Execute(Guard* pGuard)
{
  SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " 
       << "Collect Information.......";
 
}


void CollectInformation::Exit(Guard* pGuard)
{
  SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " << "I will go to report to Mao";
}

bool CollectInformation::OnMessage(Guard* pGuard, const Telegram& msg)
{
	switch(msg.Msg)
  {
	  case Msg_ReportToMao:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(pGuard->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(pGuard->ID()) << 
          ":ChairMao,report to you! ";

     pGuard->GetFSM()->ChangeState(ReportToMao::Instance());
	return true;
   }
}
  return false;
}

//----------------------------------------methods for ReportToMao

ReportToMao* ReportToMao::Instance()
{
  static ReportToMao instance;

  return &instance;
}

void ReportToMao::Enter(Guard* pGuard)
{
 
    SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " << "I run to Mao";
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pGuard->ID(),        //ID of sender
                              ent_Chair_Mao,            //ID of recipient
                              Msg_GetReport,   //the message
                              NO_ADDITIONAL_INFO); 
}

void ReportToMao::Execute(Guard* pGuard)
{ 
  //if Guard is not fatigued start to dig for nuggets again.
 
  
    SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " 
          << "I have some information to report";   
}

void ReportToMao::Exit(Guard* pGuard)
{ 
  SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " << "I go on collect information";

}

bool ReportToMao::OnMessage(Guard* pGuard, const Telegram& msg)
{	
	switch(msg.Msg)
  {
	  case Msg_GoCollect:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(pGuard->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(pGuard->ID()) << 
          ":ChairMao tell me to collect information! ";

     pGuard->GetFSM()->ChangeState(CollectInformation::Instance());
	return true;
   }
}	
  return false;
}

