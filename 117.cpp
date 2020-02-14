//我的垃圾解法
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node* tmp=root;
        while(tmp){
            if(tmp->right)
                if(tmp->left) tmp->left->next=tmp->right;
            if((tmp->left&&!tmp->right)||tmp->right){
                Node* node=tmp->right?tmp->right:tmp->left;
                Node* cur=tmp->next;
                while(cur){
                    if(cur->left||cur->right) break;
                    cur=cur->next;
                }
                if(cur) node->next=cur->left?cur->left:cur->right;
            }
            tmp=tmp->next;
        }

        connect(root->left);
        connect(root->right);
        return root;
    }
};


//大神解法，先遍历右子树，然后遍历左子树

class Solution {
public:
    Node* connect(Node* root) {
        if(root and (root->left or root->right)){
            if(root->left and root->right) root->left->next = root->right;
            
            Node *node = root->right ? root->right : root->left;
            Node *head = root->next;
            while (head and not (head->left or head->right)){
                head = head->next;
            }
            node->next = head ? (head->left ? head->left : head->right) : nullptr;
            
            connect(root->right);
            connect(root->left);
        }
        return root;
    }
};

