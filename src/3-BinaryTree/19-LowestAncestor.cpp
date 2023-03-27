#include"headFile.h"

// �����������ڵ����͹�������
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


// ���ף������ѯ�����ڵ����͹������Ȳ�����Ƶ������취�Ż�
// ��һ������ÿ���ڵ��Ӧ�ĸ��ڵ���Ϣ
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

// �����������������������ڵ�����ȶ���¼����
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
        // head�����к���ڵ㣬��head�Ĺ������ȶ���head
        headRecord(head->left, head);
        headRecord(head->right, head);

        // head�����������нڵ㣬��head�����������нڵ㣬�������ȶ���head
        subRecord(head);

        // �������
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
        preRight(l, r, h); // �Ե�ǰl�ڵ㣬��r�������к���ڵ㽨������
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