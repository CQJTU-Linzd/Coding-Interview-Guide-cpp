#include"headFile.h"

// �������ڵ���������
class MaxDistance {
public:
    class Info {
    public:
        int maxDistance;
        int height;
        Info(int dis, int h) {
            maxDistance = dis;
            height = h;
        }
    };

    int maxDistance(TreeNode* head) {
        return process(head).maxDistance;
    }

    Info process(TreeNode* head) {
        if (head == NULL) {
            return Info(0, 0);
        }
        Info leftInfo = process(head->left);
        Info rightInfo = process(head->right);
        int maxDistance = max({ leftInfo.maxDistance, rightInfo.maxDistance,
                          leftInfo.height + 1 + rightInfo.height });
        int height = max(leftInfo.height, rightInfo.height) + 1;
        return Info(maxDistance, height);
    }
};