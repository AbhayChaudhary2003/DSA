class Solution {
public:
    vector<int> temp;

    void fun(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }

        fun(root->left, k);
        temp.push_back(root->val);
        fun(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        fun(root, k);

        int n = temp.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (temp[i] + temp[j] == k) {
                    return true;
                }
            }
        }

        return false;
    }
};