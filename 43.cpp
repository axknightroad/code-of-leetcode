#include <iostream>
#include <string>

using namespace std;

string add(string a, string b) {
    if (a.empty()) a = "0";
    if (b.empty()) b = "0";
    if (a == "0") return b;
    if (b == "0") return a;
    
    int i1 = a.size() - 1;
    int i2 = b.size() - 1;
    int c = 0;
    int sum = 0;
    string ans;
    
    while (i1 >= 0 && i2 >= 0) {
        int t1 = a[i1] - '0';
        int t2 = b[i2] - '0';
        
        t1 += t2 + c;
        c = t1 / 10;
        t1 = t1 % 10;
        char tc = '0' + t1;
        string s(1, tc);
        ans = ans.insert(0, s);
        
        i1--;
        i2--;
    }
    
    while (i1 >= 0) {
        if(c) {
            int t1 = a[i1] - '0';
            t1 += c;
            c = t1 / 10;
            t1 = t1 % 10;
            char tc = '0' + t1;
            string s(1, tc);
            ans = ans.insert(0, s);
            i1--;
            
        } else {
            string temp = a.substr(0, i1 + 1);
            ans = ans.insert(0, temp);
            i1 = -1;
        }
    }
    
    while (i2 >= 0) {
        if(c) {
            int t1 = b[i2] - '0';
            t1 += c;
            c = t1 / 10;
            t1 = t1 % 10;
            char tc = '0' + t1;
            string s(1, tc);
            ans = ans.insert(0, s);
            i2--;
            
        } else {
            string temp = b.substr(0, i2 + 1);
            ans = ans.insert(0, temp);
            i2 = -1;
        }
    }
    
    if(c) {
        char tc = '0' + c;
        string s(1, tc);
        ans = ans.insert(0, s);
    }
    
    return ans;
}

string multiplyNum(string num, int n) {
    int c = 0;
    string ans;
    
    if(!n || num == "0") return "0";
    
    for (int i = num.size()-1; i >= 0; i--) {
        int t = n * (num[i] - '0') + c;
        c = t / 10;
        t = t % 10;
        char tc = '0' + t;
        string s(1, tc);
        ans = ans.insert(0, s);
    }
    
    if(c) {
        char tc = '0' + c;
        string s(1, tc);
        ans = ans.insert(0, s);
    }
    
    return ans;
}


string multiply(string num1, string num2) {
    string ans;
    
    for (int i = 0 ; i < num2.size() ; i++) {
        if (!ans.empty() && ans != "0") ans += '0';
        string temp = multiplyNum(num1, num2[i] - '0');
        ans = add(ans, temp);
    }
    
    return ans;
}

int main() {
    string s1 = "98", s2 = "9";
    string ans = multiply(s1, s2);
    cout<< ans <<endl;
}
