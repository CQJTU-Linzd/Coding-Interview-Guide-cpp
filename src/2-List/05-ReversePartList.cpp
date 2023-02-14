#include"headFile.h"

class ReversePart {
public:
    // 将第from个节点到第to个节点这一部分反转
    ListNode* reversePart(ListNode* head, int from, int to) {
        int len = 0;
        ListNode* fPre = NULL; // 第from个节点的前一个节点
        ListNode* tPos = NULL; // 第to个节点的后一个节点
        ListNode* node1 = head;
        while (node1) {
            len++;
            fPre = len == from - 1 ? node1 : fPre;
            tPos = len == to + 1 ? node1 : tPos;
            node1 = node1->next;
        }
        if (from < to || from < 1 || to > len) {
            return head;
        }
        node1 = fPre == NULL ? head : fPre->next;
        ListNode* node2 = node1->next;
        node1->next = tPos;
        ListNode* next;
        while (node2 != tPos) {
            next = node2->next;
            node2->next = node1;
            node1 = node2;
            node2 = next;
        }
        if (fPre != NULL) {
            fPre->next = node1;
            return head;
        }
        return node1;
    }
};