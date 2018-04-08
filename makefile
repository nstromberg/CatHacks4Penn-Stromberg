HEADERS=course.h sec.h sol.h time.h
OBJECTS=course.o sec.o sol.o time.o main.o
ScheduleOptimizer3000:$(OBJECTS)
	g++ -std=c++11 -o $^ $(HEADERS) $(OBJECTS)
%.o:%.cpp $(HEADERS)
	g++ -c -std=c++11 $< -o $@
clean:
	rm -i $(OBJECTS) ScheduleOptimizer3000
