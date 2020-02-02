#include <stdio.h>
#include <math.h>

struct Point {double x,y;};

double THETA = M_PI * 60.0/180.0;

void koch(int d, Point p1, Point p2){
    if(d == 0){
        return ;
    }
    Point s, t, u;
    s.x = (2 * p1.x + p2.x) / 3.;
    s.y = (2 * p1.y + p2.y) / 3.;
    u.x = (p1.x + 2 * p2.x) / 3.;
    u.y = (p1.y + 2 * p2.y) / 3.;
    t.x = s.x + (u.x - s.x) * cos(THETA) - (u.y - s.y) * sin(THETA);
    t.y = s.y + (u.x - s.x) * sin(THETA) + (u.y - s.y) * cos(THETA);
    koch(d-1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(d-1, s, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(d-1, t, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(d-1, u, p2);
}

int main(){
    int n;
    Point p1, p2;

    scanf("%d", &n);

    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;

    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);

    return 0;
}