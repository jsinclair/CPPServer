#include <stdio.h>

#include "HelloClass.h"

int main(int argc, char **argv)
{
	printf("hello world\n");
    
    HelloClass *testHello = new HelloClass(5);
    testHello->countToTarget();
    delete testHello;
    
    HelloClass dynam(10);
    dynam.countToTarget();
    
	return 0;
}
