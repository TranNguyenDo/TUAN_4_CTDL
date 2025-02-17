#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}

vector<int> nextSmallerRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            res[st.top()] = arr[i];  // Lưu giá trị thay vì chỉ số
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        vector<int> nextGreater = nextGreaterRight(arr);
        vector<int> result(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (nextGreater[i] != -1) {
                // Tìm phần tử nhỏ hơn đầu tiên sau vị trí nextGreater[i]
                for (int j = nextGreater[i] + 1; j < n; j++) {
                    if (arr[j] < arr[nextGreater[i]]) {
                        result[i] = arr[j];
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}