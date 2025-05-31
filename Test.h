#pragma once
#include <iostream>
#include <cmath>

# define M_PI  3.14159265358979323846

double f1(double x, double y) { //f*
    return  M_PI * M_PI * (x * x + y * y) * sin(M_PI * x * y);
}
double fm(double x, double y) {
    return -exp(-x * y * y);
}
double u1(double x, double y) {
    return sin(M_PI * x * y);
}
double mu1(double y) {
    return sin(M_PI * y);
}
double mu2(double y) {
    return  sin(M_PI * 2 * y);
}
double mu3(double x) {
    return sin(M_PI * 2 * x);
}
double mu4(double x) {
    return  sin(M_PI * 3 * x);
}

double** U(int n, int m, int a, int b, int c, int d)
{
    double** u;
    u = new double* [n + 1];
    double h = (b-a) / (double)n, k = (d-c) / (double)m;
    double* x, * y;
    x = new double[n + 1];
    y = new double[m + 1];
    for (int i = 0; i <= n; i++)
    {

        u[i] = new double[m + 1];

    }

    for (int i = 0; i <= n; i++)  
    {
        x[i] = a + i * h;

    }

    for (int j = 0; j <= m; j++) 
    {
        y[j] = c + j * k;

    }

    for (int j = 0; j <= m; j++)            
    {
        for (int i = 0; i <= n; i++)
        {
            
            u[i][j] = u1(x[i], y[j]);
            
        }
    }

    return u;
}


double** mpiTest(int n, int m, int a, int b, int c, int d, int N_max, double Eps, double& Eps_max, int& index, double& temp2, double& MaxF, double& tau, double** u, double& maxR1, double& min, double& max)
{
    double** v2;

    double T;

    double h = 1.0 / (double)n, k = 1.0 / (double)m;
    double h2 = -1.0 / (h * h), k2 = -1.0 / (k * k);
    double A = -2 * (h2 + k2);
    double** f;
    double* x, * y;
    double** R;

    char* buffer = new char[100];

    x = new double[n + 1];
    y = new double[m + 1];
    v2 = new double* [n + 1];
    f = new double* [n + 1];

    R = new double* [n + 1];

    for (int i = 0; i <= n; i++)
    {
        v2[i] = new double[m + 1];
        f[i] = new double[m + 1];

        R[i] = new double[m + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;

    }

    for (int j = 0; j <= m; j++)
    {
        y[j] = c + j * k;

    }

    for (int j = 0; j <= m; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            f[i][j] = f1(x[i], y[j]);

            if (std::abs(f[i][j]) > MaxF) MaxF = std::abs(f[i][j]);
            R[i][j] = 0;
        }
    }

    for (int j = 0; j <= m; j++)
    {
        v2[0][j] = mu1(y[j]);
        v2[n][j] = mu2(y[j]);
    }

    for (int i = 0; i <= n; i++)
    {
        v2[i][0] = mu3(x[i]);
        v2[i][m] = mu4(x[i]);
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            v2[i][j] = 0.0;
        }
    }

    double temp, prev, currentEps;

    double Max, Min;
    // Расчет оптимального значения tau
    Min = -4 * h2 * std::pow(std::sin(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::sin(M_PI / (2.0 * m)), 2);
    Max = -4 * h2 * std::pow(std::cos(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::cos(M_PI / (2.0 * m)), 2);
    T = 2 / (Min + Max);
    tau = T;
    min = Min;
    max = Max;
    while (true)
    {
        for (int j = 1; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                R[i][j] = A * v2[i][j] + h2 * (v2[i - 1][j] + v2[i + 1][j]) + k2 * (v2[i][j - 1] + v2[i][j + 1]) - f[i][j];
            }
        }

        Eps_max = 0.0;
        for (int j = 1; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                prev = v2[i][j];
                temp = prev - T * R[i][j];

                currentEps = std::abs(prev - temp);
                if (currentEps > Eps_max) { Eps_max = currentEps; };
                v2[i][j] = temp;
            }
        }


        index++;
        if ((Eps_max < Eps) || (index >= N_max))
            break;
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            temp2 = A * v2[i][j] + h2 * (v2[i - 1][j] + v2[i + 1][j]) + k2 * (v2[i][j - 1] + v2[i][j + 1]) - f[i][j];


            if (std::abs(temp2) >= maxR1) maxR1 = std::abs(temp2);
        }
    }

    return v2;

}

double fx(double x, double y) {
    return -2 * (y - 1) * (2 - y) - 2 * (x - 3) * (4 - x);
}

double ux(double x, double y) {
    return (x - 3) * (4 - x) * (y - 1) * (2 - y);
}

double mu1x(double y) {
    return 0;
}
double mu2x(double y) {
    return  0;
}
double mu3x(double x) {
    return 0;
}
double mu4x(double x) {
    return 0;
}

double** Ux(int n, int m, int a, int b, int c, int d)
{
    double** u;
    u = new double* [n + 1];
    double h = (b - a) / (double)n, k = (d - c) / (double)m;
    double* x, * y;
    x = new double[n + 1];
    y = new double[m + 1];
    for (int i = 0; i <= n; i++)
    {

        u[i] = new double[m + 1];

    }

    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;

    }

    for (int j = 0; j <= m; j++)
    {
        y[j] = c + j * k;

    }

    for (int j = 0; j <= m; j++)
    {
        for (int i = 0; i <= n; i++)
        {

            u[i][j] = ux(x[i], y[j]);

        }
    }

    return u;
}

double** mpiexp(int n, int m, int a, int b, int c, int d, int N_max, double Eps, double& Eps_max, int& index, double& temp2, double& MaxF, double& tau, double** u, double& maxR1, double& min, double& max)
{
    double** v2;

    double T;

    double h = 1.0 / (double)n, k = 1.0 / (double)m;
    double h2 = -1.0 / (h * h), k2 = -1.0 / (k * k);
    double A = -2 * (h2 + k2);
    double** f;
    double* x, * y;
    double** R;

    char* buffer = new char[100];

    x = new double[n + 1];
    y = new double[m + 1];
    v2 = new double* [n + 1];
    f = new double* [n + 1];

    R = new double* [n + 1];

    for (int i = 0; i <= n; i++)
    {
        v2[i] = new double[m + 1];
        f[i] = new double[m + 1];

        R[i] = new double[m + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;

    }

    for (int j = 0; j <= m; j++)
    {
        y[j] = c + j * k;

    }

    for (int j = 0; j <= m; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            f[i][j] = fx(x[i], y[j]);

            if (std::abs(f[i][j]) > MaxF) MaxF = std::abs(f[i][j]);
            R[i][j] = 0;
        }
    }

    for (int j = 0; j <= m; j++)
    {
        v2[0][j] = mu1x(y[j]);
        v2[n][j] = mu2x(y[j]);
    }

    for (int i = 0; i <= n; i++)
    {
        v2[i][0] = mu3x(x[i]);
        v2[i][m] = mu4x(x[i]);
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            v2[i][j] = 0.0;
        }
    }

    double temp, prev, currentEps;

    double Max, Min;
    // Расчет оптимального значения tau
    Min = -4 * h2 * std::pow(std::sin(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::sin(M_PI / (2.0 * m)), 2);
    Max = -4 * h2 * std::pow(std::cos(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::cos(M_PI / (2.0 * m)), 2);
    T = 2 / (Min + Max);
    tau = T;
    min = Min;
    max = Max;
    while (true)
    {
        for (int j = 1; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                R[i][j] = A * v2[i][j] + h2 * (v2[i - 1][j] + v2[i + 1][j]) + k2 * (v2[i][j - 1] + v2[i][j + 1]) - f[i][j];
            }
        }

        Eps_max = 0.0;
        for (int j = 1; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                prev = v2[i][j];
                temp = prev - T * R[i][j];

                currentEps = std::abs(prev - temp);
                if (currentEps > Eps_max) { Eps_max = currentEps; };
                v2[i][j] = temp;
            }
        }


        index++;
        if ((Eps_max < Eps) || (index >= N_max))
            break;
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            temp2 = A * v2[i][j] + h2 * (v2[i - 1][j] + v2[i + 1][j]) + k2 * (v2[i][j - 1] + v2[i][j + 1]) - f[i][j];


            if (std::abs(temp2) >= maxR1) maxR1 = std::abs(temp2);
        }
    }

    return v2;

}