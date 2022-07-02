#include "hash_function.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int HashFunction::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
int squ = key * key;
  
int* bi = new int[2 * key_size] {0};
  
int idx = 0, sum = 0;
int digit = 1;
  
  while (squ > 0) {
      bi[idx] = squ % 2;
      squ = squ/2;
    idx++;
    }

int start = (2*key_size - index_size) / 2;
    int end = start + index_size;
    for (int i = start; i < end; i++) {
      sum += bi[i] * digit;
      digit = digit * 2;
    }
return sum;
  
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
