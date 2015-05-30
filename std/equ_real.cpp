\begin{lstlisting}
const double eps=1e-8;
int m,nn; double a[maxn][maxn];

int dcmp(double x){ if(x>eps) return 1; if(x<-eps) return -1; return 0;}

int reduce() // r is rank
{
    int i,j,k,r;  double tmp;
    for(i=r=0; i<nn; i++){
        for(j=r; j<m && !dcmp(a[j][i]); j++);  if(j>=m) continue;
        if(j>r) for(k=0;k<=nn;k++) std::swap(a[r][k],a[j][k]);
        for(j=0;j<m;j++) if(j!=r && dcmp(a[j][i])){
            tmp=a[j][i]/a[r][i];
            for(k=0;k<=nn;k++) a[j][k]-=tmp*a[r][k];
        } ++r;
    }
    for(i=0;i<m;i++) if(dcmp(a[i][nn])){
        for(j=0;j<nn && !dcmp(a[i][j]);j++);
        if(j==nn) return 0; // else x[j]=a[i][nn]/a[i][j];
    }   return 1;
}
\end{lstlisting}
