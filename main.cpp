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
        cout << "Content-Type:image/jpeg\r\n\r\n";
        cout << "Content-Type:application/download\n";
        cout << "Content-Description: File Transfer\n";
        cout << "Content-Disposition: attachment; filename=\"img.jpg\"\n";
        
        ifstream inFile;
        size_t size = 0; // here

        inFile.open( "/content/img.jpg", ios::in|ios::binary|ios::ate );
        char* oData = 0;
        
        inFile.seekg(0, ios::end); // set the pointer to the end
        size = inFile.tellg() ; // get the length of the file
        cout << "Content-Length: " << size << "\n";
        
        inFile.seekg(0, ios::beg);
        
        oData = new char[ size+1 ]; //  for the '\0'
        inFile.read( oData, size );
        oData[size] = '\0' ; // set '\0' 
        
        for ( size_t i = 0; i < strlen(oData); i++ )
        {
            /*cout << "oData["<<i<<"] " << oData[i];
            cout << "\n";
            cout << oData[i] << " + 'a' = " << ( oData[i] + 'a' );
            cout << "\n\n";*/
            cout << oData[i];
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
    }
    
    cout << "</body>\n";
    cout << "</html>\n";
    
	return 0;
}
