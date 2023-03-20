#include"headFile.h"

// 判断完全二叉树
class IsCBT {
public:
    // 从左到右按层遍历二叉树
    // 如果当前节点有右孩子节点，无左孩子节点，直接返回false
    // 如果当前节点左右孩子不全有，那么之后的节点必须全是叶节点，否则返回false
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