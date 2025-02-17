#include <bits/stdc++.h>
using namespace std;

// Tính tổng các số trong biểu thức đã chuẩn hóa
int evaluateExpression(string expr) {
    int sum = 0;
    int num = 0;
    int sign = 1;
    
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-' || i == expr.length() - 1) {
            sum += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        }
    }
    sum += sign * num;  // Xử lý số cuối cùng
    return sum;
}

string normalize(string expr) {
    // Remove spaces
    expr.erase(remove(expr.begin(), expr.end(), ' '), expr.end());
    
    string normalized;
    bool negativeContext = false;
    
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        if (c == '-') {
            if (i == 0 || expr[i-1] == '(') {
                negativeContext = !negativeContext;
                continue;
            }
        }
        
        if (c == '(') {
            continue;
        }
        else if (c == ')') {
            continue;
        }
        else if (c == '+') {
            normalized += negativeContext ? '-' : '+';
        }
        else if (c == '-') {
            normalized += negativeContext ? '+' : '-';
        }
        else if (isdigit(c) || isalpha(c)) {
            if (normalized.empty() || normalized.back() == '+' || normalized.back() == '-') {
                if (negativeContext) {
                    if (normalized.empty() || normalized.back() != '-') {
                        normalized += '-';
                    }
                }
            }
            normalized += c;
        }
    }
    
    if (!normalized.empty() && normalized[0] == '+') {
        normalized = normalized.substr(1);
    }
    
    return normalized;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string expr1, expr2;
        getline(cin, expr1);
        getline(cin, expr2);
        
        string norm1 = normalize(expr1);
        string norm2 = normalize(expr2);
        
        // Tạo map để lưu hệ số của các biến
        map<char, int> terms1, terms2;
        int currentCoef = 1;
        
        // Xử lý biểu thức 1
        for (size_t i = 0; i < norm1.length(); i++) {
            if (norm1[i] == '+') currentCoef = 1;
            else if (norm1[i] == '-') currentCoef = -1;
            else if (isalpha(norm1[i])) {
                terms1[norm1[i]] += currentCoef;
            }
        }
        
        // Xử lý biểu thức 2
        currentCoef = 1;
        for (size_t i = 0; i < norm2.length(); i++) {
            if (norm2[i] == '+') currentCoef = 1;
            else if (norm2[i] == '-') currentCoef = -1;
            else if (isalpha(norm2[i])) {
                terms2[norm2[i]] += currentCoef;
            }
        }
        
        // So sánh các hệ số
        bool isEquivalent = true;
        if (terms1.size() != terms2.size()) {
            isEquivalent = false;
        } else {
            for (const auto& term : terms1) {
                if (terms2[term.first] != term.second) {
                    isEquivalent = false;
                    break;
                }
            }
        }
        
        cout << (isEquivalent ? "YES" : "NO") << "\n";
    }
    return 0;
}

