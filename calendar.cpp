// File: calendar.cpp
#include "calendar.h"


Calendar::Calendar(){
}

Event& Calendar::find(string query) throw (logic_error){
    bool found = false;
    static Event returnO;
    for (int i = 0; i < events.size() && !found; i++){
        if (events.at(i) == query){
            found = true;
            returnO = events.at(i);
        }
    }
    if (found == false){
        throw logic_error("Calendar::find: Query not found");
    }
    return returnO;
}

void Calendar::print(ostream &out) const{
    for (int i = 0; i < events.size(); i++)
        if (events.at(i).getStatus() == 'A')
            events.at(i).println();
}

void Calendar::read(string filename) throw (logic_error, invalid_argument){
    ifstream fin (filename.c_str());
    if (!fin.good())
        throw logic_error("Calendar::read: File not found");
    read(fin);
}

void Calendar::read(istream &in) throw (invalid_argument){
    Event event;
    while (in >> event)
        events.push_back(event);
}

unsigned Calendar::size() const{
    int linecount = 0;
    for (int i = 0; i < events.size(); i++)
        linecount++;
    // return events.size();
    return linecount;
}

void Calendar::synchronize(Calendar &e){
    synchronize(this->events, e.events);
    synchronize(e.events, this->events);
}

void Calendar::synchronize( vector<Event> &e1, vector<Event> &e2){
    bool match = false;
    for (int i = 0; i < e1.size(); i++){
        int maxcount = -1;
        match = false;
        for (int j = 0; j < e2.size() && !match; j++){
            if (e1.at(i) == e2.at(j)) {
                match = true;
                if (e1.at(i).getStatus() == 'D')
                    e2.at(j) = e1.at(i);
                if (e1.at(i) < e2.at(j))
                    e1.at(i) = e2.at(j);
            }
            maxcount = j;
        }
        if (match == false && maxcount == (e2.size()-1))
            e2.push_back(e1.at(i));
    }
}

void Calendar::write(string filename) const{
    ofstream fout;
    fout.open(filename.c_str());
    write(fout);
}

void Calendar::write(ostream &out) const{
    for (int i = 0; i < events.size(); i++)
        out << events.at(i) << endl;
}
