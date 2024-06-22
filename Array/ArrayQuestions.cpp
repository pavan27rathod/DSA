#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void reverseArray(int arr[], int size){
  int j=size-1;
  int i=0;
  int temp;
  while(i<=j){
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
    
  }
}
void extremePrint(int arr[],int size){
  for(int i=0, j=size-1;i<=j;i++,j--){
    if(i==j){
      cout<<arr[i]<<"\t";
    }
    else{
      cout<<arr[i]<<"\t";
      cout<<arr[j]<<"\t";
      
    }
    
  }
}


void moveNegativeToOneSide(int arr[], int size) {
  int j = 0;
  int index;
  for (index = 0; index < size; index++) {
    if (arr[index] < 0) {
      swap(arr[index], arr[j]);
      j++;
    }
  }
}

void sortColors(vector<int> &nums) {
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int index = 0;
  while (index <= right) {
    if (nums[index] == 0) {
      swap(nums[index], nums[left]);
      index++;
      left++;
    } else if (nums[index] == 2) {
      swap(nums[index], nums[right]);
      right--;
    } else if (nums[index] == 1) {
      index++;
    }
  }
}

void rotateByK(int arr[], int size, int k) {
  int n = size;
  int ans[n];
  for (int index = 0; index < n; index++) {
    int newIndex = (index + k) % n;
    ans[newIndex] = arr[index];
  }
  for (int index = 0; index < n; index++) {
    arr[index] = ans[index]; // Copy elements back to the original array
  }
}

// int missingNumber(int arr[], int size) {
//   int sum = 0;
//   int n = size;
//   for (int index = 0; index < n; index++) {
//     sum = sum + arr[index];
//   }
//   int totalSum = ((n) * (n + 1)) / 2;
//   int ans = totalSum - sum;
//   return ans;
// }

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
  int n = mat.size();
  int oneCount = INT_MIN;
  int row = -1;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < mat[i].size(); j++) {
      if (mat[i][j] == 1) {
        count++;
      }
    }
    if (count > oneCount) {
      oneCount = count;
      row = i;
    }
  }
  ans.push_back(row);
  ans.push_back(oneCount);
  return ans;
}

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();

  // First find the transpose of a matrix
  for (int i = 0; i < n; i++) {
    for (int j = i; j < matrix[i].size(); j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Reverse the each row of a transposed matrix
  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

bool twoSum(int arr[], int size, int k) {
  sort(arr, arr + size);
  int l = 0, h = size - 1;
  while (l < h) {
    int cSum = arr[l] + arr[h];
    if (cSum == k)
      return true;
    else if (cSum > k)
      h--;
    else if (cSum < k)
      l++;
  }
  return false;
}

// int pivotIndex(int arr[], int size){
//   int pivotIndex(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> lsum(n, 0);
//     vector<int> rsum(n, 0);

//     // Calculate the prefix sums for the left and right sides
//     for (int i = 1; i < n; i++) {
//         lsum[i] = lsum[i - 1] + nums[i - 1];
//     }

//     for (int i = n - 2; i >= 0; i--) {
//         rsum[i] = rsum[i + 1] + nums[i + 1];
//     }

//     // Find the pivot index
//     for (int i = 0; i < n; i++) {
//         if (lsum[i] == rsum[i]) {
//             return i;
//         }
//     }

//     return -1;
// }
// }

int findDuplicate(vector<int> &nums) {
  // Brute Force

  // int n=nums.size();
  // sort(nums.begin(), nums.end());
  // for(int i=0;i<n;i++){
  //     if(nums[i]==nums[i+1])
  //         return nums[i];
  // }
  // return -1;

  // Negative Marking Method

  // int ans=-1;
  // int n=nums.size();
  // for(int i=0;i<n;i++){
  //     int index=abs(nums[i]);

  //     if(nums[index]<0){
  //          ans=index
  //          return index;
  //     }

  //     nums[index]*=-1;

  // }
  // return -1;

  // Positioning Method
  while (nums[0] != nums[nums[0]]) {
    swap(nums[0], nums[nums[0]]);
  }
  return nums[0];
}

int missingNumber(int nums[], int size) {
  int n = size;
  for (int i = 0; i < n; i++) {
    int index = abs(nums[i]);
    if (nums[index - 1] > 0)
      nums[index - 1] *= -1;
  }
  for (int i = 0; i < n; i++) {
    if (nums[i] > 0)
      return i + 1;
  }
}

int firstRepeating(int arr[], int size) {
  unordered_map<int, int> hash;
  for (int i = 0; i < size; i++) {
    hash[arr[i]]++;
  }
  for (int i = 0; i < size; i++) {
    if (hash[arr[i]] > 1)
      return i + 1;
  }
}

int removeDuplicates(vector<int> &nums) {
  int i = 1;
  int j = 0;
  while (i < nums.size()) {
    if (nums[i] == nums[j])
      i++;
    else {
      j++;
      nums[j] = nums[i];
      i++;
    }
  }
  return j + 1;
}

double findMaxAvg(int arr[], int size, int k) {
  int maxSum = INT_MIN;
  int i = 0;
  int j = k - 1;
  while (j < size) {
    int sum = 0;
    for (int y = i; y <= j; y++) {
      sum += arr[y];
    }
    maxSum = max(maxSum, sum);
  }
  double maxAvg = maxSum / (int)k;
  return maxAvg;
}
// Maximum Average Subarray ->
// 1. Brute Force Solution ->
// double bruteForce(vector<int>& nums, int& k){
//     int maxSum=INT_MIN;
//     int i=0;
//     int j=k-1;
//     while(j<nums.size()){
//         int sum=0;
//         for(int y=i;y<=j;y++){
//             sum +=nums[y];
//         }
//         maxSum=max(maxSum, sum);

//     }
//     double maxAvg=maxSum/(double)k;
//     return maxAvg;
// }
// Maximum Average Subarray ->
// 2. Sliding Window Technique ->
double slidingWindowSolution(int nums[], int size, int k) {
  int i = 0;
  int j = k - 1;
  int sum = 0;
  for (int y = i; y <= j; y++) {
    sum += nums[y];
  }
  int maxSum = sum;
  j++;
  // while(j<nums.size()){
  //    sum+=nums[i++];
  //    sum+=nums[j++];
  //     maxSum=max(maxSum, sum);
  // }
  while (j < size) {
    // Update the sum by subtracting the element that's no longer in the window
    // (nums[i]) and adding the element that's now in the window (nums[j])
    sum = sum - nums[i] + nums[j];

    maxSum = max(maxSum, sum);

    // Move the window to the right
    i++;
    j++;
  }
  double maxAvg = maxSum / (double)k;
  return maxAvg;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void print(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";
  cout << endl;
}

void reverseArray(int arr[], int size) {
  int i = 0;
  int j = size - 1;
  while (i <= j) {
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
}

int getUniqueBruteForce(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (arr[i] == arr[j])
        count++;
    }
    if (count == 1)
      return arr[i];
  }
  return -1;
}

void pairs(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << arr[i] << " ";
      cout << arr[j] << endl;
    }
  }
}

void sortZeroAndOnes(int arr[], int size) {
  int zeroCount = 0;
  int oneCount = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == 0)
      zeroCount++;
    if (arr[i] == 1)
      oneCount++;
  }
  for (int i = 0; i < zeroCount; i++) {
    arr[i] = 0;
  }
  for (int j = zeroCount; j < size; j++)
    arr[j] = 1;
}

void shiftElementsByOne(int arr[], int size) {
  int last = arr[size - 1];
  // arr[0]=last;
  // int first=arr[0];
  for (int i = size - 1; i > 0; i--) {
    arr[i] = arr[i - 1];
  }
  arr[0] = last;
}

void shiftElementByOneLeft(int arr[], int size) {
  int first = arr[0];
  for (int i = 0; i < size; i++) {
    arr[i] = arr[i + 1];
  }
  arr[size - 1] = first;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << "\t";
}

void printArray(int arr[][3], int row, int col){
  for(int i=0;i<col;i++){
    for(int j=0;j<row;j++){
      cout<<arr[i][j]<<"  ";
    }
    cout<<endl;
  }
}

void sumRowWise(int arr[][3], int row, int col){
  for(int i=0;i<row;i++){
    int sum=0;
    for(int j=0;j<col;j++){
      sum=sum+arr[i][j];
    }
    cout<<sum<<endl;
  }
}

void sumColWise(int arr[][3], int row, int col){
  for(int i=0;i<col;i++){
    int sum=0;
    for(int j=0;j<row;j++){
      sum=sum+arr[j][i];
    }
    cout<<sum<<endl;
  }
}

void printDiagonalSum1(int arr[][3], int row, int col){
  int sum=0;
  for(int i=0;i<col;i++){
    sum=sum+arr[i][i];
  }
  cout<<sum<<endl;
}

void printDiagonalSum2(int arr[][3], int row, int col){
  int sum=0;
  for(int i=col-1;i>=0;i--){
    sum=sum+arr[i][i];
  }
  cout<<sum<<endl;
}

void transposeMatrix(int arr[][3], int row, int col){
  for(int i=0; i<row; i++){
    for(int j=i+1; j<col; j++){ // Notice the change here
       swap(arr[i][j], arr[j][i]);
    }
  }
}


int main() {
  // int arr[] = {-1, 2, -3, 4, -5, 6, -8, -10};
  // moveNegativeToOneSide(arr, 8);
  // printArray(arr, 8);

  // vector<int> nums = {0, 1, 2, 0, 1, 2, 0, 1, 1, 0};
  // sortColors(nums);
  // print(nums);

  //   int arr[] = {1, 2, 4, 5};
  //   // rotateByK(arr, 5, 2);
  //   // printArray(arr, 5);
  //   // int missing = missingNumber(arr, 4);
  //   // cout << missing;
  //   int arr2[] = {1, 4, 6, 8, 10};
  //   int ans = twoSum(arr2, 5, 16);
  //   cout << ans;

  // int arr[]={1,2,3};
  // int pivot=pivotIndex(arr,3);
  // cout<<"Pivot Index :"<<pivot;

  // int arr[] = {0, 2, 4, 3, 5, 3};
  // // int missing=missingNumber(arr,5);
  // // cout<<missing;
  // int repeat = firstRepeating(arr, 5);
  // cout << repeat;

  int arr[] = {1, 12, -5, -6, 50, 3};
  double avg = slidingWindowSolution(arr, 6, 4);
  cout << "Maximum Avg -> " << avg;

   int arr[]={1,2,3,4,5};
  // reverseArray(arr, 5);
  // printArray(arr,5);
  extremePrint(arr,5);

  // int arr[]={1,2,3,4,5};
  // reverseArray(arr,5);
  // printArray(arr,5);

  // int arr2[]={1,1,2,3,4,5,3,4,5,2,8};
  // getUniqueBruteForce(arr2,9);
  // int unique=getUniqueBruteForce(arr2, 11);
  // cout<<unique;

  // int arr3[]={10,20,30};
  // pairs(arr3,3);

  // int arr4[]={0,1,1,0,1,0,0,1};
  // sortZeroAndOnes(arr4,8);

  int arr5[] = {10, 20, 30, 40, 50, 60};
  // shiftElementsByOne(arr5, 6);
  shiftElementByOneLeft(arr5, 6);
  printArray(arr5, 6);

   int arr[][3]={
  {1,2,3},
  {4,5,6},
  {8,8,9}
  };

//   transposeMatrix(arr,3,3);
//   printArray(arr,3,3);
}
