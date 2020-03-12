//
// Created by Closer on 2020/3/11.
//
// 按下标处理点， 用vector表示边
// 形参问题， 以及容器的清空

// == 重载
#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int to;
    int length;

    Edge(int to, int length) : to(to), length(length) {}

    bool operator==(const Edge &x) {
        return x.to == to;
    }
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

vector<Edge> graph[605];
int dis[605];

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

vector<int> Dijkstra(int s, vector<int> camps) {
    priority_queue<Point> queue;
    vector<int> dist(605);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[s] = 0;
    queue.push(Point(s, dist[s]));
    while (!queue.empty()) {
        int u = queue.top().number;
        queue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            if (find(camps.begin(), camps.end(), v) != camps.end()) { // 若不是阵营，则跳过
                int d = graph[u][i].length;
                if (dist[v] > dist[u] + d) {
                    dist[v] = dist[u] + d;
                    queue.push(Point(v, dist[v]));
                }
            }
        }
    }
    return dist;
}


//先用两次dijkstra算法，分别求出1、2到同阵营各城市的最短路径长度，结果分别存在d1[N]、d2[N]。
//再遍历穿越边境的边，比方说<i, j>穿越边境且i、j分别属于阵营1、阵营2，G[i][j]是i到j的距离，
// 那么G[i][j]+d1[i]+d2[j]就是从这条路过境的总路径长度。找出这类路径长度里最短的那条，输出即可
int test1() {
    int n, m;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> camp1;
        vector<int> camp2;
        cin >> m;
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < m; ++i) {
            int from, to, weight;
            cin >> from >> to >> weight;
            if (from == to) continue;
            // 测试用例里有重边
            vector<Edge> ve1 = graph[from];
            Edge edge1(to, 0);
            vector<Edge>::iterator pos1 = find(ve1.begin(), ve1.end(), edge1);
            // ！！！！！！pos1->length = ... 将并不能改变graph中的值！！！！！
            if (pos1 != ve1.end()) graph[from][pos1 - ve1.begin()].length = min(pos1->length, weight);
            else graph[from].push_back(Edge(to, weight));

            vector<Edge> ve2 = graph[to];
            Edge edge2(from, 0);
            vector<Edge>::iterator pos2 = find(ve2.begin(), ve2.end(), edge2);
            // ！！！！！！pos2->length = ... 将并不能改变graph中的值！！！！！
            if (pos2 != ve2.end()) graph[to][pos2 - ve2.begin()].length = min(pos2->length, weight);
            else graph[to].push_back(Edge(from, weight));
        }
        for (int i = 0; i < n; ++i) {
            int camp = 0;
            cin >> camp;
            if (camp == 1) camp1.push_back(i + 1);
            else camp2.push_back(i + 1);
        }
        //先用两次dijkstra算法，分别求出1、2到同阵营各城市的最短路径长度，结果分别存在d1[N]、d2[N]。
        vector<int> dist1 = Dijkstra(1, camp1);  // 阵营1最短路
        vector<int> dist2 = Dijkstra(2, camp2);  // 阵营2最短路
        vector<pair<int, int>> vp; // 跨阵营1，2的边 的顶点
        vector<int> vplen;  // 跨阵营1， 2的边的weight
        //再遍历穿越边境的边，比方说<i, j>穿越边境且i、j分别属于阵营1、阵营2，G[i][j]是i到j的距离，
        for (int &i : camp1) {
            vector<Edge> ve = graph[i];
            for (int &j : camp2) {
                Edge edge(j, 0);
                auto pos = find(ve.begin(), ve.end(), edge);
                if (pos != ve.end()) {
                    vp.push_back(make_pair(i, j));
                    vplen.push_back(pos->length);
                }
            }
            ve.clear();
        }
        // 那么G[i][j]+d1[i]+d2[j]就是从这条路过境的总路径长度。找出这类路径长度里最短的那条，输出即可
        long long minLen = INT_MAX;
        for (int i = 0; i < vp.size(); ++i) {
            if (dist1[vp[i].first] == INT_MAX || dist2[vp[i].second] == INT_MAX) {
                continue;
            }
            if (minLen > dist1[vp[i].first] + dist2[vp[i].second] + vplen[i]) {
                minLen = dist1[vp[i].first] + dist2[vp[i].second] + vplen[i];
            }
        }
        if (minLen == INT_MAX) cout << -1 << endl;
        else cout << minLen << endl;
        dist1.clear();
        dist2.clear();
        camp1.clear();
        camp2.clear();
        vp.clear();
        vplen.clear();
    }
    return 0;
}