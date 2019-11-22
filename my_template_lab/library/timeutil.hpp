#pragma once

#include <ctime>

class TimeUtil
{
public:
    static const int SECOND_PER_MINUTE = 60;
    static const int SECOND_PER_HOUR = SECOND_PER_MINUTE * 60;
    static const int SECOND_PER_DAY = SECOND_PER_HOUR * 24;

    class SecondTimePoint
    {
    public:
        SecondTimePoint(int second = 0) : m_second(second) {}
        int GetSecond() const { return m_second; }

    private:
        int m_second;
    };

    class MinuteTimePoint
    {
    public:
        MinuteTimePoint(int minute = 0, int second = 0) : 
            m_minute(minute), m_second_timepoint(second)
        {}
        int GetMinute() const { return m_minute; }
        int GetSecond() const { return m_second_timepoint.GetSecond(); }

    private:
        int m_minute;
        SecondTimePoint m_second_timepoint;
    };

    class HourTimePoint
    {
    public:
        HourTimePoint(int hour = 0, int minute = 0, int second = 0) : 
            m_hour(hour), m_minute_timepoint(minute, second)
        {}

    private:
        int m_hour;
        MinuteTimePoint m_minute_timepoint;
    };

    class WeekDayTimePoint
    {
    public:
        WeekDayTimePoint(int week_day = 0, int hour = 0, int minute = 0, int second = 0) :
            m_week_day(week_day), m_hour_timepoint(hour, minute, second)
        {}
    private:
        int m_week_day;
        HourTimePoint m_hour_timepoint;
    };

    class MonthDayTimePoint
    {
    public:
        MonthDayTimePoint(int month_day = 0, int hour = 0, int minute = 0, int second = 0) :
            m_month_day(month_day), m_hour_timepoint(hour, minute, second)
        {}

    private:
        int m_month_day;
        HourTimePoint m_hour_timepoint;
    };

    class YearTimePoint
    {
    public:
        YearTimePoint(int year = 0, int month_day = 0, int hour = 0, int minute = 0, int second = 0) :
            m_year(year), m_month_day_timepoint(month_day, hour, minute, second)
        {}

    private:
        int m_year;
        MonthDayTimePoint m_month_day_timepoint;
    };

    static long long NowTimestamp()
    {
        return time(NULL);
    }

    static tm* LocalTime()
    {
        time_t now = time(NULL);
        return localtime(&now);
    }

    static int SecondToNextTimePoint(const SecondTimePoint &timepoint)
    {
        tm* local_time = LocalTime();

        if (timepoint.GetSecond() < local_time->tm_sec)
            local_time->tm_min += 1;
        local_time->tm_sec = timepoint.GetSecond();

        return static_cast<int>(mktime(local_time) - NowTimestamp());
    }

    static int SecondToNextTimePoint(const MinuteTimePoint &timepoint)
    {
        tm* local_time = LocalTime();

        if (timepoint.GetMinute() < local_time->tm_min)
            local_time->tm_hour += 1;
        local_time->tm_sec = timepoint.GetSecond();
        local_time->tm_min = timepoint.GetMinute();

        return mktime(local_time) - NowTimestamp();
    }

    static int NextTimeInterval(int minute, int second)
    {
        tm* local_time = LocalTime();

        if (minute < local_time->tm_min)
            local_time->tm_hour += 1;
        local_time->tm_sec = second;
        local_time->tm_min = minute;

        return mktime(local_time) - NowTimestamp();
    }

    static int NextTimeInterval(int hour, int minute, int second)
    {
        tm* local_time = LocalTime();

        if (hour < local_time->tm_hour)
            local_time->tm_mday += 1;
        local_time->tm_sec = second;
        local_time->tm_min = minute;
        local_time->tm_hour = hour;

        return mktime(local_time) - NowTimestamp();
    }

    static int NextWeekInterval(int week, int hour, int minute, int second)
    {
        tm* local_time = LocalTime();

        if (week < local_time->tm_wday)
            local_time->tm_wday += 7;
        local_time->tm_sec = second;
        local_time->tm_min = minute;
        local_time->tm_hour = hour;

        return mktime(local_time) - NowTimestamp();
    }

    static int NextMonthInterval(int month_day, int hour, int minute, int second)
    {
        tm* local_time = LocalTime();

        if (month_day < local_time->tm_mday)
        {
            local_time->tm_mon += 1;
        }
        local_time->tm_sec = second;
        local_time->tm_min = minute;
        local_time->tm_hour = hour;
        local_time->tm_mday = month_day;

        return mktime(local_time) - NowTimestamp();
    }
};