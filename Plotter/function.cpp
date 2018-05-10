//C++ includes
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace  std;
#define domain 1000



//Declaration of functions
vector<double> x(double starting_point, double ending_point); //domain
vector<double> sin_func(vector<double> x); //sin
vector<double> cos_func(vector<double> x); //cos
vector<double> tg_func(vector<double> x); //tg
vector<double> sinh_func(vector<double> x); //sin hyperbolic
vector<double> cosh_func(vector<double> x); //cos hyperbolic
vector<double> tgh_func(vector<double> x); //tg hyperbolic
vector<double> exp_func(vector<double> x); //exponential
vector<double> ln_func(vector<double> x); //natural logarithm
vector<double> div_func(vector<double> x); //    1/x
vector<double> square_func(vector<double> x);  // x^2
vector<double> square_root(vector<double> x); // sqrt(x)






//Main
int main()
{
    vector<double> x(3);
    x = {1,2,3};
    cout << "x" << x(x) << "sin" << sin_func(x);
    
    
    return 0;
}


//Definition of functions
vector<double> x(double starting_point, double ending_point)
{
    vector<double> x(domain);
    double step = ((ending_point - starting_point) / domain;)
    for(int i=0; i<domain; ++i)
    {
        x[i] = step*(i+1);
    }
    
    return x;
}

vector<double> div_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i = 0; i < x.size(); i++)
    {
        y[i] = 1/x[i];
    }
    return y;
}

vector<double> square_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i = 0; i < x.size(); i++)
    {
        y[i] = x[i]*x[i];
    }
    return y;
}

vector<double> square_root(vector<double> x)
{
    vector<double> y(x.size());
    for(int i = 0; i < x.size(); i++)
    {
        y[i] = sqrt(x[i]);
    }
    return y;
}

vector<double> div_x(vector<double> x)
{
    vector<double> y(x.size());
    for(int i = 0; i < x.size(); i++)
    {
        y[i] = 1/x[i];
    }
    return y;
}


vector<double> sin_func(vector<double> x, int n)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = sin( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> cos_func(vector<double> x, int n)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = cos( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> tg_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = tan( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> sinh_func(vector<double> x, int n)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = sinh( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> cosh_func(vector<double> x, int n)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = cosh( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> tgh_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = tanh( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> exp_func(vector<double x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = exp( x[i] );
    }
    return y;
}

vector<double> ln_func(vector<double x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = log( x[i] );
    }
    return y;
}








/*
 
 git add .
 got commit -m "message"
 git push
 
 */
