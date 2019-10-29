#ifndef yungBot_h
#define yungBot_h

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <stdlib.h>
#include <string> 

class yungBot{
	public:
		int init(const char *device);
		int readBot();
		int start(const char *mode);
		yungBot();
		~yungBot();
		int fd; 
};

#endif
		
