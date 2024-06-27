#include<iostream>
using namespace std;

int zeroCount(int arr[], int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)
        count++;
    }
    return count;
}

int oneCount(int arr[], int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1)
        count++;
    }
    return count;
}

int main(){
    int arr[]={1,2,3,1,0,1,0,1,2};
    int one=oneCount(arr,9);
    int zero=zeroCount(arr,9);
    cout<<"Total zeros: "<<zero<<endl;
    cout<<"Total ones: "<<one;

}