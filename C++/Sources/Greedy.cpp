#include "../Headers/Greedy.h"

void Greedy::func1() {
    int n, m;
    scanf("%d", &n);
    getchar();
    vector<string> proxy(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, proxy[i]);
    }
    scanf("%d", &m);
    getchar();
    vector<string> server(m);
    vector<bool> flag(m);
    for (int i = 0; i < m; ++i) {
        getline(cin, server[i]);
        flag[i] = false;
    }
    int ans = 0, idx = 0, k = m;
    bool flags = false;
    while (true) {
        if (idx >= proxy.size()) {
            break;
        }
        for (int i = 0; i < m; ++i) {
            if (flag[i] == false && proxy[idx] != server[i]) {
                flag[i] = true;
                k--;
            }
        }
        if (k == 0) {
            flags = true;
            break;
        }
        idx++;
        ans++;
    }
    if (flags) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

class Station {
public:
    double price;
    double dist;

    bool operator<(const Station &a) const {
        if (a.dist == dist) {
            return price < a.price;
        }
        return dist < a.dist;
    }
};

void Greedy::func2() {
    /**
     *  当前车站： 1.如果在最大能到达距离中，有车站(a,b,c...)的价格小于当前的， 则去第一个价格小(a)的车站
     *                         若油够到达，则不加钱，并计算到达后的剩余油量
     *                         否则，油只加到刚好到达，并计算相应油钱
     *            2.如果在最大能到达距离中，没有车站的价格小于当前的，则把油加满，计算油钱，然后到区间内价格最低那个的车站
     *            3.如果在最大能到达距离中，没有车站，则over
     */
    double maxVolume, D, avgOil, n;
    while (cin >> maxVolume >> D >> avgOil >> n) {
        double totalPrice = 0.0;
        Station sta[(int) n + 1];
        for (int i = 0; i < n; ++i) {
            double p, d;
            cin >> p >> d;
            sta[i].dist = d;
            sta[i].price = p;
        }
        sta[(int) n].dist = D; // 终点站，循环出口
        sta[(int) n].price = 0.0;
        sort(sta, sta + (int) n + 1); // 按距离排序，距离相同按油价排
        if (sta[0].dist != 0) { // 0号车站不可达
            printf("The maximum travel distance = 0.00\n");
            continue;
        }
        double currentDist = 0; //当前位置
        double maxReach = 0; //可到达最大距离
        double currentOil = 0; // 当前油量
        int staIdx = 0; // 当前站
        bool flag = true;
        while (currentDist < sta[(int) n].dist) {
            maxReach = currentDist + maxVolume * avgOil; // 计算可达最大距离
            if (sta[staIdx + 1].dist > maxReach) {
                // 下一站无法到达，over，即情况3
                printf("The maximum travel distance = %.2lf\n", maxReach);
                flag = false;
                break;
            }
            double minPrice = sta[staIdx].price, dist = 0;  // dist是目的站和当前站间距
            int j, idx = staIdx;
            for (j = staIdx + 1; j < n; ++j) {
                if (maxReach < sta[j].dist) {
                    break; // 超出最大距离，没有站的价格比当前还低，结束循环，即情况2
                }
                if (minPrice > sta[j].price) {  // 可达最大距离中，有一个站比当前站价格还低，则现到这个站，即情况1
                    minPrice = sta[j].price;
                    dist = sta[j].dist - currentDist;  // 两站间距
                    idx = j;  // 记录站的索引
                    break;
                }
            }
            if (staIdx == idx) { // 情况2处理
                if (j == (int) n) { // 若是终点的前一站，加钱；结账 （按理说这里还要看看有没有剩余的油）
                    totalPrice += (D - sta[staIdx].dist) / avgOil * sta[staIdx].price;
                    break;
                }
                int idxx = staIdx + 1;
                double minP = sta[idxx].price;
                for (int i = staIdx + 1; i < j; ++i) { // 找到最大距离内，价格最低的那个站
                    if (minP > sta[i].price) {
                        minP = sta[i].price;
                        idxx = i;
                    }
                }
                totalPrice += (maxVolume - currentOil) * sta[staIdx].price; // 加钱
                staIdx = idxx; // 当前站更新
                currentOil = maxVolume - (sta[staIdx].dist - currentDist) / avgOil; // 当前油量更行
                currentDist = sta[staIdx].dist; // 当前位置更新
            } else {  //情况1处理
                if (currentOil * avgOil >= dist) {  // 若当前油量能撑到目的站，则计算剩余油量，不用加钱
                    currentOil -= dist / avgOil;
                } else {  // 若撑不到，则计算还需要多少油，并加钱，同时剩余油量清零
                    totalPrice += (dist - currentOil * avgOil) / avgOil *  sta[staIdx].price;
                    currentOil = 0.0;
                }
                staIdx = idx; // 更新当前站 和当前位置
                currentDist = sta[staIdx].dist;
            }
        }
        if (flag) {
            cout << fixed << setprecision(2) << totalPrice << endl;
        }
    }
}
