class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n/2;
        int n2 = n-n1;
        vector<long long> subsetsuma(1<<n1);
        vector<long long> subsetsumb(1<<n2);

        for(int mask = 0 ; mask<(1<<n1) ; mask++){
            long long sum = 0;
            for(int j = 0 ; j<n1 ; j++ ){
                if(mask&(1<<j)){
                    sum += nums[j];
                }
            }
            subsetsuma[mask] = (sum);
        }

        for(int mask = 0 ; mask<(1<<n2) ; mask++){
            long long sum = 0;
            for(int j = 0 ; j<n2 ; j++ ){
                if(mask&(1<<j)){
                    sum += nums[n1+j];
                }
            }
            subsetsumb[mask] = (sum);
        }
        int ans = INT_MAX;
        sort(subsetsumb.begin(),subsetsumb.end());

        for(int i = 0 ; i<(1<<n1) ; i++){
            long long first = subsetsuma[i];

            long long target = (goal - first);

            int it = lower_bound(subsetsumb.begin(),subsetsumb.end(),target) - subsetsumb.begin();

            if(it<(subsetsumb.size())) ans = min(ans,(int)abs(first + subsetsumb[it] - goal));
            if (it > 0) {

                ans = min(ans, (int)abs(first + subsetsumb[it - 1] - goal));

            }
        }

        return ans;


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna