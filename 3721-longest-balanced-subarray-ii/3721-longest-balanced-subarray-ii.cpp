class Solution {
public:
    vector<int>segMin;
    vector<int>segMax;
    vector<int>lazy;
    int n;
    void updateRange(int i ,int l,int r,int q_l,int q_r,int val){
        if(lazy[i]!=0){
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];
            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(q_r<l || q_l>r){
            return;
        }
        if(q_l<=l && r<=q_r){
            lazy[i] += val;
                if(lazy[i]!=0){
                    segMin[i] += lazy[i];
                    segMax[i] += lazy[i];
                    if(l!=r){
                        lazy[2*i+1] += lazy[i];
                        lazy[2*i+2] += lazy[i];
                    }
                    lazy[i] = 0;
                }
            return;

        }
        int mid = l + (r-l)/2;
        updateRange(2*i+1,l,mid,q_l,q_r,val);
        updateRange(2*i+2,mid+1,r,q_l,q_r,val);

        segMin[i] = min(segMin[2*i+1],segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1],segMax[2*i+2]);
    }

    int findLeftZero(int i ,int l,int r){
        if(lazy[i]!=0){
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];
            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(segMax[i]<0 || segMin[i]>0){
            return -1;
        }
        if(l==r) return l;

        int mid = l + (r-l)/2;
        int left = findLeftZero(2*i+1,l,mid);
        if(left != -1){
            return left;
        }
        return findLeftZero(2*i+2,mid+1,r);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        vector<int>cumSum(n,0);
        segMin.assign(4*n,0);
        segMax.assign(4*n,0);
        lazy.assign(4*n,0);
        int maxL = INT_MIN;
        unordered_map<int,int> mp;

        for(int i = 0 ; i<n ; i++){
            int val = nums[i]%2==0 ? 1 : -1;
            int prev = -1;
            if(mp.count(nums[i])){
                prev = mp[nums[i]];
            }

            if(prev != -1){
                updateRange(0,0,n-1,0,prev,-val);
            }

            updateRange(0,0,n-1,0,i,val);
            
            int left = findLeftZero(0,0,n-1);
            if(left!=-1){
                maxL = max(maxL,i-left+1);
            }
            mp[nums[i]] = i;
        }
        return maxL!=INT_MIN ? maxL : 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna