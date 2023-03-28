#include"headFile.h"

// ͳ����ȫ�������Ľڵ����
class CBTNodeNum {
public:
    int nodeNum(TreeNode* head) {
        if (head == NULL) {
            return 0;
        }
        return process(head, 1, mostLeftLevel(head, 1));
    }
    int process(TreeNode* node, int level, int height) {
        if (level == height) {
            return 1;
        }
        if (mostLeftLevel(node->right, level + 1) == height) { // ����������ڵ㵽�����һ��
            return (1 << (height - level)) + process(node->right, level + 1, height);
        } else { // ����������ڵ�û�е������һ��
            return (1 << (height - level - 1)) + process(node->left, level + 1, height);
        }
    }
    // head�ڵ㵱ǰ��level�㣬��head�����������ڵ��ڵڼ���
    int mostLeftLevel(TreeNode* head, int level) {
        while (head->left != NULL) {
            level++;
            head = head->left;
        }
        return level;
    }
};