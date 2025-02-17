#include <bits/stdc++.h>
using namespace std;

int evaluatePrefix(string s) {
    // Kiểm tra ràng buộc độ dài
    if (s.length() < 2 || s.length() > 20) {
        throw runtime_error("Do dai bieu thuc khong hop le");
    }
    
    stack<int> st;
    
    // Duyệt từ phải sang trái với biểu thức tiền tố
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isspace(s[i])) continue;  // Bỏ qua khoảng trắng
        
        if (isdigit(s[i])) {
            // Kiểm tra số đơn
            st.push(s[i] - '0');
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            // Kiểm tra đủ toán hạng
            if (st.size() < 2) {
                throw runtime_error("Bieu thuc khong hop le");
            }
            
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            
            // Kiểm tra chia cho 0
            if (s[i] == '/' && op2 == 0) {
                throw runtime_error("Loi chia cho 0");
            }
            
            switch (s[i]) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
            }
        } else {
            throw runtime_error("Ky tu khong hop le");
        }
    }
    
    // Kiểm tra kết quả cuối cùng
    if (st.size() != 1) {
        throw runtime_error("Bieu thuc khong hop le");
    }
    
    return st.top();
}

int main() {
    int T;
    cin >> T;
    
    // Kiểm tra ràng buộc T
    if (T < 1 || T > 100) {
        cout << "So luong test khong hop le\n";
        return 1;
    }
    
    cin.ignore();
    
    while (T--) {
        string expr;
        getline(cin, expr);
        
        try {
            cout << evaluatePrefix(expr) << "\n";
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}

