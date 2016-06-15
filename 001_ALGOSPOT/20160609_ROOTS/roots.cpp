#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int testcase, n;
vector<double> poly;
const double limit = 10;

vector<double> mibun(const vector<double>& p)
{
    vector<double> dif;
    for (int i = 0; i < p.size() - 1; i++)
        dif.push_back( (p.size() - 1 - i)*p[i] );
    return dif;
}

vector<double> gongsikwithgun(const vector<double>& p)
{
    vector<double> ret;

    if (p.size() == 2)
    {
        ret.push_back(-p[1] / p[0]);
    } else if (p.size() == 3)
    {
        double a = p[0], b = p[1], c = p[2];
        ret.push_back( (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) );
        ret.push_back( (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) );
    }
    sort(ret.begin(), ret.end());
    return ret;
}

double calc(const vector<double>& p, double x)
{
    double ret = 0;
    for (int i = 0; i <= p.size() - 1 ; i++)
        ret += pow(x, p.size() - 1 - i) * p[i];
    return ret;
}

vector<double> solve(const vector<double>& p)
{
    int degree = p.size() - 1;

    if (degree <= 2) return gongsikwithgun(p);
    vector<double> ret;
    vector<double> derivative = mibun(p);
    vector<double> sols = solve(derivative);

    sols.insert(sols.begin(), -limit - 1);
    sols.insert(sols.end(), limit + 1);

    for (int i = 0; i < sols.size() - 1; i++)
    {
        double x1 = sols[i], x2 = sols[i + 1];
        double y1 = calc(p, x1), y2 = calc(p, x2);

        if (y1 * y2 > 0) continue;
        if (y1 > y2) {swap(y1, y2); swap(x1, x2);}

        for (int i = 0; i < 100; i++)
        {
            double mx = (x1 + x2) / 2;
            double my = calc(p, mx);

            if (y1 * my <= 0)
            {
                x2 = mx;
                y2 = my;
            } else
            {
                x1 = mx;
                y1 = my;
            }
        }
        ret.push_back( (x1 + x2) / 2 );
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    scanf("%d", &testcase);

    while (testcase--)
    {
        vector<double> empty;
        double temp;

        poly = empty;

        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            scanf("%lf", &temp);
            poly.push_back(temp);
        }

        vector<double> ret(solve(poly));
        for (int i = 0; i < ret.size(); i++)
            printf("%.08lf ", ret[i]);

        printf("\n");
    }
    return 0;
}