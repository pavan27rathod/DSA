//Q1. Shift element by one - Right Shift
//I/P: {1,2,3,4,5,6} -> O/P: {6,1,2,3,4,5}

//Q2. Shift element by one - Left Shift
//I/P: {1,2,3,4,5,6} -> O/P: {2,3,4,5,6,1}
#include<iostream>
using namespace std;

void rightShift(int arr[], int size){
    int temp=arr[size-1];
    for(int i=size-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=temp;
}

void leftShift(int arr[], int size){
    int temp = arr[0];
    for(int i=0; i<size;i++){
        arr[i]=arr[i+1];
    }
    arr[size-1]=temp;
}
void printArray(int arr[], int size){
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    rightShift(arr, size);
    printArray(arr, size);
    // leftShift(arr, size);
    // printArray(arr, size);
}