#include"headFile.h"

// 统计完全二叉树的节点个数
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
        if (mostLeftLevel(node->right, level + 1) == height) { // 右树的最左节点到达最后一层
            return (1 << (height - level)) + process(node->right, level + 1, height);
        } else { // 右树的最左节点没有到达最后一层
            return (1 << (height - level - 1)) + process(node->left, level + 1, height);
        }
    }
    // head节点当前在level层，求head这棵树的最左节点在第几层
    int mostLeftLevel(TreeNode* head, int level) {
        while (head->left != NULL) {
            level++;
            head = head->left;
        }
        return level;
    }
};