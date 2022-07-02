#include "sort.h"
#include <iostream>
#include <fstream>
#include <string>


sortAlg::sortAlg() {
    arr_size = 0;
    arr = new int[100]; // Each test case will be less than 100 values
}

using namespace std;

void sortAlg::printArray(ofstream &fout) {
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);
    fout << answer << endl;
}


void sortAlg::selectionSort(ofstream &fout) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

  int minidx;
    for (int i = 0; i < arr_size - 1; i++) {
      minidx = i;
      for(int j = i+1; j<arr_size; j++){
        if(arr[minidx]>arr[j]){
          minidx = j;
        }
      }
      int tmp = arr[minidx];
      arr[minidx] = arr[i];
      arr[i] = tmp;
      printArray(fout); // DO NOT ERASE THIS LINE
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::merge(int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
int _size = right-left;
int tmparr[_size*2];
int _left = left, _right = right, idx = 0;
int r_end;
  if(right + _size >= arr_size){
  r_end = arr_size;
}
  else
    r_end = right + _size;
  
while((_left < left + _size)&&(_right < r_end)){
  if(arr[_left] < arr[_right]){
    tmparr[idx] = arr[_left];
    _left++;
    }
  else if(arr[_left]>arr[_right]){
    tmparr[idx] = arr[_right];
    _right++;
  }
  idx++;
  }

for(int i = _left; i<_left+_size; i++,idx++){
    tmparr[idx] = arr[i];

  }
for(int i = _right; i<r_end; i++, idx++){
    tmparr[idx] = arr[i];

  }
  idx = 0;
for(int i = left; i<r_end; i++,idx++){
    arr[i] = tmparr[idx];

  }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::mergeSort(ofstream &fout, int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int len = 1;
    int first, second;
  
    if (left < right) {
      while (len < arr_size) {
        first = left;
        second = first + len;
        
        while ((first <= right) && (second <= right)) {
          merge(first, second);
          printArray(fout);// DO NOT ERASE THIS LINE
          first = first + 2*len;
          second = first + len;
        }
        len = 2*len;
      }
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

}
