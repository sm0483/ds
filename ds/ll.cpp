#include <iostream>
using namespace std;


class node {
public:

	int date;
	node *next;

	void printinfo(){
	
	cout<<date<<" ";
	cout<<next;
	cout<<endl;
	
	}


};

int main(){

/*	node *head=NULL;
	node *second=NULL;
	node *third=NULL;

	head->date=3;
	head->next=second;

*/


	node head;
	node second;
	

	head.date=3;
	head.next=&second;
	second.date=4;
	second.next=NULL;

	head.printinfo();
	second.printinfo();











	return 0;






}
