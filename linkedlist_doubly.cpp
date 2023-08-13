#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
   Node* prev;
};

void insert(Node** start, Node** last, int data) {
	
	
	if(*start==NULL){
	
  Node* newNode = new Node();
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
    *last = *start = newNode;
    return;
  }
    
  else if(data<=(*start)->data){
  	
  		
	Node* newnode= new Node();
	
	newnode->data=data;
	newnode->next=*start;
	newnode->prev=NULL;
	(*start)->prev=newnode;
		*start = newnode;
	return;
  }
  
  
  else{

  Node* temp = (*start)->next;
  while (temp!= NULL){
  	
  	if(temp->data > data){
  		Node* newNode = new Node;
  newNode->data = data;
 
  newNode->next = temp;
  newNode->prev = temp->prev;
 temp->prev->next = newNode;
 temp->prev=newNode;
  return;		
	  }
  	
  	
    temp = temp->next;
  }
  
  
   Node* newnode = new Node;
  newnode->data = data;
  (*last)->next=newnode;
   newnode->prev=*last;
   newnode->next=NULL;
   (*last) = newnode;
 return;
}
}

//deletion

void deletion(Node** start , Node** last, int data){
	
	
	if(*start == NULL){
		cout<<endl<<"List is empty.....";
		return;
	}
		else if((*start)->data == data){
		
		Node* temp  = *start;
		
		if(*start = *last){
			*start = *last = NULL;
			delete temp;
			return;
		}
		else{
	
		*start = temp->next;
		(*start)->prev = NULL;
		delete temp;
		
		return;
	}
			
	Node* tep = (*start)->next;
	while(tep!=NULL ){
		
		
		if( tep->data= data){
			Node* loc = tep;
			
			if(loc->next=NULL){
				*last = (*last)->prev;
				(*last)->next = NULL;
				delete loc;
				return;
			}
			else{
				
				loc->prev->next = loc->next;
				loc->next->prev = loc->prev;
				delete loc;
				return;
				
				
			}}
			
		
		
		tep=tep->next;
		
	}
	
	  
    cout <<endl<< "Element not found in the list." << endl;
    return;
  }
	
}


  
//searching
void searching(Node** start, int data) {
	
		
	if(*start == NULL){
		cout<<endl<<"List is empty";
		return;
	}
	
	
  Node* temp = (*start)->next;

  while (temp != NULL && temp->data != data) {
    temp = temp->next;
  }
  
  if(temp==NULL){
  	cout<<endl<<"Item not found in list";
  }
else{

cout<<endl<<"Item found in the list" ;
return;}
}

//Display 

void traverse(Node* start) {
  if (start == NULL) {
    cout << "List is empty" << endl;
    return;
  }

  Node* temp = start;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
	
 Node* start = NULL;
 Node* last = NULL;

  int number, choice;
  char chr;

  do {
 
  
   cout<<"Press 1)Insertion			2)Deletion			3)search			4)Traverse"<<endl;
   
    cin >> choice;

switch(choice){

//Insertion

   case 1:{
    	
      cout << "Enter a number to insert: ";
      
      cin >> number;
      
      insert(&start,&last, number);
      break;
    } 
	
	//deletion
	
case 2: {
      cout << "Enter a number to delete: ";
      cin >> number;
      deletion(&start, &last, number);
      break;
    } 
    
    //Searching
    
  case 3: {
      cout << "Enter a number to search: ";
      cin >> number;
      searching(&start,number);
	  break;}
      
	  
	  //Traversing
	  
	  case 4:{
	  	
	  	cout<<endl<<"Your array is:  ";
	  traverse(start);
	  	break;
	  }
	  
	  default:{
      cout << "Invalid choice" << endl;
      break;
    }

}
    cout <<endl<< "Do you want to continue: (y/n): ";
    cin >> chr;
  } while (chr == 'y' || chr == 'Y');

  
  return 0;
}