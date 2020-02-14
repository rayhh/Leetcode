    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,0);
        res[0]=1;
        int pre,tmp;
        for(int i=0;i<=rowIndex;i++){
            for(int j=1;j<=i;j++){
                if(j==i) res[i]=1;
                else{
                    tmp=res[j];
                    res[j]=j==1?1+res[j]:pre+res[j];
                    pre=tmp;
                }
            }
        }
        return res;
    }
