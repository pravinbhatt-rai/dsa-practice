class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        const int inf=1e9;


        vector<int>dist(n,inf);
        dist[src]=0;


        for(int i=0;i<=k;i++){
            vector<int> temp=dist;

            for(auto &f:flights){
                int u=f[0];
                int v=f[1];

                int price=f[2];

                if(dist[u]!=inf){
                    temp[v]=min(temp[v],dist[u]+price);


                }
            }

            dist=temp;


        }

        return dist[dst]==inf?-1:dist[dst];
    }
};