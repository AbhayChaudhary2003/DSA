
class Solution {
public:
    bool res = false;
    void fun(TreeNode*root, int targetSum, int sum){
        if(root==NULL){
            return;
        }
        sum = sum+root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                res = true;
            }
            return;
        }
        fun(root->left,targetSum,sum);
        fun(root->right,targetSum,sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        fun(root,targetSum,0);
        return res;
    }
};