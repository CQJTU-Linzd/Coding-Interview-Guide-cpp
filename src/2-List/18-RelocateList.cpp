#include"headFile.h"

// 按照左右半区的方式重新组合单链表
class RelocateList {
public:
    ListNode* relocate(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* mid = head;
        ListNode* right = head->next;
        while (right->next && right->next->next) {
            mid = mid->next;
            right = right->next->next;
        }
        right = mid->next;
        mid->next = NULL;
        mergeLR(head, right);
        return head;
    }
    void mergeLR(ListNode* left, ListNode* right) {
        ListNode* next = NULL;
        while (left->next) {
            next = right->next;
            right->next = left->next;
            left->next = right;
            left = right->next;
            right = next;
        }
        left->next = right;
    }
};