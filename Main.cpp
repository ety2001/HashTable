// Main.cpp
#include "Hash.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	char[][] firsts = new char[100][20];
  char[][] lasts = new char[100][20];
  int numfirsts = 0;
  int numlasts = 0;
  boolean go = true;
  Hash* studentRecords = new Hash();
	while(go == true){
		cout << "What is your command? Enter ADD DELETE PRINT FILE or QUIT"<< endl;
		char input[7];
		cin >> input;
		char first[20];
		char last[20];
		int id;
		float gpa;
		if(input[1] == 'D'){
			cout << "Enter first name" << endl;
			cin >> first;
			cout << "Enter last name" << endl;
			cin >> last;
			cout << "Enter ID" << endl;
			cin >> id;
			cout << "Enter GPA" << endl;
			cin >> gpa;
			studentRecords->add(id, first, last, gpa);
			cout << "Student added." << endl;
		}
		if(input[1] == 'E'){
			cout << "Enter ID" << endl;
			cin >> id;
			studentRecords->delete(id);
		}
		else if(input[1] == 'R'){
			studentRecords->print();
		}
    else if(input[1] == 'I'){
      cout<<"what is the file name for first names"<<endl;
      cin>>input;
      fstream myFile(input);
      while(myFile>>first){
        strcpy(firsts[numfirsts++], first);
      }
      cout<<"what is the file name for last names"<<endl;
      cin>>input;
      fstream myFile(input);
      while(myFile>>last){
        strcpy(lasts[numlasts++], last);
      }
      cout<<"How many students do you want to generate"<<endl;
      int num;
      cin>>num;
		else if(input[1] == 'U'){
			go = false;
		}
	}
}
