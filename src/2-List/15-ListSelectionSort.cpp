#include"headFile.h"

// 单链表的选择排序
// 选择排序：从未排序的部分中找到最小值，放在已排序部分的尾部，缩小未排序的部分
class SelectionSort {
public:
    ListNode* selectionSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* tail = NULL; // 排序部分的尾部
        ListNode* cur = head; // 未排序部分的头部
        ListNode* smallPre = NULL; // 最小节点的前一个结点
        ListNode* small = NULL; // 最小节点
        while (cur) {
            small = cur;
            smallPre = getSmallestPreNode(cur);
            if (smallPre != NULL) {
                small = smallPre->next;
                smallPre->next = small->next;
            }
            cur = cur == small ? cur->next : cur; // cur就是最小值，已经排好序
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