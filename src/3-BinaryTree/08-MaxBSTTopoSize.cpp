#include"headFile.h"

// �����������������������������˽ṹ
class MaxBSTTopoSize {
public:
    // ��һ   ��ÿ���ڵ㶼��Ϊͷ�ڵ㣬�����ң��𰸾�������
    int maxTopoSize1(TreeNode* head) {
        if (head == NULL) {
            return 0;
        }
        int ans = maxTopo(head, head);
        ans = max(ans, maxTopoSize1(head->left));
        ans = max(ans, maxTopoSize1(head->right));
        return ans;
    }
    int maxTopo(TreeNode* h, TreeNode* n) {
        if (h != NULL && n != NULL && isBSTNode(h, n, n->val)) {
            return 1 + maxTopo(h, n->left) + maxTopo(h, n->right);
        }
        return 0;
    }
    // n�Ƿ�����Ϊ��hΪͷ�ڵ�Ķ������������˽ṹ��Ľڵ�
    bool isBSTNode(TreeNode* h, TreeNode* n, int value) {
        if (h == NULL) {
            return false;
        }
        if (h == n) {
            return true;
        }
        return isBSTNode(h->val > value ? h->left : h->right, n, value);
    }


    // ����   ���˹��׼�¼
    class Record {
    public:
        int l; // ���������׼��������������ڵ�
        int r; // ���������׼��������������ڵ�
        Record(int l, int r) {
            this->l = l;
            this->r = r;
        }
    };

    int maxTopoSize2(TreeNode* head) {
        unordered_map<TreeNode*, Record>map; // ĳһ���ڵ㣬�������������������Ĺ��׼�¼
        return process(head, map);
    }
    int process(TreeNode* head, unordered_map<TreeNode*, Record>& map) {
        if (head == NULL) {
            return 0;
        }
        int lInfo = process(head->left, map);
        int rInfo = process(head->right, map);
        modifyMap(head->left, head->val, map, true);
        modifyMap(head->right, head->val, map, false);
        
        int lbst = (map.count(head->left)) ? (map[head->left].l + map[head->left].r + 1) : 0;
        int rbst = (map.count(head->right)) ? (map[head->right].l + map[head->right].r + 1) : 0;

        map[head] = Record(lbst, rbst);

        return max({ lInfo, rInfo, lbst + rbst + 1 });
    }

    int modifyMap(TreeNode* n, int val, unordered_map<TreeNode*, Record>& map, bool left) {
        if (n == NULL || (!map.count(n))) {
            return 0;
        }
        Record rec = map[n];
        if ((left && n->val > val) || (!left && n->val < val)) { // ��ǰ�ڵ��޷��������˽ṹ
            map.erase(n);
            return rec.l + rec.r + 1;
        } else {
            int minus = modifyMap(left ? n->right : n->left, val, map, left); // ���ӣ���ȥ���ұ߽�
            if (left) {
                rec.r -= minus;
            } else {
                rec.l -= minus;
            }
            map[n] = rec;
            return minus;
        }
    }
};