
class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* g1first = NULL;
    TreeNode* g1second = NULL;
    TreeNode* g2first = NULL;
    TreeNode* g2second = NULL;
    int g1 = 0;
    void fun(TreeNode*root){
        if(root==NULL){
            return;
        }
        fun(root->left);
        if(prev==NULL){
            prev=root;
        }
        else{
            if(root->val<prev->val){
                if(g1==0){
                    g1first=prev;
                    g1second=root;
                    g1++;
                }
                else{
                    g2first = prev;
                    g2second = root;
                    g1++;
                }

                
            }
            prev = root;
        }
        fun(root->right);

    }




    void recoverTree(TreeNode* root) {
        fun(root);
        if(g1==1){
            swap(g1first->val,g1second->val);
        }
        else{
            swap(g1first->val,g2second->val);
        }
        return;
    }
};