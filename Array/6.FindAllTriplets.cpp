//Q. Find all the triplets from the given array
#include<iostream>
using namespace std;

void printTriplets(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
            }
        }
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    printTriplets(arr, size);
    return 0;

}