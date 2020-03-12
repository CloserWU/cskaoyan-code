//
// Created by Closer on 2020/3/11.
//
// 按下标处理点， 用vector表示边

#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int to;
    int length;

    Edge(int to, int length) : to(to), length(length) {}
};

class Point {
public:
    int number;
    int distance;

    Point(int number, int distance) : number(number), distance(distance) {}

    bool operator<(const Point &p) const {
        if (distance == p.distance) {
            return number < p.number;
        }
        return distance > p.distance;
    }
};

vector<Edge> graph[105];
int dis[105];

void Dijkstra(int s) {
    priority_queue<Point> queue;
    dis[s] = 0;
    queue.push(Point(s, dis[s]));
    while (!queue.empty()) {
        int u = queue.top().number;
        queue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            int d = graph[u][i].length;
            if (dis[v] > dis[u] + d) {
                dis[v] = dis[u] + d;
                queue.push(Point(v, dis[v]));
            }
        }
    }
}


int mod(int x, int y) {
    int ret = 1;
    while (y--) {
        ret = (ret * x) % 100000;
    }
    return ret;
}



int test() {
    int n, m;
    while (cin >> n >> m) {
        memset(graph, 0, sizeof(graph));
        fill(dis, dis + n, INT_MAX);
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            if (from == to) continue;
            graph[from].push_back(Edge(to, mod(2, i)));
            graph[to].push_back(Edge(from, mod(2, i)));
        }
        Dijkstra(0);
        for (int i = 1; i < n; ++i) {
            if (dis[i] == INT_MAX) {
                cout << -1 << endl;
            } else {
                cout << dis[i] % 100000 << endl;
            }

        }
    }
     return 0;
}