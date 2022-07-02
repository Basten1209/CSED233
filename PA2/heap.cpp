#include "heap.h"
#include <iostream>
#include <string>

using namespace std;


MaxHeap::MaxHeap() {
    heap_size = 0;
    heap_arr = new int[100]; // Default array of size 100
}

string MaxHeap::printHeap(){
    string answer;
    for (int i = 0; i < heap_size; i++)
        answer += to_string(heap_arr[i]) + " ";
    return answer;
}

void MaxHeap::insertKey(int k) {

  
  
  /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

  heap_arr[heap_size] = k;
  heap_size++;

  int child = heap_size-1;
  int parent;
  if(child % 2==1){
   parent = (child-1)/2;
  }
  else{
    parent = (child-2)/2;
  }
  while(child >= 1 && (heap_arr[parent]<heap_arr[child])){
    int temp;
     temp = heap_arr[parent];
     heap_arr[parent] = heap_arr[child];
     heap_arr[child] = temp;

    child = parent;
  if(child % 2==1){
   parent = (child-1)/2;
  }
  else{
    parent = (child-2)/2;
  }
    
  }
  


    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void MaxHeap::deleteMax() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

heap_arr[0] = heap_arr[heap_size-1];
heap_size--;

int parent = 0;
int child = parent*2+1;
int temp;
if(child+1 <= heap_size){
  if(heap_arr[child]<heap_arr[child+1])
    child = child+1;
}
  while(child<heap_size && heap_arr[parent]<heap_arr[child]){
    temp = heap_arr[child];
    heap_arr[child] = heap_arr[parent];
    heap_arr[parent] = temp;

    parent = child;
    child = child*2+1;
    
    if(child+1<=heap_size){
      if(heap_arr[child]<heap_arr[child+1])
        child = child+1;
    }

    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void MaxHeap::maxHeapProp(int i) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////


    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}