#include"headFile.h"

// �ж���ȫ������
class IsCBT {
public:
    // �����Ұ������������
    // �����ǰ�ڵ����Һ��ӽڵ㣬�����ӽڵ㣬ֱ�ӷ���false
    // �����ǰ�ڵ����Һ��Ӳ�ȫ�У���ô֮��Ľڵ����ȫ��Ҷ�ڵ㣬���򷵻�false
    bool isCBT(TreeNode* head) {
        if (head == NULL) {
            return true;
        }
        queue<TreeNode*>queue;
        bool leaf = false;
        queue.push(head);
        while (!queue.empty()) {
            TreeNode* cur = queue.front();
            queue.pop();
            if ((cur->left == NULL && cur->right != NULL)
                || (leaf && (cur->left != NULL || cur->right != NULL))) {
                return false;
            }
            if (cur->left != NULL) {
                queue.push(cur->left);
            }
            if (cur->right != NULL) {
                queue.push(cur->right);
            } else {
                leaf = true;
            }
        }
        return true;
    }
};