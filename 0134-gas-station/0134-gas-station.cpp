class Solution {
public:
    bool check(vector<int>&gas,vector<int>&cost,int idx){
        int n = gas.size();
        int i = 0;
        int rem_gas = 0 ;
        while(i<n){
            rem_gas += gas[idx] - cost[idx];
            if(rem_gas<0) return false;
            idx = (idx + 1)%n;
            i++;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>v;
        for(int i = 0 ; i<n ; i++){
            if(gas[i]-cost[i]>=0) v.push_back(i);
        }
        for(int i = 0 ; i<v.size() ; i++){
            if(check(gas,cost,v[i])){
                return v[i];
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna