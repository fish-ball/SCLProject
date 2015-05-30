\begin{lstlisting}
int cx[maxn],cy[maxn],sx[maxn],sy[maxn],lx[maxn],ly[maxn];
int nx,ny,match,g[maxn][maxn];

int path(int u)
{
    sx[u]=1; for(int v=1;v<=ny;v++) if(g[u][v]==lx[u]+ly[v] && !sy[v]) {
    sy[v]=1; if(!cy[v] || path(cy[v])) { cx[u]=v; cy[v]=u; return 1;}
    } return 0; 
}

void KuhnMunkres()
{
    int i,j,u,min;
    memset(lx,0,sizeof(lx));   memset(ly,0,sizeof(ly));
    memset(cx,0,sizeof(cx));   memset(cy,0,sizeof(cy));
    for(i=1;i<=nx;i++) for(j=1;j<=ny;j++) if(lx[i]<g[i][j]) lx[i]=g[i][j];
    for(match=0, u=1; u<=nx; u++) if(!cx[u]) {
        memset(sx,0,sizeof(sx));  memset(sy,0,sizeof(sy));
        while(!path(u)){
            min=0x3fffffff;
            for(i=1;i<=nx;i++) if(sx[i]) for(j=1;j<=ny;j++) if(!sy[j])
                if( lx[i]+ly[j]-g[i][j]<min ) min=lx[i]+ly[j]-g[i][j];
            for(i=1;i<=nx;i++) if(sx[i]) { lx[i]-=min; sx[i]=0; }
            for(j=1;j<=ny;j++) if(sy[j]) { ly[j]+=min; sy[j]=0; }
        };
    }
}
\end{lstlisting}