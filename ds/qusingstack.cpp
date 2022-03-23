#include<iostream>
#include<stack>
using namespace std;

class queue{
   stack<int>s1,s2;
   public:
   void push(int val){

	  while(!s1.empty()){
		 s2.push(s1.top());
		 s1.pop();

	  }
	  s1.push(val);

	  while(!s2.empty()){
		 s1.push(s2.top());
		 s2.pop();

	  }
   }
   void front(){
	  cout<<s1.top()<<endl;


   }
   void pop(){
	  s1.pop();


   }
};

class queue1{
   stack<int>input,output;
   public:

   void pop(){
	  if(!output.empty()){
		 output.pop();

	  }
	  else{
		 while(!input.empty()){
			output.push(input.top());
			input.pop();
		 }
		 output.pop();
	  }

   }

   void push(int val){
	  input.push(val);

   }

   void front(){
	  if(!output.empty()){
		 cout<<output.top()<<endl;

	  }
	  else{
		 while(!input.empty()){
			output.push(input.top());
			input.pop();

		 }
		 cout<<output.top()<<endl;

	  }
   }



};

int main(){
   queue1 q;
   q.push(1);
   q.push(2);
   q.push(3);
   //q.front();
   q.pop();
   q.front();

   return 0;
}
