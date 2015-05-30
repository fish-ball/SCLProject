$f(n,d)$ is the number of trees whose depth is less or equal than $d$.
\begin{lstlisting}
int f[maxn][maxd],h[maxn][maxn],n,d;

int main()
{
    ifstream cin("input.txt");
    int i,j,k;
    for(d=1; d<maxd; d++) {
        memset(h,0,sizeof(h));
        for(i=0; i<=d; i++) h[i][0]=1;
        for(i=1; i<maxn; i++) for(j=i-d; j<=i; j++)
            if(j>=0) h[i][j]=h[i-1][j]+h[i][j-1];
        for(i=1;i<maxn;i++) f[i][d]=h[i][i];
    }
    while(cin>>n>>d && n) cout<< f[n/2][d]- f[n/2][d-1]<<endl;  
    return 0;
}
\end{lstlisting}
