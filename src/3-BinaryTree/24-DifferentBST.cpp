#include"headFile.h"

// 不同的二叉搜索树
class DifferentBST {
public:
    // 原问题：返回多少种不同的结构
    int numTrees(int n) {
        if (n < 2) {
            return 1;
        }
        int ans = 0;
        for (int h = 1; h <= n; h++) {
            int leftNum = numTrees(h - 1);
            int rightNum = numTrees(n - h);
            ans += leftNum * rightNum;
        }
        return ans;
    }

    // 进阶：把所有树生成，返回
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
    vector<TreeNode*> generate(int L, int R) {
        if (L > R) {
            return vector<TreeNode*>{NULL};
        }
        vector<TreeNode*>res;
        for (int h = L; h <= R; h++) {
            vector<TreeNode*>leftTrees = generate(L, h - 1);
            vector<TreeNode*>rightTrees = generate(h + 1, R);
            TreeNode* head = new TreeNode(h);
            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    head->left = l;
                    head->right = r;
                    res.push_back(head);
                }
            }
        }
        return res;
    }
};