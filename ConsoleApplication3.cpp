/*
 this is for 3 * 3 matrix, if you can find another better case, please tell me.
    thanks for sending me the Gauss algorithm.
    Jonathan Bronstein.
*/

#include<iostream>
using namespace std;
int a[3][3];
void input() {
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            cin >> a[i][j];
        }
    }
}


int creating_sub_matrix(int i_avoid, int j_avoid) {
    int index[4];
    int slots = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != i_avoid) {
            for (int j = 0; j <= 2; j++) {
                if (j != j_avoid) {
                    index[slots] = a[i][j];
                    slots++;
                }
                else continue;
            }
        }
        else continue;
    }
    return index[0] * index[3] - index[1] * index[2];
}
int posorneg(int i, int j) {
    if ((i + j) % 2 == 0) {
        return 1;
    }
    else { return -1; }
}
int main() {
    input();
    cout << a[0][0] * creating_sub_matrix(0, 0) * posorneg(0, 0) + a[0][1]*creating_sub_matrix(0, 1) * posorneg(0, 1) + a[0][2] * creating_sub_matrix(0, 2) * posorneg(0, 2);
}

