//Q. Find the Transpose of a Matrix
// I/P: 1,2,3
//     4,5,6
//     7,8,9

// O/P : 1,4,7
//       2,5,8
//       3,6,9

#include <bits/stdc++.h>

using namespace std;

void transpose1(int arr[3][3], int col, int row){
    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++)
            swap(arr[i][j],arr[j][i]);
    }
}

void transpose2(int arr[3][3], int row, int col){
    for(int i=0;i<row;i++){
        for(int j=i+1;j<col;j++)
            swap(arr[i][j], arr[j][i]);
        cout<<endl;
    }
}

void printArray(int arr[3][3], int col, int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<arr[i][j]<<" ";
         cout<<endl;
    }
   
}

int main(){
    int arr1[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout<<"Transpose of Matrix 1 :"<<endl;
    transpose1(arr1,3,3);
    printArray(arr1,3,3);
    int arr2[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout<<"Transpose of Matrix 2 : ";
    transpose2(arr2,3,3);
    printArray(arr2,3,3);


}