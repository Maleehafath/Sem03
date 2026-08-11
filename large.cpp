#include<iostream>
using namespace std;
template <class T>
T large(T n1,T n2)
{
    return(n1>n2)?n1:n2;
}
int main()
{
    std::cout<<large<int>(1,2)<<endl;
    std::cout<<large<char>('0','1')<<endl;
    return 0;
}