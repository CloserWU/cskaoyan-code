//
// Created by Closer on 2020/3/8.
//

#include "../Headers/Graph.h"

#include <utility>

class Node {
public:
    int p1;
    int p2;

    Node() {
        this->p1 = -1;
        this->p2 = -1;
    }

    Node(int p1, int p2) : p1(p1), p2(p2) {}
};

Node tree[26];

/* 对象数组
Student stud[3]={//假设构造函数有3个参数
Student(10,20,30),//调用第一个元素的构造函数，提供3个实参
Student(40,50,60),//调用第二个元素的构造函数，提供3个实参
Student(70,80,90) //调用第三个元素的构造函数，提供3个实参
};
*/

int preOrder(int from, int to, int depth) {
    if (from == to) return depth;
    if (tree[from].p1 != -1) {
        int res = preOrder(tree[from].p1, to, depth + 1);
        if (res != -1) return res;
    }
    if (tree[from].p2 != -1) {
        int res = preOrder(tree[from].p2, to, depth + 1);
        if (res != -1) return res;
    }
    return -1;
}

void Graph::func1() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (str[1] != '-') tree[str[0] - 'A'].p1 = str[1] - 'A';
        if (str[2] != '-') tree[str[0] - 'A'].p2 = str[2] - 'A';
    }
    for (int i = 0; i < m; ++i) {
        string str;
        cin >> str;
        int from = str[0] - 'A';
        int to = str[1] - 'A';
        int depth = preOrder(from, to, 0);
        if (depth > 0) {
            if (depth == 1) {
                cout << "child" << endl;
            } else {
                for (int j = 0; j < depth - 2; ++j) {
                    cout << "great-";
                }
                cout << "grandchild" << endl;
            }
        } else {
            depth = preOrder(to, from, 0);
            if (depth > 0) {
                if (depth == 1) {
                    cout << "parent" << endl;
                } else {
                    for (int j = 0; j < depth - 2; ++j) {
                        cout << "great-";
                    }
                    cout << "grandparent" << endl;
                }
            } else {
                cout << "-" << endl;
            }
        }
    }
}

// 并查集 数组方法86ms， map方法500+ms
map<int, int> father; // <int -> 下标, int -> 父节点下标>
map<int, int> height;
/*
int father[1000010];
int height[1000010];
bool visit[1000010];
 */

/*
void Initial() {
    for (int i = 0; i < 1000010; ++i) {
        father[i] = i;
        height[i] = 0;
        visit[i] = false;
    }
}
 */
// 找到下标为x的父节点的下标
int Find(int x) {
    /*
     if (x != father[x]) {
        father[x] = Find(father[x]);
     }
     return father[x];
     */
    if (father.find(x) != father.end()) {
        if (x != father[x]) {
            father[x] = Find(father[x]);
        }
    } else {
        father[x] = x;
        height[x] = 0;
    }
    return father[x];
}

// 同父聚合
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[x] > height[y]) {
            father[y] = x;
        } else {
            father[x] = y;
            height[y]++;
        }
    }
}

void Graph::func2() {
    int x, y;
//    int maxNode = 0;
    while (cin >> x >> y) {
        /*maxNode = max(maxNode, x);
        maxNode = max(maxNode, y);
        visit[x] = true;
        visit[y] = true;*/
        Union(x, y);
    }
    int component = 0;
    for (auto &i : father) {
//        if (visit[i] && Find(i) == i) component++;
        if (i.first == i.second) component++;
    }
    cout << component << endl;
}


void Graph::func3() {
//        见 DS/Graph.cpp test()
}

class Ed {
public:
    int from;
    int to;
    double weight;

    Ed(int from, int to, double weight) : from(from), to(to), weight(weight) {}

    bool operator<(const Ed &e) const {
        return weight < e.weight;
    }
};

double getDist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}

double Kruskal(vector<Ed> ve) {
    sort(ve.begin(), ve.end());
    double sum = 0.0;
    for (auto cur : ve) {
        if (Find(cur.from) != Find(cur.to)) {
            Union(cur.from, cur.to);
            sum += cur.weight;
        }
    }
    return sum;
}

void Graph::func4() {
    int n;
    while (cin >> n) {
        double x;
        double y;
        vector<pair<double, double>> vp;
        vector<Ed> ve;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            vp.push_back(make_pair(x, y));
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ve.push_back(Ed(i, j, getDist(vp[i], vp[j])));
            }
        }
        cout << fixed << setprecision(2) << Kruskal(ve) << endl;
    }

}

void Graph::func5() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<Ed> ve;
        father.clear();
        height.clear();
        ve.clear();
        for (int i = 0; i < n - 1; ++i) {
            char from;
            int m;
            cin >> from >> m;
            for (int j = 0; j < m; ++j) {
                int dist;
                char to;
                cin >> to >> dist;
                ve.push_back(Ed(from - 'A', to - 'A', dist));
            }
        }
        cout << (int) Kruskal(ve) << endl;
    }
}

void Graph::func6() {
 // DS/Graph.cpp 和 DS/Graph01.cpp 分别从链表和数组的形式表达了图的形状，
 // 本题数据较大，long 和 int都剩不下。改用java，详见Graph.java 和 Graph01.java （最终解）
}

void Graph::func7() {

}

