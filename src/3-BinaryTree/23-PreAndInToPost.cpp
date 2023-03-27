#include"headFile.h"

// 二叉树无重复值
// 给定先序和中序数组，返回后序数组
class GetPosArray {
    vector<int>pos;
    unordered_map<int, int>map;
public:
    vector<int> getPos(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        pos.resize(n);
        for (int i = 0; i < n; i++) {
            map[in[i]] = i;
        }
        setPos(pre, in, 0, n - 1, 0, n - 1, 0, n - 1);
        return pos;
    }
    void setPos(vector<int>& pre, vector<int>& in, 
           int pi, int pj, int ni, int nj, int si, int sj) {
        if (pi > pj) {
            return;
        }
        pos[sj] = pre[pi];
        int i = map[pre[pi]];
        int leftSize = i - ni;
        int rightSize = nj - i;
        setPos(pre, in, pi + 1, pi + leftSize, ni, ni + leftSize - 1, si, si + leftSize - 1);
        setPos(pre, in, pi + leftSize + 1, pj, i + 1, nj, si + leftSize, sj - 1);
    }

    // for test
    set<int>st;
    vector<int>tpre;
    vector<int>tin;
    vector<int>tpos;

    TreeNode* randomBinaryTree(int maxlevel, int l, int r) {
        if (maxlevel == 0 || rand() % 11 <= 1) {
            return nullptr;
        }
        int val = rand() % (r - l + 1) + l;
        while (st.count(val)) {
            val = rand() % (r - l + 1) + l;
        }
        st.insert(val);
        TreeNode* head = new TreeNode(val);
        head->left = randomBinaryTree(maxlevel - 1, l, r);
        head->right = randomBinaryTree(maxlevel - 1, l, r);
        return head;
    }

    void preOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        tpre.push_back(head->val);
        preOrder(head->left);
        preOrder(head->right);
    }

    void inOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        inOrder(head->left);
        tin.push_back(head->val);
        inOrder(head->right);
    }

    void posOrder(TreeNode* head) {
        if (head == NULL) {
            return;
        }
        posOrder(head->left);
        posOrder(head->right);
        tpos.push_back(head->val);
    }

    void test() {
        srand(time(0));
        for (int t = 0; t < 10000; t++) {
            tpre.clear();
            tin.clear();
            tpos.clear();
            st.clear();

            TreeNode* head = randomBinaryTree(10, 0, 10000);
            preOrder(head);
            inOrder(head);
            posOrder(head);

            GetPosArray g;
            vector<int>ans = g.getPos(tpre, tin);
            if (ans != pos) {
                cout << "fuck" << endl;
                for (int num : ans) {
                    cout << num << " ";
                }
                cout << endl;
                for (int num : pos) {
                    cout << num << " ";
                }
            }
        }
    }

};