#include"headFile.h"

// 二叉树最小深度
class MinDepth {
    int minDepth(TreeNode* head) {
        if (!head) {
            return 0;
        }
        return process(head, 1);
    }
    int process(TreeNode* head, int level) {
        if (!head->left && !head->right) {
            return level;
        }
        int ans = INT_MAX;
        if (head->left) {
            ans = min(ans, process(head->left, level + 1));
        }
        if (head->right) {
            ans = min(ans, process(head->right, level + 1));
        }
        return ans;
    }
};