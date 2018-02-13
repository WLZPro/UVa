#include <bits/stdc++.h>
using namespace std;

double minDist;
struct point {
    double x, y;
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};


double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    point c2 = translate(a, scale(ab, u));
    double ans = dist(p, c2);
    if (ans < minDist) {
        minDist = ans;
        c = point(c2.x, c2.y);
    }
    return ans;
}

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        double ans = dist(p, a);
        if (ans < minDist) {
            minDist = ans;
            c = point(a.x, a.y);
        }
        return ans;
    }
    if (u > 1.0) {
        double ans = dist(p, b);
        if (ans < minDist) {
            minDist = ans;
            c = point(b.x, b.y);
        }
        return ans;
    }
    return distToLine(p, a, b, c);
}

int main() {
    double mx, my;
    int n;
    while (scanf("%lf", &mx) == 1) {
        scanf("%lf", &my);
        point m(mx, my);
        scanf("%d", &n);
        double prevX, prevY;
        scanf("%lf", &prevX);
        scanf("%lf", &prevY);
        minDist = 1000000000.0;
        point ans(0, 0);
        for (int i = 0; i < n; i++) {
            double x, y;
            scanf("%lf", &x);
            scanf("%lf", &y);
            distToLineSegment(m, point(prevX, prevY), point(x, y), ans);
            prevX = x;
            prevY = y;
        }
        printf("%.4f\n%.4f\n", ans.x, ans.y);
    }
}