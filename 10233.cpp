#include <cstdio>
#include <cmath>
using namespace std;
double D = sqrt(3)/2.0;

double height(int layer, int number) {
    double fixed = layer * D;
    if (layer % 2 == number % 2) {
        return D * 2.0/3.0 + fixed;
    } else {
        return D * 1.0/3.0 + fixed;
    }
}

double width(int layer, int number) {
    int middle = layer;
    int pos = number - layer * layer;
    return (middle - pos) * 0.5;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int nLayer = sqrt(n);
        int mLayer = sqrt(m);
        double nHeight = height(nLayer, n);
        double mHeight = height(mLayer, m);
        double nWidth = width(nLayer, n);
        double mWidth = width(mLayer, m);
        printf("%.3f\n", hypot(nHeight - mHeight, nWidth - mWidth));
    }
}