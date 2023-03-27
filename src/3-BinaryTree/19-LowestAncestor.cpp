#include"headFile.h"

// 二叉树两个节点的最低公共祖先
class LowestAnscetor1 {
public:
    TreeNode* lowestAncestor(TreeNode* head, TreeNode* o1, TreeNode* o2) {
        if (head == NULL || head == o1 || head == o2) {
            return head;
        }
        TreeNode* leftInfo = lowestAncestor(head->left, o1, o2);
        TreeNode* rightInfo = lowestAncestor(head->right, o1, o2);
        if (leftInfo == NULL && rightInfo == NULL) {
            return NULL;
        } else if (leftInfo != NULL && rightInfo != NULL) {
            return head;
        } else {
            return leftInfo ? leftInfo : rightInfo;
        }
    }
};


// 进阶：如果查询两个节点的最低公共祖先操作很频繁，想办法优化
// 法一：建立每个节点对应的父节点信息
class Record1 {
    unordered_map<TreeNode*, TreeNode*>map;
public:
    Record1(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        map[head] = NULL;
        setMap(head);
    }

    void setMap(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        if (head->left) {
            map[head->left] = head;
        }
        if (head->right) {
            map[head->right] = head;
        }
        setMap(head->left);
        setMap(head->right);
    }

    TreeNode* query(TreeNode* o1, TreeNode* o2) {
        unordered_set<TreeNode*>path;
        while (map.count(o1)) {
            path.insert(o1);
            o1 = map[o1];
        }
        while (!path.count(o2)) {
            o2 = map[o2];
        }
        return o2;
    }
};

// 法二：把整棵树任意两个节点的祖先都记录下来
class Record2 {
    unordered_map<TreeNode*, unordered_map<TreeNode*, TreeNode*>>map;
public:
    Record2(TreeNode* head) {
        setMap(head);
    }

    void setMap(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        // head的所有后代节点，与head的公共祖先都是head
        headRecord(head->left, head);
        headRecord(head->right, head);

        // head左子树上所有节点，与head右子树上所有节点，公共祖先都是head
        subRecord(head);

        // 先序遍历
        setMap(head->left);
        setMap(head->right);
    }

    void headRecord(TreeNode* cur, TreeNode* head) {
        if (cur == NULL) {
            return;
        }
        map[cur][head] = head;
        headRecord(cur->left, head);
        headRecord(cur->right, head);
    }

    void subRecord(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        preLeft(head->left, head->right, head);
        subRecord(head->left);
        subRecord(head->right);
    }

    void preLeft(TreeNode* l, TreeNode* r, TreeNode* h) {
        if (l == NULL) {
            return;
        }
        preRight(l, r, h); // 对当前l节点，与r及其所有后代节点建立祖先
        preLeft(l->left, r, h);
        preLeft(l->right, r, h);
    }

    void preRight(TreeNode* l, TreeNode* r, TreeNode* h) {
        if (r == NULL) {
            return;
        }
        map[l][r] = h;
        preRight(l, r->left, h);
        preRight(l, r->right, h);
    }

    TreeNode* query(TreeNode* o1, TreeNode* o2) {
        if (o1 == NULL || o2 == NULL) {
            return NULL;
        }
        if (map.count(o1)) {
            return map[o1][o2];
        }
        if (map.count(o2)) {
            return map[o2][o1];
        }
        return NULL;
    }
};