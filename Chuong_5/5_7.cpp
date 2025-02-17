#include <bits/stdc++.h>
using namespace std;

// Kiểm tra độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Kiểm tra xem có cần thêm ngoặc hay không
bool needParentheses(string op1, char currentOp, string op2, char stackOp) {
    if (op1[0] == '(' || op2[0] == '(') return false;
    int curr = precedence(currentOp);
    int prev = precedence(stackOp);
    return curr < prev;
}

string toInfix(string s) {
    // Kiểm tra ràng buộc về độ dài
    if (s.length() < 2 || s.length() > 1000000) 
        return "Invalid Expression Length";
    
    stack<string> st;
    // Duyệt từ phải sang trái với biểu thức tiền tố
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // Kiểm tra đủ toán hạng
            if (st.size() < 2) return "Invalid Expression";
            
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            
            // Luôn thêm ngoặc cho mọi phép toán
            string result = "(" + op1 + c + op2 + ")";
            st.push(result);
        }
    }
    
    // Kiểm tra kết quả cuối cùng
    if (st.size() != 1) return "Invalid Expression";
    return st.top();
}

int main() {
    int T;
    cin >> T;
    
    // Kiểm tra ràng buộc số lượng test case
    if (T < 1 || T > 100) {
        cout << "Invalid number of test cases\n";
        return 0;
    }
    
    cin.ignore();
    while (T--) {
        string expr;
        getline(cin, expr);
        cout << toInfix(expr) << "\n";
    }
    return 0;
}
