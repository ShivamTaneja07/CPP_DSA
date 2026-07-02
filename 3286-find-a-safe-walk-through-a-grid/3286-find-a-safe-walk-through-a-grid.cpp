class Solution {
public: 
    vector<vector<int>> adj = {{0,1},{1,0},{-1,0},{0,-1}};
  
    bool findSafeWalk(vector<vector<int>>& g, int h) {
     int m=g.size();
     int n=g[0].size();

     vector<vector<int>> v(m+1,vector<int> (n+1,-1));

     priority_queue<vector<int>> q;
     
     if(g[0][0]) h--;

     q.push({h,0,0});
     v[0][0]=h;

     while(q.size())
     {
       auto it=q.top(); q.pop();
       
       int i=it[1],j=it[2];

       int d=it[0];

       if( i==m-1 && j==n-1 && d>=1) return 1;

       if(d==0 || d<v[i][j]) continue;

       for(auto k : adj)
       {
        int x = i+k[0];
        int y = j+k[1];

        if(x>=0 && y>=0 && x<m && y<n) 
       {
         int nd=d-g[x][y];
         if(nd>v[x][y])
         { 
            v[x][y]=nd;
            q.push({nd,x,y});}
         }
       }
     }

     return 0;
    }
};