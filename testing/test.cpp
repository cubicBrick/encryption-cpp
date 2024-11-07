#include "../utility/bigint/main.h"
#include <iostream>
using namespace std;
using namespace utility;

// 9223372036854775807

int main(void){
    LL a, b;
    cin >> a >> b;
    LL ans = 0;
    cout << a << ' ' << b << '\n';
    if ((bigint(a) - bigint(b)).toLL(ans))
        cout << ans;
    else
        cout << "TOO SMALL";
    cout << "\nDONE\n";
}