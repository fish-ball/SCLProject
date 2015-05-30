\subsection*{Iterative Depth First Search}
\begin{lstlisting}
int list[maxn][maxn],g[maxn][maxn],degree[maxn],behide[maxn];
int found, n, curmax, curobj, map[maxn], ans[maxn], s[maxn];

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
    if( d-1>curmax ) { found=1;return; };
    int i,j;
    for(i=1;i<list[d-1][0]-curmax+d;i++) 
        if(!found && d+behide[list[d-1][i]+1]>curmax && 
           (list[d-1][0]==i || d+behide[list[d-1][i+1]]>curmax )) {
            for(j=i+1,list[d][0]=0; j<=list[d-1][0]; j++)
                if( g[list[d-1][j]][list[d-1][i]] )
                    list[d][++list[d][0]]=list[d-1][j];
            if( list[d][0]==0 || d + behide[list[d][1]]>curmax) 
                { s[d] = list[d-1][i];  dfs(d+1); }
        }       
}

void solve() // INPUT : Matrix G
{
    int i,j;  behide[n+1]=0;  behide[n]=1;
    for(i=1; i<=n ;i++) map[i]=i; sortdegree(); 
    for(i=n-1; i>0; i--) {
        curmax = behide[i+1];  found = list[1][0] = 0;
        for(j=i+1; j<=n; j++) if(g[j][i]) list[1][++list[1][0]] = j;
        s[1]=i;  dfs(2);  behide[i] = curmax+found;
        if( found ) for(j=1;j<=behide[i];j++) ans[j]=s[j];
    }
    j = behide[1]; cout<<j<<endl;  std::sort(ans+1, ans+1+j, cmp);
    for(i=1; i<=j; i++) cout<<map[ans[i]]<<" "; cout<<endl;
}
\end{lstlisting}
