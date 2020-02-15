class Solution {
private:
    int cur;
    int sum;
    void dfs(TreeNode* root){
        cur=cur*10+root->val;
        if(!root->left&&!root->right) sum+=cur; 
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        cur/=10; 
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        cur=sum=0;
        dfs(root);
        return sum;
    }
};
