#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define INF INT_MAX  


int printSolution(int p[], int n, std::vector<string> words);
 
void solveWordWrap(int* l, int n, int M, std::vector<string> words)
{
     
    int** extras = (int**)calloc(sizeof(int*), n + 1);

    

    
    int** lc = (int**)calloc(sizeof(int*), n + 1);

    for (int i = 0; i < n + 1; i++) {
        extras[i] = (int*)calloc(sizeof(int), n + 1);
        lc[i] = (int*)calloc(sizeof(int), n + 1);
    }

    
    int* c = (int*)calloc(sizeof(int), n + 1);

    // p[] is used to print the solution.  
    int* p = (int*)calloc(sizeof(int), n + 1);

    int i, j;

     
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i - 1];
        for (j = i + 1; j <= n; j++)
            extras[i][j] = extras[i][j - 1] - l[j - 1] - 1;
    }

    
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)//too many words to fit in 
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;//last line does not count
            else
                lc[i][j] = extras[i][j] * extras[i][j] * extras[i][j];//cube for cost 
        }
    }

     
    c[0] = 0;//base case
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i - 1] != INF && lc[i][j] != INF &&
                (c[i - 1] + lc[i][j] < c[j]))
            {
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }

    printSolution(p, n, words);
}

int printSolution(int p[], int n, std::vector<string> words)
{   
    int i = p[n];
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution(p, i - 1, words) + 1;

    for (int m = (i - 1); m < n; m++)
        cout << words[m] << " ";

    cout << endl;
   
    return k;//line number k
}
