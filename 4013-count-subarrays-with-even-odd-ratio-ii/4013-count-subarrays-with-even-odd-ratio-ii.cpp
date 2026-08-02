#define ll long long
class Solution {
public:
    vector<int>segmentTree;
    void update(int i ,int l,int r,int idx){
        if(l==r){
            segmentTree[i] +=1;
            return ;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx);
        }
        else{
            update(2*i+2 , mid+1,r,idx);
        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    int query(int i ,int l,int r,int ql,int qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && r<=qr){
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        return query(2*i+1,l,mid,ql,qr) + query(2*i+2,mid+1,r,ql,qr);
    }
    
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        // now what we want y>0 and x*b - y*a <=0 

        int n = nums.size();
        vector<ll>pref(n+1,0);
        
        for(int i = 0 ; i<n ; i++){
            pref[i + 1] = pref[i] + (nums[i] % 2 ? -a : b);
        }

        vector<ll> comp = pref;
        sort(comp.begin(),comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        int m = comp.size();
        auto getIdx = [&](ll x){
            return lower_bound(comp.begin(),comp.end(),x) - comp.begin();
        };
        
        segmentTree.assign(4*m,0);
        update(0,0,m-1,getIdx(pref[0]));
        long long sum = 0;
        for(int i = 1 ; i<=n ; i++){
            ll ele = pref[i];

            int idx = getIdx(ele);
            sum+= query(0,0,m-1,idx,m);

            update(0,0,m-1,idx);
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna