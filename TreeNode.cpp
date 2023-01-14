class TreeNode {
public:
    int val;
    bool save;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, bool s) {
        this->val = val;
        this->save = s;
        this->left = nullptr;
        this->right = nullptr;
    }
};
