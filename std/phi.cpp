$ \phi(n)=n\prod_{p\mid n} (1-\frac{1}{p}) $, where $p$ is a prime. \\
$\phi(846720)=193536$
\begin{lstlisting}
int Phi(int n) // O( Sqrt(N) )
{
    int i,j,ret=n;
    for(i=2,j=4; j<=n; i++,j+=i+i-1) if (!(n%i))
    {
        ret = ret / i * (i-1);
        while( !(n%i) ) n/=i;
    }
    if( n>1 ) ret = ret / n * (n-1);
    return ret;
}

#define maxn 10000000
#define maxp 1000000

int phi[maxn], prime[maxp], pnum;

void GenPhi(int n)  // O( N loglog N )
{
    int i,j,k; pnum = 0; 
    memset(phi, 0, (n+1)*sizeof(phi[0])); 
    phi[1] = 1;
    for(i=2; i<=n; i++) if( !phi[i] )
    {
        prime[pnum++] = i;
        for(j=i; j<=n; j+=i) 
        {
            if(!phi[j]) phi[j]=j;
            phi[j] = phi[j]/i*(i-1);
        }
    }
}
\end{lstlisting}
