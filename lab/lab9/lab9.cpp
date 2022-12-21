#include "iostream"
using namespace std;
const int n=10, col_razr=3;
int velich_razr(int num,int radix)
{
    while(radix>1)
    {
        num/=10;
        radix--;
    }
    return num%10;
}
void radixSort(int dop_mas[n][n], int mas[n], int radix)
{
    int mas_col[n], i,j, temp=0;
    for(i=0; i<n; i++)
        mas_col[i]=0;
    for(i=0; i<n; i++)
    {
        int a=velich_razr(mas[i], radix);
        dop_mas[mas_col[a]][a]=mas[i];
        mas_col[a]++;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<mas_col[i]; j++)
        {
            mas[temp]=dop_mas[j][i];
            temp++;
        }
    }
}
int main()
{
    
    int radix, i;
    int arr[n]={623, 543, 120, 935, 423, 610, 732, 126, 784, 648};
    int dop_arr[n][n];
    for(radix=1; radix<4; radix++)
        radixSort(dop_arr, arr, radix);
    for(i=0; i<n; i++)
        cout<<arr[i]<<endl;
    return 0;
}