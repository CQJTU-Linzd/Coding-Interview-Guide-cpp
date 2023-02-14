#include"headFile.h"

// 反转单向和双向链表
class ReverseList {
public:
    // 单向链表
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return head;
    }

    // 双向链表
    DoubleNode* reverseList(DoubleNode* head) {
        DoubleNode* pre = NULL;
        DoubleNode* next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            head->last = next;
            pre = head;
            head = next;
        }
        return head;
    }
};