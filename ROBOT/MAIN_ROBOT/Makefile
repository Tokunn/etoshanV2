CROSS   := ~/Program/cross_gcc/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf

ifneq ($(CROSS),)
	CROSS_PREFIX	:= $(CROSS)-
endif

CXX		 = $(CROSS_PREFIX)g++
CXXFLAGS = -Wall -Wextra -O2 -g -MMD -MP
LDFLAGS	 =
LIBS	 =
INCLUDE	 = -I./Include
TARGET 	 = ./bin/$(shell basename `readlink -f .`)
OBJDIR	 = ./obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR = .
endif
SOURCES	 = $(wildcard *.cpp) $(wildcard ./Include/*.cpp)
OBJECTS	 = $(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))
DEPENDS	 = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o:%.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	$(RM) -r $(OBJECTS) $(DEPENDS) $(TARGET) $(TARGET) `readlink -f $(OBJDIR)`

-include $(DEPENDS)
