#include"headFile.h"

// 最大二叉搜索子树
class MaxBST {
public:

    // 法一 书上的
    class Info {
    public:
        TreeNode* maxBSTHead;
        int maxBSTSize;
        int min;
        int max;
        Info(TreeNode* h, int size, int mi, int ma) {
            maxBSTHead = h;
            maxBSTSize = size;
            min = mi;
            max = ma;
        }
    };

    TreeNode* getMaxBST1(TreeNode* head) {
        return process(head).maxBSTHead;
    }

    // 可能性一：最大二叉搜索子树来自head的左子树
    // 可能性二：最大二叉搜索子树来自head的右子树
    // 可能性三：head与它的左子树和右子树共同组成最大二叉搜索子树
    Info process(TreeNode* head) {
        if (head == NULL) {
            return Info(NULL, 0, INT_MAX, INT_MIN);
        }
        Info leftInfo = process(head->left);
        Info rightInfo = process(head->right);
        // 获取以head为头的整棵树的最小值
        int Min = min({ head->val, leftInfo.min, rightInfo.min });
        // 获取以head为头的整棵树的最大值
        int Max = max({ head->val, leftInfo.max, rightInfo.max });
        // 只考虑可能性一、二
        int maxSize = max(leftInfo.maxBSTSize, rightInfo.maxBSTSize);
        TreeNode* maxHead = leftInfo.maxBSTSize >= rightInfo.maxBSTSize
            ? leftInfo.maxBSTHead : rightInfo.maxBSTHead;

        // 判断是否存在第三种可能性
        if (leftInfo.maxBSTHead == head->left && rightInfo.maxBSTHead == head->right
            && head->val > leftInfo.max && head->val < rightInfo.min) {
            maxSize = leftInfo.maxBSTSize + 1 + rightInfo.maxBSTSize;
            maxHead = head;
        }
        return Info(maxHead, maxSize, Min, Max);
    }


    // 法二 自己写的
    class ReturnType {
    public:
        TreeNode* maxBSTHead;
        int maxBSTSize;
        int max;
        int min;
        bool isBST;
        ReturnType(TreeNode* head, int size, int ma, int mi, bool is) {
            maxBSTHead = head;
            maxBSTSize = size;
            max = ma;
            min = mi;
            isBST = is;
        }
    };

    TreeNode* getMaxBST2(TreeNode* head) {
        return f(head).maxBSTHead;
    }

    ReturnType f(TreeNode* head) {
        if (head == NULL) {
            return ReturnType(NULL, 0, INT_MIN, INT_MAX, true);
        }
        ReturnType leftInfo = f(head->left);
        ReturnType rightInfo = f(head->right);
        
        TreeNode* maxHead = NULL;
        int maxSize = 0;
        int Min = INT_MAX;
        int Max = INT_MIN;
        bool isBST = false;

        Min = min({ head->val, leftInfo.min, rightInfo.min });
        Max = max({ head->val, leftInfo.max, rightInfo.max });

        if (leftInfo.isBST && rightInfo.isBST
            && head->val > leftInfo.max && head->val < rightInfo.min) {
            isBST = true;
            maxHead = head;
            maxSize = leftInfo.maxBSTSize + 1 + rightInfo.maxBSTSize;
        } else {
            maxSize = max(leftInfo.maxBSTSize, rightInfo.maxBSTSize);
            maxHead = leftInfo.maxBSTSize >= rightInfo.maxBSTSize
                ? leftInfo.maxBSTHead : rightInfo.maxBSTHead;
        }
        return ReturnType(maxHead, maxSize, Max, Min, isBST);
    }
};