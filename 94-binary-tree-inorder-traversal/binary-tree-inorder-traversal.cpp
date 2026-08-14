class Solution {
public:
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        func(root);
        return ans;
        
    }
    void func(TreeNode * node){
        if(node==NULL){
            return;
        }
    func(node->left);
    ans.push_back(node->val);
    func(node->right);
        return;

    }
    
};