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

double f(double x, double y, double z){
    double a = 1;
    double b = 1.5;
    double c = 2;
    double v = (pow(x/a,2) + pow(y/b,2) + pow(z/c,2)) - 1;
    return v;
}

double monte_carlo_volume(double (*fn)(double,double,double),double a,double b,double c,int N){
    float counter = 0;
    double arrX[N][3];
    ofstream outfile;
        outfile.open("monte_carlo_ellipsoid.csv");
    for(int i = 0;i<N;i++){
        double p = -a + (float(rand())/float(RAND_MAX))*2*a;
        double q = -b + (float(rand())/float(RAND_MAX))*2*b;
        double r = -c + (float(rand())/float(RAND_MAX))*2*c;
        arrX[i][0] = p;
        arrX[i][1] = q;
        arrX[i][2] = r;
        double f = (*fn)(p,q,r);
        if(f < 0){
            outfile<< arrX[i][0] << "," << arrX[i][1] << "," << arrX[i][2]<<  endl;
            counter++;
        }
    }
    outfile.close();
    double x = counter/N;
    double V = x*a*b*c*8;

    return V;
}

int main(){
    int N  = 100;
    double arrV[23];
    double arrE[23];
    double E;
    ofstream outfile;
    outfile.open("monte_carlo_volume.csv") ;
    cout << "N" << "   " << "Vol.   " << "Errors" << endl;
    outfile << "N" << "," << "Vol." << "," << "Errors" << endl;
    for(int i = 0;i<23;i++){
        arrV[i] = monte_carlo_volume(f,1,1.5,2,N);
        E = abs(arrV[i] - 12.5286)/arrV[i];
        arrE[i] = E;
        cout << N << " " << arrV[i] << " " << arrE[i] << endl;
        outfile<< N << "," << arrV[i] << "," << arrE[i] <<  endl;
        if(i<2)N = N + 500;
        else N = N + 2000;
    }
    outfile.close();
    cout << "The analytical volume is 12.5286." << endl;
    return 0;
    //RESULT: The analytical volume is 12.5286.
    /*
    N   Vol.   Errors
    100 12.96 0.033287
    600 12.84 0.0242523
    1100 12.9382 0.0316568
    3100 12.6658 0.0108328
    5100 12.4706 0.00465189
    7100 12.818 0.0225798
    9100 12.7095 0.0142296
    11100 12.6011 0.00575197
    13100 12.6577 0.0102001
    15100 12.7566 0.0178697
    17100 12.5684 0.00316834
    19100 12.6534 0.00986321
    21100 12.5778 0.00391323
    23100 12.4696 0.00473067
    25100 12.5422 0.00108047
    27100 12.6164 0.00695792
    29100 12.5641 0.00282739
    31100 12.5741 0.00362235
    33100 12.5634 0.00276866
    35100 12.5785 0.00396404
    37100 12.5913 0.00497701
    39100 12.4597 0.00552626
    41100 12.5279 5.72154e-005
    */
}


