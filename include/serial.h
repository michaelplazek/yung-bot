#ifndef serial_h
#define serial_h

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <stdlib.h>
#include <string> 
#include <limits.h> 
<<<<<<< HEAD
#include <stdint.h>
=======
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b



extern int fd;
 
class serial{
	public:
		int init(const char *device);
		//int start(int mode);
		int off();
		int startIO();
		int stopIO();
		int setMode(int mode);
		serial();
		~serial();
		
};

#endif
		
