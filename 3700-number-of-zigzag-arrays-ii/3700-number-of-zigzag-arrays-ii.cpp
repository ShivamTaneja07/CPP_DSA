class Solution {
public:
    const int mod=1e9+7;

    int dot(vector<int> &a,vector<int> &b){
        int n=a.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=sum+((a[i]*1ll*b[i])%mod);
            sum%=mod;
        }
        return (sum%mod);
    }

    void trans(vector<vector<int>> &a){
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(a[i][j],a[j][i]);
            }
        }
    }
    vector<vector<int>> Mul(vector<vector<int>> &a,vector<vector<int>> &b){
        int n=a.size();
        trans(b);
        vector<vector<int>>c(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c[i][j]=dot(a[i],b[j]);
            }
        }
        return c;
    }

    vector<vector<int>> binexp(vector<vector<int>>&a,int p){
        int n=a.size();
        vector<vector<int>>res(n,vector<int>(n));
        for(int i=0;i<n;i++)res[i][i]=1;

        while(p){
            if(p%2){
                res=Mul(res,a);
                p--;
            }
            a=Mul(a,a);
            p>>=1;
        }           
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m=(r-l+1);
        vector<vector<int>>e(m,vector<int>(m)),o,conj;
        for(int i=0;i<m;i++){
            for(int j=1+i;j<m;j++)e[i][j]=1;
        }
        o=e;
        reverse(o.begin(),o.end());
        for(auto &v:o)reverse(v.begin(),v.end());
        
        conj=Mul(e,o);

        vector<int>base(m,1);
        int dist=n-1;
        
        if(dist%2){
            dist/=2;
            conj=binexp(conj,dist);
            conj=Mul(conj,e);
        }else{
            dist/=2;
            conj=binexp(conj,dist);
        }

        long long ans=0;
        for(auto &v:conj){
           ans=(ans%mod+dot(v,base)%mod)%mod;            
        }
        ans<<=1;
        ans%=mod;
        return ans;
    }
};