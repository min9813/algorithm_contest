#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS )

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

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


int main(){
    int n, i, x1,y1,x2,y2,x3,y3,x4,y4;
    double dist;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        Segment s1(Point(x1,y1), Point(x2,y2));
        Segment s2(Point(x3,y3), Point(x4,y4));
        dist = getDistance(s1, s2);

        std::cout << std::fixed << std::setprecision(11) << dist <<"\n";

    }

    return 0;

}