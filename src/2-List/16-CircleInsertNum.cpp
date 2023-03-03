#include"headFile.h"

// 有序环形单链表中插入新节点
class InsertNum {
public:
    ListNode* insertNum(ListNode* head, int num) {
        ListNode* node = new ListNode(num);
        if (!head) {
            node->next = node;
            return node;
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != head) {
            if (pre->val <= num && num <= cur->val) {
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        pre->next = node;
        node->next = cur;
        return num < head->val ? node : head;
    }
};