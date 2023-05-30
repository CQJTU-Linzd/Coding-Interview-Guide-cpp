#include"headFile.h"

class MinLengthOfNeedSort {
public:

    int minLength(vector<int>& arr) {
        if (arr.size() < 2) {
            return 0;
        }
        int minVal = arr.back();
        int noMinIndex = -1;
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr[i] > minVal) {
                noMinIndex = i;
            } else {
                minVal = min(minVal, arr[i]);
            }
        }
        if (noMinIndex == -1) {
            return 0;
        }
        int maxVal = arr[0];
        int noMaxIndex = -1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < maxVal) {
                noMaxIndex = i;
            } else {
                maxVal = max(maxVal, arr[i]);
            }
        }
        return noMaxIndex - noMinIndex + 1;
    }

};