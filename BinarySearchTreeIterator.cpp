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

class BSTIterator {
private:
    TreeNode    _value;
    TreeNode*   _next;

public:
    BSTIterator(TreeNode* root){   
        TreeNode* node = root;

        while (node && node->left) {
            _next = node;
            node = node->left;
        }
        _value = *node;
    }
    
    int next() {
        if (_next) {
            _value.val = _next->val;
            _value.left = _next->left;
            _value.right = _next->right;
            _next = _value.right;
        }
        else
            return NULL;
        return _value.val;        
    }
    
    bool hasNext() {
        return (_next);        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */