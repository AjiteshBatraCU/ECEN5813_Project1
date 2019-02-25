objects = main.o help.o alloc.o free.o display.o modify.o set_pattern.o verify_pattern.o invert.c

#flag: 
# -g = debugging
#-wall = enable all warnings
CFLAGS = -g -Wall

exec : $(objects)
	gcc $(CFLAGS) -o exec $(objects)
	
main.o : main.c help.h
	gcc $(CFLAGS) -c main.c 
# Will need to add dependencies for each .o file. Syntax:
# file.o: file.c include_file_1.h include_file_2.h, etc...
# 	gcc $(flags) -c file.c
#
	
clean : 
	rm exec *.o