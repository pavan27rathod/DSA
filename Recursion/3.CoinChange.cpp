//https://leetcode.com/problems/coin-change/description/

int solve(vector<int>& coins, int amount){
       if(amount==0)
            return 0;
       int ans=INT_MAX;
       int mini=INT_MAX;

       
       for (int i=0;i<coins.size();i++){
            int coin=coins[i];
            
            if(coin<=amount){
                int recAns=solve(coins, amount-coin);
                if(recAns!=INT_MAX){
                    ans=1+recAns;
                }
            }
            mini=min(ans, mini);
       }
       return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
       int ans=solve(coins, amount);
       if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }