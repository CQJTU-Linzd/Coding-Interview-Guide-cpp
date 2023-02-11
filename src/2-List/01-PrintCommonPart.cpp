#include"headFile.h"

// 给两个有序链表 打印出两个链表的公共部分
class PrintCommonPart {
public:
    void printCommonPart(ListNode* head1, ListNode* head2) {
        while (head1 && head2) {
            if (head1->val == head2->val) {
                cout << head1->val << " ";
                head1 = head1->next;
                head2 = head2->next;
            } else if (head1->val > head2->val) {
                head2 = head2->next;
            } else {
                head1 = head1->next;
            }
        }
    }

    // for test

    void printCommonPart2(ListNode* head1, ListNode* head2) {
        unordered_set<int>st;
        while (head1) {
            st.insert(head1->val);
            head1 = head1->next;
        }
        while (head2) {
            if (st.count(head2->val)) {
                cout << head2->val << " ";
            }
            head2 = head2->next;
        }
    }

    // 生成长度为size，数值范围在l~r上的链表
    ListNode* randomList(int size, int l, int r) {
        srand(time(0));
        ListNode* head = new ListNode(rand() % (r - l + 1) + l);
        ListNode* cur = head;
        for (int i = 0; i < size; i++) {
            int val = rand() % (r - l + 1) + l;
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        return head;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 10; test++) {
            ListNode* h1 = randomList(100, 0, 100);
            ListNode* h2 = randomList(100, 0, 100);
            cout << "way1:" << endl;
            printCommonPart(h1, h2);
            cout << endl;
            cout << "way2:" << endl;
            printCommonPart2(h1, h2);
            cout << endl << endl;
        }
    }
};



int main() {
    PrintCommonPart pcp;
    srand(time(0));
    pcp.test();

    return 0;
}