class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        // use state expansion in dijikstra

        // Node 0 has a. Node 1 has a.Node 2 has b.

        auto copy= edges;

        vector<vector<pair<int,int>>>adj(n);

        for(auto &e:copy){
            int u=e[0];
            int v=e[1];
            int w=e[2];
        adj[u].push_back({v,w});
        }

        const long long INF=LLONG_MAX;

        // using the dp

        vector<vector<long long>>dist(n,vector<long long>(k+1,INF));


        

        using T=tuple<long long,int,int>;

        priority_queue<T,vector<T>,greater<T>> pq;
        // first dp lai 0 bana ani count 1 bana;

        dist[0][1]=0;

        pq.push({0,0,1});// cost node ani count


        while(!pq.empty()){
            auto[cost,node,cnt]=pq.top();
            pq.pop();

            if(cost!=dist[node][cnt]) continue;
            if(node==n-1){
                return (int)cost;
            }

            for(auto &[next,weight]:adj[node]){
                int newCnt;

                if(labels[node]==labels[next]){
                    newCnt=cnt+1;
                }else
                {
                    newCnt=1;

                }

                if (newCnt>k) continue;


                long long newcost=cost+weight;

                if(newcost<dist[next][newCnt]){
                    dist[next][newCnt]=newcost;

                    pq.push({newcost,next,newCnt});
                }
            }
        }


        return -1;



        
        
    }
};