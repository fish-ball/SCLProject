// Gauss Elimination : $\bigoplus_{0 \leq j<nn} a_{i,j}x_{i,j}=a_{i,nn}$
\begin{lstlisting}
int m,nn,num,list[maxn]; char a[maxn][maxn];

int reduce()
{
    int i,j,k,r;
    for(i=r=0; i<nn; i++){
        for(j=r; j<m && !a[j][i]; j++); if(j>=m) continue;
        if(j>r) for(k=0;k<=nn;k++) std::swap(a[r][k],a[j][k]);
        for(num=0,k=i;k<=nn;k++) if( a[r][k] ) list[num++]=k;
        for(j=0;j<m;j++) if(j!=r && a[j][i])
            for(k=0;k<num;k++) a[j][list[k]]^=1;
        ++r;
    }
    for(i=0;i<m;i++)
        if(a[i][nn]){
            for(j=0;j<nn && !a[i][j];j++); 
            if(j==nn) return 0; // else x[j]=a[i][nn]/a[i][j];
        }       
    return 1;
}
\end{lstlisting}
