\subsection*{$O(N^2)$}
\begin{lstlisting}
int n,wx,wy,x[maxn],y[maxn],id[maxn];
int xx[maxn],yy[maxn],ans;

bool cmp(const int&i,const int&j)
{
    return x[i]<x[j];
}

void calc(int i,int px,int py)
{
    int ret,j,low=0,high=wy;
    for(;i<n;i++) if( x[i]>px )
    {
        j=(high-low)*(x[i]-px); if(j>ans) ans=j;
        if( y[i]<py && y[i]>=low ) low = y[i];
        if( y[i]>=py && y[i]<=high ) high = y[i];       
    }   
}

int main()
{
    int i,j,k;
    cin>>wx>>wy>>n; for(i=0;i<n;i++) cin>>x[i]>>y[i];
    x[n]=y[n]=0; n++; x[n]=wx; y[n]=wy; n++;
    for(i=0;i<n;i++) id[i]=i; std::sort(id,id+n,cmp);
    for(i=0;i<n;i++) { xx[i]=x[id[i]]; yy[i]=y[id[i]]; }
    for(i=0;i<n;i++) { x[i]=xx[i]; y[i]=yy[i];}
    std::sort(yy,yy+n); k=std::unique(yy,yy+n)-yy;
    ans=0;
    for(i=0;i<n;i++) calc(i,x[i],y[i]);
    for(j=0;j<k;j++) calc(0,0,yy[j]);
    cout<<ans<<endl;
    return 0;
}
\end{lstlisting}

\subsection*{$O(D^2)$}
\begin{lstlisting}
int x[maxn],y[maxn],xlist[maxn],ylist[maxn],nx,ny,ans,n,wx,wy;
char g[maxd][maxd]; int u[maxd],d[maxd],l[maxd];

int main()
{
    int i,j,px,py,up,down,tmp; ans=0;
    cin>>wx>>wy>>n; for(i=0;i<n;i++) cin>>x[i]>>y[i];
    nx=ny=n;  for(i=0;i<n;i++) { xlist[i]=x[i]; ylist[i]=y[i]; }
    xlist[nx++]=ylist[ny++]=0; xlist[nx++]=wx; ylist[ny++]=wy;
    std::sort(xlist,xlist+nx); nx=std::unique(xlist,xlist+nx)-xlist;
    std::sort(ylist,ylist+ny); ny=std::unique(ylist,ylist+ny)-ylist;
    
    for(i=0; i<nx; i++) memset(g, 0, n);
    
    for(i=0; i<n; i++)
    {
        px = std::lower_bound(xlist,xlist+nx,x[i]) - xlist;
        py = std::lower_bound(ylist,ylist+ny,y[i]) - ylist;
        g[px][py]=1;
    }
\end{lstlisting}
\newpage
\begin{lstlisting}    
    for(j=0; j<ny-1; j++)
    {
        tmp = wx * ( ylist[j+1] - ylist[j] );
        if( tmp > ans ) ans = tmp;
    }
    for(i=1; i<nx; i++)
    {
        down=0; up=ny-1;
        for(j=0; j<ny; j++) if( i==1 || *(*(g+i-1)+j) ) 
            { l[j]=i-1; d[j]=0; down=j; } else
                if( down > d[j] ) d[j] = down;
        for(j=ny-1; j>=0; j--) 
        {
            if( i==1 || *(*(g+i-1)+j) ) { u[j]=ny-1; up=j; } else
                    if( up < u[j] ) u[j] = up;
            tmp = ( xlist[i] - xlist[l[j]] ) * ( ylist[u[j]]-ylist[d[j]] );
            if(tmp>ans) ans=tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}
\end{lstlisting}

\subsection*{$O(N^2)$}
\begin{lstlisting}
int n,wx,wy,id[maxn],x[maxn],y[maxn],ans,xx[maxn],yy[maxn];

bool xcmp(const int&i,const int &j) { return x[i]<x[j]; }
bool ycmp(const int&i,const int &j) { return y[i]<y[j]; }

int main()
{
    int i,j,k,l,tmp,low,high,last;
    cin>>wx>>wy>>n; for(i=0;i<n;i++) cin>>x[i]>>y[i];
    x[n]=y[n]=0; n++; x[n]=wx; y[n]=wy; n++;
    for(i=0;i<n;i++) id[i]=i;   
    std::sort(id,id+n,xcmp);
    for(i=0;i<n;i++) { xx[i]=x[id[i]]; yy[i]=y[id[i]]; }    
    for(i=0;i<n;i++) { x[i]=xx[i]; y[i]=yy[i]; }
    std::sort(id,id+n,ycmp);
    for(i=0;i<n;i++) 
    {
        l=0; last=0;
        for(j=0;j<n;j++) if( x[id[j]]<x[i] && y[id[j]]>last) 
        {
            if( y[id[j]]-last > l ) l=y[id[j]]-last;
            last=y[id[j]];
        }
        if( wy-last>l ) l=wy-last; 
        if( l*x[i] > ans ) ans =l*x[i];
        low=0; high=wy; for(j=i+1;j<n;j++)
        {
            tmp = (high-low)*(x[j]-x[i]) ;
            if( tmp> ans ) ans=tmp;
            if( y[j]>=y[i] && y[j]<high ) high = y[j];
            if( y[j]<=y[i] && y[j]>low  ) low  = y[j];
        }
    }
    cout<<ans<<endl;    
    return 0;
}
\end{lstlisting}
