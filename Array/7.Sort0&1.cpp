//Q. Sort zeros and ones in given array. Array consists only of 0 & 1
#include <iostream>
#include <algorithm>
using namespace std;

//1. Count & Fill method -> O(n)
void sortZerosOnes(int arr[], int size){
    int zeroCount=0;
    int oneCount=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)
            zeroCount++;
        if(arr[i]==1)
            oneCount++;
    }
    for(int i=0;i<zeroCount;i++)
        arr[i]=0;
    for(int i=zeroCount; i<size;i++)
        arr[i]=1;
}

//2. Two Pointers

void sortUsingPointers(int arr[], int size){
    int i=0,j=size-1;
    while(i<j){
        //First i must reach to the element 1
        while(arr[i]==0 && i<j)
            i++;
        //Similarlt j must reach to element 0
        while (arr[j]==1 && i<j)
            j--;

        //Now both i & j pointers are at element 1 & 0 respectively, swap arr[i] with arr[j] and i++, j--
        if(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
}

//3. Using sort() function
void sortUsingSort(int arr[], int size){
    sort(arr,arr+size);
}


void printArray(int arr[], int size){
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[]={1,0,1,0,1,0,1,0,0,0,0,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Using Count & Fill: ";
    sortZerosOnes(arr, size);    
    printArray(arr,size);
    cout<<endl;
    cout<<"Using Two Pointers: ";
    sortUsingPointers(arr, size);
    printArray(arr,size);
    cout<<"Using Sort function :";
    sortUsingSort(arr, size);
    printArray(arr,size);

}