#include"headFile.h"

// 正数数组中累加和为给定值的最大子数组长度
class MaxSubLengthSumTargetOfPositiveArray {
public:

	// 暴力

	int maxLength1(vector<int>& arr, int k) {
		int ans = 0;
		int curSum = 0;
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i; j < arr.size(); j++) {
				curSum = 0;
				for (int k = i; k <= j; k++) {
					curSum += arr[k];
				}
				if (curSum == k) {
					ans = max(ans, j - i + 1);
				}
			}
		}
		return ans;
	}


	// 正式 滑动窗口

	int maxLength2(vector<int>& arr, int k) {
		int L = 0;
		int ans = 0;
		int curSum = 0;
		for (int R = 0; R < arr.size(); R++) {
			curSum += arr[R];
			while (L <= R && curSum > k) {
				curSum -= arr[L++];
			}
			if (curSum == k) {
				ans = max(ans, R - L + 1);
			}
		}
		return ans;
	}


	// for test

	// 生成大小为size，数据范围在l~r的随机数组
	vector<int> randomArray(int size, int l, int r) {
		vector<int>nums;
		for (int i = 0; i < size; i++) {
			nums.push_back(rand() % (r - l + 1) + l);
		}
		return nums;
	}


	void test() {
		srand(time(0));
		for (int t = 0; t < 5000; t++) {
			int size = rand() % (100 - 1 + 1) + 1;
			int k = rand() % (100 - 1 + 1) + 1;
			auto arr = randomArray(size, 1, 100);
			int ans1 = maxLength1(arr, k);
			int ans2 = maxLength2(arr, k);
			if (ans1 != ans2) {
				//cout << "fuck" << endl;
				for (int num : arr) {
					cout << num << " ";
				}
				cout << endl << k << endl;
				cout << ans1 << " " << ans2 << endl << endl;
			}
		}
	}

};

//int main() {
//	MaxSubLengthSumTargetOfPositiveArray msl;
//	msl.test();
//	return 0;
//}