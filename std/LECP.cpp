\begin{lstlisting}
#define ABS(x)                  ( (x)>=0 ? (x) : -(x) )
#define CROSS(x1, y1, x2, y2)   ( (x1)*(y2)-(x2)*(y1) )

const double eps = 1e-8;

struct CPoint { int x, y; };

int n; CPoint p[maxn]; double ans;

bool cmp(const CPoint &a, const CPoint &b) {
    int v = CROSS( a.x, a.y, b.x, b.y );
    if ( v>0 ) return true; if ( v<0 ) return false;        
    return ( a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y );
}

CPoint c[maxn]; int nc; double fm[maxn][maxn];

void sweep(int x, int y) {
    int i, j, k, m; double v, best = 0; 
    for(nc=i=0; i<n; ++i ) if( p[i].y<y || p[i].y==y && p[i].x<x )
        { c[nc].x=p[i].x-x;  c[nc++].y=p[i].y-y; }
    if( nc<2 ) return;
    std::sort(c, c + nc, cmp);      
    memset(fm, 0, sizeof(fm));
    for( i=1; i<nc; ++i ) { 
        j=i-1; while(j>=0 && CROSS(c[i].x, c[i].y, c[j].x, c[j].y)==0) --j;
        int nev = 0, ev[maxn];
        while( j>=0 ) { 
            v = CROSS(c[j].x, c[j].y, c[i].x, c[i].y)/2.0;  k=j-1; 
            while( k>=0 && CROSS( c[j].x-c[i].x, c[j].y-c[i].y,
                                  c[k].x-c[i].x, c[k].y-c[i].y ) >0 ) --k;              
            if( k>=0 ) v += fm[j][k];               
            if( v-best>eps ) best = v;              
            if( CROSS(c[i].x, c[i].y, c[i-1].x, c[i-1].y) )
                if( v-fm[i][j]>eps ) fm[i][j]=v;                    
            ev[ nev++ ]=j; j=k;
        }       
        if ( CROSS(c[i].x, c[i].y, c[i-1].x, c[i-1].y) ) 
            for(j=nev-2; j>=0; --j) if ( fm[i][ev[j+1]]-fm[i][ev[j]]>eps )
                fm[i][ev[j]]=fm[i][ev[j+1]];
    }   
    if( best-ans>eps ) ans = best;
}

void main() {
    int t, i; for( scanf("%d", &t); t; --t ) { scanf("%d", &n); 
        for(i=0; i<n; ++i ) scanf("%d %d", &p[i].x, &p[i].y);
        for(ans=i=0; i<n; ++i ) sweep(p[i].x, p[i].y); // main procedure
        printf("%.1lf\n", ans);     
    } 
}
\end{lstlisting}