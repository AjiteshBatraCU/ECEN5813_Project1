objects = main.o help.o alloc.o free.o display.o modify.o set_pattern.o verify_pattern.o

#flag: 
# -g = debugging
#-wall = enable all warnings
CFLAGS = -g -wall

makefile : $(objects)
	gcc $(CFLAGS) -o makefile $(objects)
	
# Will need to add dependencies for each .o file. Syntax:
# file.o: file.c include_file_1.h include_file_2.h, etc...
# 	gcc $(flags) -c file.c
#
#
	
clean : 
		rm makefile $(objects) 
