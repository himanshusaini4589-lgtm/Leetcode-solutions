#include <bits/stdc++.h>
using namespace std;

vector<int> spf (int n){
    
    vector<int>sp(n+1,0);
    for(int i = 2 ; i<=n ; i++){
        if(sp[i] == 0){
             sp[i] = i;    
            for(long long j = 1LL*i*i ; j<=n ; j+=i){
                if(sp[j] == 0){
                    sp[j] = i;
                }
            }
        }
    }
    return sp;
}

unordered_set<int> gen(int x,vector<int> &sp ){
    unordered_set<int> st;
    
    string s = to_string(x);
    sort(s.begin(),s.end());
    do{
        if (s[0] == '0')
            continue;  
        int t = stoi(s);
        while(t>1){
            int sf = sp[t];
            st.insert(sf);
            while(t%sf==0){
                t/=sf;
            }
        }
    }
    while(next_permutation(s.begin(), s.end()));
    
    return st;
}
int main() {
	int n;
	cin>>n;
	vector<int> sp = spf(10000001);
	
	while(n--){
	    int x,y;
	    cin>>x>>y;
	    unordered_set A = gen(x,sp) , B = gen(y,sp);
	    
	    int ans = INT_MIN;
	    for(auto ele : A){
	        if(B.find(ele)!=B.end()){
	            ans = max(ans,ele);
	        }
	    }
	    int correct = ans == INT_MIN ? 1 : ans;
	    cout<<correct<<endl;
	}

}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna