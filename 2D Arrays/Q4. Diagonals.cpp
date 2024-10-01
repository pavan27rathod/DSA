#include<iostream>
using namespace std;

void printDiagonals(int arr[][4], int row, int col){
    for(int i=0;i<row;i++){
        int j=i;
        cout<<arr[i][j]<<" ";
    }
}

int diagonalSum(int arr[][3], int row, int col) {
    int sum = 0;
    int minDim = min(row, col); // Handles non-square matrices

    for (int i = 0; i < minDim; i++) {
        // Primary diagonal condition
        sum += arr[i][i];
        
        // Secondary diagonal condition
        if (i < col && (row - 1 - i) < col) {
            sum += arr[i][col - 1 - i];
        }
    }

    return sum;
}


int main(){
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    // printDiagonals(arr,3,3);
    cout<<endl;
    cout<<"Sum : "<<diagonalSum(arr,3,3);
}