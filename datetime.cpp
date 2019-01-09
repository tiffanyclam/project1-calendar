// File: datetime.cpp
#include <stdexcept>
#include "datetime.h"

// Default constructor
DateTime::DateTime (){
    setDate(1, 1, 0);
    setTime(12, 0, "AM");
}

// Explicit constructor
DateTime::DateTime (int mm, int dd, int yy, int h,
                    int m, string period) throw (invalid_argument){
    setDate (mm, dd, yy);
    setTime (h, m, period);
}

// Operator Overloading ==
bool DateTime::operator== (const DateTime &dt) const{
    return (yy == dt.yy && mm == dt.mm && dd == dt.dd
            && h == dt.h && m == dt.m && period == dt.period);
}

// Operator Overloading !=
bool DateTime::operator!= (const DateTime &dt) const{
    return (yy != dt.yy || mm != dt.mm || dd != dt.dd
            || h != dt.h || m != dt.m || period != dt.period);
}

// Operator Overloading <
bool DateTime::operator< (const DateTime &dt) const{
    if (yy < dt.yy)
        return true;
    if (yy == dt.yy && mm < dt.mm)
        return true;
    if (yy == dt.yy && mm == dt.mm && dd < dt.dd)
        return true;
    if (yy == dt.yy && mm == dt.mm && dd == dt.dd
        && period == dt.period){
        if (h != 12){
            if (h < dt.h)
                return true;
            if (h == dt.h && m < dt.m)
                return true;
        }
        else if (h == 12){
            if (h > dt.h)
                return true;
            if (h == dt.h && m < dt.m)
                return true;
        }
    }
    else if (yy == dt.yy && mm == dt.mm && dd == dt.dd
             && period == "AM" && dt.period == "PM")
        return true;
    else if (yy == dt.yy && mm == dt.mm && dd == dt.dd
             && period == "PM" && dt.period == "AM")
        return false;
    return false;
}

// Operator Overloading >
bool DateTime::operator> (const DateTime &dt) const{
    if (yy > dt.yy)
        return true;
    if (yy == dt.yy && mm > dt.mm)
        return true;
    if (yy == dt.yy && mm == dt.mm && dd > dt.dd)
        return true;
    if (yy == dt.yy && mm == dt.mm && dd == dt.dd
        && period == dt.period){
        if (h != 12){
            if (h > dt.h)
                return true;
            if (h == dt.h && m > dt.m)
                return true;
        }
        else if (h == 12){
            if (h < dt.h)
                return true; 
            if (h == dt.h && m < dt.m)
                return true;
        }
    }
    else if (yy == dt.yy && mm == dt.mm && dd == dt.dd
             && (period == "AM" && dt.period == "PM"))
        return false;
    else if (yy == dt.yy && mm == dt.mm && dd == dt.dd
             && (period == "PM" && dt.period == "AM"))
        return true;
    return false;
}

// Print method
void DateTime::print(ostream &out) const{
    if (mm < 10)
        out << setfill('0') << setw(2) << mm << "/";
    else
        out << mm << "/";
    if (dd < 10)
        out << setfill('0') << setw(2) << dd << "/";
    else
        out << dd << "/";
    if (yy < 10)
        out << setfill('0') << setw(2) << yy << " ";
    else
        out << yy << " ";
    if (h < 10)
        out << setfill('0') << setw(2) << h << ":";
    else
        out << h << ":";
    if (m < 10)
        out << setfill('0') << setw(2) << m << " " << period;
    else
        out << m << " " << period;
}

// Set date method
void DateTime::setDate (int mm, int dd, int yy) throw (invalid_argument){
    if (mm < 1 || mm > 12)
        throw invalid_argument ("DateTime::setDate: month is invalid");
    switch (mm){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (dd < 1 || dd > 31)
                throw invalid_argument
                ("DateTime::setDate: day is invalid");
            break;
        case 4: case 6: case 9: case 11:
            if (dd < 1 || dd > 30)
                throw invalid_argument
                ("DateTime::setDate: day is invalid");
            break;
        case 2:
            if (dd < 1 || dd > 28)
                throw invalid_argument
                ("DateTime::setDate: day is invalid");
            break;
        }
    if (yy < 0 || yy > 99)
        throw invalid_argument
        ("DateTime::setDate: year is invalid");
    this->mm = mm;
    this->dd = dd;
    this->yy = yy;
}

// Set time method
void DateTime::setTime(int h, int m, string period) throw (invalid_argument){
    if (h < 1 || h > 12)
        throw invalid_argument
        ("DateTime::setTime: hour is invalid");
    
    if (m < 0 || m > 59)
        throw invalid_argument
        ("DateTime::setTime: minute is invalid");
    
    if (!(period == "AM" || period == "PM")) 
        throw invalid_argument
        ("DateTime::setTime: period is invalid");

    this->h = h;
    this->m = m;
    this->period = period;
}

ostream & operator<< (ostream &out, const DateTime &dt){
    dt.print(out);
    return out;
}

istream & operator>> (istream &in, DateTime &dt) throw (invalid_argument){
    char ch1 = ' ', ch2 = ' ', ch3 = ' ';
    int mm = 0, dd = 0, yy = 0, h = 0, m = 0;
    string period = "";
    
    in >> mm;
    if (in.good()){
        in >> ch1 >> dd >> ch2 >> yy;
        if (ch1 != '/' || ch2 != '/')
            in.setstate(ios::failbit);
        else
            dt.setDate(mm, dd, yy);
            
        in >> h >> ch3 >> m >> period;
        if (ch3 != ':' && ! (period == "AM" || period == "PM"))
            in.setstate(ios::failbit);
        else
            dt.setTime(h, m, period);
    }
    return in;
}
