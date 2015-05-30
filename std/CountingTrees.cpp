\begin{lstlisting}
// Rooted     {1, 5, 11, 20, 30} => {1, 9, 1842, 12826228, 354426847597 }
// Non-Rooted {1, 3, 10, 25, 30} => {1, 1, 106, 104636890,  14830871802 }
void main() 
{
    ifstream cin("input.txt");
    int i,j,n;
    memset(s, 0, sizeof(s)); a[0] = 0; a[1] = 1;
    for(i=1; i<maxn-1; i++) 
    {
        a[i+1] = 0;
        for(j=1; j<=i; j++)  
        {
            s[i][j] = s[i-j][j] + a[i+1-j];
            a[i+1] += j*a[j]*s[i][j];
        }
        a[i+1] /= i;
    }
    while(cin>>n) // a[n] = Rooted;  ans = Non-Rooted
    {
        int ans = a[n]; 
        for(i=1; 2*i<=n; i++) ans -= a[i] * a[n-i];
        if( n%2==0 ) ans += (a[n/2]+1) * a[n/2] / 2;
        cout << a[n] << " " << ans << endl;
    }
}
\end{lstlisting}