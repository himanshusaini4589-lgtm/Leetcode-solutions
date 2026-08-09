class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = a|b;
        int flip = 0;

        while(c>0 || d>0){
            int last = (d&1);
            int ans_last = (c&1);
            if(last!=ans_last && last == 0){
                flip++;
            }
            else if(last!=ans_last && last == 1){
                int q = a&1;
                int p = b&1;
                if(p==q && p==1){
                    flip+=2;
                }
                else if(p==1 || q==1){
                    flip++;
                }
            }
            d = d>>1;
            c = c>>1;
            a = a>>1;
            b  = b>>1;
        }
        return flip;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna