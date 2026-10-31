class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mini = INT_MAX;
        int n = nums.size();
        int ans = -1;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i<n-1 ; i++){
                int j = i+1,k = n-1;
                while(j<k){
                    int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    
                    if(sum == target){
                        return sum;
                    }
                    if(abs(target-sum) < mini) {

                        mini = abs(target-sum);

                        ans = sum;

                    }
                    if(sum<target){
                      
                        j++;
                    }
                    else if(sum>target){
                       
                        k--;
                    }
                }
                    
        }
            
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna