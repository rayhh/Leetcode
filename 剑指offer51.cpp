class Solution {
private:
    vector<int> nums;
    int count;
    void mysort(int left, int right){
        if(left>=right) return;
        int mid=left+((right-left)>>1);
        mysort(left,mid);
        mysort(mid+1,right);
        merge(left,mid,right);
    }

    void merge(int left, int mid, int right){
        vector<int> tmp(right-left+1,0);
        int i=left;
        int j=mid+1;
        int index=0;
        while(i<=mid&&j<=right){
            if(nums[i]>nums[j]){
                tmp[index++]=nums[j++];
                count+=mid-i+1;                    //利用归并排序的部分有序性
            }
            else tmp[index++]=nums[i++];
        }
        while(i<=mid) tmp[index++]=nums[i++];
        while(j<=right) tmp[index++]=nums[j++];
        for(int i=0;i<tmp.size();i++) nums[left+i]=tmp[i];
    }

public:
    int reversePairs(vector<int>& nums) {
        count=0;
        this->nums=nums;
        mysort(0,nums.size()-1);
        return count;
    }
};
