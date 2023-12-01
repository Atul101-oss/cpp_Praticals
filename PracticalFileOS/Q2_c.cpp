#include<iostream> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
using namespace std; 
int main() {
	int code = fork(); 
	int status,x; 
	if(code<0) {
		cout<<"UNSUCCESSFUL"<<endl; 
	} else {
		x = wait(&status);
		cout<<"pid= " <<" "<< getpid() <<" "<< "return code = " << code<<" "<<"x="<<" " << x <<endl; 
 	}
	return 0; 
}
