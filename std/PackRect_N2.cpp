\begin{lstlisting}
int x1[maxn],y1[maxn],x2[maxn],y2[maxn];
int ylist[maxn*2],id[maxn],n,ny;

bool cmp(const int&i,const int&j){ return x1[i]<x1[j]; }

int GetAreaUnion()
{
    int i,j,k,rx,l,ans=0;
    for(ny=0,i=0; i<n; i++) { ylist[ny++]=y1[i]; ylist[ny++]=y2[i]; }
    std::sort(ylist,ylist+ny); ny=std::unique(ylist,ylist+ny)-ylist;
    for(i=0; i<n; i++) id[i]=i; std::sort(id,id+n,cmp);
    for(j=0; j<ny-1; j++){
        rx = -0x3f3f3f; l=0;
        for(k=0;k<n;k++){ i = id[k];
            if( y1[i]<=ylist[j] && y2[i]>=ylist[j+1] && x2[i]>rx ) {
                if( x1[i]>rx ) l+=x2[i]-x1[i]; else l+=x2[i]-rx;
                rx = x2[i];
            }
        }
        ans += l * (ylist[j+1]-ylist[j]);
    }
    return ans;
}
\end{lstlisting}
