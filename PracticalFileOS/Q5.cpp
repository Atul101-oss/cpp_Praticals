#include<iostream>
using namespace std;
int main(){
	cout<<"\nConfigured memory is :\n";
	system("cat /proc/meminfo |awk 'NR==1{print $2}'\n");
	cout<<"\nAmount of free memory is :\n";
	system("cat /proc/meminfo |awk 'NR==2{print $2}'\n");
	cout<<"\nAmount of used memory is :\n";system("cat /proc/meminfo |awk '{if (NR==1) a=$2; if (NR==2) b=$2 } END {print a-b}'\n");
	return 0;
}
