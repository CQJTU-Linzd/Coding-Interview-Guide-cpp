#include"headFile.h"

// ÅÐ¶ÏÊÇ·ñÎªËÑË÷¶þ²æÊ÷
class IsBST {
public:
    // MorrisÖÐÐò±éÀú
    bool isBST(TreeNode* head) {
        if (head == NULL) {
            return true;
        }
        bool res = true;
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        TreeNode* pre = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) { // ÓÐ×óº¢×Ó
                while (mostRight->right != NULL && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = NULL;
                }
            }
            if (pre != NULL && pre->val > cur->val) {
                res = false;
            }
            pre = cur;
            cur = cur->right;
        }
        return res;
    }

    // ÖÐÐòµÝ¹é
    bool res = true;
    TreeNode* pre = NULL;
    bool isBST2(TreeNode* head) {
        process(head);
        return res;
    }
    void process(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        process(head->left);
        if (pre != NULL && head->val <= pre->val) {
            res = false;
            return;
        }
        pre = head;
        process(head->right);
    }

    // µÝ¹éÌ×Â·
    class Info {
    public:
        int min;
        int max;
        bool isBST;
        Info() {}
        Info(int mi, int ma, bool is) {
            min = mi;
            max = ma;
            isBST = is;
        }
    };

    bool isBST3(TreeNode* head) {
        return jiejie(head).isBST;
    }

    Info jiejie(TreeNode* head) {
        if (head->left == NULL && head->right == NULL) {
            return Info(head->val, head->val, true);
        }
        Info leftInfo, rightInfo;
        if (head->left != NULL) {
            leftInfo = jiejie(head->left);
        }
        if (head->right != NULL) {
            rightInfo = jiejie(head->right);
        }
        int cmin = INT_MAX;
        int cmax = INT_MIN;
        bool isBST = true;
        if (head->left != NULL) {
            cmin = min({ cmin, head->val, leftInfo.min });
            cmax = max({ cmax, head->val, leftInfo.max });
            if (!leftInfo.isBST || leftInfo.max >= head->val) {
                isBST = false;
            }
        }
        if (head->right != NULL) {
            cmin = min({ cmin, head->val, rightInfo.min });
            cmax = max({ cmax, head->val, rightInfo.max });
            if (!rightInfo.isBST || head->val >= rightInfo.min) {
                isBST = false;
            }
        }
        return Info(cmin, cmax, isBST);
    }

};