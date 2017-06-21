// Hash.cpp
#include <iostream>
#include "Hash.h"
using namespace std;

Hash::Hash(){
  tablesize = 100; // hash size
  table = new StudentNode*[tablesize];
  for (int i = 0; i < tablesize; i++){
    table[i] = NULL;
  }
}

int Hash::hashFun(int id) // simple hash function
{
  return id % tablesize;
}

void Hash::rehash(){
  int newSize = tablesize*2;
  StudentNode* newTable[] = new StudentNode* [newSize];
  for (int i = 0; i < newSize; i++){
    newTable[i] = NULL;
  }
  for(int i = 0; i < tablesize; i++){
    for(StudentNode* node = table[i], StudentNode* next = NULL; node != NULL; node = next){
      next = node->getNext();
      int newIndex = node->getId()%newSize;
      node->setNext(newTable[newIndex]);
      newTable[newIndex] = node;
    }
  }
  tablesize = newSize;
  delete table;
  table = newTable;
}

void Hash::insert(int id, char* first, char* last, float gpa)
{
  StudentNode *node = new StudentNode(id, first, last, gpa);
  int index = hashFun(id);
  // insert the node to the head of the chain
  node->next = table[index];
  table[index] = node;
  int collisions = 0;
  for(node = table[index]; node != NULL, node = node-getNext()){
    collisions++;
  }
  if(collisions > 3){
    rehash();
  }
}

boolean Hash::delete(int id)
{
  int index = hashFun(id);
  StudentNode *node = table[index];
  StudentNode *prev = NULL;

  while (node != NULL && node->getId() != id) {
    prev = node;
    node = node->getNext();
  }

  if (node == NULL)
    return false;
  else {
    if (prev == NULL)
      table[index] = node->getNext();
    else
      prev->getNext() = node->getNext();
    node->getNext() = NULL;
    delete node;
    return true;
  }
}

void Hash::print(){
  for(int i=0; i <tablesize; i++){
    for(StudentNode* n = table[i]; n!=NULL; n=n->getNext()){
      cout<<n->getId()<<": "<<n->getFirst()<<" "<<n->getLast()<<" "<<n->getGpa()<<endl;
    }
  }
}
