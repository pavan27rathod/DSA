#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(){
            this->prev=NULL;
            this->next=NULL;
        }
        Node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
        ~Node(){
            cout<<this->data<<" has been deleted..."<<endl;
        }
};

int findLength(Node* &head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    //If LL is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;

    }

    //If LL is not empty
    else{
        Node* newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    //If LL is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    //If LL is not empty
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    int len=findLength(head);
    //Insert at head or at position 1
    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }
    //Insert at tail
    else if(position>len){
        insertAtTail(head,tail,data);
        return;
    }
    //Insert at specified position
    else{
        Node* newNode=new Node(data);
        Node* prev=NULL;
        Node* curr=head;
        while(position!=1){
            prev=curr;
            curr=curr->next;
            position--;
        }

        prev->next=newNode;
        newNode->prev=prev;
        newNode->next=curr;
        curr->prev=newNode;
        return;
    }

        
}

void deleteNode(Node* &head, Node* &tail, int position){
    int len=findLength(head);
    //If LL is empty
    if(head==NULL){
        cout<<"Can't delete as Linked List is Empty...";
        return;
    }

    //If LL have single element
    else if(head==tail){
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }

    //Delete from head, position 1
    else if(position==1){
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
        
    }

    //Delete from tail
    else if(position==len){
        Node* prev=tail->prev;
        prev->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail=prev;
    }
    //Delete from specific position
    else{
        Node* curr=head;
        Node* prev=NULL;
        while(position!=1){
            prev=curr;
            curr=curr->next;
            position--;
        }

        Node* nextNode=curr->next;

        prev->next=nextNode;
        curr->prev=NULL;
        curr->next=NULL;
        nextNode->prev=prev;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
    Node* head=NULL;
    Node* tail=NULL;

    cout<<"Before Deletion : "<<endl;
    print(head);

    cout<<"After Deletion: "<<endl;
    // deleteNode(head, tail, 1);
    // deleteNode(head, tail, 1);
    deleteNode(head, tail, 3);
    print(head);

    
}