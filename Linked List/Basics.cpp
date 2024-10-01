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

int main() {
    Node* head = NULL;  // start with an empty list
    Node* tail = NULL;  // start with an empty list
    insertAtHead(head, tail, 20);  // Insert 20 at the head
    insertAtHead(head, tail, 50);  // Insert 50 at the head
    insertAtHead(head, tail, 60);  // Insert 60 at the head
    insertAtHead(head, tail, 90);  // Insert 90 at the head
    insertAtTail(head, tail, 77);  // Insert 77 at the tail
    insertAtPosition(head,tail,44,3);

    print(head);  // Print the linked list
    cout << endl;

    return 0;
}