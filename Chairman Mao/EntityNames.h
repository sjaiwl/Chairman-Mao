#ifndef NAMES_H
#define NAMES_H

#include <string>

enum 
{
  ent_Chair_Mao,

  ent_People,

  ent_Guard,

  ent_Peng

};

inline std::string GetNameOfEntity(int n)
{
  switch(n)
  {
  case ent_Chair_Mao:

    return "Chairman Mao";

  case ent_People:
    
    return "People";

  case ent_Guard:
    
    return "Guard"; 

  case ent_Peng:
    
    return "Peng"; 

  default:

    return "UNKNOWN!";
  }
}

#endif