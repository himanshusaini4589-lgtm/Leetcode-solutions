class NumArray {
public:
    vector<int> segT;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segT.resize(4*n);
        build(0,0,n-1,nums);
    }
    
    void build(int i,int l,int r,vector<int>&nums){
        if(l==r){
            segT[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);

        segT[i] = segT[2*i+1] + segT[2*i+2];

    }

    void update(int i,int l,int r,int idx,int val){
        if(l==r){
            segT[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid) update(2*i+1,l,mid,idx,val);
        else update(2*i+2,mid+1,r,idx,val);

        segT[i] = segT[2*i+1] + segT[2*i+2];

    }

    int query(int i,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return 0;
        if(l>=ql && r<=qr) return segT[i];

        int mid = l + (r-l)/2;
        return query(2*i+1,l,mid,ql,qr) + query(2*i+2,mid+1,r,ql,qr);

    }
    void update(int index, int val) {
        update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna