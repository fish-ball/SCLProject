Find the roots of $f_a(x)=\sum_{i=0}^{n} a_i x^i$ using \emph{Newton Iterations}, $f_b(x)=f_a(x) \frac{d}{dx}$
\begin{lstlisting}
const double eps=1e-5;
#define genx (rand()%1000)/100.0

int dcmp(double x)
{ if(x>eps) return 1; else if(x<-eps) return -1; else return 0;}

double f(double a[],int n,double x)
{
    double ret=0,xx=1;
    for(int i=0;i<=n;i++){ ret+=a[i]*xx; xx*=x; }
    return ret;
}

double newton(double a[],double b[],int n)
{
    double dy,y,x=genx,lastx=x-1;
    while(y=f(a,n,x), dcmp(lastx-x)){
        lastx=x; dy=f(b,n-1,x);
        if(!dcmp(dy)) x=genx; else x=x-y/dy;
    }
    return x;
}

void solve(double a[],double x[],int n)
{
    int i,j; double b[maxn];
    for(j=n;j>0;j--){
        for(i=0;i<j;i++) b[i]=a[i+1]*(i+1);
        x[j-1]=newton(a,b,j);
        for(b[j]=0, i=j-1; i>=0; i--) b[i]=a[i+1]+b[i+1]*x[j-1];
        for(i=0;i<j;i++) a[i]=b[i];
    }   
}
\end{lstlisting}
