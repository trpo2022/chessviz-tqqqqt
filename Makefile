CFLAGS = -Wall -Werror -I ./src
CPFLAGS = -MMD

OBJCH = obj/src/chessviz
OBJLB = obj/src/libchessviz

SRCCH = src/chessviz
SRCLB = src/libchessviz

output: start_table.o check_rule.o eror_mes.o move.o print_table.o main.o
	gcc $(OBJCH)/start_table.o $(OBJLB)/check_rule.o $(OBJLB)/eror_mes.o $(OBJLB)/move.o $(OBJLB)/print_table.o $(OBJCH)/main.o -o bin/output

start_table.o: $(SRCCH)/start_table.c
	gcc -c $(CFLAGS) $(CPFLAGS) $(SRCCH)/start_table.c -o $(OBJCH)/start_table.o

check_rule.o: $(SRCLB)/check_rule.c
	gcc -c $(CFLAGS) $(CPFLAGS) $(SRCLB)/check_rule.c -o $(OBJLB)/check_rule.o

eror_mes.o: $(SRCLB)/eror_mes.c
	gcc -c $(CFLAGS) $(CPFLAGS) $(SRCLB)/eror_mes.c -o $(OBJLB)/eror_mes.o

move.o: $(SRCLB)/move.c
	gcc -c $(CFLAGS) $(CPFLAGS) $(SRCLB)/move.c -o $(OBJLB)/move.o

print_table.o: $(SRCLB)/print_table.c
	gcc -c $(CFLAGS) $(CPFLAGS) $(SRCLB)/print_table.c -o $(OBJLB)/print_table.o

main.o: $(SRCCH)/main.c
	gcc -c $(CFLAGS) $(CPFLAGS) $(SRCCH)/main.c -o $(OBJCH)/main.o


clean:
	rm $(OBJCH)/*.o $(OBJCH)/*.d $(OBJLB)/*.o $(OBJLB)/*.d

-include /src/ 
