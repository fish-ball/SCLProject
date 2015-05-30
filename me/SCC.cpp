
int g[maxn][maxn],n, mk[maxn], list[maxn],num;

void back(int v)
{
    mk[v]=1; 
    cout<<v<<" ";
    for(int u=1; u<=n; u++) if(!mk[u] && g[u][v]) back(u);
}

void dfs(int u)
{
    mk[u]=1;
    for(int v=1; v<=n; v++) if(!mk[v] && g[u][v]) dfs(v);
    list[num--]=u;
}

int main()
{
    int i,j,k,l;
    cin>>n; 
    for(i=1;i<=n;i++) 
      for(j=1;j<=n;j++) cin>>g[i][j];
    memset(mk,0,sizeof(mk)); 
    num=n;
    for(i=1;i<=n;i++) 
      if(!mk[i]) dfs(i);
    memset(mk,0,sizeof(mk));
    for(i=1;i<=n;i++) 
      if(!mk[list[i]]) 
	{ 
	  back(list[i]); 
	  cout<<endl; 
	}
    return 0;
}
