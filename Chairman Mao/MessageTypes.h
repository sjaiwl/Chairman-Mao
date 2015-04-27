#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_PeopleGiveEggsToMao,
  Msg_PeopleShakeHandWithMao,
  Msg_PeopleWaveHandToMao,
  Msg_ReportToMao,
  Msg_GetReport,
  Msg_GoCollect


};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_PeopleGiveEggsToMao:
    
    return "GievEggs"; 

  case Msg_PeopleShakeHandWithMao:
    
    return "ShakeHand";

  case Msg_PeopleWaveHandToMao:
    
    return "WaveHand";

  case Msg_ReportToMao:
    
    return "Report";

  case Msg_GetReport:
    
    return "GetReport";

  case Msg_GoCollect:
    
    return "GoCollect";

  default:

    return "Not recognized!";
  }
}

#endif