#include"headFile.h"

// 二叉树序列化和反序列化
class Serial {
    // 先序序列化
    // '#'表示这个节点为空，!表示一个值的结束

    // 法一   先序遍历
    string serialByPre(TreeNode* head) {
        if (!head) {
            return "#!";
        }
        string res = to_string(head->val) + "!";
        res += serialByPre(head->left);
        res += serialByPre(head->right);
        return res;
    }

    // 法二   层序遍历
    string serialByLevel(TreeNode* head) {
        if (!head) {
            return "#!";
        }
        string res = to_string(head->val) + "!";
        queue<TreeNode*>que;
        que.push(head);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur->left) {
                res += to_string(cur->left->val) + "!";
                que.push(cur->left);
            } else {
                res += "#!";
            }
            if (cur->right) {
                res += to_string(cur->right->val) + "!";
                que.push(cur->right);
            } else {
                res += "#!";
            }
        }
        return res;
    }

    // 反序列化
    // 重做层遍历，遇到“#”就生成空节点，不把空节点放进队列
    TreeNode* reconByLevelString(string levelStr) {
        vector<string>values = split(levelStr, '!');
        int index = 0;
        TreeNode* head = generateNodeByString(values[index++]);
        queue<TreeNode*>que;
        if (head) {
            que.push(head);
        }
        TreeNode* cur = NULL;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            cur->left = generateNodeByString(values[index++]);
            cur->right = generateNodeByString(values[index++]);
            if (cur->left) {
                que.push(cur->left);
            }
            if (cur->right) {
                que.push(cur->right);
            }
        }
        return head;
    }
    vector<string> split(string s, char ch) {
        vector<string>res;
        int i = 0, j = 0;
        for (; j < s.size(); j++) {
            if (s[j] == ch) {
                res.push_back(s.substr(i, j - i));
                i = j + 1;
            }
        }
        return res;
    }
    TreeNode* generateNodeByString(string val) {
        if (val == "#") {
            return NULL;
        }
        return new TreeNode(atoi(val.c_str()));
    }
};