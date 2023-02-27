#include"headFile.h"

// ����������ĳֵ����Ϊ���С���м���ȡ��ұߴ����ʽ
class ListPartition {
public:
    // ԭ���⣺�Ի��ֺ��ÿһ�����ڽڵ���Ⱥ������Ҫ��
    // �����нڵ��ŵ������Ȼ����п��ŵ�partition����
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

    // ���� ���ֺ��ÿһ�����ڽڵ���Ⱥ�����Ա�����ԭ����һ��
    ListNode* listPartition2(ListNode* head, int pivot) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* sH = NULL; // С��ͷ
        ListNode* sT = NULL; // С��β
        ListNode* eH = NULL; // ��ȵ�ͷ
        ListNode* eT = NULL; // ��ȵ�β
        ListNode* bH = NULL; // ���ͷ
        ListNode* bT = NULL; // ���β
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
        // С�ĺ���ȵ�����
        if (sT) {
            sT->next = eH;
            eT = eT == NULL ? sT : eT;
        }
        // ���е���������
        if (eT) {
            eT->next = bH;
        }
        return sH ? sH : (eH ? eH : bH);
    }
};