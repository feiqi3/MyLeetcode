#include "../header.h"
#include <set>
#include <vector>
class Solution {
  struct mNode {
    vector<int> ids;
    bool isBlocked = false;
    bool reached = false;
  };

public:
  int searchTheTree(int node, std::vector<mNode> &n) {
    int res = 0;
    if(n[node].reached == false){
        n[node].reached = true;
        res = 1;
    }
    for (int &i : n[node].ids) {
      if (n[i].reached == false) {
        n[i].reached = true;
        res +=1 + searchTheTree(i, n);
      }
    }
    return res;
  }

  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    if (restricted[0] == 0)
      return 0;
    vector<mNode> nodes(n);
    vector<bool> isBlocked(n, false);
    nodes = vector<mNode>(n);
    isBlocked = vector<bool>(n, false);

    for (auto i : restricted) {
      isBlocked[i] = true;
    }
    for (int i = 0; i < edges.size(); i++) {
      int nodeBID = edges[i][0];
      int nodeAID = edges[i][1];
      if (!isBlocked[nodeAID] && !isBlocked[nodeBID]) {
        nodes[nodeAID].ids.push_back(nodeBID);
        nodes[nodeBID].ids.push_back(nodeAID);
      }
    }
    int res = 0;
    res += searchTheTree(0, nodes);
    return res;
  }
};