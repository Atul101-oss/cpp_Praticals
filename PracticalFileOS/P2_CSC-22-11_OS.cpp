/*
2. Execute various LINUX commands for:
i. Process Control: fork, getpid, ps, kill, sleep
ii. Communication: Input-output redirection, Pipe
iii. Protection Management: chmod, chown, chgrp
with cpp programs*/

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
    }

else { 
    sleep(5); 
    cout<<"I am parent process " <<" " << pid <<" " << getpid() <<endl; 
    }
    return 0; 
} 