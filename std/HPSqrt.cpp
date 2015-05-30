\begin{lstlisting}
int x[maxlen],y[maxlen],z[maxlen],bck[maxlen],lx,ly,lz;

int IsSmaller()  // is z<=y ?
{int i=ly; while(i>1 && z[i]==y[i]) i--;  return (z[i]<=y[i]); }

void Solve() // y^2=x
{
    int i,j,k;
    lx=(ly+1)/2;  ly=lx*2;
    memset(x,0,sizeof(x)); memset(z,0,sizeof(z));
    for(i=lx;i>0;i--){
        for(j=1; j<10; x[i]=j++){
            memcpy(bck,z,sizeof(z));
            z[2*i-1]++; for(k=i;k<=lx;k++)
            { z[i-1+k]+=2*x[k]; z[i+k]+=z[i-1+k]/10; z[i-1+k]%=10; }
            for(k=lx+i;k<=ly;k++){ z[k+1]+=z[k]/10;  z[k]%=10; }
            if(!IsSmaller()) break;
        };
        if(j<10) memcpy(z,bck,sizeof(bck));
    };
    for(i=lx;i>0;i--) cout<<x[i]; cout<<endl;
}

int main()
{
    char ch,s[maxlen]; int i,j;
    memset(y,0,sizeof(y));
    cin>>s; ly=strlen(s);
    for(i=0;i<ly;i++) y[i+1]=s[ly-1-i]-'0';
    Solve();
    return 0;
}
\end{lstlisting}