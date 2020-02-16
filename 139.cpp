class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {      //动态规划、记忆化搜索
        unordered_set<string> help;
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(auto s:wordDict) help.insert(s);
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&help.find(s.substr(j,i-j))!=help.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
