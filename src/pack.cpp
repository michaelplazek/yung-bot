#include <serial.h>
#include <pack.h>


/*stream desired data packets of 1 unsigned byte*/
int pack::stream(int packet){
	uint8_t command[]={142,packet};
	if(write(fd, command, sizeof(command))==-1){
		perror("failed to retrieve data packet");
		return -1;
	}
	uint8_t response=0;
	if(read(fd,&response,sizeof(response))!=1){
		perror("failed to write data packet");
		return -1;
	}
	printf("Bit Recieved=%i",response);
	printf("%i",response);
	return response;
}

pack::pack(){
	printf("Initializing Packets\n");
}

pack::~pack(){
	printf("finished reading packets\n");
}

