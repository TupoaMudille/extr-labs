#include"cpu.h"
#include <ctime>
Zadacha CPUssor::ZadGen()
{
	srand((unsigned int)time(NULL));
	int pr = rand() % 9 + 1;
	if (pr < (powerQue * 10))
	{
		srand((unsigned int)time(NULL));
		int pr1 = rand() % 9 + 1;
		Zadacha zadacha;
		zadacha.yadr = pr1;
		return zadacha;
	}
	else
	{
		Zadacha zadacha = {};
		zadacha.yadr = 0;
		return zadacha;
	}
}
void CPUssor::Wait(Queue<Zadacha>& q2ue, CPU& cpu, int Time)
{
	for (int i = 0; i < Time; i++)
	{
		if (!q2ue.EVFull())
		{
			Zadacha zadacha1;
			zadacha1 = ZadGen();
			if (zadacha1.yadr != 0)
			{
				q2ue.EVPut(zadacha1);
			}
		}
		else
		{
			errorque++;
		}
		if (q2ue.EVEmpty())
		{
			waitQue++;
		}
		else
		{
			for (int i = 0; i < q2ue.EVSize(); i++)
			{
				Zadacha zadacha2;
				zadacha2 = q2ue.EVCheck();
				if (zadacha2.yadr <= cpu.cpuCPU)
				{
					cpu.cpuCPU -= zadacha2.yadr;
					cpu.cpus.push_back(zadacha2);
					countTask++;
					q2ue.EVGet();
					continue;
				}
				else
				{
					if (zadacha2.yadr > cpu.cpuCPU)
					{
						errorcpu++;
						q2ue.EVGet();
					}
					else
						break;
				}
			}
		}

		if (cpu.cpus.size() != 0)
		{
			int i = 0;
			for (i; i < cpu.cpus.size(); i++)
			{
				cpu.cpus[i].tact++;
				srand((unsigned int)time(NULL));
				int pr = rand() % 9 + 1;
				if ((double)pr / 10 < powerCPU)
				{
					Zadacha zadacha2;
					zadacha2 = cpu.cpus[i];
					if (zadacha2.tact == 1)
					{
						continue;
					}
					done++;
					cpu.cpus.erase(cpu.cpus.begin() + i);
					cpu.cpuCPU += zadacha2.yadr;
					CycleCount += zadacha2.tact;
				}
			}
		}
		else
		{
			waitCPU++;
		}
	}
	Output(countTask, waitQue, waitCPU, Time, done, CycleCount);
}
void CPUssor::Work(int _sizeq, int _time, int _yadr, double _powercpu, double _powerque)
{
	CPU cpu;
	cpu.cpuCPU = _yadr;
	Time = _time;
	size = _sizeq;
	powerCPU = _powercpu;
	powerQue = _powerque;
	Queue<Zadacha> q2ue(size);
	Wait(q2ue, cpu, Time);
}
void CPUssor::Output(int countTask, int waitQue, int waitCPU, int time, int done, int CycleCount)
{
	cout << "INFO:" << endl;
	cout << "count of zadaches: " << countTask << endl;
	if (countTask != 0)
		cout << "count of otkazov: " << (waitQue * 100 / countTask) << "%" << endl;
	else
		cout << "count of otkazof: " << 0 << endl;
	cout << "holostoy hod: " << (waitCPU * 100 / time) << "%" << endl;
	if (done != 0)
		cout << "time of doing zadach: " << (double(time - waitCPU) / double(done)) << endl;
	else
		cout << "time of doing zadach: " << 0 << endl;
	cout << "zadach completed: " << done << endl;
	cout << "all cycles: " << CycleCount << endl;
}