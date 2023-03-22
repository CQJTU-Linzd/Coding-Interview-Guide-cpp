#include"headFile.h"

// ��������㶨���У���һ����Աparent��һ���ڵ�ĸ��ڵ�
// ��һ���ڵ㣬�ҵ����������������һ���ڵ�
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

    Node* getMostLeft(Node* node) { // ��ȡһ����������ڵ�
        if (node == NULL) {
            return NULL;
        }
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

};