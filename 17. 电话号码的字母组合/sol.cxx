#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> mVec{
           "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void handler(int index, string& str, string resStr) {
        if (index >= str.size()) {
            res.push_back(resStr);
            return;
        }
        int n = str[index] - '2';
        for (auto i : mVec[n]) {
            handler(index + 1, str, resStr + i);
        }
    }

    vector<string> letterCombinations(string digits) {
        int num = 0;
        if (digits.size() == 0)return std::vector<string>{};

        handler(0, digits, "");
        return res;
    }
};

int main() {
    Solution s;
    auto c = s.letterCombinations("3");
    for (auto i : c) {
        std::cout << i;
    }
}