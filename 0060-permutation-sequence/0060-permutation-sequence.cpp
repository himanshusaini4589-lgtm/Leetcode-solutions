class Solution {
public:
    
    // void f(int i,int n ,int cnt,int k,vector<int> &temp){
    //     if(i>=10) return;
    //     if(cnt == k){
    //         if(temp.size() == n) ans = temp;
    //         return ;
    //     }
    //     if(temp.size() == n){
    //         cnt++;
    //     }
    //     if(!nums[i]){
    //         temp.push_back(i);
    //         nums[i] = true;
    //         f(i+1,n,cnt,k,temp);
    //         temp.pop_back();
    //         nums[i] = false;
    //     }

    //     f(i+1,n,cnt,k,temp);
    // }
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i = 1 ; i<=n ; i++){
            nums.push_back(i);
        }
        int fact = 1;
        for(int i = 1 ; i<n ; i++){
            fact *= i;
        }
        k--;
        string s = "";
        while(nums.size()){
            int index = k/fact;
            s += nums[index] + '0';
           nums.erase(nums.begin() + index);
           if(nums.size()==0) break;
            k %= fact;
            fact/=nums.size();
        }
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna