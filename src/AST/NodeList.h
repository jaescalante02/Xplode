#include <string>
#include <iostream>
#include <stdio.h>
#include <list> 
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include "Node.h"

#ifndef X_NODELIST
#define X_NODELIST


//List of nodes
class NodeList  {
  public:
  std::list<Node *> nodeList;
  
  NodeList() { }
  void add(Node* n){
      nodeList.push_back(n);
  }
  
  void push(Node* n){
      nodeList.push_front(n);
  }
  
  int size(){
    return nodeList.size();
  }
  
  void print(){   
    for(std::list<Node *>::iterator iter = nodeList.begin(); iter != nodeList.end(); ++iter){
         (*iter)->print(); 
    }
  }

};


#endif
