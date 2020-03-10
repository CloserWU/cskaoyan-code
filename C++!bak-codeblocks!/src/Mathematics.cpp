#include "../include/Mathematics.h"

void Mathematics::func1() {
    int n;
    while(cin >> n) {
        vector<int> v;
        while(n != 0) {
            v.push_back(n % 8);
            n /= 8;
        }
        long long res = 0;
        for(int i = v.size() - 1; i >= 0; i--) {
            cout << v[i];
        }
        cout << endl;
    }
}

void Mathematics::func2() {
    int m = 1, A, B;
    cin >> m;
    while(m != 0) {
        cin >> A >> B;
        long res = (long) A + B;
        vector<int> v;
        if(res == 0) v.push_back(0);
        while(res != 0) {
            v.push_back(res % m);
            res /= m;
        }
        for(int i = v.size() - 1; i >= 0; i--) {
            cout << v[i];
        }
        cout << endl;
        cin >> m;
    }
}
map<char, int> m;

string Multiple(string str, int x) {
    int carry = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        int current = m[str[i]] * x + carry;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if(carry != 0) {
        str = "1" + str;
    }
    return str;
}

string Add(string str, int x) {
    int carry = x;
    for(int i = str.size() - 1; i >= 0; i++) {
        int current = m[str[i]] + carry;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if(carry != 0) {
        str = "1" + str;
    }
    return str;
}

void Mathematics::func3() {
    /**
    int num = 0;
    while (~scanf ("%x", &num))
        printf("%d\n",  num);
    return 0;
    */

    /**
    while(cin>>hex>>n){
        cout<<dec<<n<<endl;
    }
    */
    m['0'] = 0;m['1'] = 1;m['2'] = 2;m['3'] = 3;
    m['4'] = 4;m['5'] = 5;m['6'] = 6;m['7'] = 7;
    m['8'] = 8;m['9'] = 9;
    m['A'] = 10;m['a'] = 10;
    m['B'] = 11;m['b'] = 11;
    m['C'] = 12;m['c'] = 12;
    m['D'] = 13;m['d'] = 13;
    m['E'] = 14;m['e'] = 14;
    m['F'] = 15;m['f'] = 15;
    string str;
    while(cin >> str) {
        int res = 0;
        for(int i = str.size() - 1; i >=2; i--) {
                // c++ pow 指数为0时， 返回0
            res += m[str[i]] * pow(16, str.size() - 1 - i);
        }
        cout << res << endl;
    }

}

void Mathematics::func4() {
    m['0'] = 0;m['1'] = 1;m['2'] = 2;m['3'] = 3;
    m['4'] = 4;m['5'] = 5;m['6'] = 6;m['7'] = 7;
    m['8'] = 8;m['9'] = 9;
    m['A'] = 10;m['a'] = 10;
    m['B'] = 11;m['b'] = 11;
    m['C'] = 12;m['c'] = 12;
    m['D'] = 13;m['d'] = 13;
    m['E'] = 14;m['e'] = 14;
    m['F'] = 15;m['f'] = 15;
    string n;
    int a, b;
    while(cin >> a >> n >> b) {
        long long res = 0;
        for(int i = n.size() - 1; i >= 0; i--) {
            double p = pow(a, n.size() - 1 - i);
            res += m[n[i]] * p;
            ///res += m[n[i]] * pow(a, n.size() - 1 - i); 精度丢失, pow的返回值一定要赋值给double
            /// https://www.cnblogs.com/someblue/p/3397715.html
        }
        vector<char> v;
        while(res != 0) {
            int mod = res % b;
            if(mod >= 10) {
                v.push_back((char)(mod - 10 + 'A'));
            } else {
                v.push_back((char)(mod + '0'));
            }
            res /= b;
        }
        for(int i = v.size() - 1; i >= 0; i--) {
            cout << v[i];
        }
        cout << endl;
    }
}

// a < b
int GCD(int a, int b) {
    if(a == 0) {
        return b;
    } else {
        return GCD(b % a, a);
    }
}

void Mathematics::func5() {
    int n;
    while(cin >> n) {
        if(n == 0) break;
        int num = 0;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(GCD(v[j], v[i]) == 1) {
                    num++;
                }
            }
        }
        cout << num << endl;
    }
}

void Mathematics::func6() {
    int n;
    while(cin >> n) {
        vector<int> v;
        bool mark[150000];
        memset(mark, 150000,true);
        mark[0] = false;
        mark[1] = false;
        for(int i = 2; i < 100000; i++) {
            if(mark[i]) {
                n--;
                v.push_back(i);
                // int j = i * i 爆int
                for(int j = i * 2; j < 100000; j += i) {
                    mark[j] = false;
                }
            }
            if(n == 0) {
                cout << v[v.size() - 1] << endl;
                break;
            }
        }
    }
}

void Mathematics::func7() {
    int n;
    ///因为小于sqrt(n)的数i如果能整除n，则必定还有一个>sqrt(n)的因数j，使得i*j=n。
    ///+2是把这两个因数都算进去了。最后如果i*i=n，说明有两个相同的i是因数，只算一个。
    while(cin >> n) {
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            int tmp;/// long long tmp; 错 j*j 和 longlong型无法比较
            scanf("%d", &tmp);
            int num = 0;
            int j;
            for(j = 1; j * j < tmp; j++) {
                if(tmp % j == 0) {
                    num += 2;
                }
            }
            if(j * j == tmp) num++;
            printf("%d\n", num);
        }
    }
}

void Mathematics::func8() {
    /// TODO
}

int FastExp(long long x, long long y, long long k) {
    long long res = 1;
    for (; y; y >>= 1, x = x * x % k) {
        if (y & 1) {
            res = res * x % k;
        }
    }
    return res;
}

void Mathematics::func9() {
    int x, y, k;
    while (cin >> x >> y >> k) {
        int ans = FastExp(x, y, k - 1);
        if (ans == 0) {
            ans = k - 1;
        }
        cout << ans << endl;
    }
}

void Mathematics::func10() {
    int n, m;
    while (cin >> n) {
        if (n == 0) break;
        cin >> m;
        int A[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        int tmp;
        int res = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            flag = true;
            for (int j = 0; j < m; j++) {
                cin >> tmp;
                A[i][j] += tmp;
                if (A[i][j] != 0) flag = false;
            }
            if (flag) res++;
        }

        for (int j = 0; j < m; ++j) {
            flag = true;
            for (int i = 0; i < n; i++) {
                if (A[i][j] != 0) flag = false;
            }
            if (flag) res++;
        }
        cout << res << endl;
    }
}

void Mathematics::func11() {
    int a0, a1, p, q, k, i, a;
    while (cin >> a0 >> a1 >> p >> q >> k) {
        for (i = 2; i <= k; i++) {
            a = (p * a1 + q * a0);
            a0 = a1 % 10000;
            a1 = a % 10000;
        }
        cout << a1 << endl;
    }
}

void Mathematics::func12() {
    /// Java BigInteger
}

void Mathematics::func13() {
    /// Java BigInteger
}
