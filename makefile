
CC      = gcc
CPP     = g++
RM      = rm -rf

## debug flag  
DBG_ENABLE   = 1

## source file path  
SRC_PATH   := .

## target exec file name  
TARGET     := test_RSA

## get all source files  
SRCS         += $(wildcard $(SRC_PATH)/*.cpp )

## all .o based on all .c  
OBJS        := $(SRCS:.cpp=.o)


## need libs, add at here  
LIBS := 

## used headers  file path  
INCLUDE_PATH := .

## used include librarys file path  
LIBRARY_PATH := .

## debug for debug info, when use gdb to debug  
ifeq (1, ${DBG_ENABLE})   
	CFLAGS += -D_DEBUG -O0 -g -DDEBUG=1
endif  

## get all include path  
CFLAGS  += $(foreach dir, $(INCLUDE_PATH), -I$(dir))

## get all library path  
LDFLAGS += $(foreach lib, $(LIBRARY_PATH), -L$(lib))

## get all librarys  
LDFLAGS += $(foreach lib, $(LIBS), -l$(lib))


all: clean build  

build:
	$(CPP) -c $(CFLAGS) $(SRCS)
	$(CPP) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)
	$(RM) $(OBJS)

clean:  
	$(RM) $(OBJS) $(TARGET)
# EXECUTABLE := main    # 可执行文件名
# LIBDIR:=              # 静态库目录
# LIBS :=               # 静态库文件名
# INCLUDES:=.           # 头文件目录
# SRCDIR:=              # 除了当前目录外，其他的源代码文件目录
# #
# # # Now alter any implicit rules' variables if you like, e.g.:

# CC:=g++
# CFLAGS := -g -Wall -O3
# CPPFLAGS := $(CFLAGS)
# CPPFLAGS += $(addprefix -I,$(INCLUDES))
# CPPFLAGS += -MMD
# #
# # # The next bit checks to see whether rm is in your djgpp bin
# # # directory; if not it uses del instead, but this can cause (harmless)
# # # `File not found' error messages. If you are not using DOS at all,
# # # set the variable to something which will unquestioningly remove
# # # files.
# #

# RM-F := rm -f


# # # You shouldn't need to change anything below this point.
# #
# SRCS := $(wildcard *.cpp) $(wildcard $(addsuffix /*.cpp, $(SRCDIR)))
# OBJS := $(patsubst %.cpp,%.o,$(SRCS))
# DEPS := $(patsubst %.o,%.d,$(OBJS))
# MISSING_DEPS := $(filter-out $(wildcard $(DEPS)),$(DEPS))
# MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.cpp,$(MISSING_DEPS)))


# .PHONY : all deps objs clean veryclean rebuild info

# all: $(EXECUTABLE)

# deps : $(DEPS)

# objs : $(OBJS)

# clean :
# 	@$(RM-F) *.o
# 	@$(RM-F) *.d
# veryclean: clean
# 	@$(RM-F) $(EXECUTABLE)

# rebuild: veryclean all
# ifneq ($(MISSING_DEPS),)
# $(MISSING_DEPS) :
# 	@$(RM-F) $(patsubst %.d,%.o,$@)
# endif
# -include $(DEPS)
# $(EXECUTABLE) : $(OBJS)
# 	$(CC) -o $(EXECUTABLE) $(OBJS) $(addprefix -L,$(LIBDIR)) $(addprefix -l,$(LIBS))

# info:
# 	@echo $(SRCS)
# 	@echo $(OBJS)
# 	@echo $(DEPS)
# 	@echo $(MISSING_DEPS)
# 	@echo $(MISSING_DEPS_SOURCES)