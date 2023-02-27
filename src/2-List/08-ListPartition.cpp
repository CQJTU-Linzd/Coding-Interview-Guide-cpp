#include"headFile.h"

// 将单向链表按某值划分为左边小、中间相等、右边大的形式
class ListPartition {
public:
    // 原问题：对划分后的每一部分内节点的先后次序不做要求
    // 把所有节点存放到数组里，然后进行快排的partition过程
    ListNode* listPartition1(ListNode* head, int pivot) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        vector<ListNode*>nodes;
        while (cur) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        partition(nodes, pivot);
        for (int i = 1; i < nodes.size(); i++) {
            nodes[i - 1]->next = nodes[i];
        }
        nodes.back()->next = NULL;
        return nodes[0];
    }
    void partition(vector<ListNode*>& nodes, int pivot) {
        int small = -1;
        int big = nodes.size();
        int index = 0;
        while (index != big) {
            if (nodes[index]->val < pivot) {
                swap(nodes[++small], nodes[index++]);
            } else if (nodes[index]->val == pivot) {
                index++;
            } else {
                swap(nodes[--big], nodes[index]);
            }
        }
    }

    // 进阶 划分后的每一部分内节点的先后次序仍保持与原链表一致
    ListNode* listPartition2(ListNode* head, int pivot) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* sH = NULL; // 小的头
        ListNode* sT = NULL; // 小的尾
        ListNode* eH = NULL; // 相等的头
        ListNode* eT = NULL; // 相等的尾
        ListNode* bH = NULL; // 大的头
        ListNode* bT = NULL; // 大的尾
        ListNode* next = NULL;
        while (head) {
            next = head->next;
            head->next = NULL;
            if (head->val < pivot) {
                if (!sH) {
                    sH = head;
                    sT = head;
                } else {
                    sT->next = head;
                    sT = sT->next;
                }
            } else if (head->val == pivot) {
                if (!eH) {
                    eH = head;
                    eT = head;
                } else {
                    eT->next = head;
                    eT = eT->next;
                }
            } else {
                if (!bH) {
                    bH = head;
                    bT = head;
                } else {
                    bT->next = head;
                    bT = bT->next;
                }
            }
            head = next;
        }
        // 小的和相等的相连
        if (sT) {
            sT->next = eH;
            eT = eT == NULL ? sT : eT;
        }
        // 所有的重新连接
        if (eT) {
            eT->next = bH;
        }
        return sH ? sH : (eH ? eH : bH);
    }
};