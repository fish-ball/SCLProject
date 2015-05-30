\begin{lstlisting}
int n,a[maxn],s[maxn][maxn],h[maxn][maxn],kk[maxn][maxn];

int solve()
{
    int i,j,k,l;  memset(h,0,sizeof(h));
    for(i=1;i<=n;i++) { s[i][i]=a[i]; h[i][i]=0; kk[i][i]=i;
        for(j=i+1;j<=n;j++) s[i][j]=s[i][j-1]+a[j];
    }
    for(l=1; l<n; l++) { 
        for(i=1;i<n;i++) { j=i+l; h[i][j]=0x0fffffff;
            for(k=kk[i][j-1]; k<=kk[i+1][j]; k++)
                if( h[i][k-1]+h[k+1][j]-a[k]+s[i][j] < h[i][j]) {
                    h[i][j] = h[i][k-1]+h[k+1][j]+s[i][j]-a[k];
                    kk[i][j] = k;
                }
        }
    }
    return h[1][n];
}
\end{lstlisting}
