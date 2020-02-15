class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i = 0;i < s.length();i++)//变大写 忽略除了字母或者数组以外的
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
            if((s[i] >='A' && s[i] <='Z') || (s[i] >= '0' && s[i] <= '9'))
             str += s[i];

        }
//双指针
        int l = 0;
        int r = str.length() - 1;
        while(l < r)
        {
            if(str[l] != str[r])
            return false;
            l++;
            r--;
        }
        return true;
    }
};
