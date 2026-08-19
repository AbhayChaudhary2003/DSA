
class Solution {
public:
    TreeNode*ans=NULL;
    void func(TreeNode*root,int val){
        if(root==NULL)
            return;
        if(root->val==val)
            ans = root;
        if(root->val>val)
            func(root->left,val);
        else
            func(root->right,val);
        return;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        func(root,val);
        return ans;
        
    }
};