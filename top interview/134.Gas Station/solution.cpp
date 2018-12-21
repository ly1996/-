class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int res = -1, gasRest = 0, costMost = 0;
    for (int i = 0; i < gas.size(); i++){
      gasRest += gas[i]-cost[i];
      if (costMost > gasRest){
          costMost = gasRest;
          res = i;
      }
    }
    if (gasRest < 0)
      return -1;
    return res + 1;
  }
};