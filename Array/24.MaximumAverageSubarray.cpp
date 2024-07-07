double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<k; i++) sum += nums[i];
        int maxSum = sum; // assuming max sum is the sum of first 'k' elements
        int left = 0;
        int right = k;
        while(right < nums.size()) { // sliding window
            sum = sum - nums[left]; // remove left element's value from sum
            left++; // shift left index
            sum = sum + nums[right]; // add right element's value to sum
            right++; // shift right index
            maxSum = max(maxSum, sum); // check if new sum is more than maxSum
        }
        return (double)maxSum / k; // return the average
        
        
    }