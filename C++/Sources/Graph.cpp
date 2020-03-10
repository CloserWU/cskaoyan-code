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

}
