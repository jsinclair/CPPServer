#include <iostream>
using namespace std;

#include "HelloClass.h"

int main(int argc, char **argv)
{
	/*printf("hello world\n");
    
    HelloClass *testHello = new HelloClass(5);
    testHello->countToTarget();
    delete testHello;
    
    HelloClass dynam(10);
    dynam.countToTarget();*/
    
    HelloClass dynam(10);
    
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>Hello World - First CGI Program</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<h2>Hello World! This is my first CGI program</h2>\n";
    cout << "<p>";
    
    dynam.countToTarget();
    
    cout << "</p>";
    cout << "</body>\n";
    cout << "</html>\n";
    
	return 0;
}
