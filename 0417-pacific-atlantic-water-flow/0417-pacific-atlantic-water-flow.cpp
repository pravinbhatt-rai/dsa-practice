class Solution {
public:
    int m,n;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>& visited){
        visited[r][c]=true;

        for(auto & d:dir){
            int nr=r+d[0];
            int nc=c+d[1];

            if(nr<0||nr>=m||nc<0||nc>=n){
                continue;
            }
            if(visited[nr][nc]){
                continue;
            }

            if(heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,heights,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m=heights.size();
        n=heights[0].size();

        vector<vector<bool>>pacefic(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));

        for(int c=0;c<n;c++){
            dfs(0,c,heights,pacefic);
            dfs(m-1,c,heights,atlantic);
        }

        for(int r=0;r<m;r++){
             dfs(r,n-1,heights,atlantic);
            dfs(r,0,heights,pacefic);
        }

        vector<vector<int>>ans;

        for(int r=0;r<m;r++)
            {
                for(int c=0;c<n;c++){
                    if(pacefic[r][c]&&atlantic[r][c]){
                        ans.push_back({r,c});
                    }
                }
            }


            return ans;
        
    }
};