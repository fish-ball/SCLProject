\begin{lstlisting}
int n,g[maxn][maxn],mk[maxn],d[maxn],low[maxn],len,que[maxn];
int color,ti,cutvertexnum,cutvertexlist[maxn],blocknum;

void dvsvisit(int u,int p)
{
    int v,s=0,bCutvertex=0; low[u]=d[u]=++ti; mk[u]=-color; que[++len]=u;
    for(v=1; v<=n; v++) if(g[u][v] && v!=p)
        if(mk[v]==0){ dvsvisit(v,u); s++;
            if(low[v]<low[u]) low[u]=low[v];
            if(low[v]>=d[u]){
                while(que[len]!=v) cout<<que[len--]<<" ";
                cout<<que[len--]<<" "<<u<<endl; 
                bCutvertex=1; blocknum++;
            }
        } else if(d[v]<low[u]) low[u]=d[v];
    if((p && bCutvertex) || (!p && s>1)) cutvertexlist[cutvertexnum++]=u;
    mk[u]=color;
}

void dfs()
{
    int i,j,k; memset(mk,0,sizeof(mk));
    color=ti=cutvertexnum=blocknum=0;
    for(i=1; i<=n; i++) if(!mk[i]){
        ++color; len=0; dvsvisit(i,0);
        if(len>1 || d[i]==ti){
            while(len>1) cout<<que[len--]<<" ";
            cout<<i<<endl; blocknum++;
        }
    }
    cout<<"Block Number : "<<blocknum<<endl;
    cout<<"Cutvertex Number: "<<cutvertexnum<<endl;
    for(i=0;i<cutvertexnum;i++) cout<<cutvertexlist[i]<<" "; 
    cout<<endl<<endl;
}
\end{lstlisting}
