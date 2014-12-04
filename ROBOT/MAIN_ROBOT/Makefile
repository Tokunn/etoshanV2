CROSS := arm-linux-gnueabi

ifneq ($(CROSS),)
	CROSS_PREFIX	:= $(CROSS)-
endif

CXX = $(CROSS_PREFIX)g++
CXXFLAGS = -Wall -Wextra -O2
LDFLAGS =

TARGET = MAIN_ROBOT

all: $(TARGET)

MAIN_ROBOT: main.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	$(RM) *~ *.o $(TARGET)

%.o:%cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
