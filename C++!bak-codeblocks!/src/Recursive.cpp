#include "../include/Recursive.h"

void Recursive::func1() {
    int m;
    while (cin >> m) {
        int vv[m][m];
        for (int i = 0; i < m; ++i) {
            vv[i][0] = 1;
            vv[i][i] = 1;
            if (i >= 1 && i <= m - 1) {
                for (int j = 1; j < i; ++j) {
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                }
            }
        }
        for (int i = 1; i < m - 1; ++i) {
            vv[m - 1][i] = vv[m - 2][i] + vv[m - 2][i - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                cout << vv[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int length;
bool flags[7] = {false};
char ch[7];
void recursive(string str, int len) {
    if (length == len) {
        cout << ch << endl;
        return;
    }
    for (int i = 0; i < length; ++i) {
        if (!flags[i]) {
            ch[len] = str[i];
            flags[i] = true;
            recursive(str, len + 1);
            flags[i] = false;
        }
    }

}

void Recursive::func2() {
    string str;
    while (cin >> str) {
        length = str.size();
        sort(str.begin(), str.end());
        recursive(str, 0);
        cout << endl;
    }
}




vector<int> v;

string gcg(int m) {
    string str;
    int idx = 0;
    if (m == 0) return "0";
    if (m == 2) return "2";
    while (m != 0) {
        if (m >= v[idx]) {
            m -= v[idx];
            if (idx == 13) {
                str += "+2";
            } else {
                str += "+2(" + gcg(14 - idx) + ")";
            }
        }
        idx++;
    }
    return str.substr(1);
}

void Recursive::func3() {
    v.clear();
    for (int i = 0; i <= 14; ++i) {
        v.push_back(pow(2, 14 - i));
        cout<< v[i] << " ";
    }
    cout << endl;
    int m;
    while (cin >> m) {
        cout << gcg(m) << endl;
    }
}


