Note: \emph{fraction.h} contains a \emph{Fraction Class} (Section \ref{fraction_class} on Page \pageref{fraction_class})
\begin{lstlisting}
#include<fraction.h>

int m,nn; Fraction a[maxn][maxn];
int dcmp(Fraction x){return x.a;}

int reduce()
{
    int i,j,k,r;  double tmp;
    for(i=r=0; i<nn; i++){
        for(j=r; j<m && !dcmp(a[j][i]); j++);  if(j>=m) continue;
        if(j>r) for(k=0;k<=nn;k++) std::swap(a[r][k],a[j][k]);
        for(j=0;j<m;j++) if(j!=r && dcmp(a[j][i])){
            tmp=a[j][i]/a[r][i];
            for(k=0;k<=nn;k++) a[j][k]=a[j][k]-tmp*a[r][k];
        } ++r;
    }
    for(i=0;i<m;i++) if(dcmp(a[i][nn])){
        for(j=0;j<nn && !dcmp(a[i][j]);j++);
        if(j==nn) return 0; // else x[j]=a[i][nn]/a[i][j];
    }   return 1;
}
\end{lstlisting}
