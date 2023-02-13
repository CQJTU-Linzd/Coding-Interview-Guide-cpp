#include"headFile.h"

// 删除单链表和双链表的倒数第K个节点
class RemoveLastKthNode {
public:
    // 单链表
    ListNode* removeKth(ListNode* head, int k) {
        if (!head || k < 1) {
            return head;
        }
        ListNode* cur = head;
        while (cur) {
            k--;
            cur = cur->next;
        }
        if (k > 0) {
            return head;
        } else if (k == 0) {
            return head->next;
        } else {
            cur = head;
            while (++k != 0) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
            return head;
        }
    }

    // 双链表
    DoubleNode* removeKth(DoubleNode* head, int k) {
        if (!head || k < 1) {
            return head;
        }
        DoubleNode* cur = head;
        while (cur) {
            k--;
            cur = cur->next;
        }
        if (k > 0) {
            return head;
        } else if (k == 0) {
            head->next->last = nullptr;
            return head->next;
        } else {
            cur = head;
            while (++k != 0) {
                cur = cur->next;
            }
            DoubleNode* newNext = cur->next->next;
            cur->next = newNext;
            if (newNext) {
                newNext->last = cur;
            }
            return head;
        }
    }
};