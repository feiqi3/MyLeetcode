#include "../header.h"
#include <string>
#include <vector>



//数学规律：手推
//第一版，用vector来记录Z字形每一行的字符串
class Solution1 {
public:
    string convert(const string& s, int numRows) {
    
    if(numRows == 1)return s;

    int char_one_v = numRows * 2 - 2;
    int len = s.size();
    int z_num = len / char_one_v + 1;
    vector<string> ls(numRows, "\0");
    for (size_t i = 0; i < z_num;) {
      for (size_t c = 0; c < char_one_v; c++) {
        int pos = i * char_one_v + c;
        if (pos >= len)break;
        if (c < numRows) {
          ls[c] = ls[c] + s[pos];
        } else if (c >= numRows && c < 2 * numRows - 2) {
          ls[2 * numRows - c - 2] = ls[2 * numRows - c - 2] + s[pos];
        }
      }
      i++;
    }
    string res;
    for (auto i = ls.begin(); i != ls.end(); i++) {
      res += *i;
    }
    return res;
    }
};

//第二版，改进边界条件
class Solution2 {
public:
    string convert(const string& s, int numRows) {

    if(numRows <= 1)return s;
    int len = s.size();
    if(len <= numRows)return s;

    int char_one_v = numRows * 2 - 2;
    int z_num = len / char_one_v + 1;
    vector<string> ls(numRows, "\0");
    for (size_t i = 0; i < z_num;) {
      for (size_t c = 0; c < char_one_v; c++) {
        int pos = i * char_one_v + c;
        if (pos >= len)break;
        if (c < numRows) {
          ls[c] = ls[c] + s[pos];
        } else if (c >= numRows && c < 2 * numRows - 2) {
          ls[2 * numRows - c - 2] = ls[2 * numRows - c - 2] + s[pos];
        }
      }
      i++;
    }
    string res;
    for (auto i = ls.begin(); i != ls.end(); i++) {
      res += *i;
    }
    return res;
    }
};

//第三版，用数学规律
//按照行往下
//直接构造字符串
class Solution3 {
public:
    string convert(const string& s, int numRows) {
        if (numRows <= 1)
            return s;
        int len = s.size();
        if (len <= numRows)
            return s;
        int char_one_v = numRows * 2 - 2;
        int max_v = (len - 1) / char_one_v+1;
        string res = "\0";

        for (auto i = 0; i < numRows; i++) {
            int pos;
            for (auto v = 0; v < max_v; v++)
            {
                int v_offset = v * char_one_v;
                pos = v_offset + i;
                if (pos >= len || pos >= v_offset + char_one_v)continue;
                res += s[pos];
                pos = v_offset + 2 * numRows - 2 - i;
                if (pos >= len || pos >= v_offset + char_one_v || i == numRows -1)continue;
                res += s[pos];
            }
        }

        return res;
    }
};

//第四版 用char*来操作，最快最小
class Solution4 {
public:
        string convert(const string& s, int numRows) {
        if (numRows <= 1)
            return s;
        int len = s.size();
        if (len <= numRows)
            return s;
        int char_one_v = numRows * 2 - 2;
        int max_v = (len - 1) / char_one_v+1;
        char* res = new char[len+1];
        int char_p = 0;
        for (auto i = 0; i < numRows; i++) {
            int pos;
            for (auto v = 0; v < max_v; v++)
            {
                int v_offset = v * char_one_v;
                pos = v_offset + i;
                if (pos >= len || pos >= v_offset + char_one_v)continue;
                res[char_p]= s[pos];
                char_p++;
                pos = v_offset + 2 * numRows - 2 - i;
                if (pos >= len || pos >= v_offset + char_one_v || i == numRows -1)continue;
                res[char_p] = s[pos];
                char_p++;

            }
        }
        res[char_p] = '\0';
        string r(res);
        delete[] res;
        return string(r);
    }
};
