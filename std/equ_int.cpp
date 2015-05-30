// Gauss Elimination : $\sum_{0 \leq j<nn} a_{i,j}x_{i,j}=a_{i,nn}$
\begin{lstlisting}
int m,nn, a[maxn][maxn];

int gcd(int x,int y)
{ if(y==0) return x; else return gcd(y,x%y); }

void yuefen(int b[],int ct)
{
    int i,j=0,k;
    for(i=0;i<ct;i++) if(b[i]) if(j) k=gcd(b[i],k); else {k=b[i]; j=1;}
    if(k!=0) for(i=0;i<ct;i++) b[i]/=k; 
}

int reduce() // return 0 means no solution!
{
    int i,j,k,r,tmp;
    for(i=r=0; i<nn; i++){
        for(j=r; j<m && !a[j][i]; j++);  if(j>=m) continue;
        if(j>r) for(k=0;k<=nn;k++) std::swap(a[r][k],a[j][k]);
        for(j=0;j<m;j++) if(j!=r && a[j][i]){
            tmp=a[j][i];
            for(k=0;k<=nn;k++) a[j][k]=a[j][k]*a[r][i]-tmp*a[r][k];
            yuefen(a[j],nn+1);
        } ++r;
    }
    for(i=0;i<m;i++) if(a[i][nn]) {
        for(j=0;j<nn && !a[i][j];j++);
        if(j==nn) return 0; // else x[j]=a[i][nn]/a[i][j];
    }
    return 1;
}
\end{lstlisting}
