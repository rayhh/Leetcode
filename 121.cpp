class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //维护两个变量
        int max=0;     //迄今为止的最大收益
        int minprice=INT_MAX;     //到目前为止能够买入的最低价格
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minprice) minprice=prices[i];
            if(prices[i]-minprice>max) max=prices[i]-minprice;
        }
        return max;
    }
};
