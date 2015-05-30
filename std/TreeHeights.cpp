\begin{lstlisting}
#define maxn 5003*4

int n,num,nbs[maxn],next[maxn*2],h[maxn];
int out1[maxn],out2[maxn],son1[maxn],in[maxn],value[maxn];
int son[maxn],pnt[maxn],bro[maxn],weight[maxn],id[maxn];

void solve()
{
    int i,j,k(1),l;
    id[1]=1; weight[1]=in[1]=0;
    for(i=1;i<=k;i++) for(j=son[id[i]];j;j=bro[j]) id[++k]=j;
    for(i=2;i<=n;i++) weight[i]=1;  
    for(k=n;k>0;k--){ i=id[k];
        for(j=son[i];j;j=bro[j]) 
            if(out1[j]+weight[j]>=out1[i])
            { out2[i]=out1[i]; out1[i]=out1[j]+weight[j]; son1[i]=j; }
            else if(out1[j]+weight[j]>out2[i]) out2[i]=out1[j]+weight[j];
    }
    for(k=2;k<=n;k++){ i=id[k]; in[i]=0;
        if(in[pnt[i]]>in[i]) in[i]=in[pnt[i]];
        if(i==son1[pnt[i]])  l=out2[pnt[i]]; else l=out1[pnt[i]];
        if(l>in[i]) in[i]=l; in[i]+=weight[i];
    }
}

void dfs(int node)
{
    for(int j,i=nbs[node];i;i=next[i]){
        j=value[i]; if(j==pnt[node]) continue;
        pnt[j]=node; bro[j]=son[node]; son[node]=j; dfs(j);
    }
}

void out()
{
    int maxh=-1, minh=n+1,i;
    for(i=1;i<=n;i++) {
        if(in[i]<out1[i]) h[i]=out1[i]; else h[i]=in[i];
        if(h[i]>maxh) maxh=h[i];  if(h[i]<minh) minh=h[i];          
    }   
    cout<<"Best Roots  :";
    for(i=1;i<=n;i++) if(h[i]==minh) cout<<" "<<i;
    cout<<endl <<"Worst Roots :";
    for(i=1;i<=n;i++) if(h[i]==maxh) cout<<" "<<i;
    cout<<endl;
}

int main()
{
    int i,j,k,l;
    while(cin>>n){
        for(i=1;i<=n;i++)
            out1[i]=out2[i]=son1[i]=son[i]=bro[i]=pnt[i]=next[i]=nbs[i]=0;
        for(num=1,i=1;i<=n;i++){ cin>>l; for(k=0;k<l;k++)
            { cin>>j; value[num]=j; next[num]=nbs[i]; nbs[i]=num++;} }
        dfs(1); solve(); out();     
    }
    return 0;
}
\end{lstlisting}
