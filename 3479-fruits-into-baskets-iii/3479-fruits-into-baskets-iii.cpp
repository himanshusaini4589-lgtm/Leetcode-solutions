class Solution {
public:
    int n;
    vector<int>segmentTree;

    void build(vector<int>&nums,int i,int l,int r){
        if(l==r){
            segmentTree[i] = l;
            return;
        }
        int mid = l + (r-l)/2;
        build(nums,2*i+1,l,mid);
        build(nums,2*i+2,mid+1,r);
        int left = nums[segmentTree[2*i+1]];
        int right = nums[segmentTree[2*i+2]];
        if(left>=right){
            segmentTree[i] = segmentTree[2*i+1];
        }
        else{
            segmentTree[i] = segmentTree[2*i+2];
        }
    }
     void update(vector<int>& nums, int i, int l, int r, int idx) {

        if (l == r) {

            segmentTree[i] = l;

            return;

        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)

            update(nums, 2 * i + 1, l, mid, idx);

        else

            update(nums, 2 * i + 2, mid + 1, r, idx);

        int left = segmentTree[2 * i + 1];

        int right = segmentTree[2 * i + 2];

        if (nums[left] >= nums[right])

            segmentTree[i] = left;

        else

            segmentTree[i] = right;

    }
    void query(vector<int> &nums,int i,int l,int r,int value){
        if(value>nums[segmentTree[i]]) return ;
        if(l==r){
            nums[l] = 0;
            update(nums,0,0,n-1,l);
            return;
        }
        
        int mid = l + (r-l)/2;
        if(value<=nums[segmentTree[2*i+1]]){
            query(nums,2*i+1,l,mid,value);
        }
        else{
            query(nums,2*i+2,mid+1,r,value);
        }
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = fruits.size();
        segmentTree.resize(4*n);
        build(baskets,0,0,n-1);
        for(int i = 0 ; i<n ; i++){
            query(baskets,0,0,n-1,fruits[i]);
        }
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            if(baskets[i]!=0){
                count++;
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna