// File: event.cpp
#include "event.h"

// Default constructor
Event::Event(){
    setStatus('A');
}

// Test explicit constructor
Event::Event(char status, string id, string name,
             string location, DateTime start,
             DateTime end, DateTime modified)
{
    this->status = status;
    this->id = id;
    this->name = name;
    this->location = location;
    this->start = start;
    this->end = end;
    this->modified = modified;
    setStatus(status);
}

string Event::getName() const{
    return name;
}

string Event::getLocation() const{
    return location;
}

char Event::getStatus() const{
    return status;
}

// Operator Overloading ==
bool Event::operator==(const Event &e) const{
    return (id == e.id);
}

// Operator Overloading !=
bool Event::operator!=(const Event &e) const{
    return (!(id == e.id));
}

// Operator Overloading <
bool Event::operator<(const Event &e) const{
    return (modified < e.modified);
}

// Operator Overloading >
bool Event::operator>(const Event &e) const{
    return (modified > e.modified);
}

// Operator == Query
bool Event::operator==(const string &query) const{
    bool found = false;
    if (status == 'A'){
        if (name.find(query) != string::npos
            || location.find(query) != string::npos)
            found = true;
    }
    return found;
}

// Print method
void Event::println(ostream &out) const{
    out << name << " " << location << " "
        << start << " " << end << endl;
}

// Set status method
void Event::setStatus(char status) throw (invalid_argument){
    if (!(status == 'A' || status == 'D'))
        throw invalid_argument
        ("Event::setStatus: status is invalid");
    this->status = status;
}

// Read quoted strings method
string Event::readDoubleQuotedString (istream &in) const { 
    char quote = ' ';
    string name = "";
    
    if (in.good()){
        in >> quote;
        getline(in, name, '"');
        if (quote != '"')
            in.setstate(ios::failbit);
        else
            return name;
    }
    return name;
}

ostream& operator<<(ostream &out, const Event &e){
    char quote = '"';

    out << e.status << " ";
    out << setfill(' ') << setw(30);
    out << e.id << " " << quote << e.name << quote << " "
        << quote << e.location << quote << " "
        << e.start << " " << e.end << " " << e.modified;
    return out;
}

istream& operator>>(istream &in, Event &e) throw (invalid_argument){
    char status = ' ';
    string id = "", name = "", location = "";
    DateTime start, end, modified;
    
    in >> status;
    if (in.good()){
        in >> e.id;
        e.setStatus(status);
        e.name = e.readDoubleQuotedString(in);
        e.location = e.readDoubleQuotedString(in);
        in >> e.start;
        in >> e.end;
        in >> e.modified;
        e.setStatus(status);
    }
    return in;
}

