#include <nitro.h>
#include <string.h>

#include "struct_defs/igt.h"

#include "igt.h"

void IGT_Init (IGT * igt)
{
    igt->hours = 0;
    igt->minutes = 0;
    igt->seconds = 0;
}

void IGT_AddSeconds (IGT * igt, u32 amount)
{
    u32 newHours, newMinutes, newSeconds;

    if ((igt->hours == IGT_HOURS_MAX) && (igt->minutes == IGT_MINUTES_MAX) && (igt->seconds == IGT_SECONDS_MAX)) {
        return;
    }

    newHours = igt->hours;
    newMinutes = igt->minutes;
    newSeconds = igt->seconds + amount;

    if (newSeconds > IGT_SECONDS_MAX) {
        newMinutes = igt->minutes + (newSeconds / (IGT_SECONDS_MAX + 1));
        newSeconds %= (IGT_SECONDS_MAX + 1);

        if (newMinutes > IGT_MINUTES_MAX) {
            newHours = igt->hours + (newMinutes / (IGT_MINUTES_MAX + 1));
            newMinutes %= (IGT_MINUTES_MAX + 1);

            if (newHours >= IGT_HOURS_MAX) {
                newHours = IGT_HOURS_MAX;
                newMinutes = IGT_MINUTES_MAX;
                newSeconds = IGT_SECONDS_MAX;
            }
        }
    }

    igt->hours = newHours;
    igt->minutes = newMinutes;
    igt->seconds = newSeconds;
}

u16 IGT_GetHours (const IGT * igt)
{
    return igt->hours;
}

u8 IGT_GetMinutes (const IGT * igt)
{
    return igt->minutes;
}

u8 IGT_GetSeconds (const IGT * igt)
{
    return igt->seconds;
}
