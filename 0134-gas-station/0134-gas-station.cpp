class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int tank = 0;
        int total = 0;

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];

            tank += diff;
            total += diff;

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (total >= 0) ? start : -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna