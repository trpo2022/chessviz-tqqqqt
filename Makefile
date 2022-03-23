CFLAGS = -Wall -Werror -I ./src
CPFLAGS = -MMD

output: start_table.o check_rule.o eror_mes.o move.o print_table.o main.o
	gcc obj/src/chessviz/start_table.o obj/src/libchessviz/check_rule.o obj/src/libchessviz/eror_mes.o obj/src/libchessviz/move.o obj/src/libchessviz/print_table.o obj/src/chessviz/main.o -o output
	mv output bin/

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
	rm obj/src/chessviz/*.o obj/src/libchessviz/*.o obj/src/chessviz/*.d obj/src/libchessviz/*.d bin/output

-include /src/ 
