

#include <stdio.h>
#include "../include/IO.h"
using namespace phigraph;

int main(){

	//int i,j;
	//for(i=0;i<5;i++)
	//	for(j=0;j<=5;j++){
	//		printf("%d\n",(i+j));
	//	}
	//	
	//	
	PhiIO*io = new PhiIO();
	char* s = (io->readStringFromFile("/home/wubo/work/project/PhiGraph/inputs/rMatGraph_J_5_100.txt")).get();
	cout << s;
	return 0;
}

