\begin{lstlisting}
// upper : maximum possible right point of intervals
int upper, tree[maxinterval+1];

void init()
{ upper=0; memset(tree,0,sizeof(tree)); }

void update( int r,int x ) // sum[1..r] +=x
{ while(r<=upper){ tree[r]+=x; r+=(r&(r^(r-1))); } }

int sum(int r)             // return sum[1..r]
{
    int res = 0;
    while ( r>0 ) { res+=tree[r]; r-=(r&(r^(r-1))); }
    return res;
}
\end{lstlisting}
