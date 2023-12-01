#include<iostream>
#include<unistd.h>
using namespace std;

int main() {
	int pid = fork();
	if (pid<0) {
		cout<<"UNSUCCESSFUL"<<endl;
		return -1;
	}
	else if(pid==0) {
		cout<<"I am a child process" <<" "<< pid <<" " <<getpid()<<endl;
	}else{
		sleep(5);
		cout<<"I am parent process " <<" " << pid <<" " << getpid() <<endl;
	}
	return 0; 
}
