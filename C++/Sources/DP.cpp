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

void DP::func5() {
    int t, m;
    while (cin >> t >> m) {
        int dp[t + 1];
        int time[m + 1];
        int val[m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &time[i], &val[i]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = t; j >= time[i]; --j) {
                dp[j] = max(dp[j], dp[j - time[i]] + val[i]);
            }
        }
        cout << dp[t] << endl;
    }
}

void DP::func6() {
    int m, n;  // 集齐m，  n张邮票
    const int INF = 1000;
    while (cin >> m >> n) {
        int stamp[n + 1];
        int dp[n + 1][m + 1]; // 前n个邮票，集齐m， 所需要的邮票数
        /*
         dp[i][j] 前i个邮票，集齐j， 所需要的邮票数
         -若第i个邮票不放入，则相当于前i-1张邮票要集齐j， dp[i][j] = dp[i - 1][j]
         -若第j个邮票放入，则相当于前i-1张邮票，集齐j-stamp[i],然后票数加一， dp[i][j] = dp[i - 1][j - stamp[i]] + 1;
         两者取最小值， dp[i][j] = min{dp[i - 1][j], dp[i - 1][j - stamp[i]] + 1 | j > stamp[i]}
         dp[n][m]即为所求。
         那么dp数组如何初始化？边界值设置为几？
         根据定义 -当dp[0...n][0]时，不管有多少张邮票，都要凑成0，则显而易见，一张邮票都不用就行，所以dp[0...n][0] = 0
                 - 当dp[0][1...m]时，没有一张邮票给你，但是要凑 大于0的数，则不可能，所以dp[0][1...m] = INF  (一个很大的数，别是INT_MAX，会爆int)

         做完以上工作，下来就是套01背包的板子
         */
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j == 0) dp[i][j] = 0;
                else dp[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &stamp[i]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= stamp[i]; --j) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - stamp[i]] + 1);
            }
        }
        int res = (dp[n][m] == INF) ? 0 : dp[n][m];
        cout << res << endl;
    }
}
