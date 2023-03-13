#include"headFile.h"

// ��������morris����
class Morris {
public:
    // morris��
    void morris(TreeNode* head) {
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) { // ��������Ϊ��
                while (mostRight->right != NULL && mostRight->right != cur) {// �ҵ������������ҵĽڵ�
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) { // cur��һ�������ýڵ�
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else { // mostRight->right == cur�� cur�ڶ��������ýڵ�
                    mostRight->right = NULL;
                }
            }
            // ������Ϊ��
            // ����cur�����������ҽڵ����ָ����ָ��cur��
            cur = cur->right;
        }
    }

    // morris�ӹ����������
    // curֻ�ܵ���һ�εĽڵ㣨���������Ľڵ㣩��cur����ʱֱ�Ӵ�ӡ
    // cur���Ե������εĽڵ㣨���������Ľڵ㣩��cur��һ�ε���ʱ��ӡ���ڶ��ε��ﲻ��ӡ
    void morrisPre(TreeNode* head) {
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) { // ��������
                while (mostRight->right != NULL && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) { // ��һ�ε���
                    cout << cur->val << " ";
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else { // �ڶ��ε���
                    mostRight->right = NULL;
                }
            } else { // ��������
                cout << cur->val << " ";
            }
            cur = cur->right;
        }
        cout << endl;
    }

    // morris�ӹ����������
    // curֻ�ܵ���һ�εĽڵ㣨���������Ľڵ㣩��cur����ʱֱ�Ӵ�ӡ
    // cur���Ե������εĽڵ㣨���������Ľڵ㣩��cur��һ�ε���ʱ����ӡ���ڶ��ε����ӡ
    void morrisIn(TreeNode* head) {
        TreeNode* cur = head;
        TreeNode* mostRight = NULL;
        while (cur != NULL) {
            mostRight = cur->left;
            if (mostRight != NULL) { // ��������
                while (mostRight->right != NULL && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == NULL) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else { // �ڶ��ε���
                    cout << cur->val << " ";
                    mostRight->right = NULL;
                }
            } else { // ��������
                cout << cur->val << " ";
            }
            cur = cur->right;
        }
        cout << endl;
    }

    // morris�ӹ����������
    // curֻ�ܵ���һ�εĽڵ㣨���������Ľڵ㣩��ֱ������������ӡ
    // cur���Ե������εĽڵ㣨���������Ľڵ㣩��cur��һ�ε��ﲻ��ӡ��
    // �ڶ��ε�������ӡ��������ұ߽�
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

    void printEdge(TreeNode* head) { // �����ӡhead��������ұ߽�
        TreeNode* tail = reverseEdge(head);
        TreeNode* cur = tail;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->right;
        }
        reverseEdge(tail);
    }

    TreeNode* reverseEdge(TreeNode* head) { // �ұ߽練ת
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