#include"headFile.h"

// 二叉树结点定义中，多一个成员parent，一个节点的父节点
// 给一个节点，找到中序遍历中它的下一个节点
class NextNode {
public:
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* parent;
        Node(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
    };

    Node* nextNode(Node* node) {
        if (node == NULL) {
            return node;
        }
        if (node->right != NULL) {
            return getMostLeft(node->right);
        } else {
            Node* parent = node->parent;
            while (parent != NULL && parent->left != node) {
                node = parent;
                parent = node->parent;
            }
            return parent;
        }
    }

    Node* getMostLeft(Node* node) { // 获取一棵树的最左节点
        if (node == NULL) {
            return NULL;
        }
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

};