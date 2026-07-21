class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int pivat = n-1;
        for(int i = n-2 ; i>=0 ; i--){
            if(arr[i]>arr[i+1]){
                pivat = i;
                break;
            }
        }
        if(pivat == n-1) return arr;
        int s = n-1;
        for(int i = n-1 ; i>=0; i--){
            if(arr[pivat]>arr[i]){
                s = i;
                break;
            }
        }
        while(s>pivat+1 && arr[s]==arr[s-1]){
            s--;
        }
        swap(arr[s],arr[pivat]);
        
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna