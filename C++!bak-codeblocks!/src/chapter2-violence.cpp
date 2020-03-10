#include "../include/chapter2-violence.h"

bool func1_no7(int n) {
    while(n != 0) {
        if(n % 10 == 7) return false;
        n /= 10;
    }
    return true;
}

void Violence::func1() {
    int n = 0;
    cin >> n;
    long long int res = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 7 != 0 && func1_no7(i)) {
            res += pow(i, 2);
        }
    }
    cout << res;
}

void Violence::func2() {
    int n = 0;
    cin >> n;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < (100 - 5 * x) / 3; y++) {
            for(int z = 0; z < (100 - 5 * x - 3 * y) * 3; z++) {
                if (15 * x + 9 * y + z <= 3 * n && x + y + z == 100) {
                    printf("x=%d,y=%d,z=%d\n", x, y, z);
                }
            }
        }
    }
}

void Violence::func3() {
    int n = 0;
    cin >> n;
    int x, y, z, price = 99999;
    cin >> x >> y >> z;
    for(; price > 0; price--) {
        for(int i = 1; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(i * 10000 + x * 1000 + y * 100 + z * 10 + j == price * n) {
                    printf("%d %d %d", i, j, price);
                    return;
                }
            }
        }
    }
    cout << 0;
}


char mmap[3003][3003];
char str[6][6];
int n;

void dfs(int m, int x, int y){
    if (m == 1){
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                mmap[x + i][y + j] = str[i][j];
        return;
    }
    int size = (int)pow(n*1.0, m - 1);
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (str[i][j] != ' ')
                dfs(m - 1, x + i*size, y + j*size);
        }
    }
}

void Violence::func4() {
    n = 1;
    while (n){
        cin >> n;
        getchar();
        for (int i = 0; i < n; i++){
            cin.getline(str[i],6);
        }
        int m;
        cin >> m;
        int size = (int)pow(n*1.0, m);
        for (int i = 0; i<size; i++){
            for (int j = 0; j<size; j++)
                mmap[i][j] = ' ';
            mmap[i][size] = '\0';
        }
        dfs(m, 0, 0);
        for (int i = 0; i<size; i++)
            cout<<mmap[i]<<endl;
    }
    return;
}


void Violence::func5() {
    char str[80];
    cin >> str;
    int len = strlen(str);
    int n1 = 0, n2 = 0;
    for(int i = 1; i <= len; i++) {
        if(len + 2 - 2 * i >= i && i > n1) n1 = i;
    }
    n2 = len + 2 - 2 * n1;
    // cout<< n1 << " " << n2 << endl;
    char metrix[n1][n2 + 1];
    memset(metrix, ' ', sizeof(metrix));
    for(int i = 0; i < n1; i++) {
        metrix[i][n2] = '\0';
        metrix[i][0] = str[i];
        metrix[i][n2 - 1] = str[len - i - 1];
    }
    for(int i = 0; i < n2; i++) {
        metrix[n1 - 1][i] = str[n1 + i - 1];
    }
    for(int i = 0; i < n1; i++) {
        cout << metrix[i] << endl;
    }

}

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int daysOfYear(int year) {
    if(isLeapYear(year)) return 366;
    return 365;
}


int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

vector<string> months = {"January","February","March","April","May","June","July","August","September","October","November","December"};
vector<string> weekdays = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

void Violence::func6() {
    int year1, month1, day1;
    int year2, month2, day2;
    scanf("%4d%2d%2d", &year1, & month1, &day1);
    scanf("%4d%2d%2d", &year2, & month2, &day2);
    int res = 0;
    while(year2 > year1) {
        res += daysOfYear(year1);
        year1++;
    }
    for(int i = month1; i < month2; i++) {
        res += daytab[isLeapYear(year2)][i];
    }
    res += day2 - day1;
    cout << res + 1;

}

void Violence::func7() {
    int year, month, day;
    //char monthStr[20];
    string monthStr;
    //scanf("%2d %s %4d", &day, monthStr, &year);
    while( cin >> day >> monthStr >> year) {
        //cout << day << monthStr << year;
        for(int i = 0; i < months.size(); i++) {
            if(monthStr == months[i]) {
               month = i;
               break;
            }
        }
        int y = year;
        long long allDay = 0;
        // 计算从公元1年1月1号到当前的天数
        for(int i = 1; i < year; i++) {
            allDay += daysOfYear(i);
        }
        for(int i = 0; i <= month; i++) {
            allDay += daytab[isLeapYear(year)][i];
        }
        allDay += day - 1;
        cout << weekdays[allDay % 7];
    }

}

void Violence::func8() {
    int line = 0;
    vector<int> vv = {1,3,5,7,8,10,12};
    cin >> line;
    for(int i = 0; i < line; i++) {
        int year, month, day;
        //cin >> year >> month >> day;
        scanf("%4d %2d %2d", &year, &month, &day);
        if(month == 12 && day == 31) {
            printf("%04d-%02d-%02d\n", ++year, 1, 1);
            continue;
        }
        if(month == 2 && day == 28) {
            if(isLeapYear(year)) {
                printf("%04d-%02d-%02d\n", year, 2, 29);
                continue;
            } else {
                printf("%04d-%02d-%02d\n", year, 3, 1);
                continue;
            }
        }
        if(day == 29) {
            printf("%04d-%02d-%02d\n", year, 3, 1);
            continue;
        }
        if(find(vv.begin(), vv.end(), month) != vv.end() && day == 31) {
            printf("%04d-%02d-%02d\n", year, ++month, 1);
            continue;
        }
        if(find(vv.begin(), vv.end(), month) == vv.end() && day == 30) {
            printf("%04d-%02d-%02d\n", year, ++month, 1);
            continue;
        }
        printf("%04d-%02d-%02d\n", year, month, ++day);
    }
}

void Violence::func9() {
    int p, t, g1, g2, g3, gj;
    double res;
    while(cin >> p >> t >> g1 >> g2 >> g3 >> gj) {
        if(abs(g1 - g2) <= t) {
            res = (double)(g1 + g2) / 2.0;
            printf("%.1f\n", res);
            continue;
        }
        if(abs(g3 - g1) <= t && abs(g3 - g2) <= t) {
            res = (double)max(g3, max(g2, g1));
            printf("%.1f\n", res);
            continue;
        }
        if(abs(g3 - g1) <= t || abs(g3 - g2) <= t) {
            res = (double)(min(abs(g3 - g1), abs(g3 - g2)) + 2 * g3) / 2.0;
            printf("%.1f\n", res);
            continue;
        }
        if(abs(g3 - g1) > t && abs(g3 - g2) > t) {
            res = (double)gj;
            printf("%.1f\n", res);
            continue;
        }
    }
}


void Violence::func10() {
}


struct Ant {
    int position;
    int direct;
    bool operator < (const Ant &a) const {
        return position < a.position;
    }
};

void Violence::func11() {
    int n;
    while(cin >> n) {
        vector<Ant> ants;
        for(int i = 0; i < n; i++) {
            Ant ant;
            cin >> ant.position >> ant.direct;
            ants.push_back(ant);
        }
        sort(ants.begin(), ants.end());
        int target = 0, toLeft = 0;
        for(int i = 0; i < n; i++) {
            if(ants[i].direct == 0) {
                target = i;
            }
            if(ants[i].direct == -1) {
                toLeft++;
            }
        }
        if(toLeft == target) {
            cout << "Cannot fall!" << endl;
        } else if(toLeft > target) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(ants[i].direct == -1 && cnt == target) {
                    cout << ants[i].position << endl;
                    return;
                }
                if(ants[i].direct == -1) cnt++;
            }
        } else {
            int cnt = 0;
            for(int i = n - 1; i >= 0; i--) {
                if(ants[i].direct == 1 && cnt == n - target - 1) {
                    cout << 100 - ants[i].position << endl;
                    return;
                }
                if(ants[i].direct == 1) cnt++;
            }
        }
    }
}
