#include<iostream>
using namespace std;
int main(){
	cout<<"\n Kernel version:\n";
	system("uname -s");
	cout<<"\nCPU space: \n";
	system("cat /proc/cpuinfo |awk 'NR==3,NR==4{print}' \n");
	return 0;
}
