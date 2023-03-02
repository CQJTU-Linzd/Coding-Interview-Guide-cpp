#include"headFile.h"

// 约瑟夫环问题
// 报数报到m，就杀死这个节点
// 返回最后存活下来的节点
class JosephusKill {
public:
    // 法一 模拟报数过程
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

    // 法二 找出报数和编号、老编号和新编号之间的关系
    ListNode* kill2(ListNode* head, int m) {
        if (head == NULL || head->next == head || m < 1) {
            return head;
        }
        int tmp = 1;
        ListNode* cur = head->next;
        while (cur != head) { // 求长度
            tmp++;
            cur = cur->next;
        }
        tmp = getLive(tmp, m); // 求出最后存活节点的编号
        while (--tmp) {
            head = head->next;
        }
        head->next = head;
        return head;
    }
    // n个节点组成的环，最后存活下来的节点编号
    int getLive(int n, int m) {
        if (n == 1) {
            return 1;
        }
        return (getLive(n - 1, m) + m - 1) % n + 1;
    }
};