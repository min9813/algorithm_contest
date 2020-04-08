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
    return abs(cross(p-l.p1, l.p2 - l.p1)/(l.p2 - l.p1).abs());
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.p2 - s.p1, p - s.p1)<0.0) return (p-s.p1).abs();
    if(dot(s.p1 - s.p2, p - s.p2)<0.0) return (p-s.p2).abs();
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
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


int main(){
    int n, i, x1,y1,x2,y2,a,b;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    Point p1(x1,y1);
    Point p2(x2,y2);
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        Point p3(a,b);
        int out = ccw(p1, p2, p3);
        if(out==COUNTER_CLOCKWISE){
            std::cout << "COUNTER_CLOCKWISE\n";
        }else if(out==CLOCKWISE){
            std::cout << "CLOCKWISE\n";
        }else if(out==ONLINE_BACK){
            std::cout << "ONLINE_BACK\n";
        }else if(out==ONLINE_FRONT){
            std::cout << "ONLINE_FRONT\n";
        }else{
            std::cout << "ON_SEGMENT\n";
        }
    }

    return 0;

}