class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& basket) {
        int n = fruits.size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(fruits[i]<=basket[j]){
                    basket[j] = 0;
                    break;
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            if(basket[i]!=0){
                count++;
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna