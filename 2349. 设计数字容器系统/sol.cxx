#include "../header.h"
#include <vector>
#include <unordered_map>
class NumberContainers {
public:
    map<int, int> kv;
    unordered_map<int, set<int>> numSet;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(kv.find(index) !=kv.end()){
            numSet[kv[index]].erase(index);
            if(numSet[kv[index]].empty()){numSet.erase(kv[index]);}
            kv[index] = number;
            numSet[number].insert(index);
        }else {        
        kv[index] = number;
        numSet[number].insert(index);
        }
    }
    
    int find(int number) {
        if(numSet.find(number) == numSet.end())return -1;
        else
         return *numSet[number].begin();
    }
};