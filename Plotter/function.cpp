//C++ includes
#define _USE_MATH_DEFINES

#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;
#define domain 1000


//Definition of functions
vector<double> xs(double starting_point, double ending_point)
{
    vector<double> x(domain);
    double step = ((ending_point - starting_point) / domain);
    for(int i=0; i<domain; ++i)
    {
        x[i] = step*(i-domain/2);
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

vector<double> sin_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = sin( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> cos_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = cos( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> tg_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = tan( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> sinh_func(vector<double> x)
{
    vector<double> y( x.size());
    for(int i=0; i< x.size(); ++i)
    {
        y[i] = sinh(  x[i] * M_PI / 180);
    }
    return y;
}

vector<double> cosh_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = cosh( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> tgh_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = tanh( x[i] * M_PI / 180);
    }
    return y;
}

vector<double> exp_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
    {
        y[i] = exp( x[i] );
    }
    return y;
}

vector<double> ln_func(vector<double> x)
{
    vector<double> y(x.size());
    for(int i=0; i<x.size(); ++i)
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
