#include <string>
#include <iostream>

using namespace std;

bool isMatchRecursion(string s, string p, int i, int j) {
    while (i < s.size() && j < p.size()) {
        if(p[j + 1] != '*') {
            if (s[i] == p[j] || p[j] == '.') {
                i++; j++;
            } else return false;
        } else {
            while ((s[i] == p[j] || p[j] == '.')  && i < s.size()) {
                if (isMatchRecursion(s, p, i, j + 2)) {
                    return true;
                }
                i++;
            }
            j += 2;
        }
    }
    
    while (j < p.size()) {
        if (p[j + 1] == '*') j += 2;
        else break;
    }
    
    if(i == s.size() && j == p.size())
        return true;
    else
        return false;
    
}

bool isMatch(string s, string p) {
    return isMatchRecursion(s, p, 0, 0);
}

int main() {
    string s("aa");
    string p(".*");
    
    if (isMatch(s, p)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
