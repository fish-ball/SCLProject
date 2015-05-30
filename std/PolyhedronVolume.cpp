Remark : All faces are assumed oriented {\bf counterclockwise} from the outside; \\
Volume6 returns six times the volume of the tetrahedron determined by abc \\
and the origin d.  Volume6 is positive iff d is on the negative side of abc, \\
where the positive side is determined by the rh-rule.  So the volume is positive \\
if the ccw normal to abc points outside the tetrahedron.

\begin{lstlisting}
struct TPoint { double x, y, z; };
typedef int TFace[3];

double Volume6( TPoint a, TPoint b, TPoint c, TPoint d ) // d = origin
{ 
    double  vol, bdx, bdy, bdz, cdx, cdy, cdz;
    bdx = b.x-d.x;  bdy = b.y-d.y;  bdz = b.z-d.z;
    cdx = c.x-d.x;  cdy = c.y-d.y;  cdz = c.z-d.z;
    vol =  ( a.z - d.z ) * ( bdx * cdy - bdy * cdx)
         + ( a.y - d.y ) * ( bdz * cdx - bdx * cdz)
         + ( a.x - d.x ) * ( bdy * cdz - bdz * cdy);
    return vol;
}

void main()
{
  int n, F, i, j; double vol;
  TPoint p[maxn]; TFace face[maxn*2-4];
  cin>>n; for(i=0; i<n; i++) cin >> p[i].x >> p[i].y >> p[i].z;
  cin>>F; for(i=0; i<F; i++) for(j=0;j<3;j++) cin >> face[i][j];
  if( F != 2 * n - 4 ) { printf( "Not a simple polyhedron!\n" ); return;}
  for( vol = i = 0; i < F; i++ )
    vol += Volume6( p[face[i][0]], p[face[i][1]], p[face[i][2]], p[0] );
  vol /= 6.0;  cout << vol <<endl;
}
\end{lstlisting}