#include"headFile.h"

// �ڵ㶨��
class TrieNode {
public:
    int pass;
    int end;
    vector<TrieNode*>nexts; // �ַ�����ܶ࣬���Ի��ɹ�ϣ�� map<char, TrieNode*>nexts
    TrieNode() {
        pass = 0;
        end = 0;
        // nexts[0] == null û������'a'��·
        // nexts[0] != null ������'a'��·
        nexts.resize(26, nullptr);
    }
};
// ǰ׺��
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }
    void insert(string word) {
        if (word.empty()) return;
        TrieNode* node = root;
        node->pass++;
        int index = 0;
        for (char ch : word) {
            index = ch - 'a';
            if (node->nexts[index] == nullptr) {
                node->nexts[index] = new TrieNode;
            }
            node = node->nexts[index];
            node->pass++;
        }
        node->end++;
    }
    // word�������֮ǰ���������
    int search(string word) {
        if (word.empty()) return 0;
        TrieNode* node = root;
        int index = 0;
        for (char ch : word) {
            index = ch - 'a';
            if (node->nexts[index] == nullptr) {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->end;
    }
    // ���м�����ַ����У��м�������pre����ַ�����Ϊǰ׺��
    int prefixNumber(string pre) {
        if (pre.empty()) return 0;
        TrieNode* node = root;
        int index = 0;
        for (char ch : pre) {
            index = ch - 'a';
            if (node->nexts[index] == nullptr) {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->pass;
    }
};