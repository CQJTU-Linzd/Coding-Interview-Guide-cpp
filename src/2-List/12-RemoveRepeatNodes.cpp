#include"headFile.h"

// ɾ������������ֵ�ظ����ֵĽڵ�
// 1->2->2->3->3
// 1->2->3
class RemoveRepeatNodes {
public:
    // ��һ ��ϣ��
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

    // ���� ����ѡ������
    // 1->2->2->3->3->1
    // ��ǰ�ڵ�ֵ��1������������ֵΪ1�Ľڵ�ɾ��
    // ��ǰ�ڵ�ֵ��2������������ֵΪ2�Ľڵ�ɾ��
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