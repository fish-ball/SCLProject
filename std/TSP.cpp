\begin{lstlisting}
int n,x[maxn],y[maxn],id[maxn];
double g[maxn][maxn];

double dis(int x1,int y1,int x2,int y2)
{ return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }

double solve()
{
    int i,j,k,l,loop;
    double cur,ans=1e30;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g[i][j]=dis(x[i],y[i],x[j],y[j]);
            
    for(k=0;k<n;k++)
    {
        for(l=0;l<50;l++)
        {
            for(i=0;i<n;i++) id[i]=i;
            std::swap(id[0],id[k]);
            std::random_shuffle(id+1,id+n);
            
            loop=1;
            while(loop){
                loop=0;
                for(i=1;i<n;i++) for(j=i+1;j<n-1;j++)
                    if( g[id[i-1]][id[i]] + g[id[j]][id[j+1]]
                      > g[id[i-1]][id[j]] + g[id[i]][id[j+1]] + 1e-8 )
                    {
                        loop=1;
                        std::reverse(id+i,id+j+1);
                    }
            };
            
            for(cur=0,i=0; i<n-1; i++)
                cur+=g[id[i]][id[i+1]];
                
            if(cur<ans) ans=cur;
        }
    }
    return ans;
}
\end{lstlisting}
