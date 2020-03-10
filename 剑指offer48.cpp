class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        if(len<2) return len;
        int r=0,l=0,Max=1;
        map<char,int> m;                   //用map存放s中字符最后一次出现的位置
        while(r<len){
            while(m[s[r]]>=1){             //更新左边界
                m.erase(s[l]);
                l++;
            }
            Max=max(Max,r-l+1);
            m[s[r]]++;
            r++;
        }
        return Max;
    }
};
