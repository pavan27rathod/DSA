// Q.https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int size){
    int j=0;
    int i=1;
    while(i<size){
        if(arr[i]==arr[j])
            i++;
        else{
            j++;
            arr[j]=arr[i];
            i++;
        }
    }
    return j+1;
}
int main(){
    int arr[]={0,0,1,1,1,2,2,3,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    int n=removeDuplicates(arr,size);
    cout<<n;
 
}