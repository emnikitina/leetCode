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

// 30ms
/* void addElemants(std::vector<int>* sequence, TreeNode* node) {
    if (node) {
        if (node->left)
            addElemants(sequence, node->left);
        sequence->push_back(node->val);
        if (node->right)
            addElemants(sequence, node->right);
    }  
};

bool isValidBST(TreeNode* root) {
    std::vector<int> sequence;

    addElemants(&sequence, root);
    for (size_t i = 1; i < sequence.size(); i++) {
        if (sequence[i] <= sequence[i - 1])
            return false;
    }
    return true;      
}*/


// 35ms
TreeNode* findMin(TreeNode* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

TreeNode* findMax(TreeNode* node) {
    while (node && node->right)
        node = node->right;
    return node;
}

bool isValidBST(TreeNode* root) {
    if (root) {
        if ((root->left && findMax(root->left)->val >= root->val) || (root->right && findMin(root->right)->val <= root->val))
            return false;
        if (!isValidBST(root->left) || !isValidBST(root->right))
            return false;
    }
    return true;
}

void printTree(TreeNode* root) {
    if (root) {
        if (root->left)
            printTree(root->left);
        std::cout << root->val << " ";
        if (root->right)
            printTree(root->right);
    }
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

    // for (size_t i = 0; i < v.size(); i++)
    //         std::cout << v[i] << " ";

    /*TreeNode root(5), r(4), l(1), rr(6), rl(3);
    std::vector<std::string> tree = {"5", "1", "4", "null", "null", "3", "6"};
    root.left = &l;
    root.right = &r;
    root.right->left = &rl;
    root.right->right = &rr;*/

    TreeNode root(2), r(3), l(1);
    root.left = &l;
    root.right = &r;

    std::cout << "print tree: \n";
    printTree(&root);
    std::cout << std::endl;
    
    std::cout << std::boolalpha << isValidBST(&root) << std::endl;
    return 0;
}