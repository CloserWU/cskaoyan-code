//
// Created by Closer on 2020/3/14.
//
#include "../Headers/DP.h"


void DP::func1() {
    int dp[20];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 20; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
}

class Seq {
public:
    int begin;
    int end;
    int val;
};

void DP::func2() {
    int dp[10001];
    int arr[10001];
    int k;
    while (cin >> k) {
        if (k == 0) break;
        bool flag = false;
        int maximum = INT_MIN;
        int begin = 0, end = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < k; ++i) {
            scanf("%d", &arr[i]);
            if (arr[i] >= 0) flag = true;
            if (i == 0)
                dp[i] = arr[i];
            else {
                dp[i] = max(arr[i] + dp[i - 1], arr[i]);
            }
            if (maximum < dp[i]) {  // 记路当前最优队列的结尾下标
                end = i;
            }
            maximum = max(maximum, dp[i]);
        }
        // 从结尾加标开始往后找，第一个dp[i]小于零的，begin即为次下标下一个
        for (int i = end; i >= 0; --i) {
            if (dp[i] < 0) {
                begin = i + 1;
                break;
            }
        }
        if (flag) printf("%d %d %d\n", maximum, arr[begin], arr[end]);
        else printf("%d %d %d\n", 0, arr[0], arr[k - 1]);
    }
}

void DP::func3() {
    int n;
    while (cin >> n) {
        // 从左往右升序DP，dp_asc[i]表示i位置为结束的最长递子序列长度
        int dp_asc[n];
        // 从右往左降序DP, dp_desc[i]表示以i为结尾的最长递减子序列长度
        int dp_desc[n];
        int std[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &std[i]);
        }
        // 升序DP dp[i] = max{1, dp[j] + 1 | j < i && std[i] > std[j]}
        for (int i = 0; i < n; ++i) {
            dp_asc[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (std[i] > std[j]) {
                    dp_asc[i] = max(dp_asc[i], dp_asc[j] + 1);
                }
            }
        }
        // 降序DP dp[i] = max{1, dp[j] + 1 | j < i && std[i] < std[j]}
        // 这里从后往前推，注意if判断
        for (int i = n - 1; i >= 0; --i) {
            dp_desc[i] = 1;
            for (int j = n - 1; j > i; --j) {
                if (std[i] > std[j]) {
                    dp_desc[i] = max(dp_desc[i], dp_desc[j] + 1);
                }
            }
        }
        int maxN = -1;
        // 遍历两个DP
        for (int i = 0; i < n; ++i) {
            maxN = max(maxN, dp_asc[i] + dp_desc[i] - 1);  // 减去重复计算的i
        }
        cout << n - maxN << endl;
    }
}

void DP::func4() {
    char s1[101];
    char s2[101];
    int dp[101][101];
    while (scanf("%s%s", s1 + 1, s2 + 1) != EOF) {
        int n = strlen(s1 + 1);
        int m = strlen(s2 + 1);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}
