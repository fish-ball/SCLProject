\begin{lstlisting}
#define maxn 10000000
#define maxp 1000000

char mk[maxn];
int prime[maxp], pnum;

void GenPrime(int n)
{
    int i,j,k; pnum = 0; memset(mk, 0, n+1); 
    for(i=2,k=4; i<=n; i++,k+=i+i-1) if( !mk[i] )
    {
        prime[pnum++] = i;
        if(k<=n) for(j=i+i; j<=n; j+=i) mk[j] = 1;
    }
}
\end{lstlisting}