//
// Created by Closer on 2020/3/10.
//
// 按点的名字处理点，建议不用链表表示边，较为复杂，也不是不可以

#include <bits/stdc++.h>

// .cpp 文件不能放到CMakeLists.txt里面

using namespace std;

// 用邻接表构造图
class Edge {  // 边
public:
    int weight;   // 边权
    string nodeName;  // 边所连接的顶点名
    Edge *next;   // 下一条边

    Edge() {
        weight = 0;
        next = nullptr;
    }

    Edge(int weight, string nodeName, Edge *next) {
        this->weight = weight;
        this->nodeName = std::move(nodeName);
        this->next = next;
    }
};

class GNode {  // 顶点
public:
    string nodeName;  // 顶点名
    Edge *head;   // 边指针

    GNode() {
        head = nullptr;
    }

    GNode(string nodeName, Edge *head) {
        this->nodeName = std::move(nodeName);
        this->head = head;
    }
};

map<string, GNode *> graph;  // <string, GNode*> --> <顶点， 顶点指针>
map<string, bool> visit;
map<string, int> dist;

void InitialVisit() {
    map<string, bool>::iterator it;
    for (it = visit.begin(); it != visit.end(); it++) {
        it->second = false;
    }
//    for(auto &i : visit) {
//        i.second = false;
//    }
}

void InitialGraph() {
    dist.clear();
    visit.clear();
    for (auto &i : graph) {
        GNode *gNode = i.second;
        Edge *edge = gNode->head;
        Edge *tmp = nullptr;
        while (edge != nullptr) {
            tmp = edge;
            edge = edge->next;
            delete tmp;
        }
        delete gNode;
    }
    graph.clear();
}

// 插入 node1 -> node2 的边
void InsertEdge(const string &node1, const string &node2, int weight) {
    if (graph.find(node1) != graph.end()) {  // 如果这个顶点以及存在，则将边加入这个顶点 （GNode 的 Edge；Edge的链表使用头插法）
        GNode *node = graph[node1];
        Edge *head = node->head;
        Edge *newEdge = new Edge(weight, node2, head);
        node->head = newEdge;
        graph[node1] = node;
    } else {            // 如果这个点不存在，则新建一个顶点， 然后将边加入；
        Edge *edge = new Edge(weight, node2, nullptr);
        auto *gNode = new GNode(node1, edge);
        graph[node1] = gNode;
    }
    visit[node1] = false;
    dist[node1] = INT_MAX;
}

void showGraph() {
    for (auto &i : graph) {
        GNode *gNode = i.second;
        Edge *edge = gNode->head;
        cout << gNode->nodeName;
        while (edge != nullptr) {
            cout << " --> " << edge->nodeName << " " << edge->weight;
            edge = edge->next;
        }
        cout << endl;
    }
}

int BFS() {
    int component = 0;
    for (auto &i : graph) {
        component++;
        queue<GNode *> Q;
        if (visit[i.first]) {
            continue;
        }
        Q.push(i.second);
        while (!Q.empty()) {
            GNode *gNode = Q.front();
            Q.pop();
            Edge *edge = gNode->head;
            cout << " --- " << gNode->nodeName;
            visit[gNode->nodeName] = true;
            while (edge != nullptr) {
                if (!visit[edge->nodeName]) {
                    Q.push(graph[edge->nodeName]);
                    visit[edge->nodeName] = true;
                }
                edge = edge->next;
            }
        }
        cout << endl;
    }
    return component;
}

int DFS() {
    int component = 0;
    for (auto &i : graph) {
        component++;
        stack<GNode *> S;
        if (visit[i.first]) {
            continue;
        }
        S.push(i.second);
        while (!S.empty()) {
            GNode *gNode = S.top();
            S.pop();
            Edge *edge = gNode->head;
            cout << " --- " << gNode->nodeName;
            visit[gNode->nodeName] = true;
            while (edge != nullptr) {
                if (!visit[edge->nodeName]) {
                    S.push(graph[edge->nodeName]);
                    visit[edge->nodeName] = true;
                }
                edge = edge->next;
            }
        }
        cout << endl;
    }
    return component;
}


bool Sort(const pair<string, int> &p1, const pair<string, int> &p2) {
    return p1.first < p2.first;
}

vector<map<string, int> *> *Solution() {
    auto *vm = new vector<map<string, int> *>;
    vm->clear();
    for (auto &i : graph) {
        stack<GNode *> S;
        if (visit[i.first]) {
            continue;
        }
        S.push(i.second);
        auto *m = new map<string, int>;
        m->clear();
        while (!S.empty()) {
            GNode *gNode = S.top();
            S.pop();
            Edge *edge = gNode->head;
//            cout << " --- " << gNode->nodeName;
            visit[gNode->nodeName] = true;
            while (edge != nullptr) {
                if (!visit[edge->nodeName]) {
                    S.push(graph[edge->nodeName]);
                    visit[edge->nodeName] = true;
                }
                (*m)[gNode->nodeName] += edge->weight;
                (*m)[edge->nodeName] += edge->weight;
                edge = edge->next;
            }
        }
        if (!m->empty() && m->size() >= 3) vm->push_back(m);
    }
    return vm;
}

void showResult(vector<map<string, int> *> *vm, int threshold) {
    vector<pair<string, int>> vp;
    for (auto m : *vm) {
        if (m->size() >= 3) {
            int total = 0;
            int maxWeight = INT_MIN;
            string maxString;
            for (auto &j : *m) {
                if (j.second > maxWeight) {
                    maxWeight = j.second;
                    maxString = j.first;
                }
                total += j.second;
            }
            if (total > threshold * 4) {
//                cout << maxString << " " << m->size() << endl;
                vp.push_back(make_pair(maxString, m->size()));
            }
        }
    }
    if (!vp.empty()) {
        sort(vp.begin(), vp.end(), Sort);
        cout << vp.size() << endl;
        for (const pair<string, int> &p : vp) {
            cout << p.first << " " << p.second << endl;
        }
    } else {
        cout << 0 << endl;
    }
}

int test() {
    int n, k;
    while (cin >> n >> k) {
        graph.clear();
        string str1;
        string str2;
        int weight;
        for (int i = 0; i < n; ++i) {
            cin >> str1 >> str2 >> weight;
            InsertEdge(str1, str2, weight);
            InsertEdge(str2, str1, weight); //构造无向图 ，插入两条边
        }
//        showGraph();
//        cout << endl;
//        DFS();
        InitialVisit();
//        cout << endl;
        vector<map<string, int> *> *mp = Solution();
        showResult(mp, k);
    }
    return 0;
}

/**
8 59
BBB AAA 20
CCC BBB 10
AAA CCC 40
EEE DDD 70
DDD FFF 5
FFF GGG 30
GGG HHH 20
HHH FFF 10

AAA --> CCC 40
BBB --> AAA 20
CCC --> BBB 10
DDD --> FFF 5
EEE --> DDD 70
FFF --> GGG 30
GGG --> HHH 20
HHH --> FFF 10

AAA --> CCC 40 --> BBB 20
BBB --> CCC 10 --> AAA 20
CCC --> AAA 40 --> BBB 10
DDD --> FFF 5 --> EEE 70
EEE --> DDD 70
FFF --> HHH 10 --> GGG 30 --> DDD 5
GGG --> HHH 20 --> FFF 30
HHH --> FFF 10 --> GGG 20
*/

class Point {
public:
    string nodeName;
    int distance;

    Point(string nodeName, int distance) : nodeName(move(nodeName)), distance(distance) {}

    bool operator<(const Point &p) const {
        return distance > p.distance;
    }
};

void Dijkstra(const string& source) {
    priority_queue<Point> queue;
    dist[source] = 0;
    queue.push(Point(source, dist[source]));
    while (!queue.empty()) {
        string key = queue.top().nodeName;
        queue.pop();
        GNode *gNode = graph[key];
        Edge *edge = gNode->head;
        while (edge != nullptr) {
            string end = edge->nodeName;
            int d = edge->weight;
            if (dist[end] > dist[key] + d) {
                dist[end] = dist[key] + d;
                queue.push(Point(end, dist[end]));
            }
            edge = edge->next;
        }
    }
}

int test1() {
    int n, m;
    while (cin >> n >> m) {
        InitialGraph();
        string str1;
        string str2;
        for (int i = 0; i < n; ++i) {
            cin >> str1 >> str2;
            InsertEdge(str1, str2, pow(2, i));
            InsertEdge(str2, str1, pow(2, i)); //构造无向图 ，插入两条边
        }
//        showGraph();
//        cout << endl;
//        InitialVisit();
//        DFS();
        Dijkstra("0");  // 计算从点0到其他点的距离
        map<string, int>::iterator it;
        for (it = dist.begin(); it != dist.end(); it++) {
            if (it != dist.begin())
                cout << it->second << endl;
        }
    }
    return 0;
}