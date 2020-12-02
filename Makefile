#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o Student.o DomesticStudent.o InternationalStudent.o ToeflScore.o
	g++ -g -o main main.o Student.o DomesticStudent.o InternationalStudent.o ToeflScore.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: Student.cpp
	g++ -g -c Student.cpp
	
#compile the DomesticStudent.cpp to DomesticStudent.o
DomesticStudent.o: DomesticStudent.cpp
	g++ -g -c DomesticStudent.cpp
	
#compile the InternationalStudent.cpp to InternationalStudent.o
InternationalStudent.o: InternationalStudent.cpp
	g++ -g -c InternationalStudent.cpp
	
#compile the ToeflScore.cpp to ToeflScore.o
ToeflScore.o: ToeflScore.cpp
	g++ -g -c ToeflScore.cpp

#remove built files
clean:
	rm -rf main main.o Student.o DomesticStudent.o InternationalStudent.o ToeflScore.o *~
