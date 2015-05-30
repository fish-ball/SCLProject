\begin{lstlisting}
const int inf=0x3fffffff;

int c[maxn][maxn],f[maxn][maxn],w[maxn][maxn],pnt[maxn];
int value[maxn],d[maxn],mk[maxn],open[maxn],oldque[maxn];

void mincost(int n,int s,int t,int &flow,int &cost)
{
    int cur,tail,tl,i,j,u,v;
    memset(f,0,sizeof(f)); flow=0; cost=0;
    do{ memset(d,0,sizeof(d));
        for(i=1;i<=n;i++) value[i]=inf; 
        open[0]=s; d[s]=0x3fffffff; tail=value[s]=0;
        while(tail>=0){
            memset(mk,0,sizeof(mk)); 
            memcpy(oldque,open,sizeof(open));
            for(tl=tail,pnt[s]=cur=0,tail=-1; cur<=tl; cur++)
            for(u=oldque[cur],v=1;v<=n;v++)
                if( f[u][v]<c[u][v] && value[u]<inf 
                    && value[u]+w[u][v]<value[v] ){
                    if(!mk[v]){ mk[v]=1; open[++tail]=v;};
                    pnt[v]=u; value[v]=value[u]+w[u][v];
                    if(d[u]<c[u][v]-f[u][v]) d[v]=d[u];
                        else d[v]=c[u][v]-f[u][v];
                }
        }
        if(value[t]==inf) return;
        flow+=d[t]; cost+=d[t]*value[t];
        for(u=t;u!=s;){
            v=u; u=pnt[v]; f[u][v]+=d[t]; f[v][u]=-f[u][v];
            if( f[u][v]<0 ) w[u][v]=-w[v][u]; else
            if( f[v][u]<0 ) w[v][u]=-w[u][v];
        }
    } while(d[t]>0);
}
\end{lstlisting}
