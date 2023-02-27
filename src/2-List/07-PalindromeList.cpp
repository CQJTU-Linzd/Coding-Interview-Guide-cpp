#include"headFile.h"

// 判断一个链表是否为回文链表
class PalindromeList {
public:
    // 法一 把所有节点都压入栈中，然后挨个比较
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        stack<ListNode*>stack;
        ListNode* cur = head;
        while (cur) {
            stack.push(cur);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            if (cur->val != stack.top()->val) {
                return false;
            }
            stack.pop();
            cur = cur->next;
        }
        return true;
    }

    // 法二 只把链表的右半部分压入栈中，然后比较
    bool isPalindrome2(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* cur = head;
        ListNode* right = head->next;
        while (cur->next && cur->next->next) {
            right = right->next;
            cur = cur->next->next;
        }
        stack<ListNode*>stack;
        while (right) {
            stack.push(right);
            right = right->next;
        }
        while (!stack.empty()) {
            if (head->val != stack.top()->val) {
                return false;
            }
            stack.pop();
            head = head->next;
        }
        return true;
    }

    // 法三 只用有限几个变量
    // 右半段链表反转后指向中间节点
    bool isPalindrome3(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* n1 = head;
        ListNode* n2 = head;
        while (n2->next && n2->next->next) { // 查找中间结点
            n1 = n1->next;
            n2 = n2->next->next;
        }
        n2 = n1->next; // 右部分第一个节点
        n1->next = NULL; // mid->next = NULL
        ListNode* n3 = NULL;
        while (n2) { // 右半区反转
            n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        n3 = n1; // 保存原链表最后一个节点
        n2 = head;
        bool ans = true;
        while (n2 && n1) {
            if (n2->val != n1->val) {
                ans = false;
                break;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        // 把链表恢复成原样
        n1 = n3->next;
        n3->next = NULL;
        while (n1) {
            n2 = n1->next;
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
        return ans;
    }
};