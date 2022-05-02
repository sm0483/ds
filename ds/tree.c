//tree creation and traversal
#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int val;
	struct Node* right;
	struct Node* left;
}Node;

/*
Node * createNode(int _val){

	Node* new=(Node*)malloc(sizeof(Node));
	new->val=_val;
	new->right=NULL;
	new->left=NULL;


}
*/

void buildTree(Node* ptr,int _val){
	int key=0;
	int newl=0;

	if(ptr!=NULL){

		ptr->val=_val;
		printf("Is there left Node[y/n]{1/0}; \n");
		scanf("%d",&key);
		//for left
		if(key){
			//read new value
			printf("Enter the new value:\n ");
			scanf("%d",&newl);
			Node* new=(Node*)malloc(sizeof(Node));
			ptr->left=new;
			buildTree(new,newl);

		}
		else{
			ptr->left=NULL;
			buildTree(NULL,0);

		}

		//for right
		printf("Is there Right Node[y/n]{1/0}; \n");
		scanf("%d",&key);
		if(key){
			//read new value
			printf("Enter the new value:\n ");
			scanf("%d",&newl);
			Node* new=(Node*)malloc(sizeof(Node));
			ptr->right=new;
			buildTree(new,newl);
		}
		else{
			ptr->right=NULL;
			buildTree(NULL,0);

		}



	}
}


int main(){

	Node* head=(Node*)malloc(sizeof(Node));
	buildTree(head,1);



	return 0;

}
