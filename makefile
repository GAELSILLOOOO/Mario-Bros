bin/programa : src/main.cpp include/*
	g++ src/main.cpp -Iinclude -o bin/programa

ejecutar:bin/programa
	./bin/programa
clean : bin/programa
	rm bin/programa