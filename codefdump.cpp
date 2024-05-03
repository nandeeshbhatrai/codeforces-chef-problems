#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool solve(const vector<int>& l) {
    vector<int> b;

    for (int num : l) {
        string str = to_string(num);
        if (b.empty() && num > 10) {
            vector<int> digits(str.begin(), str.end());
            sort(digits.begin(), digits.end());
            string sortedStr(digits.begin(), digits.end());
            int sortedNum = stoi(sortedStr);

            if (sortedStr == str) {
                for (char ch : str) {
                    b.push_back(ch - '0'); 
                }
            } else {
                b.push_back(num);
            }
        } else {
            if (num < b.back()) {
                cout << "NO" << endl;
                return false;
            }

            string str = to_string(num);
            vector<int> digits(str.begin(), str.end());
            sort(digits.begin(), digits.end());
            string sortedStr(digits.begin(), digits.end());
            int sortedNum = stoi(sortedStr);

            if (b.back() < str[0] && sortedStr == str && num >= 10) {
                for (char ch : str) {
                    b.push_back(ch - '0');
                }
            } else {
                b.push_back(num);
            }
        }
    }

    for (int i = 1; i < b.size(); ++i) {
        if (b[i] < b[i - 1]) {
            cout << "NO" << endl;
            return false;
        }
    }

    cout << "YES" << endl;
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n;
        cin >> n;
        vector<int> l;
        for(int j = 0; j < n; ++j){
            int x;
            cin >> x;
            l.push_back(x);
        }
        solve(l);
    }
    return 0;
}
