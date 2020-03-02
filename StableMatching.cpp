#include <iostream>
#include <string.h>
#include <stdio.h>

/*
Nama 		: Sarah Navianti 
NPM  		: 140810180021
Kelas 		: A
Deskripsi 	: Stable Matching Problem 
 */
 

using namespace std;
#define N 5 // Sebagai arahan bahwa ada 5 nilai dan mengarahkan pasangannya 

bool pilihMen(int prioritas[2 * N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prioritas[w][i] == m1)
            return true;

        if (prioritas[w][i] == m)
            return false;
    }
} 
void Matching(int prioritas[2 * N][N]) //Matching adalah untuk pencocokan nya 
{
    int pasanganCew[N];

    bool priaSingle[N];

    memset(pasanganCew, -1, sizeof(pasanganCew));
    memset(priaSingle, false, sizeof(priaSingle));
    int jumlahSingle = N;

    while (jumlahSingle > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (priaSingle[m] == false)
                break;

        for (int i = 0; i < N && priaSingle[m] == false; i++)
        {
            int w = prioritas[m][i];

            if (pasanganCew[w - N] == -1)
            {
                pasanganCew[w - N] = m;
                priaSingle[m] = true;
                jumlahSingle--;
            }

            else
            {
                int m1 = pasanganCew[w - N];

                if (pilihMen(prioritas, w, m, m1) == false)
                {
                    pasanganCew[w - N] = m;
                    priaSingle[m] = true;
                    priaSingle[m1] = false;
                }
            } 
        }
    }
    cout << "PILIHAN PASANGAN" << endl;
    cout << "=================" << endl;
    cout << "  Man     Women  " << endl;
    cout << "=================" << endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++)
    {
        if (i < N)
        {
            if (pasanganCew[i] == 0)
                man = "Victor";
            if (pasanganCew[i] == 1)
                man = "Wyatt";
            if (pasanganCew[i] == 2)
                man = "Xavier";
            if (pasanganCew[i] == 3)
                man = "Yancey";
            if (pasanganCew[i] == 4)
                man = "Zeus";
                
            if (i == 0)
                woman = "Amy";
            if (i == 1)
                woman = "Bertha";
            if (i == 2)
                woman = "Clare";
            if (i == 3)
                woman = "Diane";
            if (i == 4)
                woman = "Erika";
        }
        cout << " " << man << "\t  " << woman << endl;
    }
}

int main()
{
    int prioritas[2 * N][N] = {{6, 5, 8, 9, 7},
                            {8, 6, 5, 7, 9},
                            {6, 9, 7, 8, 5},
                            {5, 8, 7, 6, 9},
                            {6, 8, 5, 9, 7},
                            {4, 0, 1, 3, 2},
                            {2, 1, 3, 0, 4},
                            {1, 2, 3, 4, 0},
                            {0, 4, 3, 2, 1},
                            {3, 1, 4, 2, 0}};
    Matching(prioritas);

    return 0;
}
 
