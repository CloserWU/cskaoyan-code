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
        for (int i = end; i >=0 ; --i) {
            if (dp[i] < 0) {
                begin = i + 1;
                break;
            }
        }
        if (flag) printf("%d %d %d\n", maximum, arr[begin], arr[end]);
        else printf("%d %d %d\n", 0, arr[0], arr[k - 1]);
    }
}
