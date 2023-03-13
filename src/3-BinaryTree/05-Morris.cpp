#include"headFile.h"

// 二叉树的morris遍历
class Morris {
public:
    // morris序
    void morris(TreeNode* head) {
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) { // 左子树不为空
                while (mostRight->right != NULL && mostRight->right != cur) {// 找到左子树上最右的节点
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) { // cur第一次来到该节点
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else { // mostRight->right == cur， cur第二次来到该节点
                    mostRight->right = NULL;
                }
            }
            // 左子树为空
            // 或者cur左子树上最右节点的右指针是指向cur的
            cur = cur->right;
        }
    }

    // morris加工出先序遍历
    // cur只能到达一次的节点（无左子树的节点），cur到达时直接打印
    // cur可以到达两次的节点（有左子树的节点），cur第一次到达时打印，第二次到达不打印
    void morrisPre(TreeNode* head) {
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) { // 有左子树
                while (mostRight->right != NULL && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) { // 第一次到达
                    cout << cur->val << " ";
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else { // 第二次到达
                    mostRight->right = NULL;
                }
            } else { // 无左子树
                cout << cur->val << " ";
            }
            cur = cur->right;
        }
        cout << endl;
    }

    // morris加工出中序遍历
    // cur只能到达一次的节点（无左子树的节点），cur到达时直接打印
    // cur可以到达两次的节点（有左子树的节点），cur第一次到达时不打印，第二次到达打印
    void morrisIn(TreeNode* head) {
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) { // 有左子树
                while (mostRight->right != NULL && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else { // 第二次到达
                    cout << cur->val << " ";
                    mostRight->right = NULL;
                }
            } else { // 无左子树
                cout << cur->val << " ";
            }
            cur = cur->right;
        }
        cout << endl;
    }

    // morris加工出后序遍历
    // cur只能到达一次的节点（无左子树的节点），直接跳过，不打印
    // cur可以到达两次的节点（有左子树的节点），cur第一次到达不打印；
    // 第二次到达，逆序打印这棵树的右边界
    void morrisPos(TreeNode* head) {
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) {
                while (mostRight->right != NULL && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = NULL;
                    printEdge(cur->left);
                }
            } 
            cur = cur->right;
        }
        printEdge(head);
        cout << endl;
    }

    void printEdge(TreeNode* head) { // 逆序打印head这棵树的右边界
        TreeNode* tail = reverseEdge(head);
        TreeNode* cur = tail;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->right;
        }
        reverseEdge(tail);
    }

    TreeNode* reverseEdge(TreeNode* head) { // 右边界反转
        TreeNode* pre = NULL;
        TreeNode* next = NULL;
        while (head != NULL) {
            next = head->right;
            head->right = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};