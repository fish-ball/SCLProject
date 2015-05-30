Note: UnionFind.h contains a Union-Find Set (Section \ref{unionfind_set} on Page \pageref{unionfind_set})
\begin{lstlisting}
#include<unionfind.h>

int Gather(int x,int y)
{
    if(!x && !y) return 0;
    if(!x) return find(y);
    if(!y) return find(x);
    Merge(x,y);
    return find(x);
}

void Join(int x,int y)
{
    int a=Gather(x,y); // x,y nerver be zero
    int b=Gather(vs[x],vs[y]);
    vs[a]=b; vs[b]=a;
}

void Disjoin(int x,int y)
{
    int a=Gather(x,vs[y]);
    int b=Gather(y,vs[x]);
    vs[a]=b; vs[b]=a;
}
\end{lstlisting}