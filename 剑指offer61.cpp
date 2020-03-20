//不排序版本
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool m[15];
        memset(m, 0, sizeof(m));
        int minValue = 14, maxValue = 0;
        for (int item : nums) {
            if (item == 0) {
                continue;
            }
            if (m[item]) {
                return false;
            }
            m[item] = true;
            minValue = min(minValue, item);
            maxValue = max(maxValue, item);            
        }
        return maxValue - minValue + 1 <= 5;
    }
};

//排序版本
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int zeronum=0;
        int interval=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i]!=0&&nums[i]==nums[i-1]) return false;
            if(nums[i]==0){
                zeronum++;
            }else if(i!=0&&nums[i-1]!=0){
                interval+=(nums[i]-nums[i-1]-1);
            }
        }
        return zeronum>=interval;
    }
};
