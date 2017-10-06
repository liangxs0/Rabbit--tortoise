objs=obj/ui.o obj/run.o obj/main.o 
INC=-Iinclude

bin/mian:$(objs)
	gcc $^ $(INC) -o $@
$(objs):obj/%.o:src/%.c
	gcc -c $^ $(INC) -o $@
