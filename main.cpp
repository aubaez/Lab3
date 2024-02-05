//
//  main.cpp
//  Lab4
//
//  Created by Alireza on 2/14/20.
//  Copyright Â© 2020 Alireza. All rights reserved.
//

#include "main.h"
#include "cycletime.h"
#include "timer.h"
#include <unistd.h>

using namespace std;

int main(int argc, const char * argv[])
{
	float cpu_timer;
	unsigned int delay = 1;
	
	cout << "WES237A lab 4" << endl;

	char key=0;
	
	// 1 argument on command line: delay = arg
	if(argc >= 2)
	{
		delay = atoi(argv[1]);
	}

    //TODO: declare 2 cpu_count variables: 1 for before sleeping, 1 for after sleeping (see cpu_timer)
	int32 cpu_before;
	int32 cpu_after;
    //TODO: initialize the counter
	init_counters(cpu_before, cpu_after);

    //TODO: get the cyclecount before sleeping
	get_cyclecount(cpu_before);
    usleep(delay);
    //TODO: get the cyclecount after sleeping
	get_cyclecount(cpu_after);
    //TODO: subtract the before and after cyclecount
	int32 cpu_diff = cpu_after - cpu_before;
    //TODO: print the cycle count (see the print statement for the cpu_timer below)
	cout << "Timer Difference: " << (double)cpu_diff/1000000000.0 << endl;

	LinuxTimer t;
	usleep(delay);
	t.stop();
	cpu_timer = t.getElapsed();

	
	cout << "Timer: " << (double)cpu_timer/1000000000.0 << endl;

	return 0;
}

