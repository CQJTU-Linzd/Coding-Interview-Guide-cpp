#include"headFile.h"

// 通过有序数组生成平衡二叉搜索树
class SortArrayToBST {
public:
    TreeNode* generateTree(vector<int>& arr) {
        if (arr.empty()) {
            return NULL;
        }
        return generate(arr, 0, arr.size() - 1);
    }
    TreeNode* generate(vector<int>& arr, int L, int R) {
        if (L > R) {
            return NULL;
        }
        int mid = (L + R) / 2;
        TreeNode* head = new TreeNode(arr[mid]);
        head->left = generate(arr, L, mid - 1);
        head->right = generate(arr, mid + 1, R);
        return head;
    }
};