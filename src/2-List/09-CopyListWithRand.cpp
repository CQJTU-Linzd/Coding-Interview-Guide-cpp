#include"headFile.h"

// ���ƴ������ָ��ڵ������
class CopyListWithRand {
public:
    
    class Node {
    public:
        int val;
        Node* next;
        Node* rand;
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    // ��һ ��ϣ��
    Node* copy1(Node* head) {
        if (!head) {
            return head;
        }
        unordered_map<Node*, Node*>map;
        Node* cur = head;
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->rand = map[cur->rand];
            cur = cur->next;
        }
        return map[head];
    }

    // ���� ÿ���ڵ����ɶ�Ӧ�ĸ��ƽڵ㴩����������
    Node* copy2(Node* head) {
        if (!head) {
            return head;
        }
        Node* cur = head;
        Node* next = NULL;
        while (cur) { // ���Ʋ�����ÿһ���ڵ�
            next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        Node* curCopy = NULL;
        while (cur) {
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->rand = cur->rand ? cur->rand->next : NULL;
            cur = next;
        }
        Node* res = head->next;
        cur = head;
        while (cur) {
            next = cur->next->next;
            curCopy = cur->next;
            cur->next = next;
            curCopy->next = next ? next->next : NULL;
            cur = next;
        }
        return res;
    }
};