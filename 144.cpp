//迭代版本

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            if(root){
                res.push_back(root->val);
                s.push(root);
                root=root->left;
            }
            else{
                TreeNode* cur=s.top();
                s.pop();
                if(cur->right) root=cur->right;
            }
        }
        return res;
    }
};


//递归版本

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode* root)> dfs;
        dfs=[&](TreeNode* root){
            if(!root) return;
            res.push_back(root->val);
            dfs(root->left);
            dfs(root->right); 
        };
        dfs(root);
        return res;
    }
};
