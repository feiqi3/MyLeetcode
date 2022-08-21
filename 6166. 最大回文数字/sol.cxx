
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
        //找到成对的字符，放入回文的前半部分
        //放入之后还有剩下的，那么久判断是否为最大的单个数字
        //后面放入中间
		for (int i = 9; i >= 0; i--) {
			while (charV[i] / 2 >= 1) {
				res += i + '0';
				charV[i] -= 2;
			}
			if (charV[i] == 1 && i > max_single) {
				max_single = i;
			}
		}
        //检索前导零
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
        //去除前导零
		res.erase(res.begin(), res.begin() + zeronums);
		
        //拼接逆字符串
        string res_rev = "";
		for (string::reverse_iterator i = res.rbegin(); i != res.rend(); i++) {
			res_rev += *i;
		}

        //增加中间的那个字符
		if (max_single != -1) {
			res += max_single + '0';
		}

        //拼接字符串
		string res_tmp = res + res_rev;
		
        //如果有前导零并且现在拼接起来的字符串为空
        if (flag == 1 && res_tmp == "") {
			return "0";
		}
		return res_tmp;
	}
};
int main() {}