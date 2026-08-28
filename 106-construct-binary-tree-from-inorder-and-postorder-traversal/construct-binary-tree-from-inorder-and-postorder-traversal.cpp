class Solution {
public:

    unordered_map<int, int> in;

    TreeNode* fun(vector<int>& inorder, vector<int>& postorder,
                  int inStart, int inEnd,
                  int postStart, int postEnd) {

        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        // Last element of postorder is root
        int rootValue = postorder[postEnd];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int id = in[rootValue];

        // Number of elements in left subtree
        int leftSize = id - inStart;

        // Construct left subtree
        root->left = fun(inorder, postorder,
                         inStart, id - 1,
                         postStart, postStart + leftSize - 1);

        // Construct right subtree
        root->right = fun(inorder, postorder,
                          id + 1, inEnd,
                          postStart + leftSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }

        return fun(inorder, postorder,
                   0, inorder.size() - 1,
                   0, postorder.size() - 1);
    }
};