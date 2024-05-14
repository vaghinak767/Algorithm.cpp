#include <iostream>

int **sum(int **arr1, int **arr2, int col1, int col2, int n)
{
    int **arr = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        arr[i] = new int[n];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            arr[i][j] = arr1[i][col1 + j] + arr2[i][col2 + j];
        }
    }
    return arr;
} 

int **sub(int **arr1, int **arr2, int col1, int col2, int n)
{
    int **arr = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        arr[i] = new int[n];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            arr[i][j] = arr1[i][col1 + j] - arr2[i][col2 + j];
        }
    }
    return arr;
} 

int **Strassens(int **arr1, int **arr2, int col1, int col2, int n)
{
    if(n == 1)
    {
        int **arr = new int*;
        *arr = new int;
        **arr = **arr1 * **arr2;
        return arr;
    }
    int **s1 = sub(arr2, arr2 + n / 2, 0, n / 2, n / 2);
    int **s2 = sum(arr1, arr1, 0, n / 2, n / 2);
    int **s3 = sum(arr1 + n / 2, arr1 + n / 2, 0, n / 2, n / 2);
    int **s4 = sub(arr2 + n / 2, arr2, 0, 0, n/ 2);
    int **s5 = sum(arr1, arr1 + n / 2, 0, n / 2, n / 2);
    int **s6 = sum(arr2, arr2 + n / 2, 0, n / 2, n / 2);
    int **s7 = sub(arr1, arr1 + n / 2, n / 2, n / 2, n /2);
    int **s8 = sum(arr2 + n / 2, arr2 + n / 2, 0, n / 2, n / 2);
    int **s9 = sub(arr1, arr1 + n / 2, 0, 0, n / 2);
    int **s10 = sum(arr2, arr2, 0, n / 2, n / 2);
    int **p1 = Strassens(arr1, s1, col1, 0, n / 2);
    int **p2 = Strassens(s2, arr2 + n / 2, 0, col2 + n / 2, n / 2);
    int **p3 = Strassens(s3, arr2, 0, col2, n / 2);
    int **p4 = Strassens(arr1 + n / 2, s4, col1 + n / 2, 0, n / 2);
    int **p5 = Strassens(s5, s6, 0, 0, n / 2);
    int **p6 = Strassens(s7, s8, 0, 0, n / 2);
    int **p7 = Strassens(s9, s10, 0, 0, n / 2);
    int **c11 = sum(p1, sum(p4, sub(p6, p2, 0, 0,), 0, 0), 0, 0);
}

int main()
{

}
