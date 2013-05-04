//  GAMBIT: Global and Modular BSM Inference Tool
//  *********************************************
//
//  Temporary global variable header.  This should 
//  be made obsolete eventually, by putting all 
//  variables inside an appropriate gambit_core
//  object.
//
//  *********************************************
//
//  Authors
//  =======
//
//  (add name and date if you modify)
//
//  Pat Scott
//  Apr 22
//
//  *********************************************

#ifndef __globals_hpp__
#define __globals_hpp__

namespace GAMBIT 
{

  #ifdef IN_CORE
    bool safe_mode = true;
  #else
    extern bool safe_mode;
  #endif

}

#endif // defined __globals_hpp__