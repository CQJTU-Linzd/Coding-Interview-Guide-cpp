#include"headFile.h"

// С��
class SmallSum {
public:

	// ����

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

	// ��ʽ

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

	// arr��Ϊ[l...m], [m + 1, r]���飬�����������
	int merge(vector<int>& arr, int l, int m, int r) {
		// ͳ�Ʋ���
		int ans = 0;
		int i = l, j = m + 1;
		while (i <= m && j <= r) {
			if (arr[i] <= arr[j]) {
				ans += arr[i] * (r - j + 1);  // ͳ��С��
				i++;
			} else {
				j++;
			}
		}
		// ����merge����
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

	// ���ɴ�СΪsize�����ݷ�Χ��l~r���������
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