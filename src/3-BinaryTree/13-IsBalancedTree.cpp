#include"headFile.h"

// 判断平衡二叉树
// 任何一个节点的左右子树高度差不超过1
class IsBalancedTree {
public:

    class Info {
    public:
        int height;
        bool isBalanced;
        Info(int h, bool is) {
            height = h;
            isBalanced = is;
        }
    };

    bool isBalancedTree(TreeNode* head) {
        return process(head).isBalanced;
    }

    Info process(TreeNode* head) {
        if (head == NULL) {
            return Info(0, true);
        }
        Info leftInfo = process(head->left);
        Info rightInfo = process(head->right);
        int height = 0;
        bool isBalanced = true;
        height = 1 + max(leftInfo.height, rightInfo.height);
        if (!leftInfo.isBalanced || !rightInfo.isBalanced
            || abs(leftInfo.height - rightInfo.height) > 1) {
            isBalanced = false;
        }
        return Info(height, isBalanced);
    }

};