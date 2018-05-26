// To see what an uncaught exception error looks like, run a small program that uses error() without catching any
// exceptions.
#include "std_lib_facilities.h"

int main() {
    double d = 0;
    cin >> d;
    if (!cin)
        error("Не могу считать число double"
              " в 'main()'");
}