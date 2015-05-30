\begin{lstlisting}
#define ABS(x) ( (x)>=0 ? (x) : -(x) )

struct TSegNode {
    TSegNode(int x, int y):L(x),R(y),Lch(-1),Rch(-1),count(0),len(0){}
    TSegNode(){TSegNode(-1,-1);}
    int L, R, Lch, Rch, count, len;
};

struct Tevent {
    int L, R, x; bool style;
    friend const bool operator< (Tevent a, Tevent b) 
    { if ( a.x!=b.x ) return a.x<b.x; return ( a.style && !b.style ); } 
};

int n, lx[MAXN], ly[MAXN], ux[MAXN], uy[MAXN], total, nevent, res;
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
void process() {
    int nlist, list[MAXN*2], last, i, now;
    nevent = 0;  nlist = 0; 
    for( i=0; i<n; ++i ) {
        event[nevent].x = lx[i];  event[nevent].L       = ly[i]; 
        event[nevent].R = uy[i];  event[nevent++].style = true;
        event[nevent].x = ux[i];  event[nevent].L       = ly[i]; 
        event[nevent].R = uy[i];  event[nevent++].style = false;        
        list[nlist++]   = ly[i];  list[nlist++]         = uy[i];
    }
    std::sort(event, event+nevent);
    std::sort(list, list+nlist);
    nlist = int(std::unique(list, list+nlist)-list);    
    node[total=0, total++] = TSegNode(0, nlist-1);
    CreateTree( 0 );
    for(i=0; i<total; ++i )
        { node[i].L = list[node[i].L];  node[i].R = list[node[i].R]; }
    last = i = 0;
    while( i<nevent ) {
        now = event[i].x;
        while( i<nevent && event[i].x==now && event[i].style )
            { Update(0, event[i].L, event[i].R, 1); ++i; }
        res += ABS(node[0].len-last); last = node[0].len;
        while( i<nevent && event[i].x==now )
            { Update(0, event[i].L, event[i].R, -1); ++i; }
        res += ABS(node[0].len-last); last = node[0].len;
    }
}

int main() {
    int i;  
    scanf("%d", &n);
    for(i=0; i<n; ++i) scanf("%d %d %d %d",&lx[i],&ly[i],&ux[i],&uy[i]);        
    res=0;  process();
    for(i=0; i<n; ++i){std::swap(lx[i], ly[i]); std::swap(ux[i], uy[i]);}
    process(); printf("%d\n", res); 
    return 0;
}
\end{lstlisting}