#include "yungBot.h"

int main(int argc, char *argv[]){
	yungBot steve0;
	steve0.fd = steve0.init("/dev/ttyUSB0");
	steve0.start("full");

	//steve0.off();
	//steve0.start();
	//steve0.safeMode();
return 0;
}

