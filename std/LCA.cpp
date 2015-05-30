\begin{lstlisting}
int n,h,root;  // maxh-1 = h = floor( log ( 2, n-1 ) )
int pnt[maxn][maxh],son[maxn],next[maxn],depth[maxn];
int stack[maxn], mylog[maxn];

int GetParent(int x,int len)
{
    while( len>0 ) {
        x = pnt[x][ mylog[len] ]; 
        len -= ( 1<<mylog[len] );
    }
    return x;
}

int LCA(int x,int y)  // O( log N )
{
    int nx,ny,px,py,low,mid,high;
    low=0; high = depth[x]<depth[y] ? depth[x] : depth[y];
    px = GetParent(x, depth[x]-high) ;
    py = GetParent(y, depth[y]-high) ;
    if( px == py ) return px;   
    while(high-low>1)
    {
        mid = mylog[high-low-1];
        nx = pnt[px][mid];
        ny = pnt[py][mid];
        mid = high - (1<<mid);
        if( nx == ny ) low = mid; else { high = mid; px = nx; py = ny; }
    }
    return pnt[px][mylog[high-low]];
}

int LCA_2(int x,int y) // O( log^2 N )
{
    int low,mid,high;
    low = 0;  mid = high = depth[x]<depth[y] ? depth[x] : depth[y];
    if( GetParent(x, depth[x]-mid) != GetParent(y, depth[y]-mid) )
    while(low+1<high)
    {
        mid = (low + high) / 2;
        if( GetParent(x, depth[x]-mid) != GetParent(y, depth[y]-mid) )
            high = mid; else low = mid;
    } else low = high;
    return GetParent(x, depth[x]-low) ;
}

void dfs(int d,int cur)
{
    int i,j;  stack[d] = cur;  depth[cur] = d;
    for(j=1,i=2; i<=d; j++,i*=2 ) pnt[cur][j]=stack[d-i];
    for(j=son[cur]; j; j=next[j]) dfs( d+1, j );        
}

void main()
{
    int i,j,k,l;
    for(i=0,j=1; j<maxn; i++)
    {
        k = j*2; if( k>maxn ) k = maxn;
        while( j<k ) mylog[j++] = i;
    }
    cin>>n; 
    for(i=1; i<=n; i++) {
        son[i] = next[i] = 0;
        for(j=0; j<=h; j++) pnt[i][j] = 0;
    }
    for(i=1; i<n; i++) { 
        cin >> j >> k;  pnt[j][0] = k;
        next[j]=son[k]; son[k]=j;
    }
    for(i=1; i<=n; i++) if( pnt[i][0]==0 ) { root=i; break; };
    
    dfs( 0, root );   // Preprocess Parent Array
    
    for(cin>>k; k; k--) { cin >> i >> j; cout << LCA(i,j) <<endl; }
}
\end{lstlisting}
