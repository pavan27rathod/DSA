//Q. Create and print 2D array

#include<iostream>
using namespace std;

//Printing the 2D array as it is, row first
void print2Darray(int arr[4][3],int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void printColWise(int arr[4][3], int row, int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<arr[j][i]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int arr [4][3]={
        {10,20,30},
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int arr2 [3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    print2Darray(arr,4,3);

    cout<<"Printing Column wise : ";
    printColWise(arr,4,3);
}