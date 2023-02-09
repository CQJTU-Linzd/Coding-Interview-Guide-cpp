#include"headFile.h"

// 给定一个矩阵，只有0和1
// 找到最大的 全为1 的子矩阵，返回其1的数量
class MaxSubMatrix {
public:
    int maxRecSize(vector<vector<int>>& map) {
        if (map.size() == 0 || map[0].size() == 0) {
            return 0;
        }
        int maxArea = 0;
        vector<int>height(map[0].size());
        for (int i = 0; i < map.size(); i++) {
            // 每一行，生成相应的height数组
            for (int j = 0; j < map[0].size(); j++) {
                height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
            }
            // 直方图里找最大矩形
            maxArea = max(maxArea, maxRecFromBottom(height));
        }
        return maxArea;
    }
    int maxRecFromBottom(vector<int>& height) {
        int maxArea = 0;
        stack<int>stack;
        for (int i = 0; i < height.size(); i++) {
            while (!stack.empty() && height[stack.top()] >= height[i]) {
                int j = stack.top();
                stack.pop();
                int k = stack.empty() ? -1 : stack.top();
                int curArea = (i - k - 1) * height[j];
                maxArea = max(maxArea, curArea);
            }
            stack.push(i);
        }
        // 清算
        int i = height.size();
        while (!stack.empty()) {
            int j = stack.top();
            stack.pop();
            int k = stack.empty() ? -1 : stack.top();
            int curArea = (i - k - 1) * height[j];
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }

    // for test
    bool check(vector<vector<int>>& map, int a, int b, int c, int d) {
        for (int i = a; i <= c; i++) {
            for (int j = b; j <= d; j++) {
                if (map[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    int maxRecSize2(vector<vector<int>>& map) {
        if (map.size() == 0 || map[0].size() == 0) {
            return 0;
        }
        int maxArea = 0;
        for (int a = 0; a < map.size(); a++) {
            for (int b = a; b < map.size(); b++) {
                for (int c = 0; c < map[0].size(); c++) {
                    for (int d = c; d < map[0].size(); d++) {
                        if (check(map, a, c, b, d)) {
                            int curArea = (b - a + 1) * (d - c + 1);
                            maxArea = max(maxArea, curArea);
                        }
                    }
                }
            }
        }
        return maxArea;
    }

    vector<vector<int>> randomMatrix(int maxrow, int maxcol, int l, int r) {
        srand(time(0));
        int n = rand() % maxrow + 1;
        int m = rand() % maxcol + 1;
        vector<vector<int>>matrix(n, vector<int>(m));
        for (vector<int>& nums : matrix) {
            for (int& num : nums) {
                num = rand() % (r - l + 1) + l;
            }
        }
        return matrix;
    }

    void test() {
        for (int test = 0; test < 10000; test++) {
            vector<vector<int>>matrix = randomMatrix(100, 100, 0, 1);
            int ans1 = maxRecSize(matrix);
            int ans2 = maxRecSize2(matrix);
            if (ans1 != ans2) {
                cout << "fuck!!!" << endl;
            }
        }
        cout << "end" << endl;
    }
};