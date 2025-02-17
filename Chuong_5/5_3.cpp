#include <bits/stdc++.h>
using namespace std;

string simplify(string &s) {
    stack<bool> ops;
    ops.push(true);
    string res;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            if (i > 0 && s[i - 1] == '-') ops.push(!ops.top());
            else ops.push(ops.top());
        } else if (s[i] == ')') {
            ops.pop();
        } else if (s[i] == '+' || s[i] == '-') {
            if (i == 0 || s[i - 1] == '(') {
                if (ops.top()) res += (s[i] == '+' ? "" : "-");
            } else {
                if (ops.top()) res += s[i];
                else res += (s[i] == '+' ? '-' : '+');
            }
        } else if (!isspace(s[i])) { // Bỏ khoảng trắng không cần thiết
            res += s[i];
        }
        
    }
    
    return res;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi đọc T
    cout << "So test case: " << T << endl; // Kiểm tra giá trị T
    
    while (T--) {
        string P;
        getline(cin, P);
        cout << "Bieu thuc vua nhap: " << P << endl; // Kiểm tra biểu thức đầu vào
        cout << "Ket qua: " << simplify(P) << "\n";
    }
    return 0;
}
