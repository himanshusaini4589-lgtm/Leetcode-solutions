class Solution {
    public:
    int minimumDifference(vector<int> & v) {
        int n = v.size();
        int n1 = n/2;
        int n2 = n - n1;

        vector<vector<long long>> subsetsuma(n1+1), subsetsumb(n2+1);
        for(int i = 0 ; i<(1<<n1) ; i++){
            long long sum = 0;
            int cnt = 0;
            for(int j = 0 ; j<n1 ; j++){
                if(i&(1<<j)){
                    sum += v[j];
                    cnt++;
                }
            }
            subsetsuma[cnt].push_back(sum);
        }
        for(int i = 0 ; i<(1<<n2) ; i++){
            long long sum = 0;
            int cnt = 0;
            for(int j = 0 ; j<n2 ; j++){
                if(i&(1<<j)){
                    sum += v[n1+j];
                    cnt++;
                }
            }
            subsetsumb[cnt].push_back(sum);
        }
        long long totalsum = accumulate(v.begin(),v.end(),0LL);
        long long mini = LLONG_MAX;
        for(int i = 0 ; i<=n2 ; i++){
            sort(subsetsumb[i].begin(),subsetsumb[i].end());
        }
        for(int i = 0 ; i<=n1 ; i++){
            for(long long curr : subsetsuma[i]){
                long long target = totalsum/2 - curr;
                auto it = lower_bound(
                    subsetsumb[n1-i].begin(),
                    subsetsumb[n1-i].end(),
                    target
                );
                if(it != subsetsumb[n1-i].end()){
                    long long sum = curr + *it;
                    mini = min(mini,abs(totalsum-2*sum));
                }
                // if(it != subsetsumb[n1-i].begin()){
                //     --it;
                //     long long sum = curr + *it;
                //     mini = min(mini,abs(totalsum-2*sum));
                // }
            }
        }
        return mini;
    }

};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna