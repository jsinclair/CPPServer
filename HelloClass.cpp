#include "HelloClass.h"

#include <stdio.h>

HelloClass::HelloClass(int target)
{
    this->target = target;
}

HelloClass::~HelloClass()
{
}

void HelloClass::countToTarget() {
    printf("Counting to %d\n", target);
    for (int i = 1; i <= target; i++) {
        printf("%d\n", i);
    }
}
