#pragma once
#include <string>

using namespace std;

struct Node {
  Node(char input_value) : value(input_value), left(NULL), right(NULL) {}
  char value;
  Node *left;
  Node *right;
};

class BinaryTree {
public:
  BinaryTree() { _root = NULL; };
  ~BinaryTree() {
    delete[] _root;
    _root = NULL;
  };
  void buildFromString(const char *data);

  string preOrder();
  string postOrder();
  string inOrder();
  int getDepth(int node_value);
  bool isProper();

private:
  Node *_root;
  Node *_buildFromString(const char *data, int start, int end);
  void _pre(Node *a, string &ans);
  void _post(Node *a, string &ans);
  void _in(Node *a, string &ans);
  void _dep(Node *a, int level, int node_value, int &depthcount);
  void proper(Node *a, int &check);
  /////////////////////////////////////////////////////////
  //////  TODO: Add Private members if required ///////////
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
};