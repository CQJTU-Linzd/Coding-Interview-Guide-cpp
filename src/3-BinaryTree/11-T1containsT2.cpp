#include"headFile.h"

// 判断t1树是否包含t2树全部的拓扑结构
class Contains {
public:
    bool contains(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return false;
        }
        if (t2 == NULL) {
            return true;
        }
        if (check(t1, t2)) {
            return true;
        }
        return contains(t1->left, t2) || contains(t1->right, t2);
    }
    bool check(TreeNode* h1, TreeNode* h2) {
        if (h1 == NULL || h1->val != h2->val) {
            return false;
        }
        if (h2 == NULL) {
            return true;
        }
        return check(h1->left, h2->left) && check(h1->right, h2->right);
    }
};