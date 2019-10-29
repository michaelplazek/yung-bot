#include "yungBot.h"
#include <iostream>


int yungBot::init(const char *yungin){

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
		 
		//sets input and output baud rate
		cfsetispeed(&parameters,B115200);
		cfsetospeed(&parameters,B115200);
		
		// or forces values to 1; and forces all values to 0 (off); 
		parameters.c_iflag &= IGNPAR; //flow control off; 
		parameters.c_cflag = CS8 | CLOCAL | CREAD; //8 bit character size 
		parameters.c_cflag &= PARENB;//no parity 

		//parameters.c_oflag = 
		//parameters.c_lflag = 
		parameters.c_cc[VMIN] = 1; // 1 input byte is enough to return from read()
		parameters.c_cc[VTIME] = 0;// Timer off 

		//set attribute immediately
		int set = tcsetattr(fd, TCSANOW, &parameters); 
		if(set == -1){
			perror("Error setting attributes \n");
		}
		if (fd == -1){
			perror(yungin);
		return 1;
		}	
					
	return fd;
}

//start funtion can set mode to either safe, full, or passive
int yungBot::start(const char *mode){
	if(mode=="safe"){
		 unsigned char command[]={128,131};
		if(mode=="full"){
			unsigned char command[]={128,132};
			if(mode=="passive"){
				unsigned char command[]={128};
				if(write(fd,command, sizeof(command))==-1){
				perror("error starting robot");
				return -1;
				}
			}
		}
	}
return 0;
}




 
yungBot::yungBot(){
printf("Initializing the Yung... \n");
}

yungBot::~yungBot(){	
printf("\nClosing the Yung... \n");
}


/*void yungBot::sendCommands(int commands[]){
    // Receives a series of commands and sends it to the robot.
    int send = write(fd, &commands[0], commands.size());
    if(send == -1){
	perror("Error writing to robot");
    }

}
*/

