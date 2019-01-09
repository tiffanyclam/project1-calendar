#
# Makefile for P1
#

a.out: main.o calendar.o event.o datetime.o
g++ -std=c++11 main.o calendar.o event.o datetime.o

main.o: main.cpp main.h calendar.h event.h datetime.h
g++ -std=c++11 -c main.cpp

calendar.o: calendar.cpp calendar.h event.h
g++ -std=c++11 -c calendar.cpp

event.o: event.cpp event.h datetime.h
g++ -std=c++11 -c event.cpp

datetime.o: datetime.cpp datetime.h
g++ -std=c++11 -c datetime.cpp

.PHONY: submit clean

submit:
rm -f submit.zip
zip submit.zip main.cpp main.h calendar.cpp calendar.h event.cpp event.h datetime.cpp datetime.h Makefile HONOR

clean:
rm -f *.o core a.out

