#include "percolation.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    double p;
    int n,s;
    //int count = 0;

    if (argc == 3)
    {
      p = atof(argv[0]);
      n = atoi(argv[1]);
      s = atoi(argv[2]);
      cout << "perc probability: " << p << endl;
      cout << "number of runs: " << n << endl;
      cout << "side length: " << s << endl;
    }
    else {
        if (argc == 1) {
            string path = argv[0];
        }
        p = .5;
        n = 2;
        s = 2; // sample data.. remove before running from terminal
        cout << "=== sample data used ===" << endl;
    }

    Percolation test(s);
    test.showGrid(s);
    test.open(0,0);
    cout << endl;
    test.showGrid(s);
    if (test.isOpen(0,0)) cout << endl << "is open!" << endl;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j) {
            double r = ((double) rand() / (RAND_MAX));
            cout << "r = " << r << endl;
            if (r < p) { // this may need flipped so that r > p
                test.open(i,j);
            }
        }
    }
    test.showGrid(s);
}
