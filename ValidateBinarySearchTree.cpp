#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void addElemants(std::vector<int> sequence, TreeNode* node) {
    if (node) {
        if (node->left)
            sequence.insert(sequence.begin(), node->left->val);
        sequence.push_back(node->val);
        if (node->right)
            sequence.push_back(node->right->val);
    }  
};

bool isValidBST(TreeNode* root) {
    std::vector<int> sequence;

    addElemants(sequence, root);

    for (size_t i = 1; i < sequence.size(); i++)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;

    for (size_t i = 1; i < sequence.size(); i++) {
        if (sequence[i] <= sequence[i - 1])
            return false;
    }
    return true;        
}

int main() {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = {5, 6, 7, 8};
    std::vector<int> v;

    v.insert(v.begin(), 1);
    v.push_back(2);
    v.push_back(3);

    v.insert(v.begin(), 4);
    v.push_back(5);
    v.push_back(6);

    for (size_t i = 0; i < v.size(); i++)
            std::cout << v[i] << " ";

    TreeNode* root;
    std::vector<std::string> tree = {"5", "1", "4", "null", "null", "3", "6"};

    // for (size_t i = 0; i < tree.size(); i++) {

    // }
    root->val = 5;
    *root->left = TreeNode(1);
    *root->right = TreeNode(4);
    *root->right->left = TreeNode(3);
    *root->right->right = TreeNode(6);
    
    std::cout << std::boolalpha << isValidBST(root) << std::endl;
    return 0;
}