#include <iostream>
#include <climits>
#include<vector>
using namespace std;

// Function to print the array from left to right
void printArray(int arr[], int size, int index) {
    if (index == size) {
        return;
    }
    cout << arr[index] << "\t";
    printArray(arr, size, index + 1);
}

// Function to print the array in reverse order (right to left)
void printArrayReverse(int arr[], int size, int index) {
    if (index < 0) {
        return;
    }
    cout << arr[index] << "\t";
    printArrayReverse(arr, size, index - 1);
}

// Function to search an element in the array
bool search(int arr[], int size, int index, int element) {
    if (index >= size)
        return false;
    if (arr[index] == element)
        return true;
    bool nextAns = search(arr, size, index + 1, element);
    return nextAns;
}

int minimum(int arr[], int size, int index, int &mini){
    if (index >= size) 
        return -1;
    mini=min(arr[index],mini);
    minimum(arr,size,index+1,mini);
    return mini;    
}

int maximum(int arr[], int size, int index, int &maxi){
    if (index >= size)
        return -1;
    maxi=max(arr[index],maxi);
    maximum(arr, size, index+1,maxi);
    return maxi;
    
}

void pushEvens(int arr[],int size, int index, vector<int> &ans){
    if(index>=size){}
        return ;
    if(arr[index]%2==0)
        ans.push_back(arr[index]);
    pushEvens(arr,size,index+1,ans);
}

bool checkSorted(int arr[], int size, int index){
    if(index>=size-1){
        //if index exceeds size, it means we have checked every element and it is sorted
        return true;
    }
        
    if(arr[index]<=arr[index+1]){
        bool ans=checkSorted(arr,size,index+1);
        return ans;
    }
    else
        return false;
}

int binarySearch(int arr[], int s, int e, int target){
    if(s>e){
        //Element not found 
        return -1;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==target)
        return mid;
    if(target>arr[mid])
        return binarySearch(arr,mid+1,e,target); //Search in right direction
    else    
        return binarySearch(arr,s,mid-1,target); //Search in left direction
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index=binarySearch(arr,0,size-1,6);
    cout<<"Element found at index "<<index;

    // if(checkSorted(arr,size,0))
    //     cout<<"Sorted...";
    // else
    //     cout<<"Not Sorted...";

    // vector <int> ans;

    // int mini=INT_MAX;
    // int maxi=INT_MIN;
    // cout<<"Minimum: "<<minimum(arr,size,0,mini)<<endl;
    // cout<<"Maximum: "<<maximum(arr,size,0,maxi);

    // pushEvens(arr,size,0,ans);
    // for(int i=0;i<ans.size();i++)
    //     cout<<ans[i]<<"  ";

    // cout << "Print Array: " << endl;
    // printArray(arr, size, 0);
    // cout << endl;

    // cout << "Print Array in reverse: ";
    // printArrayReverse(arr, size, size - 1);  // Start from last index to reverse print
    // cout << endl;

    // cout << "Element found? : " << (search(arr, size, 0, 4) ? "Yes" : "No") << endl;
}

