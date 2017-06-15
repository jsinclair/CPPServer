#include "HelloClass.h"

#include <iostream>

using namespace std;

HelloClass::HelloClass(int target)
{
    this->target = target;
}

HelloClass::~HelloClass()
{
}

void HelloClass::countToTarget() {
    cout << "Counting to " << target << "<br/>\n";
    //printf("Counting to %d\n", target);
    for (int i = 1; i <= target; i++) {
        if (i > 1) {
            cout << ", ";
        }
        cout << i;
        //printf("%d\n", i);
    }
    cout << "\n";
}
