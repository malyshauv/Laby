#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double x, res = 0.0, x0 = 1.0;
    int k, c, n = 0;
    cout << "vvedite x ";
    cin >> x;
    cout << endl;
    cout << "vvedite k ";
    cin >> k;
    cout << "vvedite kol-vo cifr posle zapyatoj ";
    cin >> c;
    cout << endl;
    double e = pow(10,-k);
    while(abs(x0) > e){
        res+=x0;
        n++;
        x0 = pow(-1, n) * (n + 1) * (n + 2) / 2.0 * pow(x, n);
    }
    double RES = 1.0 / pow(x + 1, 3);
    cout << fixed << setprecision(c);
    cout << "pogreshnoct = " << abs(RES - res);
    return 0;
}
