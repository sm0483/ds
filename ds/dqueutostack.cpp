#include<iostream>
#include<queue>
using namespace std;

class stack{
   queue<int>q1,q2;
   public:
   void push(int val){
	  q2.push(val);
	  while(!q1.empty()){
		 q2.push(q1.front());
		 q1.pop();
	  }
	  queue<int>temp=q1;
	  q1=q2;
	  q2=temp;	  
   }
   void pop(){
	  q1.pop();

   }
   void top(){
	  cout<<q1.front();
	  cout<<endl; 
   }
};

class stack1{
   queue<int>q;
   public:
   void push(int val){
	  q.push(val);
	  int size=q.size();
	  for(int i=0;i<size;i++){
		 int front=q.front();
		 q.pop();
		 q.push(front);
	  }
   }

   void pop(){
	  q.pop();

   }

   void top(){
	  cout<<q.front()<<endl;

   }






};

int main(){
   stack1 st;
   st.push(1);
   st.push(2);
   st.push(3);
   //st.pop();
   st.top();

   return 0;

}
