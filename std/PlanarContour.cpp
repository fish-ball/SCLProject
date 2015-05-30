\begin{lstlisting}
int x[maxn],y[maxn],g[maxn][maxn],num[maxn],base,n,size,mk[maxn][maxn];
int s[maxn], used[maxn], ans; double angle[maxn];

bool cmp(const int &i,const int&j){ return angle[i] < angle[j]; }

void dfs(int d,int u,int v)
{
    int i,j,w; s[d] = u; used[u]++;
    if( mk[u][v] ) {
        if( d==size ) {         
            used[u]--;
            for(j=1;j<=n;j++) if(used[j]>1) break; if(j<=n) return;         
            if(j>n) ++ans;          
        }       
        return;
    }   
    mk[u][v]=1; 
    for(j=0; j<num[v]; j++) if( g[v][j]==u ) break;
    j = (j+1)%num[v]; w = g[v][j]; dfs(d+1, v, w);  
}

void solve()
{
    int i,j,k,l,u,v;
    for(i=1; i<=n; i++){ 
        base=i;
        for(j=1; j<=n; j++) angle[j] = atan2(y[j]-y[i],x[j]-x[i]);
        std::sort(g[i], g[i]+num[i], cmp);
    }
    u = 1; memset(mk, 0, sizeof(mk));   
    for(i=2; i<=n; i++) if(y[i]<y[u] || (y[i]==y[u] && x[i]<x[u])) u=i;
    for(v=-1,i=0; i<num[u]; i++) {
        j = g[u][i]; if( j==u || j==v ) continue;
        if( v<0 ) { v=j; continue; }
        k = (x[j]-x[u])*(y[v]-y[u])-(y[j]-y[u])*(x[v]-x[u]);
        if( k<0 ) v=j; else
        if( k==0 ) if( y[j]<y[v] || (y[j]==y[v] && x[j]<x[v]) ) v=j;
    }
    dfs(0, v, u); ans = 0;  // outer contour
    for(i=1; i<=n; i++) for(j=0; j<num[i]; j++)
        if( !mk[i][g[i][j]] )
        {
            memset(used,0,sizeof(used));
            dfs(0,i,g[i][j]);           
        }   
}

int main()
{
    int t,i,j,k,l;
    cin>>t; while(t-->0) {
        cin>>n;
        for(k=0; k<n; k++) {
            cin>>i; cin>>x[i]>>y[i]; cin>>num[i];
            for(j=0;j<num[i];j++) cin>>g[i][j];
        }
        cin>>size; ans=0; if(size<3) size=3; 
        solve(); cout<<ans<<endl;
    } return 0;
}
\end{lstlisting}