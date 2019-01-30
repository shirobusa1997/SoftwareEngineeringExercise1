####################################
# Makefile
####################################

# if your OS is mac/Linux , CC=gcc . 
# if your OS is Windows , CC=cl . (not support)
CC=gcc

# if your OS is mac/Linux , RM=rm . 
# if your OS is Windows , RM=del . (not support)
RM=rm

# Execution File
PRG:=s16t286

all:$(PRG)

# Compile
$(PRG): main.c Func.c Definitions.c
	$(CC) -o $@ $^

# Execution
run:$(PRG)
	./$(PRG)

# Delete/rm
clean:
	-$(RM) $(PRG)
