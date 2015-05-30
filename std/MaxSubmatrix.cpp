\begin{lstlisting}
#define forbidden 1

int wx,wy,g[maxn][maxn],h[maxn],r[maxn],l[maxn];

int solve()
{
    int i,j,k,ans,left,right;   
    ans=0; memset(h,0,sizeof(h)); 
    for(i=0;i<wx;i++) {
        for(j=0;j<wy;j++) if(g[i][j]!=forbidden) h[j]++; else h[j]=0;
        for(j=0;j<wy;j++) if(h[j]) {
            if(j==0 || h[j-1]==0) left=j;                       
            if(i==0 || g[i-1][j]==forbidden) l[j]=left;
            if(left>l[j]) l[j]=left;
        }
        for(j=wy-1;j>=0;j--) if(h[j]) {
            if(j==wy-1 || h[j+1]==0 ) right=j;
            if(i==0 || g[i-1][j]==forbidden) r[j]=right;
            if(right<r[j]) r[j]=right;
        }               
        for(j=0;j<wy;j++)
            if((r[j]-l[j]+1)*h[j] > ans) ans = (r[j]-l[j]+1)*h[j];
    }   
    return ans;
}
\end{lstlisting}
