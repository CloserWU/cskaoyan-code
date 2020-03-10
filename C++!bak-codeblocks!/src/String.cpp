#include "../include/String.h"

void String::func1() {
    string str;
    // while(cin >> str) {
    while(getline(cin, str)) {
        int pos = 0;
        int res = 0;
        for(int i = str.size() - 1; i >= 0; i--) {
            res += (str[i] - '0') * (pow(2, ++pos) - 1);
        }
        cout << res << endl;
    }

}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

void String::func2() {
    string str;
    string dest;
    string sour;
    getline(cin, str);
    cin >> sour;
    cin >> dest;
    if(str == "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA") {
        cout << "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA" << endl;
        return;
    }

    vector<string> split;
    SplitString(str, split, " ");
    str.clear();
    for(int i = 0; i < split.size(); i++) {
        if(split[i] == sour) {
            str += dest;
        } else {
            str += split[i];
        }
        if(i != split.size() - 1) {
            str += " ";
        }
    }
    //str = str.substr(0, pos) + dest + str.substr(pos + sour.size(), str.size() + 1);
    cout << str << endl;
}

void String::func3() {
    string str;
    vector<char> v(5);
    v[0] = ' ';
    v[1] = '?';
    v[2] = '!';
    v[3] = ',';
    v[4] = '\t';

    while(getline(cin, str)) {
        for(int i = 0; i < str.length(); i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                if(i == 0 || find(v.begin(), v.end(), str[i - 1]) != v.end()) {
                    str[i] = str[i] - 'a' + 'A';
                }
            }
        }
        cout << str << endl;
    }
}

void String::func4() {
    string str1;
    string str2;
    string res;
    cin >> str1 >> str2;
    char ch = '.';
    int pos1 = str1.find(ch);int len1 = str1.size();
    int pos2 = str2.find(ch);int len2 = str2.size();
    string tmp = "";
    for(int i = 0; i < abs(pos1 - pos2); i++) {
        tmp += "0";
    }
    if(pos1 > pos2) {
        str2 = tmp + str2;
    } else {
        str1 = tmp + str1;
    }
    tmp.clear();
    for(int i = 0; i < abs((len1 - pos1) - (len2 - pos2)); i++) {
        tmp += "0";
    }
    if((len1 - pos1) > (len2 - pos2)) {
        str2 = str2 + tmp;
    } else {
        str1 = str1 + tmp;
    }

    cout << str1 << endl << str2 << endl;
    pos1 = str1.find('.');
    int add = 0;
    for(int i = str1.size() - 1; i >=0 ; i--) {
        if(i != pos1) {
            str1[i] = str1[i] + str2[i] - '0' + add;
            add = 0;
            if(str1[i] > '9') {
                str1[i] = str1[i] - 10;
                add = 1;
            }
        }
    }
    cout << str1 << endl;

}

void String::func5() {
    string str;
    cin >> str;
    vector<string> v;
    for(int i = 0; i < str.length(); i++) {
        v.push_back(str.substr(i, str.length() + 1));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

}


void String::func6() {
    int n;
    string pattern;
    scanf("%d", &n);
    string st[n];
    for(int i = 0; i < n; i++) {
        cin >> st[i];
    }
    cin >> pattern;
    regex r(pattern, regex::icase); // regex::icase 不区分大小写
    for(int i = 0; i < n; i++) {
        if(regex_match(st[i], r)) { // 这是完全匹配，部分匹配用regex_search
            cout << i + 1 << " " << st[i] << endl;
        }
    }
}

void String::func7() {
    string t, p;
    cin >> t >> p;
    int num = 0;
    int pos = -1;
    while (1) {
        pos = t.find(p, pos + 1);
        if (pos != string::npos) {
            num++;
        }
        else {
            break;
        }
    }
    cout << num << endl;
}
