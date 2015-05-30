\begin{lstlisting}
#include<iostream.h>
#include<fstream.h>
#include<algorithm>

#define maxn 10000
int a[maxn],t[maxn],n,ans;

void sort(int b,int e)
{
    if(e-b<=0) return;
    int mid=(b+e)/2,p1=b,p2=mid+1,i=b;  
    sort(b,mid); sort(mid+1,e); 
    while( p1<=mid || p2<=e )
        if( p2>e|| (p1<=mid && a[p1]<=a[p2]) ) t[i++]=a[p1++];
            else{ t[i++]=a[p2++];  ans+=mid-p1+1; }     
    for(i=b;i<=e;i++)a[i]=t[i];
}

int main()
{
    ifstream cin("input.txt");  
    int i,j;
    while(cin>>n) {
        for(i=0;i<n;i++) cin>>a[i];
        ans=0;  sort(0,n-1); // Counting Inverse Number
        cout<<"Minimum exchange operations : "<<ans<<endl;
    }       
    return 0;
}
\end{lstlisting}
