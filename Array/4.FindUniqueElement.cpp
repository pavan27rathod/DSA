//Q. Find 
#include<iostream>
using namespace std;

int uniqueElement(int arr[], int size){    //This method is not recommended as it is taking O(n^2) time complexity. use XOR method
    for(int i=0;i<size;i++){  
        int count=0;      //count must initialize to its base value when we progress further for another element
        for(int j=0;j<size;j++){            
            if(arr[i]==arr[j])
            count++;
        }
        if(count==1)
             return arr[i];      
    }
    return -1;
}

int uniqueElementXOR(int arr[], int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];

    }
    return ans;
}

int main(){
    int arr[]={2,10,11,10,2,13,15,13,15};
    int size= sizeof(arr)/sizeof(arr[0]);
    cout<<"Unique Element: "<<uniqueElement(arr,size)<<endl;
    cout<<"Unique Element with XOR : "<<uniqueElementXOR(arr,size);


}