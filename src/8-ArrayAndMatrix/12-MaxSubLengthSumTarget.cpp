#include"headFile.h"

// ���飨�������и�����0�����ۼӺ�Ϊ����ֵ����������鳤��
class MaxSubLengthSumTarget {
public:

	// ����

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


	// ��ʽ

	int maxLength2(vector<int>& arr, int k) {
		int ans = 0;
		int sum = 0;
		unordered_map<int, int>map;
		map[0] = -1; // ʲô����ѡ������sumΪ0����
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
			if (map.count(sum - k)) {
				ans = max(ans, i - map[sum - k]);
			}
			if (!map.count(sum)) {
				map[sum] = i;
			}
		}
		return ans;
	}


	// for test

	// ���ɴ�СΪsize�����ݷ�Χ��l~r���������
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
			int k = rand() % (100 - (-100) + 1) + (-100);
			auto arr = randomArray(size, -100, 100);
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
//	MaxSubLengthSumTarget ms;
//	ms.test();
//	return 0;
//}