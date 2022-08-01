all:
	./pasmo ./src/*.asm ./bin/ROM.bin
	
#-f3 -v0 -ocard.bin -lcard.lst -scard.sym 

clean:
	-rm ./bin/*.bin
#-rm ./bin/*.lst
#-rm ./bin/*.sym

run:
	echo "TODO!!!"