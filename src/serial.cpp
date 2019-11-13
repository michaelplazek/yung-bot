#include <serial.h>
#include <iostream>

<<<<<<< HEAD

=======
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
int fd; 

/*initialize robot*/
int serial::init(const char *yungin){

	fd = open(yungin, O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd == -1){ 
		perror("Error, failed to connect");
	}
	else{
		fcntl(fd,F_SETFL,0);
		tcflush (fd, TCIFLUSH);
	}
	struct termios parameters;
	
	int get = tcgetattr(fd, &parameters);
	if(get == -1){ 
		perror("Error getting attributes");
	}
	else{ 
		printf("%s\n", "Get attributes: success");
	}
	cfmakeraw (&parameters); 
	//sets input and output baud rate
	cfsetispeed(&parameters,B115200);
	cfsetospeed(&parameters,B115200);
	
	// or forces values to 1; and forces all values to 0 (off); 
	parameters.c_iflag &= ~(IXON | IXOFF); //flow control off; 
	parameters.c_cflag |=(CLOCAL | CREAD);
	parameters.c_cflag &= ~(PARENB | CSTOPB);//no parity 
	parameters.c_cflag &= ~CSIZE; //mask the character bits
	parameters.c_cflag |= (CS8); //8 bit character size 
	parameters.c_oflag = 0;
	parameters.c_lflag = 0;//ICANON=canonical mode
	parameters.c_cc[VMIN] = 0; // 1 input byte is enough to return from read()
	parameters.c_cc[VTIME] = 1;// Timer off 

	//set attribute immediately
	int set = tcsetattr(fd, TCSANOW, &parameters); 
	if(set == -1){
		perror("Error setting attributes \n");
	}
	if (fd == -1){
		perror(yungin);
		return -1;
	}	
	usleep(200000);			
	return fd;
}


int serial::startIO(){
<<<<<<< HEAD
	uint8_t startBit[]={128};
=======
	unsigned char startBit[]={128};
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
	if (write(fd,startBit,sizeof(startBit))==-1){
		perror("failed to open serial port");
		return -1;
	}
	printf("IO is ready!\n");
	return 0;
}

/*start funtion can set mode to either safe, full, or passive*/
int serial::setMode(int mode){
	 //safe mode
	if(mode==1){
<<<<<<< HEAD
		uint8_t command[]={131};
=======
		unsigned char command[]={131};
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
		if (write(fd,command, sizeof(command))==-1){
			perror("mode set failed");
			return -1;
		}
		printf("Robot mode set to safe \n");
	}
	//full mode	
	else if(mode==2){
<<<<<<< HEAD
		uint8_t command[]={132};
=======
		unsigned char command[]={132};
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
		if (write(fd,command, sizeof(command))==-1){
	 		perror("mode set failed");
	 		return -1;
	 	}
		printf("Robot mode set to full \n");
	}
	//passive mode
	else if(mode==3){
<<<<<<< HEAD
		uint8_t command[]={128};//passive 
=======
		unsigned char command[]={128};//passive 
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
		if (write(fd,command, sizeof(command))==-1){
	 		perror("mode set failed");
	 		return -1;
	 	}
		printf("Robot mode set to passive \n");
	}
	
	return 0;
}

/*stops robot I/O*/
int serial::stopIO(){
<<<<<<< HEAD
	uint8_t command[]={173};
=======
	unsigned char command[]={173};
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
	if(write(fd, command, sizeof(command))==-1){
		perror("robot failed to close I/O ");
		return -1;
	}
	//close(fd);
	printf("\nClosing I/O \n");
	return 0;
}

/*powers down robot*/
int serial::off(){
<<<<<<< HEAD
	uint8_t command[]={128,133};
=======
	unsigned char command[]={128,133};
>>>>>>> 2f96f161bd9a0a73f49660338be085e86cfed43b
	if(write(fd, command, sizeof(command))==-1){
		perror("robot failed to power off ");
		return -1;
	}
	printf("Powering Off...\n");
	return 0;
}


serial::serial(){
	printf("Initializing the Yung... \n");
}

serial::~serial(){	
	printf("Robot Off \n");
}




