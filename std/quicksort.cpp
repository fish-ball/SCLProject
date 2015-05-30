\begin{lstlisting}
void quicksort(int b,int e,int a[])
{
    int i=b,j=e,x=a[(b+e)/2];
    do{
      while(a[i]<x) i++;
      while(a[j]>x) j--;
      if(i<=j) std::swap(a[i++],a[j--]);
    }while(i<j);
    if(i<e) quicksort(i,e,a);
    if(j>b) quicksort(b,j,a);
}
\end{lstlisting}
