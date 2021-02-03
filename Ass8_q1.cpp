#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Library.cpp"
using namespace std;

void random_walk(double*x, double*y, double* r){
    //starting point
    double X = *x;
    double Y = *y;
    double R = *r;
    //generate a random angle
        R = sqrt(pow(X,2) + pow(Y,2));
        double a = (float(rand())/float(RAND_MAX))*2*3.141592;
        X = X + cos(a);
        Y =  Y + sin(a);
    *x = X;
    *y = Y;
    *r = R;
}

int main(){
    ofstream outfile;
        outfile.open("r_w.csv");
    int N = 250; //for 250 steps(similar will run for any value of N)
    ofstream outfile1;
        outfile1.open("RW_250.csv");
    double arrW[N][3];
    //100 times for any step number(250)
    for(int i = 0;i<100;i++){
        double x = 0;
        double y = 0;
        double r = 0;
        //random walk for N steps
        for(int j = 0;j<N;j++){
            random_walk(&x, &y, &r);
            arrW[j][0] = x;
            arrW[j][1] = y;
            arrW[j][2] = r;
            //output all the values of x,y and r after each step in a RW
            outfile << arrW[j][0] << "," <<  arrW[j][1] << "," << arrW[j][2] << endl;
        }
        //output final value of x, y and r after each RW of N steps
        outfile1 << i+1 << "," << x << "," << y << "," << r << "," << pow(r,2) << endl;
    }
    outfile.close();
    outfile1.close();
    return 0;
}
