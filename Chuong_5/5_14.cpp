#include <bits/stdc++.h>
using namespace std;

string findSmallestNumber(string s) {
    string result;
    vector<int> nums;
    int n = s.length() + 1;
    
    // Khởi tạo vector số từ 1 đến n
    for(int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    
    // Xử lý từng ký tự D
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'D') {
            reverse(nums.begin() + i, nums.begin() + i + 2);
        }
    }
    
    // Chuyển các số thành chuỗi kết quả
    for(int num : nums) {
        result += to_string(num);
    }
    
    return result;
}

int main() {
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << findSmallestNumber(s) << "\n";
    }
    return 0;
}
