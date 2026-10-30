CROSS_COMPILER = 


default : writer.o
	$(CROSS_COMPILER)gcc -o writer writer.o

writer.o : writer.c
	$(CROSS_COMPILER)gcc -c writer.c

clean :
	rm -f writer writer.o 

