#include<iostream>
#include<climits>
using namespace std;

int maximum(int arr[][4], int row, int col){
    int max=INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]>max)
                max=arr[i][j];
        }
    }
    return max;
}

int main(){
    int arr[][4]={
         {133, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 1155, 12},
        {13, 14, 15, 16}
    };

    cout<<"Maximum  Element : "<<maximum(arr,4,4);
}