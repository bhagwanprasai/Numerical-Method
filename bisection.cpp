#include <iostream>
#include <cmath>
#define f(x) ((x) * (x) - 3 * (x) + 2) // Ensure proper use of parentheses
#define e 0.0001
using namespace std;

int main() {
    float x1, x2, xm, f1, f2, fm;
    
    do {
        cout << "Enter the initial guesses (x1 and x2): ";
        cin >> x1 >> x2;
        f1 = f(x1);
        f2 = f(x2);
        
        if (f1 * f2 > 0) {
            cout << "Invalid guesses. The function values at x1 and x2 must have opposite signs." << endl;
        }
    } while (f1 * f2 > 0);

    do {
        xm = (x1 + x2) / 2;
        fm = f(xm);
        
        if (f1 * fm < 0) {
            x2 = xm;
            f2 = fm; // Update f2
        } else {
            x1 = xm;
            f1 = fm; // Update f1
        }
    } while (fabs(x2 - x1) > e);

    cout << "The root is: " << xm << endl;
    return 0;
}
