#include <iostream>
#define SIZE 10
using namespace std;

class Optimal {
private:
    int p[SIZE];
    int q[SIZE];
    int a[SIZE];
    int w[SIZE][SIZE];
    int c[SIZE][SIZE];
    int r[SIZE][SIZE];
    int n;
    int front, rear, queue[20];

public:
    Optimal() {
        front = rear = -1;
    }

    void get_data() {
        int i;
        cout << "\nOptimal Binary Search Tree\n";
        cout << "\nEnter the number of nodes: ";
        cin >> n;
        cout << "\nEnter the data as ...\n";
        for (i = 1; i <= n; i++) {
            cout << "a[" << i << "]: ";
            cin >> a[i];
        }
        cout << "\nEnter probabilities for successful search ...\n";
        for (i = 1; i <= n; i++) {
            cout << "p[" << i << "]: ";
            cin >> p[i];
        }
        cout << "\nEnter probabilities for unsuccessful search ...\n";
        for (i = 0; i <= n; i++) {
            cout << "q[" << i << "]: ";
            cin >> q[i];
        }
    }

    int Min_Value(int i, int j) {
        int m, k;
        int minimum = 32000;
        for (m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
            if ((c[i][m - 1] + c[m][j]) < minimum) {
                minimum = c[i][m - 1] + c[m][j];
                k = m;
            }
        }
        return k;
    }

    void OBST() {
        int i, j, k, m;
        for (i = 0; i < n; i++) {
            w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n] = 0;
        for (m = 2; m <= n; m++) {
            for (i = 0; i <= n - m; i++) {
                j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                k = Min_Value(i, j);
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }
    }

    void build_tree() {
        int i, j, k;
        cout << "\nThe Optimal Binary Search Tree For The Given Nodes Is...\n";
        cout << "\nThe Root of this OBST is: " << r[0][n];
        cout << "\nThe Cost Of this OBST is: " << c[0][n];
        cout << "\n\n\tNODE\tLEFT CHILD\tRIGHT CHILD\n";
        front = rear = -1;
        queue[++rear] = 0;
        queue[++rear] = n;
        while (front != rear) {
            i = queue[++front];
            j = queue[++front];
            k = r[i][j];
            cout << "\t" << k;
            if (r[i][k - 1] != 0) {
                queue[++rear] = i;
                queue[++rear] = k - 1;
                cout << "\t\t" << r[i][k - 1];
            } else {
                cout << "\t\t-";
            }
            if (r[k][j] != 0) {
                queue[++rear] = k;
                queue[++rear] = j;
                cout << "\t\t" << r[k][j];
            } else {
                cout << "\t\t-";
            }
            cout << endl;
        }
    }
};

int main() {
    Optimal obj;
    obj.get_data();
    obj.OBST();
    obj.build_tree();

    return 0;
}

// Optimal Binary Search Tree
// Enter the number of nodes 4
// Enter the data as ....
// a[1]: 1
// a[2] : 2
// a[3]: 3
// a[4]: 4
// Enter probabilites for successful search ...
// p[1]: 3
// p[2] : 3
// p[3]: 1
// p[4): 1
// Enter probabilites for unsuccessful search...
// q[0] : 2
// q[1]: 3
// q[2] : 1
// q[3]: 1
// q[4]: 1
// The Optimal Binary Search Tree For The Given Nodes Is....
// The Root of this OBST is :: 2
// The Cost Of this OBST is :: 32
// NODE LEFT CHILD RIGHT CHILD
// 1
// 3
// Output
// 4
