#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

using namespace std;

int n, xs[100], ys[100], tempXaxis, tempYaxis, i;

void draw()
{
    for(i=0; i<n; i++)
        line(xs[i], ys[i], xs[(i+1)%n], ys[(i+1)%n]);
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
