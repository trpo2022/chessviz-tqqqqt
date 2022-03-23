CFLAGS = -Wall -Werror -I ./src
CPFLAGS = -MMD

OBJCH = obj/src/chessviz/
OBJLB = obj/src/libchessviz/

output: start_table.o check_rule.o eror_mes.o move.o print_table.o main.o
	gcc $(OBJCH)/start_table.o $(OBJLB)/check_rule.o $(OBJLB)/eror_mes.o $(OBJLB)/move.o $(OBJLB)/print_table.o $(OBJCH)/main.o -o bin/output

start_table.o: src/chessviz/start_table.c
	gcc -c $(CFLAGS) $(CPFLAGS) src/chessviz/start_table.c -o obj/src/chessviz/start_table.o

check_rule.o: src/libchessviz/check_rule.c
	gcc -c $(CFLAGS) $(CPFLAGS) src/libchessviz/check_rule.c -o obj/src/libchessviz/check_rule.o

eror_mes.o: src/libchessviz/eror_mes.c
	gcc -c $(CFLAGS) $(CPFLAGS) src/libchessviz/eror_mes.c -o obj/src/libchessviz/eror_mes.o

move.o: src/libchessviz/move.c
	gcc -c $(CFLAGS) $(CPFLAGS) src/libchessviz/move.c -o obj/src/libchessviz/move.o

print_table.o: src/libchessviz/print_table.c
	gcc -c $(CFLAGS) $(CPFLAGS) src/libchessviz/print_table.c -o obj/src/libchessviz/print_table.o

main.o: src/chessviz/main.c
	gcc -c $(CFLAGS) $(CPFLAGS) src/chessviz/main.c -o obj/src/chessviz/main.o


clean:
	rm $(OBJCH)*.o $(OBJCH)*.d $(OBJLB)*.o $(OBJLB)*.d

-include /src/ 
