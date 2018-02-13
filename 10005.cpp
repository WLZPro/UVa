#include <cstdio>
#include <cmath>
int n;
double x[1005], y[1005], X, Y, d, e;
double dist(double a, double b) {
	return a*a + b*b;
}
int main() {
	//scanf("%d", &n);
    while (scanf("%d", &n), n) {
        
        for (int i = 0; i < n; i++) {
            int x1, y1;
		    scanf("%d %d", &x1, &y1);
		    X += (double) x1; 
            Y += (double) y1;
            x[i] = (double) x1; 
            y[i] = (double) y1;
	    }
        if (n == 2) {
            double deltaX = (double)x[1] - (double)x[0];
            double deltaY = (double)y[1] - (double)y[0];
            double r;
            scanf("%lf", &r);
            printf("%s\n", (2.0)*r*(2.0)*r >= dist(deltaX, deltaY) ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.");
        } else {
            X /= n; Y /= n;
            double P = 0.1;
	        for (int i = 0; i < 30000; i++) {
		        int f = 0;
		        d = dist(X - x[0], Y - y[0]);
		        for (int j = 1; j < n; j++) {
			        e = dist(X - x[j], Y - y[j]);
			        if (d < e) { d = e; f = j; }
		        }
		        X += (x[f] - X)*P;
		        Y += (y[f] - Y)*P;
		        P *= 0.999;
	        }
            d -= 0.000005;
            double r;
            scanf("%lf", &r);
            printf("%s\n", r * r - d >= 0 || n == 1 ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.");
        }
    }
}