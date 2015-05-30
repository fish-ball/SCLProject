\begin{lstlisting}
struct TSegNode {
    TSegNode(int x, int y):L(x),R(y),Lch(-1),Rch(-1),count(0),len(0){}
    TSegNode(){TSegNode(-1,-1);}
    int L, R, Lch, Rch, count, len;
};

struct Tevent {
    int L, R, x;
    bool style;
    friend const bool operator< (Tevent a, Tevent b) { return a.x<b.x; } 
};

int nlist, list[MAXN*4], total, n, nevent;
TSegNode node[MAXN*4]; Tevent event[MAXN*4];

void CreateTree(int r) {
    if ( node[r].R-node[r].L>1 ) {
        int mid = (node[r].L+node[r].R)>>1;
        node[total] = TSegNode(node[r].L, mid);
        node[r].Lch = total;  CreateTree(total++);
        node[total] = TSegNode(mid, node[r].R);
        node[r].Rch = total;  CreateTree(total++);
    }
}

void Update(int r, int L, int R, int v) {
    if ( L>=node[r].R || R<=node[r].L ) return;
    if ( L<=node[r].L && R>=node[r].R ) {
        node[r].count+=v;
        if ( v>0 && v==node[r].count ) node[r].len = node[r].R-node[r].L;
        if ( v<0 && node[r].count==0 ) if( node[r].Lch<0 ) node[r].len = 0;
        else node[r].len = node[node[r].Lch].len + node[node[r].Rch].len;
    } else {
        Update(node[r].Lch, L, R, v); Update(node[r].Rch, L, R, v);
        if ( node[r].count==0 ) node[r].len = 
            node[node[r].Lch].len + node[node[r].Rch].len;
    }
}
\end{lstlisting}
\newpage
\begin{lstlisting}
int main() {
    int i, j, res, last;
    scanf("%d", &n);
    nevent=0; nlist=0;
    for ( i=0; i<n; ++i ) {
        int lx, ly, ux, uy;
        scanf("%d %d %d %d", &lx, &ly, &ux, &uy);
        if ( lx<ux && ly<uy ) {
            event[nevent].x = lx;  event[nevent].L = ly;
            event[nevent].R = uy;  event[nevent++].style = true;
            event[nevent].x = ux;  event[nevent].L = ly;
            event[nevent].R = uy;  event[nevent++].style = false;
        }
        list[nlist++] = ly; list[nlist++] = uy;
    }
    std::sort(event, event+nevent); 
    std::sort(list, list+nlist); 
    nlist = std::unique(list, list+nlist)-list; 
    node[total=0, total++] = TSegNode(0, nlist-1);
    CreateTree( 0 );
    for( i=0; i<total; ++i ) 
        { node[i].L = list[node[i].L]; node[i].R = list[node[i].R]; }
    res = i = 0;
    while ( i<nevent ) {
        for(last=event[i].x; event[i].x==last; ++i)
            Update(0, event[i].L, event[i].R, event[i].style ? 1 : -1);
        if ( i < nevent ) res += (event[i].x - last) * node[0].len;
    }
    printf("%d\n", res);    
    return 0;
}
\end{lstlisting}