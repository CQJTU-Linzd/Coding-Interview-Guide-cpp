#include"headFile.h"

class JumpGame {
public:

    int minJumps(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int jump = 0;
        int cur = 0;
        int next = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (cur < i) {
                jump++;
                cur = next;
            }
            next = max(next, i + arr[i]);
        }
        return jump;
    }

};