\begin{lstlisting}
int LNDSS(int a[],int n) // Longest Non-descending Sub Sequence
{
    int i,j,k,*b=new int[n+1],ans=0;
    b[ans]=-0x3f3f3f3f;
    for(i=0;i<n;i++){   // lower_bound for Asending Sub Squence 
        j=std::upper_bound(b,b+ans+1,a[i])-b; 
        if(j>ans) b[++ans]=a[i];else if(a[i]<b[j]) b[j]=a[i];
    }   
    delete b; return ans;
}
\end{lstlisting}
