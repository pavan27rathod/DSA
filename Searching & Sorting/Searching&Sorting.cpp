#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
  int start = 0;
  int end = size - 1;
  // Scope of improvement in following formula
  int mid = (start + end) / 2;
  while (start <= end) {
    if (target == arr[mid])
      return mid;
    else if (target > arr[mid])
      start = mid + 1;
    else if (target < arr[mid])
      end = mid - 1;
    // Don't forget to update mid after every iteration
    mid = (start + end) / 2;
  }
  return -1;
}

int firstOccurance(int arr[], int size, int target) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end) {
    if (arr[mid] == target) {
      ans = mid;
      end = mid - 1;
    } else if (target > arr[mid])
      start = mid + 1;
    else if (target < arr[mid])
      end = mid - 1;
    mid = start + (end - start) / 2;
  }
  return ans;
}

int lastOccurance(int nums[], int size, int target) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end) {
    if (nums[mid] == target) {
      ans = mid;
      start = mid + 1;
    } else if (target > nums[mid])
      start = mid + 1;
    else if (target < nums[mid])
      end = mid - 1;
    mid = start + (end - start) / 2;
  }
  return ans;
}

int totalOccurance(int nums[], int size, int target) {
  int total = lastOccurance(nums, size, target) -
              firstOccurance(nums, size, target) + 1;
  return total;
}

// Missing element in a sorted array of 1 to n ->
int missingElement(int nums[], int size) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end) {
    int difference = nums[mid] - mid;
    if (difference == 1)
      start = mid + 1;
    else {
      ans = mid;
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  //If the last element is missing 
  if (ans + 1 == 0)
    return size + 1;
  return ans + 1;
}

// Find Pivot Element
int pivotIndex(int arr[], int size) {
  int s = 0;
  int e = size - 1;
  int mid = s + (e - s) / 2;
  int ans = -1;
  while (s <= e) {
    if (s == e)
      return s;
    // mid-1 should not go out of range of array
    else if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
      return mid - 1;
    // mid+1 should not go out of range of array
    else if (mid + 1 < size && arr[mid] > arr[mid + 1])
      return mid;
    else if (arr[s] > arr[mid])
      e = mid - 1;
    else
      s = mid + 1;
    mid = s + (e - s) / 2;
  }
  return ans;
}

int mySqrt(int x) {
  int s = 0;
  int e = x;
  long long int mid = s + (e - s) / 2;
  int ans = -1;
  while (s <= e) {
    if (mid * mid == x)
      return mid;
    else if (mid * mid > x) {
      e = mid - 1;
    } else {
      ans = mid;
      s = mid + 1;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

int divide(int dividend, int divisor) {
  int s = 0;
  int e = abs(dividend);
  int mid = s + (e - s) / 2;
  int ans = -1;
  while (s <= e) {
    if (mid * abs(divisor) == abs(dividend))
      ans = mid;
    else if (mid * abs(divisor) > abs(dividend))
      e = mid - 1;
    else {
      ans = mid;
      s = mid + 1;
    }

    mid = s + (e - s) / 2;
  }
  if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
    return ans * (-1);
  if (dividend == 0)
    return -1;
  return ans;
}

int searchNearlySorted(int arr[], int size, int target){
  int s = 0;
  int e = size-1;
  int mid = s+ (e-s)/2;
  while(s<=e){
    if(target==arr[mid-1] && mid-1>=0)
      return mid-1;
    else if(target==arr[mid])
      return mid;
    else if(target==arr[mid+1] && mid+1<size)
      return mid+1;
    else if(target<arr[mid])
      e=mid-2;
    else if(target>arr[mid+1])
      s=mid+2;
    mid= s + (e-s)/2;
  }
  return -1;
}

//Find odd occuring element
int oddOccuringElement(int arr[], int size){
  int s=0;
  int e=size-1;
  int mid = s+(e-s)/2;
  int ans=-1;
  while(s<=e){
    if(s==e)
      return s;

    //if mid is appearing on odd index
    if(mid&1){
      if(arr[mid]==arr[mid-1])
        s=mid+1;
      else{
        ans=mid
      }
      
    }
    else{
      
    }
  }
}

int main() {
  // int arr[]={10,20,30,30,30,30,30,40,40,40,70,80,90,100};
  // cout<<"Enter the no you want to find : ";
  // int target;
  // cin>>target;
  // int ans=binarySearch(arr, 10, target);
  // if(ans==-1)
  //   cout<<"No such element";
  // else
  //   cout<<"Element found at index : "<<ans;

  // int first=firstOccurance(arr, 14, 30);
  // int last=lastOccurance(arr, 14, 30);
  // cout<<"First Occurance of 30 is at Index -> "<<first;
  // cout<<endl;
  // cout<<"Last Occurance of 30 is at Index -> "<<last;
  // cout<<endl;
  // int total=totalOccurance(arr, 14, 30);
  // cout<<"Total Occurance of 30 -> "<<total;

  // Missing Element in a sorted array ->
  //  int arr[]={1,2,3,4,5,6,7,8};
  //  int ans=missingElement(arr, 8);
  //  cout<<"Missing Element -> "<<ans;

  // Pivot element ->
  // int arr[] = {2, 4, 6, 8, 10};
  // int ans = pivotIndex(arr, 5);
  // cout << "Pivot Element -> " << ans;

  //Divide ->
  // int ans=divide(35, 7);
  // cout<<ans;

 // Binary search in nearly sorted array ->
  int arr[]={20,10,30,50,40,70,60};
  int target=60;
  int targetIndex= searchNearlySorted(arr, 7, target);
  if (targetIndex==-1){
    cout<<"No such element";
  }    
  else
    cout<<"Element found at : "<<targetIndex;

  
}