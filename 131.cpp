class Solution {        
private:

    bool isValid(string s){                       //判断是否是回文串
        return s==string(s.rbegin(),s.rend());
    }

    void dfs(string s, vector<vector<string>>& res, vector<string>& cur){      //回溯算法
        if(s==""){
            res.push_back(cur);
            return;
        } 
        for(int i=1;i<=s.length();i++){
            string str=s.substr(0,i);
            if(isValid(str)){
                cur.push_back(str);
                dfs(s.substr(i,s.length()-i),res,cur);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> res;
        dfs(s,res,cur);
        return res;
    }
};
