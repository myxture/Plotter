//C++ includes
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace  std;

/*Roland voltam és ide írok magamnak egy kis noteot: x legyártás, 1000 beosztással, 2 param kezdő vég, function.h nev tipusok*/

//Declaration of functions
vector<double> sin_func(vector<double> x);
vector<double> cos_func(vector<double> x);
vector<double> tg_func(vector<double> x);


//Main
int main()
{
    
    
    
    
    
    return 0;
}


//Definition of functions
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







/*
 
 git add .
 got commit -m "message"
 git push
 
 */
