//Q. GeeksForGeeks: https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/

#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int firstRepeating(int arr[], int size){
    for(int i=0;i<size;i++){
        if(arr[i]==arr[i+1])
         return i;
    }
    return -1;

}
//hashing

int firstRepeating2(int arr[], int size){
    unordered_map <int, int>  hash;
    for(int i=0;i<size;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        if(hash[arr[i]]>1)
            return i;
    }
}

int main(){
    int arr[]={1,5,3,2,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<firstRepeating(arr,size);
    cout<<endl;
    cout<<firstRepeating2(arr,size);
}