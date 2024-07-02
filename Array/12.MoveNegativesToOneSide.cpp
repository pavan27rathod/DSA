//Q. Move all negative elements to one side of an array
//I/P: {-1,2,-3,4,-5,6,-7,-8,-10}
//O/P: {-1,-3,-5,-7,-8,-10,2,4}
//We do not have to keep track of sequence

#include<bits/stdc++.h>
using namespace std;

void moveNegatives(int arr[], int size){
    int j=0; //j to keep track of the position where the next negative element should be moved to
    for(int i=0;i<size;i++){
        if(arr[i]<0){
            swap(arr[i],arr[j]);
            j++;
        }
       
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={1,-2,-3,4,-5};
    int size=sizeof(arr)/sizeof(arr[0]);
    moveNegatives(arr,size);
    printArray(arr,size);

}