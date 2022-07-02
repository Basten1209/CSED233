#include "shift_register.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int ShiftRegister::getSeqNumber(int idx) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i = 1;
    while (i < idx) {
      int next = initial_seed * 2;
      initial_seed = next;
      
      if (initial_seed >= M) {
        initial_seed = initial_seed - M;
        initial_seed = initial_seed ^ k;
      }
      i++;
    }
    return initial_seed;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
