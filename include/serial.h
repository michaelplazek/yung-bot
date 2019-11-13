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
#include <stdint.h>



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
		
