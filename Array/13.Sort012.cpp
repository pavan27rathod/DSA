//Q. Given array consists of 0,1&2. Sort the array without using any sorting algo
//I/P : {2,0,2,1,1,0}
//O/P: {0,0,1,1,2,2}
//Leetcode Sort Colors problem : https://leetcode.com/problems/sort-colors/
//GfG Dutch National Flag Problem 

#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[], int size){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)
            zeroCount++;
        else if(arr[i]==1)
            oneCount++;
        else if(arr[i]==2)
            twoCount++;
    }
    for(int i=0;i<zeroCount;i++)
        arr[i]=0;
    for(int i=zeroCount;i<zeroCount+oneCount;i++)
        arr[i]=1;
    for(int i=zeroCount+oneCount;i<size;i++)
        arr[i]=2;
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}

int main(){
    int arr[]={2,0,2,1,1,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    sort012(arr,size);
    printArray(arr,size);
}