\begin{lstlisting}
void sort(int b,int e)
{
    if(e-b<=0) return;
    int mid=(b+e)/2,p1=b,p2=mid+1,i=b;  
    sort(b,mid); sort(mid+1,e); 
    while( p1<=mid || p2<=e )
        if( p2>e|| (p1<=mid && a[p1]<=a[p2]) ) 
            t[i++]=a[p1++]; else t[i++]=a[p2++];
    for(i=b;i<=e;i++)a[i]=t[i];
}
\end{lstlisting}
