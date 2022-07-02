#include "tree.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
  if (start > end)
    return -1;

  string s;

  for (int i = start; i <= end; i++) {

    // if open parenthesis, push it
    if (str[i] == '(')
      s.push_back(str[i]);

    // if close parenthesis
    else if (str[i] == ')') {
      if (s.back() == '(') {
        s.pop_back();

        if (!s.length())
          return i;
      }
    }
  }
  // if not found return -1
  return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {
  if (start > end)
    return NULL;

  Node *root = new Node(data[start]);
  int index = -1;

  if (start + 1 <= end && data[start + 1] == '(')
    index = findIndex(data, start + 1, end);

  if (index != -1) {
    root->left = _buildFromString(data, start + 2, index - 1);
    root->right = _buildFromString(data, index + 2, end - 1);
  }
  return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
  Node *root = _buildFromString(data, 0, strlen(data) - 1);
  _root = root;
}

string BinaryTree::preOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  string answer;
  _pre(_root, answer);
  
  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::postOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  string answer;
  _post(_root, answer);
  
  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::inOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  string answer;
  _in(_root, answer);
  
  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

int BinaryTree::getDepth(int node_value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
int depthcount = -1;
int level = 0;
  _dep(_root, level, node_value, depthcount);

  return depthcount;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

bool BinaryTree::isProper(){
 
/////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
int check = 0;
  bool answer;
  proper(_root, check);
  if(check==0)
    return true;
  else
    return false;
  }

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional private functions  */
void BinaryTree::_pre(Node *a, string &ans){

  char tempchar = a->value;
  ans += tempchar;
  ans += " ";
  if(a->left!=NULL){
    _pre(a->left, ans);
  }
  if(a->right!=NULL){
    _pre(a->right, ans);
  }
}
void BinaryTree::_post(Node *a, string &ans){


  if(a->left!=NULL){
    _post(a->left, ans);
  }
  if(a->right!=NULL){
    _post(a->right, ans);
  }
  char tempchar = a->value;
  ans += tempchar;
  ans += " ";
}
void BinaryTree::_in(Node *a, string &ans){


  if(a->left!=NULL){
    _in(a->left, ans);
  }
  char tempchar = a->value;
  ans += tempchar;
  ans += " ";
  if(a->right!=NULL){
    _in(a->right, ans);
  }
}

void BinaryTree::_dep(Node *a, int level, int node_value, int &depthcount){
    if(a!=NULL){
      
  if(a->value == node_value+48)
    depthcount = level;
    _dep(a->left, level+1, node_value, depthcount);
    _dep(a->right, level+1, node_value, depthcount);
    }
  }
  
void BinaryTree::proper(Node *a, int &check){
  if(a!=NULL){
    if((a->left!=NULL&&a->right==NULL) || (a->left==NULL&&a->right!=NULL))
      check = 1;
    
    if((a->left!=NULL&&a->right!=NULL))
      proper(a->left, check);
      proper(a->right, check);
  }
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////