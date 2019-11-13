#include <serial.h>
#include <pack.h>

int main(int argc, char *argv[]){
	serial port;
	pack packets;
<<<<<<< HEAD
	
=======
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
	fd = port.init("/dev/ttyUSB0");
	usleep(200000);
	port.startIO();
	usleep(200000);
	port.setMode(3);//1==safe;2==full,3==passive
	usleep(200000);	
<<<<<<< HEAD
	packets.stream(7);
=======
	packets.stream(7); //stream cliff sensor data
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
	usleep(200000);
	port.stopIO();
	usleep(200000);	
	port.off();	
return 0;
}
<<<<<<< HEAD

=======
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
