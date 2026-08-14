
class Solution {
public:
    vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) {
        func(root);
        return ans;
        
    }
    void func(TreeNode*node){
        if(node==NULL){
            return;
        }
        func(node->left);
        func(node->right);
        
        ans.push_back(node->val);
    }
};