#include <iostream>

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  

#include "HelloClass.h"

using namespace std;

int main(int argc, char **argv)
{
    Cgicc formData;
    
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
    
    form_iterator fi = formData.getElement("valuation");  
	
    if( !fi->isEmpty() && fi != (*formData).end()) {  
        cout << "Valuation ID: " << **fi << endl;  
    }else{
        cout << "No text entered for valuation" << endl;  
    }
    
    cout << "</body>\n";
    cout << "</html>\n";
    
	return 0;
}
