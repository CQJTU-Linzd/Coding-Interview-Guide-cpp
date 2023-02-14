#include"headFile.h"

// 删除链表的中间结点
// 链表为空或长度为1，直接返回
// 1->2，删1
// 1->2->3，删2
// 1->2->3->4，删2
// 1->2->3->4->5，删3
class RemoveMidNode {
public:
    ListNode* removeMidNode(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (head->next->next == NULL) {
            return head->next;
        }
        // 链表长度每增加2，要删除的节点就往后移一个
        ListNode* pre = head;
        ListNode* cur = head->next->next;
        while (cur->next != NULL && cur->next->next != NULL) {
            cur = cur->next->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }

    // 进阶 删除链表的a/b处节点
    // ((double)a * n) / (double)b，向上取整的值，就是要删除的节点是第几个节点
    ListNode* removeByRatio(ListNode* head, int a, int b) {
        if (a < 1 || a > b || !head) {
            return head;
        }
        double n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        n = ceil((double)(a * n) / (double)b);
        if (n == 1) {
            head = head->next;
        } else if (n > 1) {
            cur = head;
            while (--n != 1) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        return head;
    }
};