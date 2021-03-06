#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;


/* 
    [Task 1] Choose the TIGHT bound of the following maxProduct function
    
    *maxProduct*
        Input
        - int n: the length of the input arrays (n >=1)
        - int* A: an array storing n >= 1 integers
        - int* B: an array storing n >= 1 integers
        Output
        - int: The maximum product of elements from each A and B
        int maxProduct(int n, int* A, int* B) { 
            int currMax = 0; 
            for (int i = 1; i < n; i++) 
                for (int j = 1; j < n; j++) 
                    if (currMax < A[i]*B[j]) 
                        currMax = A[i]*B[j]; 
            return currMax; 
        } 

    Choices
        1: O( 1 )
        2: O( n )
        3: O( n log(n) )
        4: O( n^2 )
*/
void task_1(ofstream &fout) {
    int answer = 4;  // TODO: Change to your answer

    fout << "[Task 1]" << endl;
    fout << answer << endl;

    return;
}

/*
    [Task 2] Choose the TIGHT bound of the following medianSearch function

    *medianSearch*
        Input
        - int n: the length of the input array (n >=2)
        - double* A: an ascending sorted array with n >=2 integers
        Output
        - double*: An array B which contains n-th, n/2-th, n/4-th, .. elements of A
        double* medianSearch(int n, double* A) { 
            double *B = new double[n]; 
            //B is allocated as same size as A  
            int j = 0; 
            for (int i = n; i >= 1; i = i/2) { 
                B[j] = A[i-1]; 
                j++; 
            } 
            return B; 
        } 

    Choices
        1: O( log(n) )
        2: O( n log(n) )
        3: O( n )
        4: O( n^2 )
*/
void task_2(ofstream &fout) {
    int answer = 1;  // TODO: Change to your answer

    fout << "[Task 2]" << endl;
    fout << answer << endl;

    return;
}

/*
    [Task 3] List

    Description:
        Implement a function that can insert or delete an integer into the ascending order “sorted” list. 
        An user can delete a specified smallest element. 
        If the specified element is out of range of the given list, print “error” 
 
        Tips: Please do not try to implement sorting algorithm for this task

    Input:
        Sequence of commands, which is one of the following
        - (‘insert’,integer): insert integer into the appropriate position in the sorted list.  
        - (‘delete_at’,i): delete an item that is i-th smallest element in the list. i indicates zero-based index. 

    Output: 
        - An array after insertion/deletion in a string separated with the spacebar 
        - “error” if the index is out of range
*/

void task_3(ofstream &fout, InstructionSequence* instr_seq) {
    string answer;

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int temp[1000] = { 0 } ;   
    int count = 0;
    int swap;

    for (int i=0; i<instr_seq->length; i++) {
        string command = instr_seq->instructions[i].command;
        if (command.compare("insert") == 0) {
            /* TODO: Implement */

          temp[count] = instr_seq->instructions[i].value;
          count++;
          
          for(int a = 0; a<count-1; a++){
            for(int b = a+1; b<count; b++){
              if(temp[a] > temp[b]){
                swap = temp[a];
                temp[a] = temp[b];
                temp[b] = swap;
              }
            }
          }

         
        } else if(command.compare("delete_at") == 0) {
            /* TODO: Implement */
          int delnum = instr_seq->instructions[i].value;
          if(count == 0){
            answer = "error";
          }
          if(count-1 < delnum){
            answer = "error";
          }
          for(int i = delnum; i<count-1; i++){
            temp[i] = temp[i+1];
          }
          temp[count] = 0;
          count--;
          
        } else {
            cerr << "Invalid command" << endl;
            exit(-1);
        }
    }

        if(answer != "error"){
          for(int i = 0; i<count-1; i++){

            answer += to_string(temp[i]) + ' ';
          }
            answer += to_string(temp[count-1]);
        }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    fout << "[Task 3]" << endl;
    fout << answer << endl;
}

/*
    [Task 4] Stack

    Description:
        Implement a function that prints the top values of the stack when “top” operation is called after the sequence of “push” or “pop” operations. 
        If the stack is empty, and the “top” operation is called, then print “-1”, If “pop” operation from the empty stack then print “error” 

    Input:
        Sequence of commands, which is one of the following,
        - (‘push’,integer): push integer into the current stack (integer is always positive) 
        - (‘pop’,NULL): pop the top value of the current stack (this operation will print nothing) 
        - (‘top’,NULL): print the top value of the current stack (print ‘-1’ if the current stack is empty) 

    Output:
        - Expected printed values after processing the whole sequence, in a string separated with the spacebar 
        - “error” if the pop operation is executed on an empty stack 
*/

void task_4(ofstream &fout, InstructionSequence* instr_seq) {
    string answer;
    
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
int temp[1000] = { 0 };
int tpop[1000] = { 0 };
int count = 0;
int tcount = 0;

    for (int i=0; i<instr_seq->length; i++) {
        string command = instr_seq->instructions[i].command;
        if (command.compare("push") == 0) {
            /* TODO: Implement */
          
            temp[count] = instr_seq->instructions[i].value;
            count++;

        } else if (command.compare("pop") == 0 ){
            /* TODO: Implement */
          if (temp[0] == 0){
            answer = "error";
            break;
          }  
          temp[count-1] = 0;
            count--;

        } else if ( command.compare("top") == 0 ){
            /* TODO: Implement */

          if(temp[0] == 0){
            answer = "-1";
            break;
          }
            tpop[tcount] = temp[count-1];
            tcount++;

        } else {
            cerr << "Invalid command" << endl;
            exit(-1);
        }
    }
          if((answer != "error")&&(answer != "-1")){
            for(int i = 0; i<tcount-1; i++){

            answer += to_string(tpop[i]) + ' ';
          }
            answer += to_string(tpop[tcount-1]);
        }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    
    fout << "[Task 4]" << endl;
    fout << answer << endl;
}

/*
    [Task 5] Queue

    Description:
        - Implement a function which shows the value in the queue from the head to tail.

    Input:
        Sequence of commands, which is one of the following,
        -(‘enqueue’,integer): enqueue integer into the current queue

    Output: 
        - Values in the queue from the head to the tail, in a string separated with the spacebar 
        
*/
void task_5(ofstream &fout, InstructionSequence* instr_seq) {
    string answer; 

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
int temp[1000] = { 0 };
int count = 0;

    for (int i=0; i < instr_seq->length; i++) {
        string command = instr_seq->instructions[i].command;
        if (command.compare("enqueue") == 0) {
            /* TODO: Implement */
          
          temp[count] = instr_seq->instructions[i].value;
          count++;

        } else {
            cerr << "Invalid command" << endl;
            exit(-1);
        }
    }
            for(int i = 0; i<count-1; i++){

            answer += to_string(temp[i]) + ' ';
          }
            answer += to_string(temp[count-1]);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    
    fout << "[Task 5]" << endl;
    fout << answer << endl;
    
}

/*
    [Task 6] Queue

    Description: 
        Implement a function which shows the value of a queue after the sequence of arbitrary queue operation. 
        If the queue after the operations is empty, print “empty”. 
        If “dequeue” operates on an empty queue, print “error”.

    Input:
        Sequence of commands, which is one of the following,
        - (‘enqueue’,integer): enqueue integer into the current queue
        - (‘dequeue’,NULL): dequeue from the current queue 

    Output
        - Values in the queue from the head to the tail, in a string separated with spacebar 
        - “empty” if the queue is empty
        - “error” if the “dequeue” operation is executed on an empty queue
*/
void task_6(ofstream &fout, InstructionSequence* instr_seq) {
    string answer;
    
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

int temp[1000] = { 0 };
int count = 0;
  
    for (int i=0; i < instr_seq->length; i++) {
        string command = instr_seq->instructions[i].command;
        if (command.compare("enqueue") == 0) {
            /* TODO: Implement */
          temp[count] = instr_seq->instructions[i].value;
          count++;
          
        } else if (command.compare("dequeue") == 0) {
            /* TODO: Implement */
          if(count == 0){
            answer = "error";
            break;
          }
          for(int i = 0; i<count; i++){
            temp[i] = temp[i+1];
          }
          count--;

        } else {
            cerr << "Invalid command" << endl;
            exit(-1);
        }
    }

  if(count==0){
    answer = "empty";
  }
            if((answer != "error")&&(answer != "empty")){
            for(int i = 0; i<count-1; i++){

            answer += to_string(temp[i]) + ' ';
          }
            answer += to_string(temp[count-1]);
        }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    
    fout << "[Task 6]" << endl;
    fout << answer << endl;
}


int main(int argc, char **argv) {
    string filename = "submit.txt";
    int task_num = 0;
    InstructionSequence* instr_seq;

    // Open file
    ofstream fout;
    fout.open(filename, fstream::app);
    if (!fout.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return -1;
    }

    // Choosing task number. Default is running ALL tasks (0)
    if (argc >= 2)
        task_num = atoi(argv[1]);
    if (argc >= 3) {
        try {
            instr_seq = ParseInstructions(argv[2]);
        }
        catch (const char* e) {
            cerr << e << endl;
            return -1;
        }
    }

    // Running the task(s)
    switch (task_num) {
        case 1:
            task_1(fout);
            break;
        case 2:
            task_2(fout);
            break;
        case 3:
            task_3(fout, instr_seq);
            break;
        case 4:
            task_4(fout, instr_seq);
            break;
        case 5:
            task_5(fout, instr_seq);
            break;
        case 6:
            task_6(fout, instr_seq);
            break;
        case 0:
            task_1(fout);
            task_2(fout);

            InstructionSequence* instr_seq_3;
            instr_seq_3 = ParseInstructions(TASK_3_DEFAULT_ARGUMENT);
            task_3(fout, instr_seq_3);
            
            InstructionSequence* instr_seq_4;
            instr_seq_4 = ParseInstructions(TASK_4_DEFAULT_ARGUMENT);
            task_4(fout, instr_seq_4);
            
            InstructionSequence* instr_seq_5;
            instr_seq_5 = ParseInstructions(TASK_5_DEFAULT_ARGUMENT);
            task_5(fout, instr_seq_5);
            
            InstructionSequence* instr_seq_6;
            instr_seq_6 = ParseInstructions(TASK_6_DEFAULT_ARGUMENT);
            task_6(fout, instr_seq_6);
            break;
        default:
            cout << "Wrong task number" << endl;
    }

    fout.close();
    return 0;
}