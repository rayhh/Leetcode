class Solution {
public:                   
    int maxProfit(vector<int>& prices) {    //尽可能多的交易，出现拐点就交易
        int max=0;
        int minprices=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(minprices>prices[i]) minprices=prices[i];
            if(prices[i]-minprices>0){
                if(i==prices.size()-1) max+=prices[i]-minprices;
                else if(prices[i+1]<prices[i]){
                    max+=prices[i]-minprices;
                    minprices=prices[i+1];
                }
            }
        }
        return max;
    }
};
