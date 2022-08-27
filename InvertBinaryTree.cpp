#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void changeChildren(TreeNode* node) {
    if (!node)
        return;
    TreeNode *tmp = node->right;
    
    node->right = node->left;
    node->left = tmp;        
};


TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root->right);
        invertTree(root->left);
        changeChildren(root);
    }        
    return root;
};

int main(int argc, char** argv) {
    if (argc == 2)
        cout << "rearrange spaces text: |" << invertTree() << "|\n";
    return 0;
}