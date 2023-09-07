CC = g++
CFLAGS = -g3 -MMD -O0 -I/usr/local/include
LDFLAGS = -lllh_converter
TARGET = converter # need to change
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)
RM = rm -f

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $< -c $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include *.d

