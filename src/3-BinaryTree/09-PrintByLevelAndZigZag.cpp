#include"headFile.h"

// �����ӡ��ZigZag��ӡ
class PrintByLevelAndZigZag {
public:
    void printByLevel(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        queue<TreeNode*>queue;
        TreeNode* last = head; // ��¼��ǰ������һ��Ҫ��ӡ�Ľڵ�
        TreeNode* nLast = NULL; // ��¼��һ������һ��Ҫ��ӡ�Ľڵ�
        int level = 1;
        queue.push(head);
        cout << "Level " << level++ << ": ";
        while (!queue.empty()) {
            TreeNode* cur = queue.front();
            queue.pop();
            cout << cur->val << " ";
            if (cur->left != NULL) {
                queue.push(cur->left);
                nLast = cur->left;
            }
            if (cur->right != NULL) {
                queue.push(cur->right);
                nLast = cur->right;
            }
            if (cur == last && !queue.empty()) {
                cout << endl << "Level " << level++ << ": ";
                last = nLast;
            }
        }
    }

    // ����
    void printByLevel2(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        int level = 1;
        queue<TreeNode*>queue;
        queue.push(head);
        while (!queue.empty()) {
            int size = queue.size();
            cout << "Level " << level++ << ": ";
            for (int i = 0; i < size; i++) {
                TreeNode* cur = queue.front();
                queue.pop();
                cout << cur->val << " ";
                if (cur->left != NULL) {
                    queue.push(cur->left);
                }
                if (cur->right != NULL) {
                    queue.push(cur->right);
                }
            }
            cout << endl;
        }
    }


    // ZigZag
    void printByZigZag(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        deque<TreeNode*>dq;
        int level = 1;
        bool lr = true;
        TreeNode* last = head;
        TreeNode* nLast = NULL;
        dq.push_back(head);
        printLevelAndOrientation(level++, lr);
        while (!dq.empty()) {
            TreeNode* cur = NULL;
            if (lr) { // ��->�ң�ͷɾβ�壬�Ȳ������ٲ��Һ���
                cur = dq.front();
                dq.pop_front();
                if (cur->left != NULL) {
                    dq.push_back(cur->left);
                    nLast = nLast == NULL ? cur->left : nLast; // ��ǰ���һ��������еĽڵ㣬����һ������ӡ�Ľڵ�
                }
                if (cur->right != NULL) {
                    dq.push_back(cur->right);
                    nLast = nLast == NULL ? cur->right : nLast;
                }
            } else { // ��->��βɾͷ�壬�Ȳ��Һ����ٲ�����
                cur = dq.back();
                dq.pop_back();
                if (cur->right != NULL) {
                    dq.push_front(cur->right);
                    nLast = nLast == NULL ? cur->right : nLast;
                }
                if (cur->left != NULL) {
                    dq.push_front(cur->left);
                    nLast = nLast == NULL ? cur->left : nLast;
                }
            }
            cout << cur->val << " ";
            if (cur == last && !dq.empty()) { // cur�ǵ�ǰ������һ���ڵ�
                lr = !lr;
                last = nLast;
                nLast = NULL;
                cout << endl;
                printLevelAndOrientation(level++, lr);
            }
        }
    }

    void printLevelAndOrientation(int level, bool lr) {
        cout << "Level " << level << " from ";
        cout << (lr ? "left to right: " : "right to left: ");
    }


    // ����
    void printByZigZag2(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        bool lr = true;
        int level = 1;
        deque<TreeNode*>dq;
        dq.push_back(head);
        while (!dq.empty()) {
            int size = dq.size();
            cout << "Level " << level++ << " from ";
            cout << (lr ? "left to right: " : "right to left: ");
            if (lr) {
                for (int i = 0; i < size; i++) {
                    TreeNode* cur = dq.front();
                    dq.pop_front();
                    cout << cur->val << " ";
                    if (cur->left != NULL) {
                        dq.push_back(cur->left);
                    }
                    if (cur->right != NULL) {
                        dq.push_back(cur->right);
                    }
                }
            } else {
                for (int i = 0; i < size; i++) {
                    TreeNode* cur = dq.back();
                    dq.pop_back();
                    cout << cur->val << " ";
                    if (cur->right != NULL) {
                        dq.push_front(cur->right);
                    }
                    if (cur->left != NULL) {
                        dq.push_front(cur->left);
                    }
                }
            }
            lr = !lr;
            cout << endl;
        }
    }
};