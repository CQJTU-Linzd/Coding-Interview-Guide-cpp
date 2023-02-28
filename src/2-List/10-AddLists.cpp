#include"headFile.h"

// 两个单链表相加
class AddLists {
public:
    ListNode* addLists1(ListNode* head1, ListNode* head2) {
        stack<int>s1, s2;
        while (head1) {
            s1.push(head1->val);
            head1 = head1->next;
        }
        while (head2) {
            s2.push(head2->val);
            head2 = head2->next;
        }
        int n1 = 0, n2 = 0; // 当前栈顶元素
        int ca = 0; // 进位信息
        int n = 0;
        ListNode* node = NULL;
        ListNode* pre = NULL;
        while (!s1.empty() || !s2.empty()) {
            n1 = s1.empty() ? 0 : s1.top();
            n2 = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) {
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }
            n = n1 + n2 + ca;
            ca = n / 10;
            node = new ListNode(n % 10);
            node->next = pre;
            pre = node;
        }
        if (ca == 1) {
            node = new ListNode(1);
            node->next = pre;
        }
        return node;
    }

    // 法二 反转链表实现
    ListNode* addLists2(ListNode* head1, ListNode* head2) {
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        int n1 = 0, n2 = 0;
        int n = 0;
        int ca = 0;
        ListNode* c1 = head1;
        ListNode* c2 = head2;
        ListNode* pre = NULL;
        ListNode* node = NULL;
        while (c1 || c2) {
            n1 = c1 == NULL ? 0 : c1->val;
            n2 = c2 == NULL ? 0 : c2->val;
            n = n1 + n2 + ca;
            ca = n / 10;
            node = new ListNode(n % 10);
            node->next = pre;
            pre = node;
            c1 = c1 == NULL ? NULL : c1->next;
            c2 = c2 == NULL ? NULL : c2->next;
        }
        if (ca == 1) {
            node = new ListNode(1);
            node->next = pre;
        }
        reverseList(head1);
        reverseList(head2);
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};