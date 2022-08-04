all:	
	-sjasmplus ./src/main.asm --lst=./bin/main.lst --sym=./bin/main.sym --sld=./bin/main.sld --raw=./bin/main.bin 

clean:
	-rm ./bin/*.bin
	-rm ./bin/*.lst
	-rm ./bin/*.sym
	-rm ./bin/*.sld
	
run:
	echo "TODO!!!"