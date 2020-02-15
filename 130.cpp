class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m=board.size();
        if(m==0) return;
        const int n=board[0].size();
        if(n==0) return;
        function<void(int, int)> dfs=[&](int x, int y){     //创建一个函数dfs，用于搜素与传入参数节点连通的'O',并将其标记为G
            if(x<0||x>=m||y<0||y>=n||board[x][y]!='O') return;
            board[x][y]='G';
            dfs(x-1,y);
            dfs(x+1,y);
            dfs(x,y-1);
            dfs(x,y+1);
        };                         

        for(int i=0;i<n;i++)         //两个一重循环搜索与边界上的'O'相连通的O，并将所有与边界连通(包括边界上的'O')的'O'标记成'G'
            dfs(0,i), dfs(m-1,i);
        for(int j=0;j<m;j++)
            dfs(j,0), dfs(j,n-1);
    
        map<char,char> help={{'G','O'},{'O','X'},{'X','X'}};    //创建map用于确定二维遍历时的元素修改策略
        for(int i=0;i<m;i++)                                    //修改board
            for(int j=0;j<n;j++)
                board[i][j]=help[board[i][j]];
    }
};
