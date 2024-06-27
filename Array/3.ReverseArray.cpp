#include<iostream>
using namespace std;

void reverseArray(int arr[], int size){
    int i=0;
    int j=size-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Current Array :";
    printArray(arr,size);
    reverseArray(arr,size);
    cout<<"\nReversed Array :";
    printArray(arr,size);
}