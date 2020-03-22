//
// Created by Closer on 2020/3/21.
//
#include <bits/stdc++.h>

using namespace std;

/**
cout<<hex<<"hex:i="<<static_cast<unsigned int>(i)<<endl;
cout<<oct<<"oct:i="<<static_cast<unsigned int>(i)<<endl;
cout<<dec<<"dec:i="<<static_cast<unsigned int>(i)<<endl;
cout<<"bin:i="<<bitset<sizeof(unsigned int)*8>(i)<<endl;  // 指定位数
 printf("八进制  %o\n",a);
    printf("十六进制 %x\n",a);
    printf("十进制 %d\n",a);
    printf是格式化输出函数，它可以直接打印十进制，八进制，十六进制，输出控制符分别为%d, %o, %x, 但是它不存在二进制，
 */
void func1() {
    int n;
    int i = 0;
    int a[sizeof(unsigned int) * 8] = {0};
    while (cin >> n) {
        i = 0;
        memset(a, 0, sizeof(a));
        while (n != 0) {
            a[i] = n % 2;
            n /= 2;
        }
        for (int j = i - 1; j >= 0; --j) {
            printf("%d", a[j]);
        }
        printf("\n");
    }
}

void func2() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> queue;
    for (int i = 0; i < n; ++i) {
        int rmp;
        cin >> rmp;
        queue.push(rmp);
    }
    int res = 0;
    while (queue.size() > 1) {
        int a = queue.top();
        queue.pop();
        int b = queue.top();
        queue.pop();
        res += a + b;
        queue.push(a + b);
    }
    cout << res << endl;

}


void func3() {
    int n;
    while (cin >> n) {
        int a[n];
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                odd++;
            } else {
                even++;
            }
        }
        if (odd > even) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

void func4() {
    int n;
    while (cin >> n) {
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int k;
        cin >> k;
        int tmp = a[0];
        for (int i = 1; i < n; ++i) {
            if (k == 1) {
                cout << tmp << endl;
                break;
            }
            if (tmp != a[i]) {
                k--;
                tmp = a[i];
            }
        }
    }
}

void func4_v2() {
    int n;
    while (cin >> n) {
        priority_queue<int, vector<int>, greater<int>> queue;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            queue.push(tmp);
        }
        int idx;
        cin >> idx;
        for (int i = 0; i < n; ++i) {
            s.insert(queue.top());
            if (s.size() == idx) {
                cout << queue.top() << endl;
                break;
            }
            queue.pop();
        }
    }
}

class Matrix {
public:
    int row;
    int col;
    int matrix[10][10];

    Matrix(int row, int col) : row(row), col(col) {}
};

Matrix Multiply(Matrix x, Matrix y) {
    Matrix answer(x.row, y.col);
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < y.col; ++j) {
            answer.matrix[i][j] = 0;
            for (int k = 0; k < x.col; ++k) {
                answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
            }
        }
    }
    return answer;
}

Matrix FastExp(Matrix x, int k) {
    Matrix answer(x.row, x.col);
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            if (i == j) answer.matrix[i][j] = 1;
            else answer.matrix[i][j] = 0;
        }
    }
    while (k != 0) {
        if (k % 2 == 1) {
            answer = Multiply(answer, x);
        }
        k /= 2;
        x = Multiply(x, x);
    }
    return answer;
}

void PrintMatrix(Matrix x) {
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", x.matrix[i][j]);
        }
        printf("\n");
    }
}

void func5() {
    int n, k;
    while (cin >> n >> k) {
        Matrix x(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> x.matrix[i][j];
            }
        }
        PrintMatrix(FastExp(x, k));
    }
}

void func6() {
    //
}

void func7() {
    string str1;
    string str2;
    map<int, int> m;
    map<int, int>::iterator it;
    while (cin >> str1 >> str2) {
        m.clear();
        for (int i = 0; i < str1.size(); ++i) {
            m[str1[i] - '0']++;
        }
        int len = str2.size();
        bool flag = false;
        if (len < 5) {
            for (it = m.begin(); it != m.end(); it++) {
                if (it->first > str2[0] - '0' && it->second >= len) {
                    flag = true;
                    break;
                }
            }
        } else {
            for (it = m.begin(); it != m.end(); it++) {
                if (it->first > str2[0] - '0') {
                    int l = 0;
                    int pre = it->first - 1;
                    map<int, int>::iterator tmp;
                    for (tmp = it; tmp != m.end(); tmp++) {
                        if (tmp->first == pre + 1) {
                            l++;
                            pre = tmp->first;
                        } else {
                            break;
                        }
                    }
                    if (l >= 5) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

void func8() {
    int n;
    while (cin >> n) {
        int tree[n];
        for (int i = 0; i < n; ++i) {
            cin >> tree[i];
        }
        int depth;
        cin >> depth;
        int bak = depth;
        int idx1 = 1;
        int x = 2;
        depth--;
        // 快速幂
        while (depth != 0) {
            if (depth % 2 == 1) {
                idx1 *= x;
            }
            x *= x;
            depth /= 2;
        }
        int idx2 = 1;
        x = 2;
        depth = bak;
        while (depth != 0) {
            if (depth % 2 == 1) {
                idx2 *= x;
            }
            x *= x;
            depth /= 2;
        }
        if (idx1 > n) {
            cout << "EMPTY" << endl;
        } else {
            for (int i = idx1 - 1; i < n && i < idx2 - 1; ++i) {
                if (i != idx1 - 1) printf(" ");
                printf("%d", tree[i]);
            }
            printf("\n");
        }
    }
}

void func9() {
    string str;
    while (cin >> str) {
        int n;
        cin >> n;
        string command;
        while (n != 0) {
            cin >> command;
            if (command[0] == '0') {
                for (int i = 0; i < (command[2] - '0') / 2; ++i) {
                    char ch = str[i + command[1] - '0'];
                    str[i + command[1] - '0'] = str[command[1] - '0' + command[2] - '0' - 1 - i];
                    str[command[1] - '0' + command[2] - '0' - 1 - i] = ch;
                }
            } else {
                str = str.substr(0, command[1] - '0') + command.substr(3) +
                      str.substr(command[1] + command[2] - 2 * '0');
            }
            cout << str << endl;
            n--;
        }
    }
}

class Complex {
public:
    int x;
    int y;

    Complex(int x, int y) : x(x), y(y) {}

    // 优先队列复杂类型的自定义排序
    bool operator<(Complex c) const {
        return x * x + y * y < c.x * c.x + c.y * c.y;
    }
};

void func10() {
    int n;
    priority_queue<Complex> queue;
    while (cin >> n) {
        while (!queue.empty()) {
            queue.pop();
        }
        string command;
        while (n != 0) {
            n--;
            cin >> command;
            if (command == "Pop") {
                if (queue.size() == 0) {
                    printf("empty\n");
                } else {
                    Complex c = queue.top();
                    queue.pop();
                    printf("%d+i%d\nSIZE = %d\n", c.x, c.y, queue.size());
                }
            } else {
                int x, y;
                scanf("%d+i%d", &x, &y);
                queue.push(Complex(x, y));
                printf("SIZE = %d\n", queue.size());
            }
        }
    }
}