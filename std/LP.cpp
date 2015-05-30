Primal Simplex Method for solving Linear Programming problem in Standard Form

maximize 
\[
c_1 x_1 + c_2 x_2 + \cdots + c_n x_n + \mbox{ans}
\]

subject to
\begin{eqnarray*}
a_{1,1} \, x_1 + a_{1,2} \, x_2 + \cdots + a_{1,n} \, x_n & \le & rhs_1 \\
a_{2,1} \, x_1 + a_{2,2} \, x_2 + \cdots + a_{2,n} \, x_n & \le & rhs_2 \\
\vdots \\
a_{m,1} \, x_1 + a_{m,2} \, x_2 + \cdots + a_{m,n} \, x_n & \le & rhs_m
\end{eqnarray*}

\begin{lstlisting}
const double eps = 1e-8;
const double inf = 1e15;

#define OPTIMAL -1
#define UNBOUNDED -2
#define FEASIBLE -3
#define INFEASIBLE -4
#define PIVOT_OK 1

int basic[maxn],row[maxm],col[maxn];
double c0[maxn];

double dcmp(double x)
{
    if( x >  eps ) return 1;
    if( x < -eps ) return -1;
    return 0;
}

int Pivot(int n, int m, double *c,double a[maxn][maxn],
    double *rhs,int &i,int &j)
{
    double min = inf; int k = -1;
    for(j=0; j<=n; j++) if( !basic[j] && dcmp(c[j])>0 )
        if( k<0 || dcmp(c[j]-c[k])>0 ) k=j;
    j=k; if( k < 0 ) return OPTIMAL;
    for(k=-1,i=1; i<=m; i++) if( dcmp(a[i][j])>0 )
        if( dcmp(rhs[i]/a[i][j]-min) < 0 ) { min = rhs[i]/a[i][j]; k=i; }
    i=k; if( k < 0 ) return UNBOUNDED; else return PIVOT_OK;
}

int PhaseII(int n, int m, double *c, double a[maxn][maxn],
    double *rhs, double &ans, int PivotIndex)
{
    int i,j,k,l; double tmp;
    while(k=Pivot(n,m,c,a,rhs,i,j),k==PIVOT_OK || PivotIndex)
    {
        if( PivotIndex ) { j=0; i=PivotIndex; PivotIndex=0; }
        basic[row[i]]=0; col[row[i]]=0; basic[j]=1; col[j]=i; row[i]=j; 
        tmp=a[i][j]; for(k=0;k<=n;k++) a[i][k]/=tmp; rhs[i]/=tmp;
        for(k=1;k<=m;k++) if(k!=i && dcmp(a[k][j]))
        {
            tmp = -a[k][j]; for(l=0;l<=n;l++) a[k][l]+=tmp*a[i][l];
            rhs[k] += tmp*rhs[i];
        }
        tmp=-c[j]; for(l=0;l<=n;l++) c[l]+=a[i][l]*tmp; ans-=tmp*rhs[i];
    }   
    return k;
}

int PhaseI(int n,int m,double *c,double a[maxn][maxn],double *rhs,double &ans)
{
    int i,j,k = -1; double tmp, min = 0, ans0 = 0;
    for(i=1; i<=m; i++) if( dcmp(rhs[i]-min)<0 ) { min=rhs[i]; k=i; }
    if( k<0 ) return FEASIBLE;
    for(i=1; i<=m; i++) a[i][0] = -1;
    for(j=1; j<=n; j++) c0[j]=0;  c0[0] = -1; 
    PhaseII(n, m, c0, a, rhs, ans0, k); 
    if( dcmp(ans0)<0 ) return INFEASIBLE;   
    for(i=1; i<=m; i++) a[i][0] = 0;
    for(j=1; j<=n; j++) if( dcmp(c[j]) &&  basic[j] )
    {
        tmp = c[j]; ans += rhs[col[j]]*tmp;
        for(i=0; i<=n; i++) c[i] -= tmp*a[col[j]][i];       
    }
    return FEASIBLE;
}

int simplex(int n, int m, double *c, double a[maxn][maxn],
    double *rhs, double &ans, double *x) // standard form
{
    int i,j,k;
    for(i=1; i<=m; i++) 
    {
        for(j=n+1; j<=n+m; j++) a[i][j]=0; 
        a[i][n+i] = 1; a[i][0] = 0;
        row[i] = n+i; col[n+i] = i;
    }
    k = PhaseI (n+m, m, c, a, rhs, ans); 
    if( k == INFEASIBLE ) return k; 
    k = PhaseII(n+m, m, c, a, rhs, ans, 0);
    for(j=0;j<=n+m;j++) x[j]=0;
    for(i=1;i<=m;i++) x[row[i]]=rhs[i];     
    return k;
}

int n, m; double c[maxn],ans, a[maxm][maxn], rhs[maxm], x[maxn];

int main()
{
    ifstream cin("lp.in");
    int i,j;    
    while( cin>>n>>m && !cin.fail() )
    {
        for(j=1; j<=n; j++) cin>>c[j]; cin>>ans; c[0]=0;
        for(i=1; i<=m; i++){ for(j=1; j<=n; j++) cin>>a[i][j]; cin>>rhs[i]; }
        switch( simplex(n, m, c, a, rhs, ans, x) )
        {
            case OPTIMAL :
                printf("OPTIMAL\n%10lf\n",ans); 
                for(j=1;j<=n;j++) printf("x[ %2d ] = %10lf\n",j,x[j]); 
                break;
            case UNBOUNDED :
                printf("UNBOUNDED\n");  break;
            case INFEASIBLE :
                printf("INFEASIBLE\n"); break;
        }   printf("\n");
    }
    return 0;
}
\end{lstlisting}
