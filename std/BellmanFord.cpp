\begin{lstlisting}
const int maxn = maxm = 1000005
const int inf = 1000000000

int nbs[maxn],next[maxm],value[maxn],open[maxn],open1[maxn];
int ev[maxm],ew[maxm],mk[maxn], n,m,num,cur,tail;

void BellmanFord(int src)
{
    int i,j,k,l,t,u,v,p=0;
    for(i=1;i<=n;i++) { value[i]=inf; mk[i]=0; }
    value[src]=tail=0;  open[0]=src;
    while(++p, tail>=0){
        for(i=0;i<=tail;i++) open1[i]=open[i];
        for(cur=0,t=tail,tail=-1; cur<=t; cur++)
            for(u=open1[cur],i=nbs[u]; i; i=next[i]) {
                v=ev[i]; if( value[u]+ew[i]<value[v]){
                    value[v]=value[u]+ew[i];
                    if(mk[v]!=p) { open[++tail]=v; mk[v]=p; }
                }               
            }           
    }
}
\end{lstlisting}
