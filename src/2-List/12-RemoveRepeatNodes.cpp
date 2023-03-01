#include"headFile.h"

// 删除无序单链表中值重复出现的节点
// 1->2->2->3->3
// 1->2->3
class RemoveRepeatNodes {
public:
    // 法一 哈希表
    ListNode* removeRep1(ListNode* head) {
        if (!head) {
            return head;
        }
        unordered_set<int>set;
        set.insert(head->val);
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur) {
            if (set.count(cur->val)) {
                pre->next = cur->next;
            } else {
                set.insert(cur->val);
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }

    // 法二 类似选择排序
    // 1->2->2->3->3->1
    // 当前节点值是1，往后检查所有值为1的节点删掉
    // 当前节点值是2，往后检查所有值为2的节点删掉
    ListNode* removeRep2(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (cur) {
            pre = cur;
            next = cur->next;
            while (next) {
                if (cur->val == next->val) {
                    pre->next = next->next;
                } else {
                    pre = next;
                }
                next = next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};