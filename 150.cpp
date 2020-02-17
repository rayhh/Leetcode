class Solution {
public:
    int evalRPN(vector<string>& tokens) {                          //栈
        int res=0;
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int rightop=s.top();
                s.pop();
                int leftop=s.top();
                s.pop();
                if(tokens[i]=="+") res=leftop+rightop;
                else if(tokens[i]=="-") res=leftop-rightop;
                else if(tokens[i]=="*") res=leftop*rightop;
                else res=leftop/rightop;
                s.push(res);
            }
            else s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};
