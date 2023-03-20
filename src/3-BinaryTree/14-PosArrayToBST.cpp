#include"headFile.h"

// ���ݺ��������ؽ�����������
class PosArrayToBST {
public:
    // ԭ���⣺��һ�����飬û���ظ�ֵ��
    // �ж��Ƿ�����������������ĺ���������
    bool isPosArray(vector<int>& arr) {
        if (arr.empty()) {
            return true;
        }
        return isPost(arr, 0, arr.size() - 1);
    }
    bool isPost(vector<int>& arr, int start, int end) {
        if (start == end) {
            return true;
        }
        int less = -1;
        int more = end;
        for (int i = start; i < end; i++) {
            if (arr[i] < arr[end]) {
                less = i;
            } else {
                more = more == end ? i : more;
            }
        }
        if (less == -1 || more == end) { // end��ߵ�������arr[end]С/��
            return isPost(arr, start, end - 1);
        }
        if (less != more - 1) {
            return false;
        }
        return isPost(arr, start, less) && isPost(arr, more, end - 1);
    }

    // ����
    // ��һ�����飬û���ظ�ֵ����֪���Ƕ��������������������������������
    TreeNode* posArrayToBST(vector<int>& arr) {
        if (arr.empty()) {
            return NULL;
        }
        return generate(arr, 0, arr.size() - 1);
    }
    TreeNode* generate(vector<int>& arr, int start, int end) {
        if (start > end) {
            return NULL;
        }
        TreeNode* head = new TreeNode(arr[end]);
        int less = -1;
        int more = end;
        for (int i = start; i < end; i++) {
            if (arr[i] < arr[end]) {
                less = i;
            } else {
                more = more == end ? i : more;
            }
        }
        head->left = generate(arr, start, less);
        head->right = generate(arr, more, end - 1);
        return head;
    }
};