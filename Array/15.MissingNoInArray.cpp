//Q. Find Missing No in array
//I/P:{9,6,4,2,3,5,7,0,1}  -> O/P: 8

//Find the sum of array elements & Find sum of all terms. Get difference sum of all terms - sum of array elements

#include<bits/stdc++.h>
using namespace std;
int getMissingNo(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++)
        sum=sum+arr[i];
    int sumOfTerms=(size*(size+1))/2; //Formula to find sum of all terms/ sum of all natural numbers
    int missingNo=sumOfTerms-sum;
    return missingNo;

}

int main(){
    int arr[]={9,6,4,2,3,5,7,0,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int missingNo=getMissingNo(arr,size);
    cout<<"Missing No: "<<missingNo;
}