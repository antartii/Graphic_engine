#include "system.h"

long int Linux::get_uptime()
{
    std::ifstream uptime_file("/proc/uptime");
    long int uptime = 0;

    if (uptime_file.is_open()) {
        uptime_file >> uptime;
        uptime_file.close();
    }
    return uptime;
}