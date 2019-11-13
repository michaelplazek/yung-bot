#include <serial.h>
#include <pack.h>

int main(int argc, char *argv[]){
	serial port;
	pack packets;
	
	fd = port.init("/dev/ttyUSB0");
	usleep(200000);
	port.startIO();
	usleep(200000);
	port.setMode(3);//1==safe;2==full,3==passive
	usleep(200000);	
	packets.stream(7);
	usleep(200000);
	port.stopIO();
	usleep(200000);	
	port.off();	
return 0;
}

