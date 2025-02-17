#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool hasRedundantParentheses(const string &exp) {
    stack<char> st;

    for (char ch : exp) {
        if (ch == ')') {
            if (st.empty()) return false; // Kiểm tra nếu stack rỗng

            bool hasOperator = false;
            int count = 0; // Đếm số phần tử trong dấu ngoặc

            // Kiểm tra các ký tự trong ngoặc
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
                st.pop();
                count++;
            }

            // Xóa dấu '(' ra khỏi stack
            if (!st.empty()) {
                st.pop();
            }

            // Nếu không có toán tử HOẶC chỉ có một phần tử trong ngoặc => dư thừa
            if (!hasOperator || count == 0) {
                return true;
            }
        } else {
            st.push(ch);
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Loại bỏ ký tự xuống dòng sau khi nhập số T

    while (T--) {
        string exp;
        getline(cin, exp);

        if (hasRedundantParentheses(exp)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
