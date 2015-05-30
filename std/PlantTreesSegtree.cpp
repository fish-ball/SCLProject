\begin{lstlisting}
#define maxn 50000
#define maxup 50006

int nspan,span[maxn][3],up,tree[maxup];
int iteam[maxup],next[maxup],num;

int funt_comp(const void *a, const void *b)
{ return ((const int *)b)[0]-((const int *)a)[0]; }

void add(int r)
{ for(;r<=up; r+=r&(r^(r-1))) ++tree[r]; }

int sum(int r)
{ int ans = 0; for(;r>0; r-=r&(r^(r-1))) ans+=tree[r]; return ans; }

void go()
{
    int j,k,i,ans=0; up=0;
    for(i=0; i<nspan; ++i){
        scanf("%d %d %d", &span[i][0], &span[i][1], &span[i][2]);
        ++span[i][0]; ++span[i][1];
        if (span[i][1]>up) up=span[i][1];
    }
    qsort(span, nspan, sizeof(int)*3, funt_comp);
    for(j=0;j<=up;j++) next[j]=j+1;
    next[up]=0; memset(tree,0,(up+1)*sizeof(int));
    for(i=0; i<nspan; i++){
        k=sum(span[i][1])-sum(span[i][0]-1);
        if(k>=span[i][2]) continue; else k=span[i][2]-k;
        j=span[i][0]; if(next[j-1]!=j) j=next[j];
        while(k--){
            next[span[i][0]]=next[span[i][0]-1]=next[j];
            ans++;  add(j); j=next[j];
        }
    }
    printf("%d\n", ans);
}

int main() {
    while( 1==scanf("%d", &nspan) ) go();
    return 0;
}
\end{lstlisting}
