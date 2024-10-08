#include<iostream>
using namespace std;

//Define Node
class Node{
    public:
        int data;
        Node* next;

        //Default Constructor that initializes the node with 0 & null pointer
        Node(){
            this->data=0;
            this->next=NULL;
        }

        //Parametrize the constructor that initializes the node with given data and null pointer
        Node(int data){
            this->data=data;
            this->next=NULL;
        }

        //Deconstructor to check if the node has been deleted or not
        ~Node(){
            cout<<"Current Node "<<this->data <<" has been deleted...";
        }

};

// Function to find the length of the linked list
int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;  // move to next node
        len++;  // increment length
    }
    return len;
}

//Insert node at beginning i.e. at head position
void insertAtHead(Node* &head, Node* &tail, int data){
    //When the list is empty, head will point to null, so
    //1. Create new Node -> 2. Make that node head, & tail of list as there will only be only one element, if initially list is empty
    if(head==NULL){
        Node *newNode= new Node(data);
        head=newNode;
        tail=newNode;
    }

    //If the list is not empty then
    //1. Create new Node -> 2. Point new Node's next to head -> 3. make new node as head
    else{
        Node* newNode= new Node(data);
        newNode->next=head;
        head=newNode;
    }
}

//Insert node at end of list i.e. at tail position

void insertAtTail(Node* &head, Node* &tail, int data){
    //When the list is empty, head will point to null, so
    //1. Create new Node -> 2. Make that node head, & tail of list as there will only be only one element, if initially list is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    // If list is not empty
    // Create a new node, connect the current tail to it, and update the tail
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
}

//Insert at desired position
void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    int len=findLength(head);

     // If inserting at the head (position 1)
     if(position==1){
         insertAtHead(head,tail,data);
         return ;
     }

     // If inserting at a position greater than the length, insert at the tail
     else if(position>len){
        insertAtTail(head,tail,data);
        return;
     }

     //Insert at desired position
     else{
        Node* newNode=new Node(data);
        Node* prev=NULL;
        Node* curr= head; // start at head

        while(position !=1){
            prev=curr; //store curr node as prev
            curr=curr->next; //Move to next node
            position--; //Decrement position counter
        }
        //Insert new node between prev and curr
        newNode->next=curr;  // Link newNode to the current node
        prev->next=newNode;  // Link previous node to newNode

     }     
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";  // print current node's data
        temp = temp->next;  // move to next node
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    int len=findLength(head);
    //If the list is empty
    if(head==NULL){
        cout<<"Linked List is Empty, can't delete"<<endl;
        return;
    }

    //If the list contains only single element
    else if(head==tail){
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }   

    //Delete from head
    else if(position==1){
        //Create temp pointer pointing to head -> Make next node as head -> make temp->next=null -> delete temp node
        Node* temp=head;
        head=head->next; // OR head=temp->next, both are equally correct
        temp->next=NULL;
        delete temp;
        return;
    }

    //Delete from Tail 
    else if(position==len){
        //Make a temporary pointer prev & traverse till second last node -> point that second last node to null -> delete tail -> Make the second last node as tail
        Node* prev=head;
        while(prev->next != tail){
            prev=prev->next;
        }

        prev->next=NULL;
        delete tail;
        tail=prev;
        return;
    }

    //Delete from specific position
    else{
        Node* prev=NULL;
        Node* curr=head;
        while(position !=1){
            position--;
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return;
    }

}

int main() {
    Node* head = NULL;  // start with an empty list
    Node* tail = NULL;  // start with an empty list
    insertAtHead(head, tail, 40);  // Insert 20 at the head
    insertAtHead(head, tail, 30);  // Insert 50 at the head
    insertAtHead(head, tail, 20);  // Insert 60 at the head
    insertAtHead(head, tail, 10);  // Insert 90 at the head
    insertAtTail(head, tail, 50);  // Insert 77 at the tail

    print(head);  // Print the linked list
    cout << endl;

    deleteNode(head,tail,3);
    cout<<endl;
    print(head);

    return 0;
}