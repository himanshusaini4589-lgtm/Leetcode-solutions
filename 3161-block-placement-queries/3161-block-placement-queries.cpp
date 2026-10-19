class Solution {
public:
    int n = 50000;
    vector<int> segTree;
    void construct(int n){
        segTree.resize(4*n,0);
    }

    void update(int idx,int val ,int i,int l ,int r){
        if(l==r){
            segTree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid){
            update(idx,val,2*i+1,l,mid);
        }
        else{
            update(idx,val,2*i+2,mid+1,r);
        }

        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
    }

    int query(int i,int l,int r,int q_l,int q_r){
        if(q_l>r || q_r<l){
            return 0;
        }
        if(q_l<=l && q_r >=r){
            return segTree[i];
        }
        int mid = l + (r-l)/2;

        return max(query(2*i+1,l,mid,q_l,q_r),query(2*i+2,mid+1,r,q_l,q_r));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        construct(50000);
        set<int>st;
        st.insert(0);
        vector<bool> res;
        for(auto &q : queries){
            if(q[0]==1){
                int x = q[1];
                auto it = st.upper_bound(x);
                int nxt = (it) != st.end() ? *it : -1;
                int pre = *prev(it);
                update(x,x-pre,0,0,n-1);
                if(nxt!=-1) update(nxt, nxt-x,0,0,n-1);
                st.insert(q[1]);
            }
            else{
                int x= q[1];
                int sz = q[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int maxi = query(0,0,n-1,0,pre);
                int maxgap = max(x-pre,maxi);
                if(maxgap>=sz) res.push_back(true);
                else res.push_back(false);
                
            }
            
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna