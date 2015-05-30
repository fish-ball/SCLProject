\begin{lstlisting}
#define sqr(z) ((z)*(z))
struct point { double x,y; } pt[maxn]; // [1..n]
int n,o[maxn],on;

int dcmp(double a,double b) {
    if (a - b < 1e-10 && b - a < 1e-10) return 0;
    if (a > b) return 1; return -1;
}

bool cmp(const point& a,const point& b)
{ return dcmp(a.x,b.x) < 0; }

bool cmp2(const int& a,const int& b)
{ return dcmp(pt[a].y,pt[b].y) < 0; }

double dis(point a,point b)
{ return sqrt( sqr(a.x - b.x) + sqr(a.y - b.y) ); }

double min(double a,double b) { return a < b ? a : b; }

double search(int s,int t) {
    int mid = (s + t) / 2,i,j; double ret(1e300);
    if (s >= t) return ret;
    for(i=mid; i>=s && !dcmp(pt[i].x,pt[mid].x); i--); ret=search(s,i);
    for(i=mid; i<=t && !dcmp(pt[i].x,pt[mid].x); i++);
    ret=min(ret,search(i,t));  on=0;
    for(i=mid; i>=s && dcmp(pt[mid].x-pt[i].x,ret)<=0; i--) o[++on]=i;
    for(i=mid+1; i<=t && dcmp(pt[i].x-pt[mid].x,ret)<= 0; i++) o[++on]=i;
    std::sort(o+1,o+on+1,cmp2);
    for(i=1; i<=on; i++) for(j=1; j<=10; j++) if(i+j<=on)
        ret = min(ret,dis(pt[o[i]],pt[o[i+j]]));
    return ret;
}

double solve() { std::sort(pt+1,pt+1+n,cmp); return search(1,n); }
\end{lstlisting}