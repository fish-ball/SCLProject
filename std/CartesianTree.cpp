\begin{lstlisting}
int lson[maxn],rson[maxn],pnt[maxn],root,n;

void BuildCartesianTree(int a[],int n)
{
    int i,j;
    for(i=0; i<n; j=i++) { 
        pnt[i]=i-1; lson[i]=rson[i]=-1; j=i;
        while( pnt[j]>=0 && a[i]>a[pnt[j]] ) j = pnt[j];
        if( j!=i ) { pnt[i]=pnt[j]; lson[i]=j; pnt[j]=i; };
        if(pnt[i]>=0) rson[pnt[i]]=i; 
    }
    for(i=0;i<n;i++) if(pnt[i]<0) root=i;
}
\end{lstlisting}
