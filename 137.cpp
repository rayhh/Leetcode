//每个int型整数只有sizeof(int)*8位，分别统计每一位出现的次数，寻找规律

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<sizeof(int)*8;i++){
            int mask=1<<i;
            int count=0;
            for(int j=0;j<nums.size();j++)
                if(nums[j]&mask) count++;
            if(count%3) res+=mask; 
        }
        return res;
    }
};
