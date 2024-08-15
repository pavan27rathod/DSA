#include<iostream>
using namespace std;

void printArrayRowWise(int arr[][4], int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<arr[i][j]<<"  ";
        cout<<endl;
    }
}

void printArrayColWise(int arr[][4], int row, int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++)
            cout<<arr[j][i]<<"  ";
        cout<<endl;
    }
}

int main(){
    int arr[][4]={
         {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout<<"Row wise Print : "<<endl;
    printArrayRowWise(arr,4,4);
    cout<<"Column Wise Print : "<<endl;
    printArrayColWise(arr,4,4);
}