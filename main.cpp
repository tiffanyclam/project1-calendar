// File: main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include "main.h"

void runTest (int test){
    switch (test){
        case 1: {
            try {
                DateTime d1 (11, 1, 50, 12, 00, "AM");
                cout << d1;
                DateTime d2 (11, 1, 50, 1, 00, "AM");
                cout << d2;
                if (d1 == d2)
                    cout << "equal" << endl;
                else
                    cout << "not equal" << endl;
                if (d1 != d2)
                    cout << "not equal" << endl;
                else
                    cout << "equal" << endl;
                if (d1 < d2)
                    cout << "less than" << endl;
                else
                    cout << "not less than" << endl;
                if (d1 > d2)
                    cout << "greater than" << endl;
                else
                    cout << "not greater than" << endl;
            }
            catch (invalid_argument &e){
                cout << "Invalid argument: " << e.what() << endl;
            }
            catch (logic_error &e){
                cout << "Logic error: " << e.what() << endl;
            }
            catch (...){
                cout << "Uncaught exception" << endl;
            }
            cout << "Finished" << endl;
            break;
        }
        case 2: {
            try {
                DateTime d1 (12, 1, 4, 4, 00, "AM");
                cout << d1;
                DateTime d2 (11, 1, 50, 9, 00, "AM");
                cout << d2;
                if (d1 == d2)
                    cout << "equal" << endl;
                else
                    cout << "not equal" << endl;
                if (d1 != d2)
                    cout << "not equal" << endl;
                else
                    cout << "equal" << endl;
                if (d1 < d2)
                    cout << "less than" << endl;
                else
                    cout << "not less than" << endl;
                if (d1 > d2)
                    cout << "greater than" << endl;
                else
                    cout << "not greater than" << endl;
            }
            catch (invalid_argument &e){
                cout << "Invalid argument: " << e.what() << endl;
            }
            catch (logic_error &e){
                cout << "Logic error: " << e.what() << endl;
            }
            catch (...){
                cout << "Uncaught exception" << endl;
            }
            cout << "Finished" << endl;
            break;
        }
            
        case 4:
            try{
                DateTime d1 (11, 1, 50, 12, 00, "AM");
                cout << d1;
                DateTime d2 (11, 1, 50, 1, 00, "AM");
                cout << d2;
                DateTime d3 (8, 1, 50, 10, 00, "AM");
                cout << d3;
                DateTime d4 (8, 1, 50, 10, 00, "PM");
                cout << d4;
                Event e1 ('A', "93B3FFC2-CC21-4457-918E-C04E4D9BFB6F",  "Panel", "ICC Aud", d1, d2, d3);
                e1.println();
                cout << "print done" << endl;
                cout << e1;
                cout << "cout done" << endl;
                
                Event e2 ('A', "851B0018-6AA7-4480-9F00-D85BB858C5BE",  "Ben", "",  d1, d2, d4);
                e2.println();
                cout << "print done" << endl;
                cout << e2;
                cout << "cout done" << endl;
                
                if (e1 == e2)
                    cout << "id are same" << endl;
                else
                    cout << "id not same" << endl;
                if (e1 != e2)
                    cout << "id not same" << endl;
                else
                    cout << "id are same" << endl;
                if (e1 < e2)
                    cout << "m1 < m2" << endl;
                else
                    cout << "not m1 < m2" << endl;
                if (e1 > e2)
                    cout << "m1 > m2" << endl;
                else
                    cout << "not m1 > m2" << endl;
            }
            catch (invalid_argument &e){
                cout << "Invalid argument: " << e.what() << endl;
            }
            catch (logic_error &e){
                cout << "Logic error: " << e.what() << endl;
            }
            catch (...){
                cout << "Uncaught exception" << endl;
            }
            cout << "Finished" << endl;
            break;
    }
}

int main(int argc, char * argv[]){
    try {
        string inputfile1 (argv[1]);
        string inputfile2 (argv[2]);
        string outputfile1 (argv[1]);
        string outputfile2 (argv[2]);
        inputfile1 += ".in";
        inputfile2 += ".in";
        outputfile1 += ".out";
        outputfile2 += ".out";
        Calendar c1;
        Calendar c2;
        c1.read(inputfile1);
        c2.read(inputfile2);
        c1.synchronize(c2);
        c1.write(outputfile1);
        c2.write(outputfile2);
    }
    catch (invalid_argument &e){
        cout << "Invalid argument: " << e.what() << endl;
    }
    catch (logic_error &e){
        cout << "Logic error: " << e.what() << endl;
    }
    catch (...){
        cout << "Uncaught exception" << endl;
    }

    return 0;
}

