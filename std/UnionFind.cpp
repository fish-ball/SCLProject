\begin{lstlisting}
int rank[maxn],pnt[maxn];

void makeset(int x)
{ rank[pnt[x]=x]=0; }

int find(int x) 
{
    int px=x,i;
    while(px!=pnt[px]) px=pnt[px];
    while(x!=px){ i=pnt[x]; pnt[x]=px; x=i; };
    return px;
}

void merge(int x,int y) // or just pnt[find(x)]=find(y)
{
    if( rank[x=find(x)]>rank[y=find(y)]) pnt[y]=x;
        else { pnt[x]=y; rank[y]+=(rank[x]==rank[y]); };
}
\end{lstlisting}
