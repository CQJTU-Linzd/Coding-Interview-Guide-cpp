#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<map>

// ���쳲��������е�n���10^9 + 7ȡģ
int mod = 1e9 + 7;
void Fib() {
    int n;
    cin >> n;
    vector<int>dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << dp[n] << endl;
}

// n x m ������ת90��
void matrixTurn90() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    // �������ĵ�һ�� Ϊ ԭ�����һ�еĵ���
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

// �������Ӿ���
void maxSubMatrix() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                for (int l = k; l < m; l++) {
                    int temp = 0;
                    for (int p = i; p <= j; p++) {
                        for (int q = k; q <= l; q++) {
                            temp += matrix[p][q];
                        }
                    }
                    maxSum = max(maxSum, temp);
                }
            }
        }
    }
    cout << maxSum << endl;
}

// ʮ����תR���� 2 =< R <= 16
void Exchange() {
    int N, R;
    cin >> N >> R;
    if (N == 0) {
        cout << 0 << endl;
    }
    if (N < 0) {
        cout << "-";
        N = -N;
    }
    int now = 0;
    vector<char>ret;
    while (N) {
        now = N % R;
        if (now <= 9) {
            ret.push_back('0' + now);
        }
        else {
            ret.push_back('A' + now - 10);
        }
        N /= R;
    }
    reverse(ret.begin(), ret.end());
    for (char ch : ret) {
        cout << ch;
    }
}

// ������
// ������ǻ��������ͰѸ�����ת����ԭ����ӵõ�����������������ǻ����������ظ��任
class Solution {
public:
    int reverseNum(int n) {
        int ret = 0;
        int temp = n;
        while (temp) {
            ret = ret * 10 + temp % 10;
            temp /= 10;
        }
        return ret;
    }
    bool check(int n) {
        return reverseNum(n) == n;
    }
    void P() {
        int n;
        cin >> n;
        int cnt = 0;
        vector<int>path;
        path.push_back(n);
        while (!check(n)) { // ����Ƿ������
            cnt++;
            n = reverseNum(n) + n;
            path.push_back(n);
        }
        cout << cnt << endl;
        for (int num : path) {
            cout << num << " ";
        }
    }
};


// �������ƶ�
int dx[4] = { 0, -1, 0, 1 }; // �� �� �� ��
int dy[4] = { 1, 0, -1, 0 };
void Move() {
    int n, dis;
    string Command;
    int face = 3; // �տ�ʼ���� dx[3], dy[3]
    int curx = 0, cury = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Command >> dis; // left 3; right 2; forward 1; back 5
        if (Command[0] == 'b') {
            face = (face + 2) % 4;
        }
        else if (Command[0] == 'l') {
            face = (face + 1) % 4;
        }
        else if (Command[0] == 'r') {
            face = (face + 3) % 4;
        }
        curx += dx[face] * dis;
        cury += dy[face] * dis;
    }
    cout << curx << " " << cury << endl;
}
