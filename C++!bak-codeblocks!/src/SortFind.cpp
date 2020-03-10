#include "../include/SortFind.h"

void SortFind::func1() {
    int n;
    while(cin >> n) {
        vector<int> vv;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            vv.push_back(tmp);
        }
        sort(vv.begin(), vv.end());
        cout << vv[vv.size() - 1] << endl;
        if(n != 1) {
            cout << vv[0];
            for(int i = 1; i < n - 1; i++) {
                cout << " " << vv[i];
            }
            cout << endl;
        } else {
            cout << -1 <<endl;
        }
    }
}

bool Desc(int a, int b) {
    return b < a;
}

bool Asce(int a, int b) {
    return a < b;
}

void SortFind::func2() {
    vector<int> vv;
    for(int i = 0; i < 10; i++) {
        int tmp;
        cin >> tmp;
        vv.push_back(tmp);
    }
    sort(vv.begin(), vv.end(), Desc);
    for(int i = 0; i < vv.size(); i++) {
        if(vv[i] % 2 == 1) {
            cout << vv[i] << " ";
        }
    }
    sort(vv.begin(), vv.end(), Asce);
    for(int i = 0; i < vv.size(); i++) {
        if(vv[i] % 2 == 0) {
            cout << vv[i] << " ";
        }
    }
    cout << endl;
}

class Mouse{
public:
    string color;
    int weight;
    Mouse(string color, int weight) {
        this->color = color;
        this->weight = weight;
    }
};

bool DescMouse(Mouse o1, Mouse o2) {
    return o1.weight > o2.weight;
}

void SortFind::func3() {
    int n;
    while(cin >> n) {
        vector<Mouse> vv;
        for(int i = 0; i < n; i++) {
            string s;
            int w;
            cin >> w >> s;
            Mouse m(s, w);
            vv.push_back(m);
            //cin >> vv[i].weight >> vv[i].color;
        }
        sort(vv.begin(), vv.end(), DescMouse);
        for(int i = 0; i < n; i++) {
            cout << vv[i].color << endl;;
        }
    }
}

class Country {
public:
    int goldNumber;
    int modelNumber;
    int population;
    double goldRate;
    double modelRate;
    int index;
    Country(int goldNumber, int modelNumber, int population, double goldRate, double modelRate, int index) {
        this->goldNumber = goldNumber;
        this->modelNumber = modelNumber;
        this->population = population;
        this->goldRate = goldRate;
        this->modelRate = modelRate;
        this->index = index;
    }

};

bool sortCountry1(Country o1, Country o2) {
    return o1.goldNumber > o2.goldNumber;
}
bool sortCountry2(Country o1, Country o2) {
    return o1.modelNumber > o2.modelNumber;
}
bool sortCountry3(Country o1, Country o2) {
    return o1.goldRate > o2.goldRate;
}
bool sortCountry4(Country o1, Country o2) {
    return o1.modelRate > o2.modelRate;
}


vector<int> mySort(vector<Country> vv, int cas) {
    int n = vv.size();
    vector<int> v(n);
    int rate = 0;
    int l = 0;
    switch(cas) {
        case 1:
            sort(vv.begin(), vv.end(), sortCountry1);
            v[vv[0].index] = ++rate;
            for(int i = 1; i < n; i++) {
                if(vv[i].goldNumber == vv[i - 1].goldNumber) {
                    v[vv[i].index] = rate;l++;
                } else {
                    v[vv[i].index] = rate + l + 1;rate = rate + l + 1;l=0;
                }
            }
            return v;
        case 2:
            sort(vv.begin(), vv.end(), sortCountry2);
            v[vv[0].index] = ++rate;
            for(int i = 1; i < n; i++) {
                if(vv[i].modelNumber == vv[i - 1].modelNumber) {
                    v[vv[i].index] = rate;l++;
                } else {
                    v[vv[i].index] = rate + l + 1;rate = rate + l + 1;l=0;
                }
            }
            return v;
        case 3:
            sort(vv.begin(), vv.end(), sortCountry3);
            v[vv[0].index] = ++rate;
            for(int i = 1; i < n; i++) {
                if(vv[i].goldRate == vv[i - 1].goldRate) {
                    v[vv[i].index] = rate;l++;
                } else {
                    v[vv[i].index] = rate + l + 1;rate = rate + l + 1;l=0;
                }
            }
            return v;
        case 4:
            sort(vv.begin(), vv.end(), sortCountry4);
            v[vv[0].index] = ++rate;
            for(int i = 1; i < n; i++) {
                if(vv[i].modelRate == vv[i - 1].modelRate) {
                    v[vv[i].index] = rate;l++;
                } else {
                    v[vv[i].index] = rate + l + 1;rate = rate + l + 1;l=0;
                }
            }
            return v;
    }
}

/**typedef pair<int, int> PAIR;

ostream& operator << (ostream& out, const PAIR& p) {
    if(p.second)
    return cout << p.first << ":" << p.second << endl;
}
/** map按key排序
map<int, int, less<int> > rate;
rate[s1[i]] = 1;
rate[s2[i]] = 2;
rate[s3[i]] = 3;
rate[s4[i]] = 4;
map<int, int>::iterator iter = rate.begin();
cout << *iter;
*/

void show(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
}

void SortFind::func4() {
    int n, m;
    cin >> n >> m;
    vector<Country> vv;
    for(int i = 0; i < n; i++) {
        int goldNumber, modelNumber, population;
        cin >> goldNumber >> modelNumber >> population;
        Country o(goldNumber, modelNumber, population, (double)goldNumber / population, (double)modelNumber / population, i);
        vv.push_back(o);
    }
    vector<int> v;
    for(int i= 0; i < m; i++) {
        int m0;
        cin >> m0;
        v.push_back(m0);
    }
    for(int i = 0; i < n; i++) {
        vector<int>::iterator it = find(v.begin(), v.end(), i);
        int pos = it - v.begin();
        if(it == v.end()) {
            vv.erase(vv.begin() + pos);
        }
    }
    for(int i = 0; i < m; i++) {
        vv[i].index = i;
    }
    vector<int> s1 = mySort(vv, 1);/*show(s1);*/
    vector<int> s2 = mySort(vv, 2);/*show(s2);*/
    vector<int> s3 = mySort(vv, 3);/*show(s3);*/
    vector<int> s4 = mySort(vv, 4);/*show(s4);*/
    for(int i = 0; i < m; i++) {
        vector<int> tmp(4);
        tmp[0] = s1[i];tmp[1] = s2[i];tmp[2] = s3[i];tmp[3] = s4[i];
        int mins = tmp[0], index = 0;
        for(int j = 1; j < 4; j++) {
            if(mins > tmp[j]) {
                index = j;mins = tmp[j];
            }
        }
        cout << mins << ":" << index + 1 << endl;
    }
    cout << endl;
}

int BinarySearch(vector<int> v, int target) {
    int left = 0;
    int right = v.size() - 1;
    while(left <= right) {
        int middle = (right - left) / 2 + left;
        if(v[middle] < target) {
            left = middle + 1;
        } else if(v[middle] > target) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}

class Pair{
public:
    int x;
    int y;
    Pair(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

bool PairCompare(Pair o1, Pair o2) {
    if(o1.x != o2.x) {
        return o1.x < o2.x;
    }
    return o1.y < o2.y;
}

void SortFind::func5() {
    int n;
    cin >> n;
    vector<Pair> vv;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        Pair o(x, y);
        vv.push_back(o);
    }
    sort(vv.begin(), vv.end(), PairCompare);
    cout << vv[0].x << " " << vv[0].y << endl;
}

void SortFind::func6() {
    int m;
    while(cin >> m) {
        vector<int> v;
        for(int j = 0; j < m; j++) {
            int t;
            cin >> t;
            v.push_back(t);
        }
        for(int j = 0; j < m; j++) {
            if(j !=0 && j != m - 1) {
                if(v[j] > v[j - 1] && v[j] > v[j + 1]) {
                    cout << j << " ";
                } else if(v[j] < v[j - 1] && v[j] < v[j + 1]) {
                    cout << j << " ";
                }
            } else if(j == 0 && v[j] != v[j + 1]) {
                cout << j << " ";
            } else if(j == m - 1 && v[j] != v[j - 1]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

/// map会自动排序，要想按插入顺序 可以用vector<pair<first, second>
/// java中使用LinkedHashMap
void SortFind::func7() {
    map<char, vector<int> > m;
    string str;
    cin >> str;
    map<char, vector<int> >::iterator it;
    for(int i = 0; i < str.length(); i++) {
        vector<int> v;
        if(m.find(str[i]) == m.end()) {
            v.push_back(i);
            m[str[i]] = v;
        } else {
            v = m[str[i]];
            v.push_back(i);
            m[str[i]] = v;
        }
    }
    for(it = m.begin(); it != m.end(); it++) {
        vector<int> v = it->second;
        if(v.size() > 1) {
            for (int i = 0; i < v.size(); i++) {
                printf("%c:%d", it->first, v[i]);
                if (i != v.size() - 1) {
                    printf(",");
                }
            }
            cout << endl;
        }
    }
}

void SortFind::func7_v2() {
    vector<pair<char, vector<int>>> m;
    string str;
    cin >> str;
    vector<pair<char, vector<int>>>::iterator it;
    for(int i = 0; i < str.length(); i++) {
        for(int j = 0; j < m.size(); j++) {
                // find
            pair<char, vector<int>> p= m[j];
            if(p.first == str[i]) {
                vector<int> v = p.second;
                v.push_back(i);
                p.second = v;
                m[j] = p;
                break;
            }
        }
        // not find
        pair<char, vector<int>> p;
        p.first = str[i];
        vector<int> v;
        v.push_back(i);
        p.second = v;
        m.push_back(p);
    }

    for(int i = 0; i < m.size(); i++) {
        pair<char, vector<int>> p= m[i];
        vector<int> v = p.second;
        if(v.size() > 1) {
            for(int j = 0; j < v.size(); j++) {
                printf("%c:%d", p.first, v[j]);
                if(j != v.size() - 1) {
                    printf(",");
                }
            }
            cout << endl;
        }
    }
}
