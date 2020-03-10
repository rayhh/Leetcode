class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<2) return s;
        int res=1, ll=0, rr=0;
        for(int i=0;i<s.length();i++){
            int l=i-1;
            int r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){    //回文子串中心为单字母的情况
                if(r-l+1>res){
                    res=r-l+1;
                    rr=r;
                    ll=l;
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){    //回文子串中心为双字母的情况
                if(r-l+1>res){
                    res=r-l+1;
                    rr=r;
                    ll=l;
                }
                l--;
                r++;
            }

        }
        return s.substr(ll,rr-ll+1);
    }
};
