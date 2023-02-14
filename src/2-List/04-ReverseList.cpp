#include"headFile.h"

// ��ת�����˫������
class ReverseList {
public:
    // ��������
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

    // ˫������
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