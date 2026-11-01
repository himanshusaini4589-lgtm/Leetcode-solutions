class Solution {
public:
    
    long long minimumMaxValue(int n, int index, int value) {
            if(value == 1) return -1;
            bool is_prime = true;
            for(int i = 2 ; i*i<=value ; i++){
                if(value % i == 0) is_prime = false;
            }

            if(is_prime){
                if(index != 0) return -1;
                int rem = n-index-2;
                long long curr = 2*value;
                long long ans = curr + (long long)rem*2;
                return ans;
            }
            if(value%2 == 0){
                if(index*2 >= value) return -1;
                long long ans = (long long)(n-index-1)*2 + (long long)value;
                return ans;
            }
            else{
                int spf = -1;
                for(int i = 3 ; i<=n ; i+=2){
                    if(value%i == 0) {
                        spf = i;
                        break;
                    }
                }
                int prev_ele = value - spf;
                int prev_num = index-1;
                if(prev_num*2 >= prev_ele ) return -1;
                int nxt = value + spf;
                if(index == n-1){
                    return value;
                }
                else if(index == n-2){
                    return value + spf;
                }
                else{
                    int rem = n-index-2;
                    long long ans = (long long)value + (long long)spf + (long long)rem*2;
                    return ans;
                }
            }
            return -1;        
        
            //     if(is_prime){
            //         if(index != 0) return -1;
            //         if(index == n-2) return 2*value;
            //         else{
            //             int rem = n-index-2;
            //             int curr = 2*value;
            //             int ans = curr + rem*2;
            //             return ans;
            //         }
            //     }
        
            // if(value %2 == 0 && index*2 >=value ) return -1;
            // if(value %2 != 0 && index*2+1 >=value ) return -1;
            // if(value == 1) return -1;
            // if(value%2==0){
            //     return (n-index-1)*2 + value;
            // }
            // else{
                
            //         if(index == n-1) return value;
            //         if(index == n-2) return 3+value;
            //         else{
            //             int rem = n-index-2;
            //             int curr = 3+value;
            //             int ans = curr + rem*2;
            //             return ans;
            //         }
                    
                
            // }

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna