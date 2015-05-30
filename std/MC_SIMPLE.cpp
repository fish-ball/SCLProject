\subsection*{Simple Depth First Search}
\begin{lstlisting}
int list[maxn][maxn], g[maxn][maxn] ,s[maxn], degree[maxn];
int found, n, curmax, curobj, ans[maxn], map[maxn];

int cmp(const int &i, const int &j){ return map[i]<map[j]; }

void sortdegree()
{
    int i,j,k,l;  memset(degree, 0, sizeof(degree));
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(g[i][j]) ++degree[i];
    for(i=1; i<=n; i++) {       
        for(k=i, j=i+1; j<=n; j++) if( degree[j]<degree[k] ) k=j;
        if( k!=i ) {
            std::swap(degree[i],degree[k]); std::swap(map[i],map[k]);
            for(l=1;l<=n;l++) std::swap(g[i][l],g[k][l]);
            for(l=1;l<=n;l++) std::swap(g[l][i],g[l][k]);   
        }
    }
}

void dfs(int d)
{
    if( d-1+list[d][0]<=curmax ) return;
    if( d-1>curmax ){ curmax = d-1; 
        for(int i=1; i<=curmax; i++) ans[i] = s[i];
    }
    for(int j,i=1; i<list[d][0]-curmax+d; i++) {
        for(j=i+1,list[d+1][0]=0; j<=list[d][0]; j++)
            if( g[list[d][j]][list[d][i]] )
                list[d+1][++list[d+1][0]] = list[d][j];
        s[d] = list[d][i];  dfs( d+1 );
    }       
}

void solve() // only need a matrix G
{
    int i,j; curmax=0; list[1][0]=n;
    for(i=1;i<=n;i++) map[i]=i;  sortdegree();
    for(j=1; j<=n; j++) list[1][j] = j;
    dfs(1); cout<<curmax<<endl; 
    std::sort(ans+1, ans+1+curmax, cmp);
    for(i=1; i<=curmax; i++) cout<<map[ans[i]]<<" "; cout<<endl;
}
\end{lstlisting}