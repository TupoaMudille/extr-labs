#include "queue.h"
#include <Windows.h>
#include <vector>
#include <iostream>
using namespace std;

struct Zadacha
{
	int yadr = 0;
	int tact = 0;
};
struct CPU
{
	vector <Zadacha> cpus;
	int cpuCPU = 0;
};

class CPUssor
{
private:
	int Time;
	int CycleCount = 0;
	int done = 0;
	int random = 0;
	int size = 0;
	double powerCPU = 0;
	double powerQue = 0;
	int errorque = 0;
	int waitQue = 0;
	int errorcpu = 0;
	int waitCPU = 0;
	int countTask = 0;
public:
	void Wait(Queue<Zadacha>& q2ue, CPU& cpu, int time);
	void Work(int _sizeq, int _time, int _yadr, double _powercpu, double _powerque);
	Zadacha ZadGen();
	void Output(int countTask, int waitQue, int waitCPU, int time, int done, int CycleCount);
};