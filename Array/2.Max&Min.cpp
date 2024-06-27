//Find maximum & minimum no in an array
#include<iostream>
#include<limits.h>
using namespace std;

int maximum(int arr[], int size){
    int max=INT_MIN; //storing minimum value of int and comparing every element in array with this variable,after iteration greatest elements will be assigned
    for(int i=0;i<size;i++){
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
int minimum(int arr[], int size){
    int min= INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<min)
        min=arr[i];
    }
    return min;
}

int max(int arr[], int size){  //using inbuilt function max to get greatest value in array
    int maxAns=INT_MIN;
    for(int i=0;i<size;i++){
        maxAns=max(maxAns,arr[i]);
    }
    return maxAns;
}

int min(int arr[], int size){  //using inbuilt function min to get lowest value in array
    int minAns=INT_MAX;
    for(int i=0;i<size;i++){
        minAns=min(minAns, arr[i]);
    }
    return minAns;
}

int main(){
    int arr[]={-2,4,-6,8,-10,12,14,-1};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum no in array is "<<maximum(arr,size)<<endl;
    cout<<"Minimum no in array is "<<minimum(arr,size)<<endl;
    cout<<"Maximum no in array is "<<max(arr,size)<<endl;
    cout<<"Minimum no in array is "<<min(arr,size)<<endl;

}