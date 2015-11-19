#include "percolation.h"
#include <vector>
#include <iostream>

using std::vector;

//Percolation(int);              // create N-by-N grid, with all sites blocked
//    void open(int, int);         // open site (row i, col j) if it is not already
//    bool isOpen(int, int);    // is site (row i, col j) open?
//    bool isFull(int, int);    // is site (row i, col j) full?
//    bool percolates();            // does the system percolate?

Percolation::Percolation(int n) { // create N-by-N grid, with all sites blocked
    //vector<vector<int> > grid;
    grid.resize(n);

    for (int i=0; i<n; ++i)
    {
        grid[i].resize(n);
    }

    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j) {
            grid[i][j] = 0; // all sites set to blocked
        }
    }
} // done?

void Percolation::open(int i, int j) { // open site (row i, col j) if it is not already
    if (grid[i][j] == 0) {
        grid[i][j] = 1;
    }
} // works!

bool Percolation::isOpen(int i,int j) {
    if (grid[i][j] == 1)
        return true;
    else
        return false;
} // works!

void Percolation::showGrid(int n) { // for debugging
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j) {
            std::cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int Percolation::findRoot(int i) {

}
