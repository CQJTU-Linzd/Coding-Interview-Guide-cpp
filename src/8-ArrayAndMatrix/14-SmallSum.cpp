#include"headFile.h"

// 小和
class SmallSum {
public:

	// 暴力

	int getSmallSum(vector<int>& arr) {
		if (arr.empty()) {
			return 0;
		}
		int ans = 0;
		for (int i = 1; i < arr.size(); i++) {
			int sum = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] <= arr[i]) {
					sum += arr[j];
				}
			}
			ans += sum;
		}
		return ans;
	}

	// 正式

	int getSmallSum2(vector<int>& arr) {
		if (arr.empty()) {
			return 0;
		}
		return f(arr, 0, arr.size() - 1);
	}

	int f(vector<int>& arr, int l, int r) {
		if (l == r) {
			return 0;
		}
		int mid = (l + r) >> 1;
		return f(arr, l, mid) + f(arr, mid + 1, r) + merge(arr, l, mid, r);
	}

	// arr分为[l...m], [m + 1, r]两组，两组各自有序
	int merge(vector<int>& arr, int l, int m, int r) {
		// 统计部分
		int ans = 0;
		int i = l, j = m + 1;
		while (i <= m && j <= r) {
			if (arr[i] <= arr[j]) {
				ans += arr[i] * (r - j + 1);  // 统计小和
				i++;
			} else {
				j++;
			}
		}
		// 正常merge过程
		vector<int>help(r - l + 1);
		i = l;
		j = m + 1;
		int index = 0;
		while (i <= m && j <= r) {
			help[index++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
		}
		while (i <= m) {
			help[index++] = arr[i++];
		}
		while (j <= r) {
			help[index++] = arr[j++];
		}
		index = 0;
		for (int i = l; i <= r; i++) {
			arr[i] = help[index++];
		}
		return ans;
	}

	// for test

	// 生成大小为size，数据范围在l~r的随机数组
	vector<int> randomArray(int size, int l, int r) {
		srand(time(0));
		vector<int>nums;
		for (int i = 0; i < size; i++) {
			nums.push_back(rand() % (r - l + 1) + l);
		}
		return nums;
	}

	void test() {
		srand(time(0));
		for (int t = 0; t < 1000; t++) {
			int size = rand() % (1000 - 1 + 1) + 1;
			auto arr = randomArray(size, 0, 100);

			auto ans1 = getSmallSum(arr);
			auto ans2 = getSmallSum2(arr);


			if (ans1 != ans2) {
				cout << "fuck" << endl;
			}
		}
	}

};

//int main() {
//	SmallSum ss;
//	ss.test();
//
//	return 0;
//}