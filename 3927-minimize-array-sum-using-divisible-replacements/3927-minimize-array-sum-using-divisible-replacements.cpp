class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        for(auto ele : nums){
            mp[ele]++;
            maxi = max(maxi,ele);
        }
        vector<int>arr(maxi+1,0);
        for(int i = 0 ; i<n ; i++){
            arr[nums[i]] = mp[nums[i]];
        }
        long long sum = 0;
        
        if(arr[1]!=0){
            return n;
        }

        int h = 2;
        while(h<arr.size()){
            if(arr[h]==0){
                h++;
                continue;
            }
            sum += (long long)h*(long long)mp[h];
            for(int i = h*2 ; i<arr.size() ; i+=h){
                if(arr[i]!=0){
                    sum+= (long long)h*(long long)mp[i];
                    arr[i] = 0;
                }
            }
            h++;
        }
        return sum;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna