#include <iostream>
#include <stdlib.h>

using namespace std;

//void percolation(int);
//void open(int,int);
//bool isOpen(int,int);
//bool isFull (int,int);
//bool percolates();

/*
    From terminal, program must accept:
    p = percolation probability
    n = number of runs
    s = size of board
    test.txt = a saved board state that must be read in and populate a board in memory
*/


// class WeightedQuickUnionUF {
// private:
//     int * parent;
//     int * size;
//     int count;

//     void validate(int p) {
//     }

// public:
//     WeightedQuickUnionUF(); {

//     }
//     WeightedQuickUnionUF(int n) {
//         count = n;
//         parent = new int[n];
//         size = new int[n];
//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     };


//     int getCount() {
//         return count;
//     }
//     int find(int p) {
//         validate(p);
//         while (p != parent[p]) {
//             p = parent[p];
//             }
//         return p;
//     }
//     bool connected(int p, int q) {
//         return find(p) == find(q);
//     }

// 

class UF {
  int *id, cnt, *sz;
  public:
// Create an empty union find data structure with N isolated sets.
UF() {
    id = 0;
    cnt = 0;
    sz = 0;
}

UF(int N) {
    cnt = N; id = new int[N]; sz = new int[N];
    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
~UF() { delete[] id; delete[] sz; }

// Return the id of component corresponding to object p.
int find(int p) {
    int root = p;
    while (root != id[root])    root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
    return root;
}
// Replace sets containing x and y with their union.
void merge(int x, int y) {
    int i = find(x); int j = find(y); if (i == j) return;
    // make smaller root point to larger one
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    cnt--;
}
// Are objects x and y in the same set?
bool connected(int x, int y) { return find(x) == find(y); }
// Return the number of disjoint sets.
int count() { return cnt; }
};

class Percolation {
private:
    int * states; // rather than int states[]
    int side;
    //WeightedQuickUnionUF cellStorage;
    UF* cellStorage;

    void checkRange(int,int);
    void onion(int,int);
    int getCellIndex(int,int);
public:
    Percolation() {
        side = 0;
        states[0] = 0;
    }
    Percolation(int n) {
        side = n;
        int temp = n * n + 2;
        //cellStorage = new WeightedQuickUnionUF(temp); // watch the effects of +2 here, may not be needed
        cellStorage = new UF(temp);
        states = new int[n*n+2];
        for (int i=0; i < n*n; i++) {
            states[i] = 0; // set this site to 0, blocked
        }
    };
    void open(int,int);
    bool isOpen(int,int);
    bool isFull(int,int);
    bool percolates();
};


int main(int argc, char *argv[]) {
    double p;
    int n,s;

    if (argc == 3)
    {
        p = atof(argv[0]);
        n = atoi(argv[1]);
        s = atoi(argv[2]);
    }
    //cout << p << " " << n << " " << s << endl;

    return 0;
}

