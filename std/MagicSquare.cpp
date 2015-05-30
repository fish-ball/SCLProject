\begin{lstlisting}
#define maxn 1000
int a[maxn][maxn],n;

void build(int n,int a[][maxn]) // No solutions when n=2!
{
    int i,j,k,n2=n*n,m=n/2,m2=m*m;
    for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=0;
    if (n==2) return;           // No solutions
    if (n%2==1)
        for(i=0,j=n/2,k=1;k<=n2;k++) {
            a[i][j] = k;
            if(!a[(i+n-1)%n][(j+1)%n]) 
                { i=(i+n-1)%n;  j=(j+1)%n; } else i=(i+1)%n;
        }
    else if(n%4==0)
        for(k=0,i=0;i<n;i++) for(j=0;j<n;j++) {
            a[i][j] = ++k;
            if (i%4==j%4||i%4+j%4==3) a[i][j] = n2+1-a[i][j];
        }
    else if(n%4==2)
        for(i=0,j=m/2,k=0;k<m2;k++) {
            if((i<=m/2 && !(i==m/2&&j==m/2))||(i==m/2+1&&j==m/2)){ // L
                a[i*2  ][j*2+1]=k*4+1;  a[i*2+1][j*2]=k*4+2;
                a[i*2+1][j*2+1]=k*4+3;  a[i*2  ][j*2]=k*4+4;
            } else if (i>m/2+1) { // X
                a[i*2  ][j*2]=k*4+1;    a[i*2+1][j*2+1]=k*4+2;
                a[i*2+1][j*2]=k*4+3;    a[i*2  ][j*2+1]=k*4+4;
            } else { // U
                a[i*2  ][j*2  ]=k*4+1; a[i*2+1][j*2]=k*4+2;
                a[i*2+1][j*2+1]=k*4+3; a[i*2][j*2+1]=k*4+4;
            }
            if (!a[(i+m-1)%m*2][(j+1)%m*2]) i=(i+m-1)%m,j=(j+1)%m; 
                else i=(i+1)%m;
        }
}

int main()
{
    while (cin>>n) {
        build(n,a); cout<<"Order "<<n<<":"<<endl;
        for (int j,i=0;i<n;i++)
            { for (j=0;j<n;j++) cout<<a[i][j]<<' '; cout<<endl;}
    }
    return 0;
}
\end{lstlisting}
