#include"headFile.h"

// Լɪ������
// ��������m����ɱ������ڵ�
// ��������������Ľڵ�
class JosephusKill {
public:
    // ��һ ģ�ⱨ������
    ListNode* kill1(ListNode* head, int m) {
        if (head == NULL || head->next == head || m < 1) {
            return head;
        }
        ListNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        int count = 0;
        while (head != last) {
            count++;
            if (count == m) {
                last->next = head->next;
                count = 0;
            } else {
                last = last->next;
            }
            head = head->next;
        }
        return head;
    }

    // ���� �ҳ������ͱ�š��ϱ�ź��±��֮��Ĺ�ϵ
    ListNode* kill2(ListNode* head, int m) {
        if (head == NULL || head->next == head || m < 1) {
            return head;
        }
        int tmp = 1;
        ListNode* cur = head->next;
        while (cur != head) { // �󳤶�
            tmp++;
            cur = cur->next;
        }
        tmp = getLive(tmp, m); // ��������ڵ�ı��
        while (--tmp) {
            head = head->next;
        }
        head->next = head;
        return head;
    }
    // n���ڵ���ɵĻ�������������Ľڵ���
    int getLive(int n, int m) {
        if (n == 1) {
            return 1;
        }
        return (getLive(n - 1, m) + m - 1) % n + 1;
    }
};