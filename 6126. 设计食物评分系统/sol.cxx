#include "../header.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>
//TLE
int getMinDicOrder(const string &a, const string &b) {
  int s = min(a.size(), b.size());
  for (int i = 0; i < s; i++) {
    int tmp = a[i] - b[i];
    if (tmp < 0) {
      return 1;
    } else if (tmp > 0) {
      return 2;
    } else {
      continue;
    }
  }
  //返回最短的字符串
  return s == a.size() ? 1 : 2;
}
class FoodRatings {
public:
  struct mpair {
    string food;
    int rating;
  };
  map<string, vector<mpair *>> m;
  map<string, mpair *> mf;
  vector<string> foodss;
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    foodss = foods;
    std::sort(foodss.begin(), foodss.end(), [](string &a, string &b) {
      return getMinDicOrder(a, b) == 1 ? true : false;
    });
    for (int i = 0; i < foods.size(); i++) {
      mpair *tmp = new mpair{foods[i], ratings[i]};
      mf[foods[i]] = tmp;
      m[cuisines[i]].push_back(tmp);
    }
  }

  void changeRating(string food, int newRating) {
    mf[food]->rating = newRating;
  }

  string highestRated(string cuisine) {
    int max_ = std::numeric_limits<int>::min();
    int a = 0;
    vector<string> foodsss;
    auto i = m[cuisine];
    for (int j = 0; j < i.size(); j++) {
      if (i[j]->rating > max_) {
        max_ = i[j]->rating;
        a = j;
      }
    }
    for (auto j : i) {
      if (j->rating == max_) {
        a = getMinDicOrder(i[a]->food, j->food);
      }
    }
    return i[a]->food;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
  vector<string> foodss{"aab", "abb"};
  std::sort(foodss.begin(), foodss.end(), [](string &a, string &b) {
    return getMinDicOrder(a, b) == 1 ? true : false;
  });
  std::cout<<foodss[0];
}