//用一个多余的节点存储数组中最后一个元素所对应的节点，即最后访问的一个节点

vector<int> postorderTraversal(TreeNode* root){
	vector<int> res;
	TreeNode* pre=nullptr;
	stack<TreeNode*> s;
	while(root||!s.empty()){
		if(root){
			s.push(root);
			root=root->left;
		}else{
			root=s.top();
			if(root->right&&root->right!=pre) root=root->right;
			else{
				res.push_back(root->val);
				pre=root;
				s.pop();
				root=nullptr;
			}
		}
	}
	return res;
}
