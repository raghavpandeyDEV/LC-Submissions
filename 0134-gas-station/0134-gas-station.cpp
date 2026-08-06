class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int totalCost=0;

        int n=cost.size();

        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalCost>totalGas)return -1;

        int currGas=0;
        int currCost=0;
        int start=0;

        for(int i=0;i<n;i++){

            currGas+=gas[i];
            currCost+=cost[i];
            if(currCost>currGas){
               start=i+1;
               currGas=0;
               currCost=0;
               continue;
            }
        }

       return start;
    }
};