#pragma once
#include <iostream>
#include <cmath>

# define M_PI  3.14159265358979323846

// Вариант 7
// a=0
// b=2
// c=0
// d=1
// u*=exp(sin(pi*xy)^2
// f=|x^2-2y|
// mu1=sin(pi*y)^2
// mu2=sin(2pi*y)^2
// mu3=sin(pi*x)^2
// mu4=sin(2pi*x)^2

double f2(double x, double y)
{
    return -exp(-x * y * y);
}

double U(double x, double y)
{
    return sin(M_PI * x * y);
}

double q1(double y)
{
    return (y - 2) * (y - 3);
}

double q2(double y)
{
    return y * (y - 2) * (y - 3);
}

double q3(double x)
{
    return (x - 1) * (x - 2);
}

double q4(double x)
{
    return x * (x - 1) * (x - 2);
}

double** mpiMain(int n, int m, int a, int b, int c, int d, int N_max, double Eps,double& Eps_max,int& index,double& temp2,double& MaxF, double& tau, double& maxR1, double& min, double& max)
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
            f[i][j] = f2(x[i], y[j]);

            if (std::abs(f[i][j]) > MaxF) MaxF = std::abs(f[i][j]);
            R[i][j] = 0;
        }
    }

    for (int j = 0; j <= m; j++)
    {
        v2[0][j] = q1(y[j]);
        v2[n][j] = q2(y[j]);
    }

    for (int i = 0; i <= n; i++) 
    {
        v2[i][0] = q3(x[i]);
        v2[i][m] = q4(x[i]);
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

    Min = -4 * h2 * std::pow(std::sin(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::sin(M_PI / (2.0 * m)), 2);
    Max = -4 * h2 * std::pow(std::cos(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::cos(M_PI / (2.0 * m)), 2);
    T = 2 / (Max + Min);
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
        if ((Eps_max <= Eps) || (index >= N_max))
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
  
double** mpiMain2(int n, int m, int a, int b, int c, int d, int N_max, double Eps, double& Eps_max2, int& index2, double& temp22, double& MaxF2, double& tau, double& maxR2, double& min, double& max)
{
    double** v22;

    double T2;


    double h = 1.0 / (double)n, k = 1.0 / (double)m;
    double h2 = -1.0 / (h * h), k2 = -1.0 / (k * k);
    double A = -2 * (h2 + k2);
    double** f_2;
    double* x2, * y2; 
    double** R2; 

    x2 = new double[n + 1];
    y2 = new double[m + 1];
    v22 = new double* [n + 1];
    f_2 = new double* [n + 1];

    R2 = new double* [n + 1];

    for (int i = 0; i <= n; i++)
    {
        v22[i] = new double[m + 1];
        f_2[i] = new double[m + 1];

        R2[i] = new double[m + 1];
    }

    for (int i = 0; i <= n; i++)  
    {
        x2[i] = a + i * h;

    }

    for (int j = 0; j <= m; j++)  
    {
        y2[j] = c + j * k;

    }

    for (int j = 0; j <= m; j++)           
    {
        for (int i = 0; i <= n; i++)
        {
            f_2[i][j] = f2(x2[i], y2[j]);

            if (std::abs(f_2[i][j]) > MaxF2) MaxF2 = std::abs(f_2[i][j]);
            R2[i][j] = 0;
        }
    }

    for (int j = 0; j <= m; j++) 
    {
        v22[0][j] = q1(y2[j]);
        v22[n][j] = q2(y2[j]);
    }

    for (int i = 0; i <= n; i++)  
    {
        v22[i][0] = q3(x2[i]);
        v22[i][m] = q4(x2[i]);
    }

    for (int j = 1; j < m; j++)   
    {
        for (int i = 1; i < n; i++)
        {
            v22[i][j] = 0.0;
        }
    }

    double Max, Min;
    // Расчет оптимального значения tau
    Min = -4 * h2 * std::pow(std::sin(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::sin(M_PI / (2.0 * m)), 2);
    Max = -4 * h2 * std::pow(std::cos(M_PI / (2.0 * n)), 2) - 4 * k2 * std::pow(std::cos(M_PI / (2.0 * m)), 2);
    T2 = 2 / (Min + Max);
    tau = T2;
    max = Max;
    min = Min;
    double temp, prev, currentEps;
   
    while (true)
    {
        for (int j = 1; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                R2[i][j] = A * v22[i][j] + h2 * (v22[i - 1][j] + v22[i + 1][j]) + k2 * (v22[i][j - 1] + v22[i][j + 1]) - f_2[i][j];
            }
        }

        Eps_max2 = 0.0;
        for (int j = 1; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                prev = v22[i][j];
                temp = prev - T2 * R2[i][j];

                currentEps = std::abs(prev - temp);
                if (currentEps > Eps_max2) { Eps_max2 = currentEps; };
                v22[i][j] = temp;
            }
        }


        index2++;
        if ((Eps_max2 < Eps) || (index2 >= N_max))
            break;
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            temp22 = A * v22[i][j] + h2 * (v22[i - 1][j] + v22[i + 1][j]) + k2 * (v22[i][j - 1] + v22[i][j + 1]) - f_2[i][j]; 


            if (std::abs(temp22) >= maxR2) maxR2 = std::abs(temp22);
        }
    }
    return v22;
}