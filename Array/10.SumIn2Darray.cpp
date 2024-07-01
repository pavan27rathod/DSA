//Q. Find the sum row-wise & column-wise in 2D array

#include<iostream>
using namespace std;

void sumRowWise(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
    }
}

void sumColWise(int arr[][3],int row,int col){
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];
        }
        cout<<sum<<endl;
    }

}

int main(){
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout<<"Printing sum row-wise : "<<endl;
    sumRowWise(arr,3,3);
    cout<<"Printing sum column-wise :"<<endl;
    sumColWise(arr,3,3);
}