#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
#include <cmath>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS )

class Point{
    public:
        double x, y;

        Point(double x=0, double y=0): x(x),y(y){}

        Point operator + (Point p) {return Point(x+p.x, y+p.y);}
        Point operator - (Point p) {return Point(x-p.x, y-p.y);}
        Point operator * (double a) {return Point(x*a, y*a);}
        Point operator / (double a) {return Point(x/a, y/a);}

        double abs() {return std::sqrt(norm());}
        double norm() {return x * x + y * y;}

        bool operator < (const Point &p) const{
            return x != p.x ? x < p.x : y < p.y;
        }

        bool operator == (const Point &p) const{
            return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
        }
};

typedef Point Vector;

double dot(Vector v1, Vector v2){
    return v1.x * v2.x + v1.y * v2.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, M;
    lf x, y;
    sll(N);
    vector<complex<lf>> A(N);
    // vector<lf> norms(N);
    rep(i,N){
        slf(x);
        slf(y);
        A[i] = complex<double>(x, y);
        // norms[i] = A[i].abs();
    }

    lf pi = acos(-1.0);
    // cout << "pi = " << pi <<endl;
    ll vertical_num = 0;
    ll not_big_num = 0;
    rep(i, N){
        vector<lf> args_all(2*(N-1));
        ll idx = 0;
        rep(j, N){
            if(j!=i){
                // lf arg = arg(A[j] - A[i]);
                args_all[idx] = arg(A[j] - A[i]);
                idx ++;
            }
        }

        // rep(j,N-1){
        //     printf("i=%lld, args[%lld] = %lf\n", i, j, args_all[j]);
        // }
        sort(args_all.begin(), args_all.begin()+N-1);

        rep(j, N-1){
            args_all[idx] = args_all[idx-(N-1)] + 2 * pi;
            idx ++;
        }
        args_all.push_back(100);
        // printf("idx = %lld, 2*(N-1)=%lld\n", idx, 2*(N-1));

        ll r = 0;
        rep(j, N-1){
            while(args_all[r]-args_all[j] < pi * 0.5 - EPS){
                r ++;
            }

            if(args_all[r] - args_all[j] < pi*0.5+EPS){
                vertical_num ++;
            }

            not_big_num += (r - j - 1);
        }
        // printf("r=%lld\n", r);
    }

    ll t = N * (N-1) * (N-2) / 6;
    ll big_num = t*3 - vertical_num - not_big_num;
    ll small = t - (big_num + vertical_num);

    printf("%lld %lld %lld\n", small, vertical_num, big_num);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}