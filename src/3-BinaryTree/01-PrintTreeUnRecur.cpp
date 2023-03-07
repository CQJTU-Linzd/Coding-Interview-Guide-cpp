#include"headFile.h"

// 非递归方式实现二叉树的三种遍历
class UnRecur {
public:
    // 先序遍历
    void preOrderUnRecur(TreeNode* head) {
        if (head != NULL) {
            stack<TreeNode*>stack;
            stack.push(head);
            while (!stack.empty()) {
                TreeNode* cur = stack.top();
                stack.pop();
                cout << cur->val << " ";
                if (cur->right != NULL) {
                    stack.push(cur->right);
                }
                if (cur->left != NULL) {
                    stack.push(cur->left);
                }
            }
        }
    }

    // 中序遍历
    void inOrderUnRecur(TreeNode* head) {
        if (head != NULL) {
            stack<TreeNode*>stack;
            while (head != NULL || !stack.empty()) {
                if (head != NULL) {
                    stack.push(head);
                    head = head->left;
                } else {
                    head = stack.top();
                    stack.pop();
                    cout << head->val << " ";
                    head = head->right;
                }
            }
        }
    }

    // 后序遍历
    // 法一：用两个栈实现
    void posOrderUnRecur1(TreeNode* head) {
        if (head != NULL) {
            stack<TreeNode*>s1, s2;
            s1.push(head);
            while (!s1.empty()) {
                TreeNode* cur = s1.top();
                s1.pop();
                s2.push(cur);
                if (cur->left) {
                    s1.push(cur->left);
                }
                if (cur->right) {
                    s1.push(cur->right);
                }
            }
            while (!s2.empty()) {
                cout << s2.top()->val << " ";
                s2.pop();
            }
        }
    }

    // 法二：一个栈实现
    void posOrderUnRecur2(TreeNode* head) {
        if (head != NULL) {
            stack<TreeNode*>stack;
            TreeNode* h = head; // 最近一次弹出并打印的节点
            TreeNode* c = NULL; // stack的栈顶节点
            while (!stack.empty()) {
                c = stack.top();
                if (c->left != NULL && h != c->left && h != c->right) {
                    stack.push(c->left);
                } else if (c->right != NULL && h != c->right) {
                    stack.push(c->right);
                } else {
                    cout << stack.top()->val << " ";
                    stack.pop();
                    h = c;
                }
            }
        }
    }
};