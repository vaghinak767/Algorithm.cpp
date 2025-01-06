// կենտ չափանի մատրիցների պահը պիտի նօրից նայվի
#include <iostream>

int **add_mat(int **arr1, int **arr2, int col1, int col2, int n)
{
    int **res = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        res[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res[i][j] = arr1[i][j + col1] + arr2[i][j + col2];
        }
    }
    return res;
}

int **sub_mat(int **arr1, int **arr2, int col1, int col2, int n)
{
    int **res = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        res[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res[i][j] = arr1[i][j + col1] - arr2[i][j + col2];
        }
    }
    return res;
}

int **Strassens(int **arr1, int **arr2, int col1, int col2, int n)
{
    int **C = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        C[i] = new int[n];
    }
    if (n == 1)
    {
        C[0][0] = arr1[0][col1] * arr2[0][col2];
    }
    else
    {
        int **S1 = sub_mat(arr2, arr2 + n / 2, col2 + n / 2, col2 + n / 2, n / 2);
        int **S2 = add_mat(arr1, arr1, col1, col1 + n / 2, n / 2);
        int **S3 = add_mat(arr1 + n / 2, arr1 + n / 2, col1, col1 + n / 2, n / 2);
        int **S4 = sub_mat(arr2 + n / 2, arr2, col2, col2, n / 2);
        int **S5 = add_mat(arr1, arr1 + n / 2, col1, col1 + n / 2, n / 2);
        int **S6 = add_mat(arr2, arr2 + n / 2, col2, col2 + n / 2, n / 2);
        int **S7 = sub_mat(arr1, arr1 + n / 2, col1 + n / 2, col1 + n / 2, n / 2);
        int **S8 = add_mat(arr2 + n / 2, arr2 + n / 2, col2, col2 + n / 2, n / 2);
        int **S9 = sub_mat(arr1, arr1 + n / 2, col1, col1, n / 2);
        int **S10 = add_mat(arr2, arr2, col2, col2 + n / 2, n / 2);
        int **P1 = Strassens(arr1, S1, col1, 0, n / 2);
        int **P2 = Strassens(S2, arr2 + n / 2, 0, col2 + n / 2, n / 2);
        int **P3 = Strassens(S3, arr2, 0, col2, n / 2);
        int **P4 = Strassens(arr1 + n / 2, S4, col1 + n / 2, 0, n / 2);
        int **P5 = Strassens(S5, S6, 0, 0, n / 2);
        int **P6 = Strassens(S7, S8, 0, 0, n / 2);
        int **P7 = Strassens(S9, S10, 0, 0, n / 2);
        for (int i = 0; i < n / 2; i++)
        {
            delete[] S1[i];
            delete[] S2[i];
            delete[] S3[i];
            delete[] S4[i];
            delete[] S5[i];
            delete[] S6[i];
            delete[] S7[i];
            delete[] S8[i];
            delete[] S9[i];
            delete[] S10[i];
        }
        delete[] S1;
        delete[] S2;
        delete[] S3;
        delete[] S4;
        delete[] S5;
        delete[] S6;
        delete[] S7;
        delete[] S8;
        delete[] S9;
        delete[] S10;
        int **C111 = add_mat(P5, P4, 0, 0, n / 2);
        int **C211 = add_mat(C111, P6, 0, 0, n / 2);
        int **C122 = add_mat(P5, P1, 0, 0, n / 2);
        int **C222 = add_mat(P3, P7, 0, 0, n / 2);
        int **C11 = sub_mat(C211, P2, 0, 0, n / 2);
        int **C12 = add_mat(P1, P2, 0, 0, n / 2);
        int **C21 = add_mat(P3, P4, 0, 0, n / 2);
        int **C22 = sub_mat(C122, C222, 0, 0, n / 2);
        for (int i = 0; i < n / 2; i++)
        {
            delete[] P1[i];
            delete[] P2[i];
            delete[] P3[i];
            delete[] P4[i];
            delete[] P5[i];
            delete[] P6[i];
            delete[] P7[i];
            delete[] C111[i];
            delete[] C211[i];
            delete[] C122[i];
            delete[] C222[i];
        }
        delete[] P1;
        delete[] P2;
        delete[] P3;
        delete[] P4;
        delete[] P5;
        delete[] P6;
        delete[] P7;
        delete[] C111;
        delete[] C211;
        delete[] C122;
        delete[] C222;
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                C[i][j] = C11[i][j];
                C[i][j + n / 2] = C12[i][j];
                C[i + n / 2][j] = C21[i][j];
                C[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            delete[] C11[i];
            delete[] C12[i];
            delete[] C21[i];
            delete[] C22[i];
        }
        delete[] C11;
        delete[] C12;
        delete[] C21;
        delete[] C22;
    }
    return C;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int **arr1 = new int *[n];
    int **arr2 = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        arr1[i] = new int[n];
        arr2[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> arr2[i][j];
        }
    }
    int **res = Strassens(arr1, arr2, 0, 0, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] arr1[i];
        delete[] arr2[i];
        delete[] res[i];
    }
    delete[] arr1;
    delete[] arr2;
    delete[] res;
}
