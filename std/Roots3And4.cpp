\[
c_0 + c_1*x + c_2*x^2 + c_3*x^3 + c_4*x^4 = 0
\]
The functions return the number of distinct non-complex roots and put the values into the s array.
\begin{lstlisting}
const double pi = acos(-1.0); // 3.14159265358979323846

double cbrt(double x)
{
    if( x> eps ) return  pow(  x, 1/3.0);
    if( x<-eps ) return -pow( -x, 1/3.0);
    return 0;
}

int SolveQuadric(double c[3], double s[2])
{
    double p, q, d;  // normal form: x^2 + px + q = 0
    p = c[1]/(2*c[2]); q = c[0]/c[2]; d = p*p-q;
    if( dcmp(d)==0 ) { s[0] = - p; return 1; }
    if( dcmp(d) < 0 ) return 0;
    d = sqrt( d );
    s[0] = - p + d;
    s[1] = - p - d;
    return 2;
}

int SolveCubic(double c[4], double s[3])
{
    int     i, num;   // normal form: x^3 + Ax^2 + Bx + C = 0 
    double  sub, A, B, C, sqa, p, q, cbp, d;
    A = c[2]/c[3];  B = c[1]/c[3];  C = c[0]/c[3];
    sqa = A * A;      //  x = y - A/3  =>  x^3 +px + q = 0 
    p = 1.0/3 * (- 1.0/3 * sqa + B);
    q = 1.0/2 * (2.0/27 * A * sqa - 1.0/3 * A * B + C);
    cbp = p * p * p;  // use Cardano's formula
    d = q * q + cbp;
    if( dcmp(d)==0 ) {
        if( dcmp(q)==0 ) { s[0] = 0; num = 1; } // one triple solution
        else { // one single and one double solution
            double u = cbrt( -q );
            s[0] = 2 * u;  s[1] = - u;  num = 2; 
        }
    } else if( dcmp(d)<0 ) { // Casus irreducibilis: three real solutions
        double phi = 1.0/3 * acos(-q / sqrt(-cbp));
        double t = 2 * sqrt(-p);
        s[ 0 ] =   t * cos(phi);
        s[ 1 ] = - t * cos(phi + pi / 3);
        s[ 2 ] = - t * cos(phi - pi / 3);
        num = 3;
    } else { /* one real solution */    
        d = sqrt(d); double u = cbrt(d-q), v = - cbrt(d+q);
        s[ 0 ] = u + v; num = 1;
    }
    /* resubstitute */
    sub = 1.0/3 * A;  for( i=0; i<num; ++i) s[i] -= sub;
    return num;
}
\end{lstlisting}
\newpage
\begin{lstlisting}
int SolveQuartic(double c[5], double s[4])
{
    double  e[4], z, u, v, sub, A, B, C, d, sqa, p, q, r;
    int     i, num;            // x^4 + Ax^3 + Bx^2 + Cx + D = 0
    A = c[3]/c[4];  B = c[2]/c[4];  C = c[1]/c[4];  d = c[0]/c[4];
    sqa = A * A;               // x = y - A/4  =>  x^4 + px^2 + qx + r = 0
    p = - 3.0/8 * sqa + B;
    q = 1.0/8 * sqa * A - 1.0/2 * A * B + C;
    r = - 3.0/256*sqa*sqa + 1.0/16*sqa*B - 1.0/4*A*C + d;
    if( dcmp(r)==0 ) {         // no absolute term: y(y^3 + py + q) = 0
        e[0] = q;  e[1] = p;  e[2] = 0;  e[3] = 1;
        num = SolveCubic(e, s);  s[ num++ ] = 0;
    } else {                   // solve the resolvent cubic ...
        e[0] = 1.0/2 * r * p - 1.0/8 * q * q;   e[1] = - r;
        e[2] = - 1.0/2 * p;                     e[3] = 1;
        SolveCubic(e, s);
        z = s[ 0 ];            // ... and take the one real solution
        u = z*z-r;  v = 2*z-p; // ... to build two quadric equations
        if(dcmp(u)==0) u=0; else if(dcmp(u)>0) u=sqrt(u); else return 0;
        if(dcmp(v)==0) v=0; else if(dcmp(v)>0) v=sqrt(v); else return 0;
        e[0] = z-u;  e[1] = dcmp(q)<0 ? -v : v;  e[2] = 1; 
        num = SolveQuadric(e, s);
        e[0] = z+u;  e[1] = dcmp(q)<0 ? v : -v;  e[2] = 1;
        num += SolveQuadric(e, s + num);
    }
    sub = 1.0/4*A;  for( i=0; i<num; ++i) s[i] -= sub; // resubstitute
    return num;
}
\end{lstlisting}