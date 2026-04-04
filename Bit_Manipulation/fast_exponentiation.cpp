#include <iostream>
using namespace std;
int fast(int x, int num)
{
    int ans = 1;
    while (num > 0)
    {
        int lastdig = num & 1;
        if (lastdig)
        {
            ans = ans * x;
        }
        x = x * x;
        num = num >> 1;
    }
    return ans;
}
int main(){
    int x = 5;
    int num = 6;
    cout << fast(num, x) << endl;
}