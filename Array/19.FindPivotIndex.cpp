//Q. Find Pivot index in an array : Leetcode : https://leetcode.com/problems/find-pivot-index/description/
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the
// sum of all the numbers strictly to the index's right.
//Input: nums = [1,7,3,6,5,6]
//Output: 3

#include<bits/stdc++.h>
using namespace std;

//Brute force solution
int pivotIndex(int arr[], int size){
    for(int i=0;i<size;i++){
        int leftSum=0,rightSum=0;
        for(int j=0;j<i;j++)
            leftSum+=arr[j];
        for(int j=i+1;j<size;j++)
            rightSum=rightSum+arr[j];
        if(leftSum==rightSum)
            return i;
    }
    return -1;
}

// Prefix sum approach
int pivotIndex2(int nums[], int size){
    int lsum[size];
    int rsum[size];
    // for(int i=1;i<size;i++)
    //     lsum[i]=lsum[i-1]+arr[i-1];
    // for(int i=size-2;i>=0;i--)
    //     rsum[i]=rsum[i+1]+arr[i+1];
    // for(int i=0;i<size;i++){
    //     if(lsum[i]==rsum[i])
    //         return i;
    // }
    // return -1;
    for(int i=1;i<size;i++)
            lsum[i]=lsum[i-1]+nums[i-1];
        for(int i=size-2;i>=0;i--)
            rsum[i]=rsum[i+1]+nums[i+1];
        for(int i=0;i<size;i++){
            if(lsum[i]==rsum[i])
                return i;
        }
         return -1;

}


int main(){
    int arr[]={1,7,3,6,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<pivotIndex(arr,size);
    cout<<endl;
    cout<<pivotIndex2(arr,size);
}