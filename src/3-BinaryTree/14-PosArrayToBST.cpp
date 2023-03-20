#include"headFile.h"

// 根据后序数组重建搜索二叉树
class PosArrayToBST {
public:
    // 原问题：给一个数组，没有重复值，
    // 判断是否可能是搜索二叉树的后序遍历结果
    bool isPosArray(vector<int>& arr) {
        if (arr.empty()) {
            return true;
        }
        return isPost(arr, 0, arr.size() - 1);
    }
    bool isPost(vector<int>& arr, int start, int end) {
        if (start == end) {
            return true;
        }
        int less = -1;
        int more = end;
        for (int i = start; i < end; i++) {
            if (arr[i] < arr[end]) {
                less = i;
            } else {
                more = more == end ? i : more;
            }
        }
        if (less == -1 || more == end) { // end左边的数都比arr[end]小/大
            return isPost(arr, start, end - 1);
        }
        if (less != more - 1) {
            return false;
        }
        return isPost(arr, start, less) && isPost(arr, more, end - 1);
    }

    // 进阶
    // 给一个数组，没有重复值，已知它是二叉搜索树后序遍历结果，构建出这棵树
    TreeNode* posArrayToBST(vector<int>& arr) {
        if (arr.empty()) {
            return NULL;
        }
        return generate(arr, 0, arr.size() - 1);
    }
    TreeNode* generate(vector<int>& arr, int start, int end) {
        if (start > end) {
            return NULL;
        }
        TreeNode* head = new TreeNode(arr[end]);
        int less = -1;
        int more = end;
        for (int i = start; i < end; i++) {
            if (arr[i] < arr[end]) {
                less = i;
            } else {
                more = more == end ? i : more;
            }
        }
        head->left = generate(arr, start, less);
        head->right = generate(arr, more, end - 1);
        return head;
    }
};