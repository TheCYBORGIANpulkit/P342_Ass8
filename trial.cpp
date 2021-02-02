#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "Library.cpp"
using namespace std;

double f(float x){
    double y = pow(x,2);
    return exp(-y);
}

double f2(float x){
    double y = pow(x,2);
    return (-2)*(exp(-y))*(1 - 2*y);
}

int Counter_Midpointer(float a,float b, int N){
    float e = pow(b - a,3);
    float g = abs(f2(1));
    for(int i =0;i<1000;i++){
        float f = 24*(pow(N,2));
        float h = e/f;
        if(((e/f)*g) > 0.001){
            N = N + 1;
        }
        else return N;
    }
}

int main(){
    cout << f(0) << endl;
    int N = Counter_Midpointer(0,1,1);
    cout << N << endl;
    cout << "Integration for counter N = " << Midpoint(f,0,1.0,N) << endl;
    /*
    int M = Counter_Trapezoidal(0,1,1);
    cout << "Integration for counter = " << M << Trapezoidal(f,0,1.0,M) << endl;
    int P = Counter_Simpsons(0,1,1);
    cout <<"Integration for counter = " << P << Simpsons(f,0,1.0,P) << endl;
    */
    return 0;

}
