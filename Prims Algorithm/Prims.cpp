#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 
using namespace std;

int minimum(int key[], bool minst[])
{
    int min = 100, minIn;

    for (int i = 0; i < 5; i++)
        if (minst[i] == false && key[i] < min)
            min = key[i], minIn = i;

    return minIn;
}

void print(int p[], int g[5][5])
{
    int totalWeight = 0;
    cout << "Edge \t\t Weight\n";
    for (int i = 1; i < 5; i++)
    {
        cout << i << " - " << p[i] << " \t\t " << g[i][p[i]] << endl;
        totalWeight += g[i][p[i]];
    }
    cout << "\nTotal weight = " << totalWeight << endl;
}

void minST(int g[5][5])
{
    int p[5];
    int key[5];
    bool minst[5];

    for (int i = 0; i < 5; i++)
        key[i] = 100, minst[i] = false;

    key[0] = 0;
    p[0] = -1;

    for (int count = 0; count < 5 - 1; count++)
    {
        int u = minimum(key, minst);

        minst[u] = true;

        for (int v = 0; v < 5; v++)
        {
            if (g[u][v] && minst[v] == false && g[u][v] < key[v])
                p[v] = u, key[v] = g[u][v];
        }
    }

    print(p, g);
}

int main()
{
    int Gr[5][5] = { { 0, 9, 5, 2, 0 },
                    { 9, 0, 0, 6, 5 },
                    { 5, 0, 0, 4, 5 },
                    { 2, 6, 4, 0, 4 },
                    { 0, 5, 5, 4, 0 } };

    minST(Gr);

    return 0;
}