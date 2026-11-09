#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // number of test cases
    while (t--)
    {
        long long n;
        cin >> n; // size of the array
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
            cin >> arr[i];

        // Key idea:
        // Let g' = gcd of all elements EXCEPT arr[i].
        // If we replace arr[i] with any value x, the new gcd = gcd(g', x).
        //  - If g' == 1: gcd(1, x) = 1 for every x, so the gcd can never change
        //                -> index i is NOT strong.
        //  - If g' > 1:  we can get at least two different results
        //                (x = 1 gives 1, x = g' gives g'), so one of them
        //                must differ from the current gcd -> index i IS strong.
        // So: index i is strong  <=>  gcd of all elements except arr[i] > 1.

        // prefix_gcd[i] = gcd(arr[0], arr[1], ..., arr[i])
        vector<long long> prefix_gcd(n);
        prefix_gcd[0] = arr[0];
        for (long long i = 1; i < n; i++)
            prefix_gcd[i] = gcd(prefix_gcd[i - 1], arr[i]);

        // suffix_gcd[i] = gcd(arr[i], arr[i + 1], ..., arr[n - 1])
        vector<long long> suffix_gcd(n);
        suffix_gcd[n - 1] = arr[n - 1];
        for (long long i = n - 2; i >= 0; i--)
            suffix_gcd[i] = gcd(suffix_gcd[i + 1], arr[i]);

        long long answer = 0; // count of strong indices
        for (long long i = 0; i < n; i++)
        {
            // g' for index i: combine everything on the left and right of i
            long long gcd_excluding_i;
            if (i == 0) // nothing on the left
                gcd_excluding_i = suffix_gcd[1];
            else if (i == n - 1) // nothing on the right
                gcd_excluding_i = prefix_gcd[n - 2];
            else // left part [0, i-1] and right part [i+1, n-1]
                gcd_excluding_i = gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]);
            if (gcd_excluding_i > 1) // changing arr[i] can change the overall gcd
                answer++;
        }
        cout << answer << endl;
    }
    return 0;
}

// Time Complexity: O(n log(max(arr[i])))
// Space Complexity: O(n)

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna