//
// Created by Closer on 2020/3/6.
//

#include "../include/DataStructure2.h"

class BTree {
public:
    BTree* left;
    BTree* right;
    int data;
    BTree(int data) : data(data), left(nullptr), right(nullptr) {}
};



int SearchStep(BTree* root, int target, int step) {
    if (root != nullptr) {
        step++;
        if (root -> data == target) {
            return step;
        } else if (root -> data < target) {
            return SearchStep(root -> left, target, step);
        } else {
            return SearchStep(root -> right, target, step);
        }
    }
    return -1;
}

BTree* BuildBST(BTree* root, int x) {
    if (root == nullptr) {
        root = new BTree(x);
    } else if (root -> data < x) {
        root -> left = BuildBST(root -> left, x);
    } else {
        root -> right = BuildBST(root -> right, x);
    }
    return root;
}

bool JudgeSameBST(BTree* root, BTree* root1) {
    if (root == nullptr && root1 != nullptr) return false;
    if (root1 == nullptr && root != nullptr) return false;
    if (root1 != nullptr && root != nullptr) {
        if (root -> data != root1 -> data) {
            return false;
        } else {
            return JudgeSameBST(root -> left, root1 -> left) && JudgeSameBST(root -> right, root1 -> right);
        }
    }
    return true;
}

void DataStructure2::func1() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        string build;
        cin >> build;
        BTree* root = nullptr;
        map<int, int> m;
        for (char i : build) {
            root = BuildBST(root, i - '0');
        }
        for (int i = 0; i < n; ++i) {
            BTree* root1 = nullptr;
            build.clear();
            cin >> build;
            for (char j : build) {
                root1 = BuildBST(root1, j - '0');
            }
            if (JudgeSameBST(root, root1)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

void DataStructure2::func2() {
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

void DataStructure2::func3() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            queue.push(tmp);
        }
        int ans = 0;
        while (queue.size() > 1) {
            int a = queue.top();
            queue.pop();
            int b = queue.top();
            queue.pop();
            ans += a + b;
            queue.push(a + b);
        }
        cout << ans << endl;
    }
}

void DataStructure2::func4() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            m[tmp]++;
        }
        int s;
        cin >> s;
        cout << m[s] << endl;
    }

}

class Sign {
public:
    string id;
    int a_h;
    int a_m;
    int a_s;
    int l_h;
    int l_m;
    int l_s;
    Sign(string id, int a_h, int a_m, int a_s, int l_h, int l_m, int l_s)
        : id(move(id)), a_h(a_h), a_m(a_m), a_s(a_s), l_h(l_h), l_m(l_m), l_s(l_s) {}
    /*bool operator < (const Sign& sign) const  {
        if (sign.h == h) {
            if (sign.m == m) {
                return sign.s < s;
            }
            return sign.m < m;
        } else {
            return sign.h < h;
        }
    }*/
};

bool cmpArrive(const Sign& s1, const Sign& s2) {  // 小到大
    if (s1.a_h == s2.a_h) {
        if (s1.a_m == s2.a_m) {
            return s1.a_s < s2.a_s;
        }
        return s1.a_m < s2.a_m;
    } else {
        return s1.a_h < s2.a_h;
    }
}

bool cmpLeave(const Sign& s1, const Sign& s2) {  // 小到大
    if (s1.l_h == s2.l_h) {
        if (s1.l_m == s2.l_m) {
            return s1.l_s < s2.l_s;
        }
        return s1.l_m < s2.l_m;
    } else {
        return s1.l_h < s2.l_h;
    }
}

void DataStructure2::func5() {
    int n;
    cin >> n;
    getchar();
    vector<Sign> v;
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        int pos1 = str.find_first_of(' ');
        int pos2 = str.find_last_of(' ');
//        cout << pos1 << endl << pos2 << endl;
        string id = str.substr(0, pos1);
        string arrive = str.substr(pos1 + 1, pos2 - pos1 - 1);
        string leave = str.substr(pos2 + 1);
//        cout << id << endl << arrive << endl << leave << endl;

        int posa1 = arrive.find_first_of(':');
        int posa2 = arrive.find_last_of(':');

        int a_h = stoi(arrive.substr(0, posa1));
        int a_m = stoi(arrive.substr(posa1 + 1, posa2 - posa1 - 1));
        int a_s = stoi(arrive.substr(posa2 + 1));

        int posl1 = leave.find_first_of(':');
        int posl2 = leave.find_last_of(':');

        int l_h = stoi(leave.substr(0, posl1));
        int l_m = stoi(leave.substr(posl1 + 1, posl2 - posl1 - 1));
        int l_s = stoi(leave.substr(posl2 + 1));

        v.push_back(Sign(id, a_h, a_m, a_s, l_h, l_m, l_s));
    }
    sort(v.begin(), v.end(), cmpArrive);
    cout << v[0].id;
    sort(v.begin(), v.end(), cmpLeave);
    cout << " " << v[v.size() - 1].id << endl;

}
/*
链接：https://www.nowcoder.com/questionTerminal/a4b37b53a44d454ab0834e1517983215?f=discussion
来源：牛客网

//取巧使用map的字典序和映射特性
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  std::map<string, string> open;
  std::map<string, string> close;
  string tmp1,tmp2,tmp3;
  int n,i;
  while (cin>>n) {
for ( i = 0; i < n; i++) {
cin>>tmp1>>tmp2>>tmp3;
open.insert(pair<string,string>(tmp2,tmp1));
close.insert(pair<string,string>(tmp3,tmp1));
}
cout<<open.begin()->second;
cout<<' ';
cout<<close.rbegin()->second;
}
return 0;
}
 */


void DataStructure2::func6() {
    int n, m;
    cin >> n >> m;
    map<int, int> mm;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        mm[tmp]++;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        if (mm[v[i]]  > 1) {
            cout << mm[v[i]] - 1 << endl;
        } else {
            cout << "BeiJu" << endl;
        }
    }
}

