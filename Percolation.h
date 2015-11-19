#ifndef PERCOLATION_H
#define PERCOLATION_H
#include <vector>
using namespace std;

class Percolation {
private:
public:
    Percolation(int);              // create N-by-N grid, with all sites blocked
    void open(int, int);         // open site (row i, col j) if it is not already
    bool isOpen(int, int);    // is site (row i, col j) open?
    bool isFull(int, int);    // is site (row i, col j) full?
    bool percolates();            // does the system percolate?

    vector<vector<int> > grid; // initial declaration of the grid
    int ptr[];

    void showGrid(int);
    int findRoot(int);
};

#endif // PERCOLATION_H
