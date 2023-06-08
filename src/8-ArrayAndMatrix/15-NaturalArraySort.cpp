#include"headFile.h"

// ��Ȼ�����������
class NaturalArraySort {
public:

	// ��һ

	void sort1(vector<int>& arr) {
		int tmp = 0;
		int next = 0;
		for (int i = 0; i < arr.size(); i++) {
			tmp = arr[i];
			while (arr[i] != i + 1) {
				next = arr[tmp - 1];
				arr[tmp - 1] = tmp;
				tmp = next;
			}
		}
	}

	// ����

	void sort2(vector<int>& arr) {
		int tmp = 0;
		for (int i = 0; i < arr.size(); i++) {
			while (arr[i] != i + 1) {
				swap(arr[i], arr[arr[i] - 1]);
			}
		}
	}

};