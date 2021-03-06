#include <iostream>
#include <fstream>
#include <cstring> // for std::strlen
#include <cstddef> // for std::size_t -> is a typedef on an unsinged int

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  

#include "HelloClass.h"

using namespace std;
using namespace cgicc;

int main(int argc, char **argv)
{
    Cgicc formData;
    
	/*printf("hello world\n");
    
    HelloClass *testHello = new HelloClass(5);
    testHello->countToTarget();
    delete testHello;
    
    HelloClass dynam(10);
    dynam.countToTarget();*/
    
    form_iterator fi = formData.getElement("valuation");  
	
    if( !fi->isEmpty() && fi != (*formData).end()) {
        ifstream file("content/Valuation.pdf");
        
        if(file.is_open()) {
            cout << "Content-Type:application/pdf\n";
            cout << "Content-Type:application/force-download\n";
            //cout << "Content-Type:application/octet-stream\n";
            cout << "Content-Description: File Transfer\n";
            cout << "Content-Disposition: attachment; filename=\"Valuation.pdf\"\n";
            
            size_t size = 0;
            file.seekg(0, ios::end); // set the pointer to the end
            size = file.tellg() ; // get the length of the file
            cout << "Content-Length: " << size << "\r\n\r\n";
            file.seekg(0, ios::beg); // set the pointer to the beginning
            
            cout << file.rdbuf();
            cout << "\r";
            file.close();
        } else {
            cout << "Content-type:text/html\r\n\r\n";
            cout << "<html>\n";
            cout << "<head>\n";
            cout << "<title>Hello CGI</title>\n";
            cout << "</head>\n";
            cout << "<body>\n";
            cout << "<h2>Couldn't open file.</h2>\n";
            cout << "<p>";
        }
        
        //cout << "Valuation ID: " << **fi << endl;  
    }else{
        cout << "Content-type:text/html\r\n\r\n";
        cout << "<html>\n";
        cout << "<head>\n";
        cout << "<title>Hello CGI</title>\n";
        cout << "</head>\n";
        cout << "<body>\n";
        cout << "<h2>Hello World!</h2>\n";
        cout << "<p>";
        
        HelloClass dynam(10);
        dynam.countToTarget();
        
        cout << "</p>";
        
        cout << "No text entered for valuation" << endl;
        
        cout << "</body>\n";
        cout << "</html>\n";
    }
    
	return 0;
}
