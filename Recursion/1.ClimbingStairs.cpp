// Q. https://leetcode.com/problems/climbing-stairs/

int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;
        if(n==2)
            return 2;
        int ans= climbStairs(n-1)+climbStairs(n-2);
        return ans;
}