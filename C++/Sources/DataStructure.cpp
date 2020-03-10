#include "../Headers/DataStructure.h"
void DataStructure::func1() {
    int n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        stack<int> s;
        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;
            if(str == "P") {
                int tmp;
                cin >> tmp;
                s.push(tmp);
            } else if(str == "A") {
                if(s.empty()) {
                    printf("E\n");
                } else {
                    printf("%d\n", s.top());
                }
            } else if(str == "O") {
                if(!s.empty()) {
                    s.pop();
                }
            }
        }
        cout << endl;
    }


}
static int index = 0;
double getNumber(string str) {
    double number = 0;
    while (isdigit(str[index])) {
        number = number * 10 + str[index++] - '0';
    }
    return number;
}

double calculate(double x, double y, char op) {
    double res = 0;
    if (op == '+') {
        res = x + y;
    } else if (op == '-') {
        res = x - y;
    } else if (op == '*') {
        res = x * y;
    } else if (op == '/') {
        res = x / y;
    }
    return res;
}
void DataStructure::func2() {
    index = 0;
    map<char, int> priority;
    priority['+'] =  2;
    priority['-'] =  2;
    priority['*'] =  3;
    priority['/'] =  3;
    priority['#'] =  0;
    priority['$'] =  1;
    stack<char> oper;
    stack<double> data;
    string str;
    cin >> str;
    str += "$";
    oper.push('#');
    while (index < str.length()) {
        if (isdigit(str[index])) {
            data.push(getNumber(str));
        } else {
            if (priority[oper.top()] < priority[str[index]]) {
                oper.push(str[index++]);
            } else {
                double y = data.top();data.pop();
                double x = data.top();data.pop();
                data.push(calculate(x, y, oper.top()));
                oper.pop();
            }
        }
    }
    cout << data.top() << endl;
}
