// linkedlist.h

#ifndef linkedlist_h
#define linkedlist_h

struct Student{
  char first[20];
  char last[20];
  int id;
  float gpa;
  Student* next;
};

class LinkedList{
  private:
    Student* head;
    Student* tail;
  public:
    Student* getHead();
    Student* getTail();
    void addStudent(char, char, int, float);
}
