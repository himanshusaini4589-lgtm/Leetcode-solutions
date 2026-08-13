class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev;
        unordered_set<int>curr;
        unordered_set<int>result;
        int n = arr.size();
        for(int i = 0 ; i< n; i++){

            for(auto ele : prev){
                curr.insert(ele|arr[i]);
                result.insert(ele|arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return result.size();


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna