#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
    //break into 2 arrays from mid
    int mid=(s+e)/2;

    //Get the length of both left & right array
    int lenLeft=mid-s+1;
    int lenRight=e-mid;

    //create left & right temporary arrays in heap memory
    int *left=new int[lenLeft];
    int *right=new int[lenRight];

    //copy values from original given array
    //Left array
    int k=s;
    for(int i=0;i<lenLeft;i++){
        left[i]=arr[k];
        k++;
    }

    //Right array
    k=mid+1;
    for(int i=0;i<lenRight;i++){
        right[i]=arr[k];
        k++;
    }

    //Actual Merge Starts Now
    int leftIndex=0;
    int rightIndex=0;
    int mainArrayIndex=s ;// you will make mistake here, we are initializing with beginning of subarray

    //Put smaller element first
    while(leftIndex<lenLeft && rightIndex <lenRight){
        if(left[leftIndex]<right[rightIndex]){
            arr[mainArrayIndex]=left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex]=right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
     //2 corner cases
    //When left array is exhaust & some element are left in right array, then copy as it is
    while(rightIndex<lenRight){
        arr[mainArrayIndex]=right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    //when right array is exhaust & some elements are left in left array, copy as it is
        
    while(leftIndex<lenLeft){
        arr[mainArrayIndex]=left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    //delete temporary arrays
    delete[] left;
    delete[] right;

}

void mergeSort(int arr[],int s, int e){
    if(s>=e)
        return;
    //break into left & right array
    int mid=(s+e)/2;
    
    //recursion on left array
    mergeSort(arr,s,mid);

    //recursion on right array
    mergeSort(arr,mid+1,e);

    //Merge 2 sorted left & right arrays
    merge(arr,s,e);
}

int main(){
    int arr[]={38, 27, 43, 3, 9, 82, 10};
    int size=6;
    int s=0;
    int e=size-1;

    cout<<"Before merge sort : "<<endl;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
    
    mergeSort(arr,s,e);
    cout<<"\nAfter Merge Sort : "<<endl;

    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
}