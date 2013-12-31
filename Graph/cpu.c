#include  <unistd.h>


int main(void) 
{
	int i;
	while(1) {
		
		for (i = 0; i < 9600000; i++);
		sleep(10);
	}
	return 0;
}
