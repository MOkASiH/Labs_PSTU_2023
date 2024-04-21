#pragma once
#include<iostream>
#include<fstream>

using namespace std;

int ta;

void write_arr(int a[], int c) {
    ofstream M("M.txt");
    for (int i = 0; i < n; i++) {
        M << a[i] << " ";
    }
}

void Merge(int c[], int d[], int l, int m, int r)
{ 

    int i = l, j = m + 1, k = r;

    while ((i <= m) && (j <= r))
    {
        if (c[i] <= c[j])
            d[l++] = c[i++];
        else
            d[l++] = c[j++];
    }
    if (i > m)
        for (int q = j; q <= r; q++)  
            d[l++] = c[q];
    else
        for (int p = i; p <= m; p++)
            d[l++] = c[p];
}

void MergePass(int x[], int y[], int s, int n, int* t)
{
    int i = 0;
    while (i <= ta - 2 * s)
    {
        int r = ((i + 2 * s) < ta) ? t[i + 2 * s] : n;

        Merge(x, y, t[i], t[i + s] - 1, r - 1);
        i = i + 2 * s;
    }
    if (i + s < ta) 
        Merge(x, y, t[i], t[i + s] - 1, n - 1);
    else  if (i < ta)
    {
        for (int j = t[i]; j <= n - 1; j++)
            y[j] = x[j];
    }
}

void MergeSort(int a[], int n, int* t)
{
    int* b = new int[n];
    int s = 1;
    while (s < ta)
    {
        MergePass(a, b, s, n, t);  
        s += s; 
        MergePass(b, a, s, n, t); 
        s += s;
    }
    write_arr(a, n);
}


void GetBPoint(int a[], int b[], int n, int& m)
{
    int j = 0;
    b[j++] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            b[j++] = i + 1; 
    }
    m = j; 
}
