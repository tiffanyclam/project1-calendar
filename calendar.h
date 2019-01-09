#ifndef CALENDAR_H
#define CALENDAR_H

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "event.h"

using namespace std;

/**
 * A class for storing events of a calendar that can be synchronized
 * with other calendars.  Methods exist to read and write events to
 * and from files, which serve as proxies for sending and receiving
 * between calendars on devices, on computers, and in the cloud.  A
 * find method searches for events based on name and location.
 *
 * @author Mark Maloof (maloof at cs georgetown edu)
 * @version 1.1, 11/28/12
 * @version 1.2, 11/08/16
 */

class Calendar
{
public:
    Calendar();
    Event &find( string query ) throw ( logic_error );
    void print( ostream& out = cout ) const;
    void read( string filename ) throw ( logic_error, invalid_argument );
    void read( istream& in ) throw ( invalid_argument );
    unsigned size() const;
    void synchronize( Calendar& e );
    void write( string filename ) const;
    void write( ostream& out = cout ) const;
    
private:
    vector<Event> events;
    
    void synchronize( vector<Event>& e1, vector<Event>& e2 );
    
}; // Calendar class

#endif

