
#include "../header.h"
#include <map>
#include <string>
#include <vector>
class Solution {
public:
	vector<int> charV;
	string largestPalindromic(string num) {
		charV = std::vector<int>(10, 0);
		for (auto i : num) {
			charV[i - '0'] += 1;
		}
		string res = "";
		int max_single = -1;
		for (int i = 9; i >= 0; i--) {
			while (charV[i] / 2 >= 1) {
				res += i + '0';
				charV[i] -= 2;
			}
			if (charV[i] == 1 && i > max_single) {
				max_single = i;
			}
		}
		int zeronums = 0;
		char flag = 0;
		for (int i = 0; i < res.size(); i++) {
			if (res[i] == '0')
			{
				flag = 1;
				zeronums++;
			}
			else
				break;
		}
		res.erase(res.begin(), res.begin() + zeronums);
		string res_rev = "";
		for (string::reverse_iterator i = res.rbegin(); i != res.rend(); i++) {
			res_rev += *i;
		}
		if (max_single != -1) {
			res += max_single + '0';
		}
		string res_tmp = res + res_rev;
		if (flag == 1 && res_tmp == "") {
			return "0";
		}
		return res_tmp;
	}
};
int main() {}