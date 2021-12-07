#include <iostream>
#include <string>
#include "cpu.h"
using namespace std;

int main()
{
	int Qsize, time, yadres;
	double powerCPU, powerQue;
	Qsize=100;//size queue
	yadres=4; //yadrs
	powerCPU=2;//sposobnost/power cpu
	powerQue=2;//power queue
	time=2;//time
	CPUssor cpussor1;
	cpussor1.Work(Qsize, time, yadres, powerCPU, powerQue);
	return 0;
}