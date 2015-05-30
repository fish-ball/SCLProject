\begin{lstlisting}
int P[ML][ML],D[ML][ML],T[ML][ML];

void init()
{
    int i,j,x,k,l;
    for(P[0][0]=l=1;l<ML;l++) {
        P[0][l] = P[l][0] = 1;
        for(i=1;i<l;i++) P[i][l-i] = P[i-1][l-i]+P[i][l-i-1];
    }
    for(i=0;i<ML;i++) for (k=j=0; j<ML-i && k!=ML;j++)
        for(x=0;x<P[i][j];x++) { if (k==ML) break; D[i][k++] = 1<<j; }
    for(i=0;i<ML;i++) T[i][0] = 0;
    for(j=1;j<ML;j++) for(i=0;i<20;i++) T[i][j] = T[i][j-1]+D[i][j-1];
}

int main()
{
    init();
    for (int a,b,casec=1 ; cin>>a>>b && (a||b) ;casec++)
        cout << "Case " << casec << ": " << T[b-3][a] << endl;
    return 0;
}
\end{lstlisting}
