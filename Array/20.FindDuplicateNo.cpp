// Leetcode : https://leetcode.com/problems/find-the-duplicate-number/description/

#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {

        // int size=nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<size;i++){
        //     if(nums[i]==nums[i+1])
        //         return nums[i];
        // }
        // return -1;

        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }