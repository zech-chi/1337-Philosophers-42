#include <stdio.h>
#include <sys/time.h>

int	main() {
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz); // return 0 on sucess or -1 on failure
	printf("Seconds since January 1, 1970: %ld s and %d μs\n", tv.tv_sec, tv.tv_usec);
	printf("Minutes west of Greenwich: %d\n", tz.tz_minuteswest);
	printf("Daylight Saving Time adjustment: %d\n", tz.tz_dsttime);
	return (0);
}