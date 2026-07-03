class Solution {
    private:
    bool check(int mid,int n,long long k,vector<vector<pair<int,int>>>adj){
        vector<long long>dis(n,LLONG_MAX);
         priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                           greater<>>pq;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto[d,node]=pq.top();
            pq.pop();
            if(d>k) continue;
            if(node==n-1) return true;
            if(d>dis[node]) continue;
            for(auto it:adj[node]){

                int adjn=it.first;
                int edw=it.second;
                if(edw<mid) continue;
                if(dis[adjn]>d+edw){
                    dis[adjn]=d+edw;
                    pq.push({dis[adjn],adjn});
                }
            }

        }
        return false;

        
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
          int n=online.size();
        vector<vector<pair<int,int>>>adj(n);
        int src=0,dst=n-1;
        int l=INT_MAX;int r=INT_MIN;
        for(auto edge:edges){
            if(!online[edge[0]]||!online[edge[1]]) continue;
            l=min(l,edge[2]);
            r=max(r,edge[2]);
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        if(!check(l,n,k,adj)) return -1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,n,k,adj)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r;
   
    
    }
};