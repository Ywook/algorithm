#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    bitset<100000> a,b;

    cin>>a>>b;

    cout<<(a&b)<<endl;
    cout<<(a|b)<<endl;
    cout<<(a^b)<<endl;
    cout<<~(a)<<endl;
    cout<<~(b)<<endl;
}