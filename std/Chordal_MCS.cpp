\begin{lstlisting}
int n,m,mk[maxn],degree[maxn],PEO[maxn],g[maxn][maxn];

int Chordal()
{
    memset(mk,0,sizeof(mk)); memset(degree,0,sizeof(degree));
    for(int j,k,u,v,i=0;i<n;i++) {
        j=-1;   u=-1;
        for(k=0;k<n;k++) if(!mk[k] && (j<0 || degree[k]>degree[j])) j=k;
        mk[j]=1; PEO[i]=j;              
        for(k=i-1;k>=0;k--) if( g[j][PEO[k]] ) 
            if( u<0 ) u=PEO[k]; else if( !g[u][PEO[k]]) return 0;
        for(k=0;k<n;k++) if(!mk[k] && g[j][k]) degree[k]++;             
    }   
    return 1;
}
\end{lstlisting}
