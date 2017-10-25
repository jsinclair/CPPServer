#include <iostream>
#include <fstream>
#include <cstring> // for std::strlen
#include <cstddef> // for std::size_t -> is a typedef on an unsinged int

// CGI includes
#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  

// MySQL includes
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

// JagPDF include
#include <jagpdf/api.h>

#include "HelloClass.h"

/** 
 * Build command:
 * g++ -Wall -I/usr/include/cppconn -o hello.cgi main.cpp HelloClass.cpp -lcgicc -L/usr/lib -lmysqlcppconn
 */

using namespace std;
using namespace cgicc;
using namespace jag;

int main(int argc, char **argv)
{
    pdf::Document doc(pdf::create_file("./public/hello.pdf"));
    pdf::Image img = doc.image_load_file("/opt/homevaluation/nodejs/public/valuation/res/Pools/80000.jpg");
    doc.page_start(597.6, 848.68);
    doc.page().canvas().text(50, 800, "Hello, world!");
    doc.page().canvas().image(Image, 20, 20);
    doc.page_end();
    doc.finalize();
//    return 0;

    
    Cgicc formData;
    
	/*printf("hello world\n");
    
    HelloClass *testHello = new HelloClass(5);
    testHello->countToTarget();
    delete testHello;
    
    HelloClass dynam(10);
    dynam.countToTarget();*/
    
    form_iterator fi = formData.getElement("valuation");  
	
    /*if( !fi->isEmpty() && fi != (*formData).end()) {
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
    }*/
    
    if( !fi->isEmpty() && fi != (*formData).end()) {
        cout << "Content-type:text/html\r\n\r\n";
        cout << "<html>\n";
        cout << "<head>\n";
        cout << "<title>Hello CGI</title>\n";
        cout << "</head>\n";
        cout << "<body>\n";
        cout << "<h2>Stuff.</h2>\n";
        cout << "Valuation ID: " << **fi << "<br/>";
        try {
            sql::Driver *driver;
            sql::Connection *con;
            sql::Statement *stmt;
            sql::ResultSet *res;

            /* Create a connection */
            driver = get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
            /* Connect to the MySQL test database */
            con->setSchema("house_val_db");
            
            stmt = con->createStatement();
            res = stmt->executeQuery("select id, FirstNames, Surname from homeowner");
            cout << "\t... MySQL replies: <br/>";
            while (res->next()) {
                /* Access column data by alias or column name */
                cout << res->getString("id") << ": " << res->getString("FirstNames") << " " << res->getString("Surname") << "<br/>";
                
                /* Access column data by numeric offset, 1 is the first column */
                //cout << res->getString(1) << endl;
            }
            delete res;
            delete stmt;
            delete con;
        
        } catch (sql::SQLException &e) {
            cout << "# ERR: SQLException in " << __FILE__;
            cout << "(" << __FUNCTION__ << ") on line ";
            cout << __LINE__ << "\n";
            cout << "# ERR: " << e.what();
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )\n";
        }
        
        cout << "</body>\n";
        cout << "</html>\n";
    } else {
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
