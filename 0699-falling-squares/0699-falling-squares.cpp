class Solution {
public:
    vector<int>segT;
    vector<int>lazy;
    void prop(int i,int l,int r){
        if(lazy[i]==0) return ;
        
        if(l!=r){
            segT[2*i+1] = lazy[i];
            segT[2*i+2] = lazy[i];
            lazy[2*i+1] = lazy[i];
            lazy[2*i+2] = lazy[i];
        }
        lazy[i] = 0 ;
    }
    void update(int i ,int l,int r,int ql,int qr,int val){
        prop(i,l,r);

        if(l > qr || r < ql) return;

        if(ql <=l && r <= qr){
            segT[i] = val;
            lazy[i] = val;
            return;
        }


        int mid = l + (r-l)/2;

        update(2*i+1, l, mid, ql, qr, val);

        update(2*i+2, mid+1, r, ql, qr, val);
        segT[i] = max(segT[2*i+1],segT[2*i+2]);
    }

    int query(int i,int l,int r,int ql,int qr){
        if(l>qr || r<ql){
            return 0;
        }
        prop(i,l,r);
        if(ql<=l && r<=qr){
            return segT[i];
        }
        int mid = l + (r-l)/2;
        return max(query(2*i+1,l,mid,ql,qr),query(2*i+2,mid+1,r,ql,qr));
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> coords;

        for (auto &p : positions) {

            coords.push_back(p[0]);

            coords.push_back(p[0] + p[1]);

        }

        sort(coords.begin(), coords.end());

        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int n = coords.size();
        segT.resize(4*n,0);
        lazy.resize(4*n,0);
        vector<int> result;
        int maxHeight = 0;
        for(auto ele : positions){
            int x = ele[0];
            int sz = ele[1];
            int y = x + sz;
            int l = lower_bound(coords.begin(),coords.end(),x) - coords.begin();
            int r = lower_bound(coords.begin(),coords.end(),y) - coords.begin()-1;
            int height = query(0,0,n-1,l,r) + sz;
           
            update(0,0,n-1,l,r,height);

            maxHeight = max(maxHeight, height);

            result.push_back(maxHeight);
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna