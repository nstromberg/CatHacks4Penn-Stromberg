HEADERS=course.h sec.h sol.h stime.h
OBJECTS=course.o sec.o sol.o main.o 
ScheduleOptimizer3000:$(OBJECTS) stime.o
	g++ -std=c++11 $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -std=c++11 -c $< -o $@ 
stime.o: stime.h
	g++ -std=c++11 -c $^ -o $@
clean:
	rm -i *.o ScheduleOptimizer3000
