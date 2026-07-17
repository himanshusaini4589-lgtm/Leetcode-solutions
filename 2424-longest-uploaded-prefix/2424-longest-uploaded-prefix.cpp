class LUPrefix {
public:
    vector<int>segmentTree;
    vector<int> up;
    int m;
    LUPrefix(int n) {
        m = n;
        up.resize(n+1,0);
        segmentTree.resize(4*(n+1));
    }
    
    void update(int i,int l,int r,int idx){
        if(l==r){
            segmentTree[i] = 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx);
        }
        else{
            update(2*i+2,mid+1,r,idx);
        }
        segmentTree[i] = (segmentTree[2*i+1] & segmentTree[2*i+2]);
    }

    int query(int i,int l,int r){
        if(segmentTree[i]==1) return r;
        if(l==r){
            return l-1;
        }
        int mid = l + (r-l)/2;
        if(segmentTree[2*i+1]==0){
            return query(2*i+1,l,mid);
        }
        return query(2*i+2,mid+1,r);
    }
    void upload(int video) {
        up[video] = 1;
        update(0,1,m,video);
    }
    
    int longest() {
        int k = query(0,1,m);
        return k;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna