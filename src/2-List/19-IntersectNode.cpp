#include"headFile.h"

// 两个单链表（可能有环）如果相交，返回相交的第一个节点；不相交返回null
class IntersectNode {
public:
    // 如果两个链表一个有环，一个无环，一定不会相交
    ListNode* getIntersectNode(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) {
            return NULL;
        }
        ListNode* loop1 = getLoopNode(head1); // 链表1的环入口
        ListNode* loop2 = getLoopNode(head2); // 链表2的环入口
        if (loop1 == NULL && loop2 == NULL) { // 两个都是无环链表
            return noLoopIntersectNode(head1, head2);
        }
        if (loop1 != NULL && loop2 != NULL) { // 两个都有环
            return bothLoopIntersectNode(head1, loop1, head2, loop2);
        }
        return NULL; // 一个有环一个无环，不相交
    }
    // 判断一个链表是否有环，如果有，返回入口第一个节点；否则返回null
    ListNode* getLoopNode(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return NULL;
        }
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        // 快指针一次走两步，慢指针一次走一步
        // 如果快指针到达终点，说明没有环；否则fast和slow一定会相遇
        while (slow != fast) {
            if (fast->next == NULL || fast->next->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        // 让快指针重新指向head，慢指针不动，然后全都走一步，再次相遇就是环入口
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
    // 判断两个无环链表是否相交
    ListNode* noLoopIntersectNode(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) {
            return NULL;
        }
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        int n = 0;
        while (cur1->next) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2->next) {
            n--;
            cur2 = cur2->next;
        }
        // cur1和cur2分别指向两个链表的最后一个节点
        // 如果两个链表相交，则cur1和cur2一定相等；否则就不相交
        // n > 0，说明链表1更长；n < 0，说明链表2更长
        if (cur1 != cur2) {
            return NULL;
        }
        cur1 = n > 0 ? head1 : head2; // 指向长的链表
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n != 0) { // 让长的链表多走几步
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    // 判断两个有环链表是否相交
    // loop：链表的环入口
    ListNode* bothLoopIntersectNode(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2) {
        ListNode* cur1 = NULL;
        ListNode* cur2 = NULL;
        if (loop1 == loop2) { // 环的入口相同，类似方法二
            cur1 = head1;
            cur2 = head2;
            int n = 0;
            while (cur1 != loop1) {
                n++;
                cur1 = cur1->next;
            }
            while (cur2 != loop2) {
                n--;
                cur2 = cur2->next;
            }
            cur1 = n > 0 ? head1 : head2;
            cur2 = cur1 == head1 ? head2 : head1;
            n = abs(n);
            while (n != 0) {
                n--;
                cur1 = cur1->next;
            }
            while (cur1 != cur2) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        } else {
            cur1 = loop1->next;
            while (cur1 != loop1) {
                if (cur1 == loop2) {
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return NULL;
        }
    }
};