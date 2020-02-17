class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minspare=INT_MAX;
        int total=0;
        int index=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];

            if(total<minspare){
                index=i+1;
                minspare=total;
            }
        }
        return total<0?-1:(index==gas.size()?0:index);
    }
};

