OBJS = main.o Repl.o CommandProcessor.o Table.o VirtualMachine.o

db: $(OBJS)
	gcc -o db $(OBJS)

main.o: main.c Controller.c Controller.h
	gcc -c main.c

Repl.o: Repl.c Repl.h
	gcc -c $^

CommandProcessor.o: CommandProcessor.c CommandProcessor.h
	gcc -c $^

Table.o: Table.c Table.h
	gcc -c $^

VirtualMachine.o: VirtualMachine.c VirtualMachine.h Controller.c Controller.h
	gcc -c $^

clean:
	rm *.o *.gch