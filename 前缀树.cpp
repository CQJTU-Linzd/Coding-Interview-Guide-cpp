#include"headFile.h"

// 节点定义
class TrieNode {
public:
    int pass;
    int end;
    vector<TrieNode*>nexts; // 字符种类很多，可以换成哈希表 map<char, TrieNode*>nexts
    TrieNode() {
        pass = 0;
        end = 0;
        // nexts[0] == null 没有走向'a'的路
        // nexts[0] != null 有走向'a'的路
        nexts.resize(26, nullptr);
    }
};
// 前缀树
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
    // word这个单词之前加入过几次
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
    // 所有加入的字符串中，有几个是以pre这个字符串作为前缀的
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