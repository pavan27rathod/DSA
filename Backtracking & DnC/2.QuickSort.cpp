#include<iostream>
using namespace std;

// Original:       [9, 1, 4, 0, 33, 5]
// First Pivot:                5
//                        /        \
// Left Subarray: [1, 4, 0]         [33, 9] (Right Subarray)
//                 |                 |
//    Pivot:       0                 9
//             /      \            /   \
//   [0]       [1, 4]     |      [9]   [33]
//                       Pivot:  4



void quickSort(int arr[], int s, int e){
    if(s>=e)
        return;
    int i=s-1;
    int j=s;
    int pivot=e;

    while(j<pivot){
        if(arr[j] < arr[pivot]){
            ++i;
            swap(arr[j],arr[i]);
        }
        j++;
    }
    ++i;
    swap(arr[i], arr[j]);
    quickSort(arr,s,i-1);
    quickSort(arr,i+1,e);
}
int main(){
    int arr[]={9,1,4,0,33,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int s=0;
    int e=size-1;
    cout<<"Before Quick Sort : "<<endl;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    quickSort(arr,s,e);
    cout<<"After Quick Sort : "<<endl;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
}