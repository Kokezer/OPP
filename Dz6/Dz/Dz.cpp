#include <iostream>

using namespace std;

template<typename T> 

void calc(T n, char c, T m) 
{
    
    switch (c)
    {
   
    case'+':cout << n << c << m << " = " << (n + m) << endl; break;
    case'-': cout << n << c << m << " = " << (n - m) << endl; break;
    case'/': cout << n << c << m << " = " << (n / m) << endl; break;
    case'*': cout << n << c << m << " = " << (n * m) << endl; break;
    default: cout << "Wrong" << endl;
    }
}
int main() 
{
    
    char a;
    int c, b;
    cout << " 1st number: \n";
    cin >> c;
    cout << " + | - | * | /  \n";
    cin >> a;
    cout << " 2st number:\n";
    cin >> b;
    calc(c, a, b);

    return 0;
}