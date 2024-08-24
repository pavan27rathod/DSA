//Q. https://leetcode.com/problems/house-robber/

int solve(vector<int>& nums, int size, int index){
        if(index>=size)
            return 0;
        int opt1=nums[index] + solve(nums,size,index+2);
        int opt2=solve(nums,size,index+1);
        int ans=max(opt1,opt2);
        return ans;

    }
    int rob(vector<int>& nums) {
        int size=nums.size();
        int index=0;
        int ans=solve(nums,size,index);
        return ans;
    }