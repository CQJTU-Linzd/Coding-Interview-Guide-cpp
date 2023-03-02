#include"headFile.h"

// ����������ת����˫������
// leftָ�뵱��last��rightָ�뵱��next
class BSTtoDoubleList {
public:
    // ��һ ջ��������������
    TreeNode* convert1(TreeNode* root) {
        if (!root) {
            return root;
        }
        queue<TreeNode*>queue;
        inorder(root, queue);
        TreeNode* head = queue.front();
        queue.pop();
        TreeNode* pre = head;
        pre->left = NULL;
        TreeNode* cur = NULL;
        while (!queue.empty()) {
            cur = queue.front();
            queue.pop();
            pre->right = cur;
            cur->left = pre;
            pre = cur;
        }
        pre->right = NULL;
        return head;
    }
    void inorder(TreeNode* head, queue<TreeNode*>& queue) {
        if (!head) {
            return;
        }
        inorder(head->left, queue);
        queue.push(head);
        inorder(head->right, queue);
    }

    // ���� �ݹ���·
    class Info {
    public:
        TreeNode* start;
        TreeNode* end;
        Info() {}
        Info(TreeNode* s, TreeNode* e) {
            this->start = s;
            this->end = e;
        }
    };

    TreeNode* convert2(TreeNode* root) {
        if (!root) {
            return root;
        }
        return process(root).start;
    }
    Info process(TreeNode* head) {
        if (!head) {
            return Info(NULL, NULL);
        }
        Info leftInfo = process(head->left);
        Info rightInfo = process(head->right);
        if (leftInfo.end != NULL) {
            leftInfo.end->right = head;
        }
        if (rightInfo.start != NULL) {
            rightInfo.start->left = head;
        }
        head->left = leftInfo.end;
        head->right = rightInfo.start;
        return Info(leftInfo.start != NULL ? leftInfo.start : head,
                    rightInfo.end != NULL ? rightInfo.end : head);
    }
};