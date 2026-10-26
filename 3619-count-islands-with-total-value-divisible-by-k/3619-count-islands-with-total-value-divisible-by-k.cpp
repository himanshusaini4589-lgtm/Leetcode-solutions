class Solution {
public:
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,1,0,-1};
    int n;
    int m;

    long long dfs(vector<vector<int>>& nums,vector<vector<int>>&vis,int r,int c){
        vis[r][c] = 1;
        long long sum = nums[r][c];
        for(int i= 0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(((nr<n && nr>=0) && (nc>=0 && nc<m)) && !vis[nr][nc] && nums[nr][nc] !=0){
                sum += dfs(nums,vis,nr,nc);
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& nums, int k) {
        n = nums.size();
        m = nums[0].size();
    
        vector<vector<int> >vis(n,vector<int>(m,0));

        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(nums[i][j]==0){
                    vis[i][j] = 1;
                }
            }
        }

        int count = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(!vis[i][j] && nums[i][j]!=0){
                   long long sum =  dfs(nums,vis,i,j);
                   if(sum%k ==0) count++;
                }
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna