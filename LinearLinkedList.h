#ifndef LinearLinkedList
#define LinearLinkedList
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}Node;
Node * InsertLast(Node* R,int data);
void DisplayElements(Node* R);
Node * InsertFirst(Node* R,int data);
Node * InsertPosition(Node* R,int position,int data);
Node * DeleteNode(Node* R,int data);
Node * InsertSmalltoLarge(Node* R,int data);
/************************************************************************
 --Function Description--
 Parameters:
 	Parameter_1:root node,type:Node pointer   
	Parameter_2:new node value,type integer
 Return Veriable: root
 Return Type    : Node pointer
 Description:
  if root is null,create new root
  if list has nodes,create a new node and add it the end of the list.
*************************************************************************/
Node * InsertLast(Node* R,int data){
	Node* temp=(Node*)malloc(sizeof(Node));
	Node* noChanceRoot=R;
	temp->data=data;
	temp->next=NULL;
	if(R==NULL)
		{ return temp;}
	else{
		while(R->next!=NULL)
			{ R=R->next;}
		R->next=temp;
		return noChanceRoot;
	}		
}
/*****************************************************************
--Function Description--
Parameters:
	Parameter_1:root node,type:Node pointer
Return Type:void
Description: print all node values		
******************************************************************/
void DisplayElements(Node* R){
	while(R!=NULL){
		printf("%d\t",R->data);
		if(R->next!=NULL)
			{R=R->next;	}
		else
			{break;	}
	}
	printf("\n\n");
}
/**********************************************************************
 --Function Description--
 Parameters:
 	Parameter_1:root node,type:Node pointer   
	Parameter_2:new node value,type integer
 Return Veriable: root
 Return Type    : Node pointer
 Description:
  if root is null,create new root
  if list has nodes,create a new node and make node root
***********************************************************************/
Node * InsertFirst(Node* R,int data){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	if(R==NULL)
		{ return temp;}
	else{
		temp->next=R;
		return temp;
	}
}
/*****************************************************************************
 --Function Description--
 Parameters:
 	Parameter_1:root node,type:Node pointer   
	Parameter_2:new node position,type:integer
	Parameter_3:new node value,type:integer
 Return Veriable: root
 Return Type    : Node pointer
 Description:
  root position is 1
  if you want to add new root node you can write 1 for position
  Do you want to add other positions for new node,you can write other number
  Please read to comment in the function
******************************************************************************/
Node* InsertPosition(Node* R,int position,int data){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	Node* noChanceRoot=R;
	if(position==1){
		temp->next=R;
		return temp;
	}
	// root's position is one 
	int count_position=2;
	while(R!=NULL){
	 // We are in root(position 1) but position is 2 because
	 //We add in 2, iteration veriable in 1
	 /*
	 actually, :D 
	 in first code,I wrote count_position=1 but after than I chance it count_position=2
	 and I like second code.It is truth than second for me :) 
	 
	 if you want to add after position
	 you can write count_positiion=1;
	 Example :
	 	1 5 6 8 9	
	 InsertPosition(root,2,16);
	 count_position=2;
	 	1 16 5 6 8 9 
	 count_position=1;
	    1 5 16 6 8 9 
	 you can try :) 	 
	 */
		if(count_position==position){
			temp->next=R->next;
			R->next=temp;
			return noChanceRoot;		
		}
		if(R->next!=NULL){
			R=R->next;
			count_position++;
		}
		else{
			printf("Node not found in position!\n");
			return noChanceRoot;
		}
	}	
}
/*****************************************************************
 --Function Description--
 Parameters:
 	Parameter_1:root node,type:Node pointer   
	Parameter_2:deleted node value type:integer
 Return Veriable: root
 Return Type    : Node pointer
 Description:
  if Node's value equals to parameter,Node will be deleted 
*****************************************************************/
Node *DeleteNode(Node* R,int data){
	Node* noChanceRoot=R;
	if(R->data==data){//Root node
		Node*temp=R;
		R=R->next;
		free(temp);
		return R;
	}
	while(R!=NULL){
		if(R->next->data==data){ 
			Node* temp=R->next;
			R->next=R->next->next;
			free(temp);
			return noChanceRoot;
		}
		else if(R->next!=NULL)
			{ R=R->next;}
		if(R->next==NULL){
			printf("Value not found in  list!\n");
			return noChanceRoot;
		}		
	}	
}
/***************************************************************
 --Function Description--
 Parameters:
 	Parameter_1:root node,type:Node pointer   
	Parameter_2:deleted node value type:integer
 Return Veriable: root
 Return Type    : Node pointer
 Description:
  create small to large ordered list
***************************************************************/
Node * InsertSmalltoLarge(Node* R,int data){
		Node* noChanceRoot=R;
		Node* temp=(Node*)malloc(sizeof(Node));
		temp->data=data;
		temp->next=NULL;
		if(R==NULL){  //Root is NULL
			return temp;
		}
		else if(R->next==NULL||data<R->data){ // only node or new node value smaller than root
		   if(data<R->data){
		   	temp->next=R;
		   	return temp; // new root
		   }
		   else{// R->next ==NULL
		   	R->next=temp;
		   	return noChanceRoot;
		   }
		} 
		else{ // a lot of nodes
			while(R->next!=NULL&&data>R->next->data)
				{ R=R->next;	} 
			temp->next=R->next;
			R->next=temp;
			return noChanceRoot;
		}		
}
#endif
