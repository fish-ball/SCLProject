\begin{lstlisting}
struct CJob{ int value,deadline; } job[maxn];

int n, ans, pnt[maxdeadline+1];

int find(int x)
{ 
    int y, p=x;
    while( p!=pnt[p] ) p=pnt[p];
    while( x!=pnt[x] ) { y=pnt[x]; pnt[x]=p; x=y; };
    return p;
}

bool cmp(const CJob &a, const CJob &b){ return a.value > b.value; }

void solve()
{
    int i,j,k; 
    ans=k=0;  std::sort(job, job+n, cmp);
    for(i=1;i<=n;i++) if( job[i].deadline>=k ) k=job[i].deadline;
    for(i=0;i<=k;i++) pnt[i]=i;
    for(i=0;i<n;i++) {
        j=find(job[i].deadline);
        if( j ) {
            ans+=job[i].value;  // Select Job i
            pnt[j]=j-1;
        }       
    }
    cout<<ans<<endl;
}
\end{lstlisting}