#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <list>
#include <algorithm>
#include <set>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS )

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
static const int BOTTOM = 0;
static const int LEFT = 1;
static const int RIGHT = 2;
static const int TOP = 3;


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

class Segment{
    public:
        Point p1, p2;
        Segment(Point p1=Point(), Point p2=Point()): p1(p1), p2(p2){
        }
};

typedef Segment Line;

class Circle{
    public:
        Point c;
        double r;
        Circle(Point c=Point(), double r=0.0):c(c), r(r){}
};

typedef std::vector<Point> Polygon;
typedef std::list<Point> PolygonList;

class EndPoint {
    public:
        Point p;
        int seg, st;
        EndPoint(){}
        EndPoint(Point p, int seg, int st):p(p), seg(seg), st(st){}

        bool operator < (const EndPoint &ep) const{
            if(p.y == ep.p.y){
                return st < ep.st;
            }else return p.y < ep.p.y;
        }
};

bool intersection(Segment s1, Segment s2);
bool intersection(Point p1, Point p2, Point p3, Point p4);

double dot(Vector v1, Vector v2){
    return v1.x * v2.x + v1.y * v2.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

bool is_orthogonal(Vector a, Vector b){
    return equals(dot(a,b), 0.0);
}

bool is_orthogonal(Point a1, Point a2, Point b1, Point b2){
    return is_orthogonal(a1 - a2, b1 - b2);
}

bool is_parallel(Vector a, Vector b){
    return equals(cross(a,b), 0.0);
}

bool is_parallel(Point a1, Point a2, Point b1, Point b2){
    return is_parallel(a1 - a2, b1 - b2);
}

Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    // printf("%lf x=%lf, y=%lf", base.norm(), base.x, base.y);
    double r = dot(base, p - s.p1) / base.norm();
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    return p + (project(s,p) - p) * 2.0;
}

double getDistance(Point a, Point b){
    return (b-a).abs();
}

double getDistanceLP(Line l, Point p){
    return fabs(cross(p-l.p1, l.p2 - l.p1)/(l.p2 - l.p1).abs());
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.p2 - s.p1, p - s.p1)< -EPS) return (p-s.p1).abs();
    if(dot(s.p1 - s.p2, p - s.p2)< -EPS) return (p-s.p2).abs();
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
    if(intersection(s1, s2)) return 0.0;
    return fmin(fmin(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)), 
            fmin(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b)>EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b)< -EPS) return CLOCKWISE;
    if(dot(a,b)< -EPS) return ONLINE_BACK;
    if(a.norm() < b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersection(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1,p2,p4)<=0) && (ccw(p3,p4,p1) * ccw(p3,p4,p2)<=0);
}

bool intersection(Segment s1, Segment s2){
    return intersection(s1.p1, s1.p2, s2.p1, s2.p2);
}

Point getCrossPoint(Segment s1, Segment s2){
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

std::pair<Point, Point> getCrossPoints(Circle c, Line l){
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
    double base = sqrt(c.r * c.r - (pr - c.c).norm());
    Point a = pr + e * base;
    Point b = pr - e * base;
    if (a < b){
        return std::make_pair(a,b);
    }else{
        return std::make_pair(b,a);
    }
}

double arg(Vector p){return std::atan2(p.y,p.x);}
Vector polar(double a, double theta){
    return Vector(std::cos(theta)*a, std::sin(theta)*a);
}
std::pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
    double d = (c1.c - c2.c).abs();
    double theta = std::acos((d*d+c1.r*c1.r-c2.r*c2.r)/(2*c1.r*d));
    double phi = arg(c2.c-c1.c);
    Point a = c1.c+polar(c1.r, theta+phi);
    Point b = c1.c+polar(c1.r, -theta+phi);
    if (a < b){
        return std::make_pair(a,b);
    }else{
        return std::make_pair(b,a);
    }
}

int contains(Polygon &g, Point p){
    int i;
    bool is_cross = false;
    for(i=0;i<g.size();i++){
        Point a = g[i] - p;
        Point b;
        if(i==g.size()-1){
            b = g[0] - p;
        }else{
            b = g[i+1] - p;
        }
        if(a.y>b.y)std::swap(a,b);
        if(abs(cross(a,b))<EPS && dot(a,b)<EPS){
            return 1;
        }
        if(a.y < EPS && EPS < b.y && cross(a,b)>EPS) is_cross = !is_cross ;
    }
    return (is_cross ? 2 : 0 );
}

Polygon andrew_scan(Polygon s){
    Polygon u, l;
    if(s.size()<3) return s;
    int i;
    std::sort(s.begin(), s.end());
    // for(auto ppp:s){
    //     printf("x=%lf y=%lf\n", ppp.x, ppp.y);
    // }
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);

    for(i=2;i<s.size();i++){
        for(int j=u.size();j>=2 && ccw(u[j-2],u[j-1],s[i])==COUNTER_CLOCKWISE; j--){
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    for(i=s.size()-3;i>=0;i--){
        for(int j=l.size();j>=2 && ccw(l[j-2],l[j-1],s[i])==COUNTER_CLOCKWISE; j--){
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    std::reverse(l.begin(), l.end());
    // for(auto ppp:l){
        // printf("x=%lf y=%lf\n", ppp.x, ppp.y);
    // }
    for(i=u.size()-2;i>=1;i--){
        l.push_back(u[i]);
    }
    return l;

}

int manhattan_intersection(std::vector<Segment> &S){
    int n = S.size();
    std::vector<EndPoint> EP(2*n);
    int k = 0;
    for(int i=0;i<n;i++){
        if(S[i].p1.y == S[i].p2.y){
            if(S[i].p1.x > S[i].p2.x) std::swap(S[i].p1, S[i].p2);
        }else if(S[i].p1.y > S[i].p2.y) std::swap(S[i].p1, S[i].p2);
        if(S[i].p1.y == S[i].p2.y){
            // 水平線分
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        }else{
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
        // printf("after : segment %d x1=%lf, y1=%lf, x2=%lf, y2=%lf\n",i, S[i].p1.x, S[i].p1.y, S[i].p2.x, S[i].p2.y);
    }
    // printf("2n=%d, k=%d\n", 2*n, k);
    

    std::sort(EP.begin(), EP.end());
    // for(auto i:EP){
        // printf("x=%lf y=%lf, type=%d seg id=%d \n",i.p.x, i.p.y, i.st, i.seg);
    // }
    // for(int i=0;i<n;i++){
        // printf("after sort : segment %d x1=%lf, y1=%lf, x2=%lf, y2=%lf\n",i, S[i].p1.x, S[i].p1.y, S[i].p2.x, S[i].p2.y);
    // }
    std::set<int> BT;
    BT.insert(1000000001);
    int cnt = 0;
    for(int i=0;i<2*n;i++){
        if(EP[i].st == TOP){
            BT.erase(EP[i].p.x);
        }else if(EP[i].st == BOTTOM){
            BT.insert(EP[i].p.x);
        }else if(EP[i].st == LEFT){
            // 水平線分と交差する垂直線分の左端と右端の座標
            std::set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);
            std::set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);
            cnt += std::distance(b, e);
            // printf("i=%d EP id=%d %d %d p1 x= %lf p2 x=%lf\n", i,EP[i].seg, b,e, S[EP[i].seg].p1.x, S[EP[i].seg].p2.x);
        }
    }

    return cnt;
}



int main(){
    int k,n, i, out, x1,y1,x2,y2;
    std::vector<Segment> S;
    scanf("%d", &n);
    S.resize(n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        S[i] = Segment(Point(x1, y1), Point(x2,y2));
    }

    int ans = manhattan_intersection(S);

    printf("%d\n", ans);

    

    return 0;

}