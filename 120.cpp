class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(2, vector<int>(triangle.back().size(), 0));
        dp[0][0]=triangle[0][0];
        int cur=0;
        for(int i=1;i<triangle.size();i++){
            cur=1-cur;
            for(int j=0;j<triangle[i].size();j++){
                if(j==0) dp[cur][j]=dp[1-cur][j]+triangle[i][j];
                else if(j==triangle[i].size()-1) dp[cur][j]=dp[1-cur][j-1]+triangle[i][j];
                else dp[cur][j]=min(dp[1-cur][j-1],dp[1-cur][j])+triangle[i][j];
            }
        }
        return *min_element(dp[cur].begin(),dp[cur].end());
    }
};
