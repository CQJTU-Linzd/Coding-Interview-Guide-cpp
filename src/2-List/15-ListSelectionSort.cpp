#include"headFile.h"

// �������ѡ������
// ѡ�����򣺴�δ����Ĳ������ҵ���Сֵ�����������򲿷ֵ�β������Сδ����Ĳ���
class SelectionSort {
public:
    ListNode* selectionSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* tail = NULL; // ���򲿷ֵ�β��
        ListNode* cur = head; // δ���򲿷ֵ�ͷ��
        ListNode* smallPre = NULL; // ��С�ڵ��ǰһ�����
        ListNode* small = NULL; // ��С�ڵ�
        while (cur) {
            small = cur;
            smallPre = getSmallestPreNode(cur);
            if (smallPre != NULL) {
                small = smallPre->next;
                smallPre->next = small->next;
            }
            cur = cur == small ? cur->next : cur; // cur������Сֵ���Ѿ��ź���
            if (tail == NULL) {
                head = small;
            } else {
                tail->next = small;
            }
            tail = small;
        }
        return head;
    }
    ListNode* getSmallestPreNode(ListNode* head) {
        ListNode* smallPre = NULL;
        ListNode* small = head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur) {
            if (cur->val < small->val) {
                smallPre = pre;
                small = cur;
            }
            pre = cur;
            cur = cur->next;
        }
        return smallPre;
    }
};