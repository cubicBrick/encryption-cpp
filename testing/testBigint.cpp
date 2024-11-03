#include "../utility/bigint/main.h"
#include <iostream>
using namespace std;
using namespace utility;

int main(void){
    LL a, b;
    cin >> a >> b;
    LL ans = 0;
    (bigint(a) + bigint(b)).toLL(ans);
    cout << ans;
}