//快速幂算法
class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        double X=x;
        long long N=n;
        if(n<0){
            X=1/x;
            N=-N;
        }
        while(N>0){
            if(N&1) res*=X;
            X*=X;
            N=N>>1;
        }
        return res;
    }
};
