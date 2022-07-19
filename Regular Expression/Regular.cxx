#include "../header.h"

class Solution {
public:
  string ss, pp;
  bool isMatch(string s, string p) {
    auto pPtr = p.begin();
    auto sPtr = s.begin();
    int isSmatch = 1;
    ss = s;
    pp = p;
    auto save = pPtr;
    if (charPattern(sPtr, pPtr, &isSmatch)) {
      return true;
    } else {
      pPtr = save;
    }
    if (dotPattern(sPtr, pPtr, &isSmatch)) {
      return true;
    } else {
      pPtr = save;
    }
    return isSmatch == 1;
  }

public:
  bool charPattern(string::iterator &sPtr, string::iterator &pPtr,
                   int *isSmatch);

  bool starPattern(string::iterator &sPtr, string::iterator &pPtr,
                   int *isSmatch);
  bool dotPattern(string::iterator &sPtr, string::iterator &pPtr,
                  int *isSmatch);
};
inline bool Solution::dotPattern(string::iterator &sPtr, string::iterator &pPtr,
                                 int *isSmatch) {
  if (*isSmatch == -1) {
    return false;
  }

  if (++pPtr == ss.end() || *(pPtr) != '.') {
    return false;
  }

  if (sPtr++ == ss.end()) {
    *isSmatch = -1;
    return false;
  }

  auto save = pPtr;
  //递归下降
  if (starPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  if (charPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  if (dotPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  return false;
}

inline bool Solution::charPattern(string::iterator &sPtr,
                                  string::iterator &pPtr, int *isSmatch) {
  if (*isSmatch == -1) {
    return false;
  }

  if (++pPtr == ss.end() || (*(pPtr) > 'z' && *(pPtr) < 'a')) {
    return false;
  }

  if (sPtr++ == ss.end()) {
    *isSmatch = -1;
    return false;
  }

  auto save = pPtr;
  //递归下降
  if (starPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  if (charPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  if (dotPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  return false;
}

bool Solution::starPattern(string::iterator &sPtr, string::iterator &pPtr,
                           int *isSmatch) {
  if (*isSmatch == -1) {
    return false;
  }

  if (++pPtr == ss.end() || *pPtr == '*') {
    return false;
  }
  char starChar = *(--sPtr);
  auto save = pPtr;
  while (1) {
    if (sPtr == ss.end()) {
      break;
    }
    if (starChar != '.' && *sPtr != starChar) {
      break;
    }
    if (charPattern(sPtr, pPtr, isSmatch)) {
      return true;
    } else {
      pPtr = save;
    }
  }

  //递归下降
  if (charPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  if (dotPattern(sPtr, pPtr, isSmatch)) {
    return true;
  } else {
    pPtr = save;
  }
  return false;
}
int main() {}