Parity of the Stirling number of the second kind
\begin{lstlisting}
#define int long long

int calc(int n,int k)
{
	if( k==0 ) if( n==0 ) return 1; else return 0;
		  else if( k==1 ) return 1; else 
	{
		int p = 0, p2 = 1;
		while( k>p2*2 || n-k/2>p2 ) { p++; p2<<=1; }
		if( k>p2) return calc(n-p2,k-p2);
		if( n-k>=p2/2 ) return calc(n-p2/2,k);
		return 0;
	}
}
\end{lstlisting}