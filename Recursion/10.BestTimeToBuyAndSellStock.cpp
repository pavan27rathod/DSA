//Q. https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

void findMaxProfit(vector<int>& prices,int i, int &minPrice, int &maxProfit){
        if(i>=prices.size())
            return;
        if(prices[i]<minPrice)
            minPrice=prices[i];
        int todaysProfit=prices[i]-minPrice;
        if(todaysProfit>maxProfit)
            maxProfit=todaysProfit;

        findMaxProfit(prices,i+1,minPrice,maxProfit);
}
int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;

        findMaxProfit(prices,0, minPrice, maxProfit);
        return maxProfit;
}