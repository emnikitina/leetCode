#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


int treeHeight(TreeNode* root) {
    int l, r;
    
    if (!root)
        return 0;
    l = treeHeight(root->left);
    r = treeHeight(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;
    return std::max(l, r) + 1;
};
    

bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
    int l, r;
    l = treeHeight(root->left);
    r = treeHeight(root->right);
    if (l != -1 && r != -1 && abs(l - r) < 2)
        return true;
    return false;        
}

int main(int argc, char** argv) {

    TreeNode* node = NULL;
    size_t l = 1, r = 2;

    std::cout << "max: " << std::max(0, 0) << std::endl;

    for (size_t i = 1; i < argc; i++) {
        if (i == 1 && argv[i] == "nullptr")
            node = nullptr;
        else {
            
        }
    }
    std::cout << "balanced: " << isBalanced(node);
    
    return 0;
}