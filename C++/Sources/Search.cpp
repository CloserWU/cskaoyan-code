//
// Created by Closer on 2020/3/4.
//

#include "../Headers/Search.h"

map<string, int> mm;
queue<string> q;

bool Judge(string str) {
    return str.find("2012") != string::npos;
}

string Swap(string str, int idx) {
    char ch = str[idx];
    str[idx] = str[idx + 1];
    str[idx + 1] = ch;
    return str;
}

int BFS(string str) {
    mm.clear();
    while (!q.empty()) q.pop();
    q.push(str);
    mm[str] = 0;
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        for (int i = 0; i < str.size() - 1; ++i) {
            string newS = Swap(s, i);
            if (mm.find(newS) == mm.end()) {
                mm[newS] = mm[s] + 1;
                if (Judge(newS)) return mm[newS];
                else q.push(newS);
            }
        }
    }
    return -1;
}

void Search::func1() {
    int n;
    string str;
    while (cin >> n >> str) {
        if (Judge(str)) cout << 0 << endl;
        else cout << BFS(str) << endl;
    }
}

class Status {
public:
    int pos;
    int remain;

    Status() {
        this->pos = 0;
        this->remain = 0;
    }

    Status(int pos, int remain) : pos(pos), remain(remain) {}
};

void Search::func2() {
    int n;
    while (cin >> n) {
        int ans = 0;
        vector<int> v(n);
        vector<bool> flags(n);
        queue<Status> s;
        Status st(0, 40);
        s.push(st);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }
        int index;
        while (!s.empty()) {
            st = s.front();
            s.pop();
            index = st.pos;
            if (st.remain == 0) {
                ans++;
//                cout << st.pos << " " << st.remain << endl;
                continue;
            }
            if (index < n) {
                Status stu(index + 1, st.remain);
                s.push(stu);
                stu.remain -= v[index];
                if (stu.remain >= 0)
                    s.push(stu);
            }
        }
        cout << ans << endl;
    }

}

/**
#include <stdio.h>

int n;
int a[21];

int count(int i, int V) {
    if (V == 0)
        return 1;
    if (i == n || V < 0)
        return 0;
    return count(i+1, V-a[i]) + count(i+1, V);
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        printf("%d\n", count(0, 40));
    }
    return 0;
}
*/

int queen[95][8];
int one[8];
int total = 0;
void Judge(int idx) {
    if (idx == 8) {
        total++;
        for (int i = 0; i < 8; ++i) {
            queen[total][i] = one[i];
        }
    } else {
        // i 是列 ,  j 是行
        for (int i = 0; i < 8; ++i) {
            bool flag = true;
            one[idx] = i;
            for (int j = 0; j < idx; ++j) {
                if (one[j] == i || idx - i == j - one[j] || idx + i == one[j] + j) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                Judge(idx + 1);
            }
        }
    }
}

void Search::func3() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Judge(0);
        int b;
        cin >> b;
        for (int j = 0; j < 8; ++j) {
            cout << queen[b][j] + 1;
        }
        cout << endl;
    }
}
