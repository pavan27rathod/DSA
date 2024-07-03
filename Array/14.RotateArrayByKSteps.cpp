//I/P: {10,20,30,40,50,60}, k=2
//O/P: {50,60,10,20,30,40}

//Modulus method: Whenever we get the problems like rotate, reverse first try to solve with this modulus method then think of another solutions

#include<bits/stdc++.h>
using namespace std;

void rotateByK(int arr[], int size, int k){

    int arr2[size];
    for(int i=0;i<size;i++){
        int newIndex=(i+k)%size; // First find new index for every element of current array
        arr2[newIndex]=arr[i];  //Now push the element to the new index and new array
    }
    for(int i=0;i<size;i++)     //copying the elements from the temporary array arr2 back to the original array arr. 
        arr[i]=arr2[i];

}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"  ";
}


int main(){
    int arr[]={10,20,30,40,50,60};
    int size=sizeof(arr)/sizeof(arr[0]);
    rotateByK(arr, size, 2);
    printArray(arr, size);
}