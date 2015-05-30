\subsection*{O($N\log{N}$) Preprocess, O($1$) Query}
\begin{lstlisting}
int n,L,q, a[maxn],h[maxn][maxL]; // maxL = sqrt{N} + 3

void PreProcess()
{
    int i,j,l;
    for(i=0;i<n;i++) h[i][0]=a[i];
    for(j=1,l=1; l*2<=n; j++,l*=2) for(i=0; i<=n-l*2; i++)
        h[i][j] = (h[i][j-1]>h[i+l][j-1]) ? h[i][j-1] : h[i+l][j-1];
}

int Query(int be,int ed) // return max{a[op..ed]}
{
    int j=0,l=1; while( 2*l<=ed-be+1 ) { j++; l*=2; }
    return (h[be][j]>h[ed+1-l][j]) ? h[be][j] : h[ed+1-l][j];
}
\end{lstlisting}

\subsection*{O($N$) Preprocess, O($\sqrt{N}$) Query}
\begin{lstlisting}
int a[maxn],b[maxL],n,L,q;

void PreProcess()
{
    int i,j,up,k; L = (int)sqrt(n);
    for(i=k=0;  i<n; k++ ) { 
        up=i+L;  if( up>n ) up = n;
        for(j=i+1; j<up; j++) if( a[j]>a[i] ) i=j;
        b[k]=i;  i=up;
    }
}

int Query(int be,int ed) // return max{a[op..ed]}
{
    int i,up,u,v,k;
    u = be / L;  v = ed / L;  k = be;
    if( u<v ) {
        k=be;  up=(u+1)*L; 
        for(i=u+1; i<v ; i++) if( a[b[i]]>a[k] ) k = b[i];
        for(i=be; i<up; i++)     if( a[i]>a[k] ) k = i;
        for(i=v*L; i<=ed; i++)   if( a[i]>a[k] ) k = i;
    } else for(i=be; i<=ed; i++) if( a[i]>a[k] ) k = i;
    return k;
}
\end{lstlisting}