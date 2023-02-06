#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<map>
class MyCompare {
public:
    bool operator()(int a, int b) {
        int amod = a % 3;
        int bmod = b % 3;
        /*if (amod == bmod) return a < b;
        return amod < bmod;*/
        return amod == bmod ? a < b : amod < bmod;
    }
};
// 按余数排序
void MySort() {
    vector<int>nums = { 3, 7, 56, 0, 5, 9, 23 };
    sort(nums.begin(), nums.end(), MyCompare());
    for (int num : nums)cout << num << " ";
}

// 按浮点数距离最近整数的大小排序
double EPSILON = 1e-6;
class MyCompare1 {
public:
    bool operator()(double a, double b) {
        double afbs = fabs(a - round(a));
        double bfbs = fabs(b - round(b));
        if (fabs(afbs - bfbs) < EPSILON) { //当两个浮点数相差足够小，则认为这两个浮点数相等
            return a < b;
        }
        return afbs < bfbs;
    }
};
void MySort1() {
    vector<double>nums = { 41.555556 };
    sort(nums.begin(), nums.end(), MyCompare1());
    cout << fixed << setprecision(4) << nums[0] << endl;
}

// 串幸运珠
void MySort2() {
    string s;
    cin >> s;// G R B
    sort(s.begin(), s.end());
    /// <summary>
    /// 一红二绿三蓝组成一串
    /// </summary>
    map<char, int>mp;
    for (char ch : s) {
        mp[ch]++;
    }
    int cnt = 0;
    while (mp['B'] > 0 && mp['G'] > 0 && mp['R'] > 0) {
        cnt++;
        mp['R']--;
        mp['G'] -= 2;
        mp['B'] -= 3;
    }
    cout << cnt << endl;
}

// 按各位数字之和大小排序
class MyCompare3 {
public:
    int getSum(int x) {
        int ret = 0;
        while (x) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
    bool operator()(int a, int b) {
        int aSum = getSum(a);
        int bSum = getSum(b);
        return aSum == bSum ? a < b : aSum < bSum;
    }
};
void MySort3() {
    vector<int>nums;
    sort(nums.begin(), nums.end(), MyCompare3());
}

// 摘气球 
// 输出每个小朋友能够摸到的气球数量
void pickBall() {
    vector<int>cHeight = {1, 3, 4, 5, 7}; // 第i个小朋友能够摸到的高度cHeight[i]
    vector<int>bHeight = {3, 4, 4, 5, 5, 6, 7}; // 第i个气球的高度bHeight[i]
    
    sort(cHeight.begin(), cHeight.end());
    sort(bHeight.begin(), bHeight.end());

    multimap<int, bool>mp;
    for (int h : bHeight) {
        mp.insert(make_pair(h, false)); // false表示没被摘
        //mp[h] = false;
    }

    vector<int>ret(cHeight.size(), 0);
    for (int i = 0; i < cHeight.size(); i++) {
        for (auto& it : mp) {
            if (it.second == false && it.first <= cHeight[i]) {
                ret[i]++;
                it.second = true;
            }
        }
    }
    for (int i = 0; i < ret.size(); i++) {
        cout << "第" << i + 1 << "个小朋友：" << ret[i] << endl;
    }
}
