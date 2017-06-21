// Hash.h

#include <string.h>
#include "StudentNode.h"


class Hash {
public:
   int tablesize;
   ListNode **table;
   Hash();
   int hashFun(int); // map a key to an array index
   void insert(int, char*, char*, float); // insert a data
   boolean delete(int); // delete a data with a key
   void print(); 
}
