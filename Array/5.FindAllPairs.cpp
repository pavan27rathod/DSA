//Q. Find all pairs in given array
#include<iostream>
using namespace std;

void printAllPairs(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0;j<size;j++){
            cout<<arr[i]<<" "<<arr[j]<<",";
            cout<<endl;
        }          
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    printAllPairs(arr,size);
}