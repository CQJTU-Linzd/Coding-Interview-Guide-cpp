#include"headFile.h"

// 合并两个有序单链表
class MergeList {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) {
            return head1 ? head1 : head2;
        }
        ListNode* head = head1->val <= head2->val ? head1 : head2;
        ListNode* cur1 = head == head1 ? head1 : head2;
        ListNode* cur2 = head == head1 ? head2 : head1;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                pre = cur1;
                cur1 = cur1->next;
            } else {
                next = cur2->next;
                pre->next = cur2;
                cur2->next = cur1;
                pre = cur2;
                cur2 = next;
            }
        }
        if (cur1 == NULL) {
            pre->next = cur2;
        }
        return head;
    }
};