\begin{lstlisting}
#define maxn 3010

int n,pnt[maxn],rank[maxn];

int find(int x)
{
    if(x!=pnt[x]) pnt[x]=find(pnt[x]);
    return pnt[x];
}

int main() {
    int i,j,ans(0),x;
    cin >> n;
    memset(pnt,0,sizeof(pnt));
    for(i=1; i<=n; i++) for(j=1; j<=n; j++){
        cin>>x;
        if(!x){
            if(pnt[j])pnt[find(j)]=j;
            if(pnt[j-1])pnt[j-1]=j;
            pnt[j]=j;
        } else { if(pnt[j]==j) ans++; pnt[j] = 0; }
    }
    for(i=1; i<=n; i++) if(pnt[i]==i) ans++;
    cout<<ans<<endl;
    return 0;
}
\end{lstlisting}
