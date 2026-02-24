#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int current) {
        if (root == NULL) return 0;
        current = (current << 1) | root->val;
        if (root->left == NULL && root->right == NULL) {
            return current;
        }
        return dfs(root->left, current) + dfs(root->right, current);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    
    Solution obj;
    
    int result = obj.sumRootToLeaf(root);
    
    cout << "Sum of Root to Leaf Binary Numbers: " << result << endl;
    
    return 0;
}