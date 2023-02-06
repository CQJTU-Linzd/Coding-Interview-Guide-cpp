#include"headFile.h"

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& nodes) {

    }
    void Main() {
        int n;
        cin >> n;
        vector<int>nodes(n);
        for (int i = 0; i < n; i++) {
            cin >> nodes[i];
        }
        TreeNode* root = buildTree(nodes);
    }
};