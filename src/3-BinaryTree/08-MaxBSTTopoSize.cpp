#include"headFile.h"

// 子树中满足二叉搜索子树的最大拓扑结构
class MaxBSTTopoSize {
public:
    // 法一   以每个节点都作为头节点，往下找，答案就在其中
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
    // n是否能作为以h为头节点的二叉搜索树拓扑结构里的节点
    bool isBSTNode(TreeNode* h, TreeNode* n, int value) {
        if (h == NULL) {
            return false;
        }
        if (h == n) {
            return true;
        }
        return isBSTNode(h->val > value ? h->left : h->right, n, value);
    }


    // 法二   拓扑贡献记录
    class Record {
    public:
        int l; // 左子树贡献几个二叉搜索树节点
        int r; // 右子树贡献几个二叉搜索树节点
        Record(int l, int r) {
            this->l = l;
            this->r = r;
        }
    };

    int maxTopoSize2(TreeNode* head) {
        unordered_map<TreeNode*, Record>map; // 某一个节点，它的左子树和右子树的贡献记录
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
        if ((left && n->val > val) || (!left && n->val < val)) { // 当前节点无法加入拓扑结构
            map.erase(n);
            return rec.l + rec.r + 1;
        } else {
            int minus = modifyMap(left ? n->right : n->left, val, map, left); // 左孩子，就去搜右边界
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