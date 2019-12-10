#pragma once

#include <ctime>
#include <cstdio>
#include <string>

template<time_t (*NowFunc)(time_t *) = time>
class TimeUtil
{
public:
    static long long NowTimestamp()
    {
        return NowFunc(NULL);
    }

    static std::string SecondToString(long long second)
    {
        if (second <= 0)
        {
            return "00:00:00";
        }
        int hour = second / 3600;
		int minutes = (second - hour * 3600) / 60;
		int sec = second - hour * 3600 - minutes * 60;

        char buffer[1024] {};
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hour, minutes, sec);

        return buffer;
    }

    static const char* week_name[7];

    class Timestamp
    {
    private:
        long long m_timestamp;
    public:
        Timestamp(long long timestamp = 0) :
            m_timestamp(timestamp)
        {}
        operator long long()
        {
            return m_timestamp;
        }

        int Second() const
        {
            return LocalTime()->tm_sec;
        }
        int Minutes() const
        {
            return LocalTime()->tm_min;
        }
        int Hour() const
        {
            return LocalTime()->tm_hour;
        }
        int Day() const
        {
            return LocalTime()->tm_mday;
        }
        int Week() const
        {
            return LocalTime()->tm_wday;
        }
        int Month() const
        {
            return LocalTime()->tm_mon + 1;
        }
        int Year() const
        {
            return LocalTime()->tm_year + 1900;
        }

        std::string AscTime() const
        {
            char buffer[1024] {};
            snprintf(buffer, sizeof(buffer), "%d-%02d-%02d %02d:%02d:%02d %s",
                    Year(), Month(), Day(), Hour(), Minutes(), Second(), week_name[Week()] );
            return buffer;
        }

    private:
        const tm *LocalTime() const
        {
            time_t t = static_cast<time_t>(m_timestamp);
            return localtime(&t);
        }
    };

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
        int GetHour() const { return m_hour; }
        int GetMinute() const { return m_minute_timepoint.GetMinute(); }
        int GetSecond() const { return m_minute_timepoint.GetSecond(); }

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
        int GetWeek() const { return m_week_day; }
        int GetHour() const { return m_hour_timepoint.GetHour(); }
        int GetMinute() const { return m_hour_timepoint.GetMinute(); }
        int GetSecond() const { return m_hour_timepoint.GetSecond(); }

    private:
        int m_week_day;
        HourTimePoint m_hour_timepoint;
    };

    class MonthDayTimePoint
    {
    public:
        MonthDayTimePoint(int month = 1, int month_day = 1, int hour = 0, int minute = 0, int second = 0) :
            m_month(month), m_month_day(month_day), m_hour_timepoint(hour, minute, second)
        {}
        int GetMonth() const { return m_month; }
        int GetMonthDay() const { return m_month_day; }
        int GetHour() const { return m_hour_timepoint.GetHour(); }
        int GetMinute() const { return m_hour_timepoint.GetMinute(); }
        int GetSecond() const { return m_hour_timepoint.GetSecond(); }

    private:
        int m_month;
        int m_month_day;
        HourTimePoint m_hour_timepoint;
    };

    class YearTimePoint
    {
    public:
        YearTimePoint(int year = 1970, int month = 1, int month_day = 1, int hour = 0, int minute = 0, int second = 0) :
            m_year(year), m_month_day_timepoint(month, month_day, hour, minute, second)
        {}
        int GetYear() const { return m_year; }
        int GetMonthDay() const { return m_month_day_timepoint.GetMonthDay(); }
        int GetHour() const { return m_month_day_timepoint.GetHour(); }
        int GetMinute() const { return m_month_day_timepoint.GetMinute(); }
        int GetSecond() const { return m_month_day_timepoint.GetSecond(); }

    private:
        int m_year;
        MonthDayTimePoint m_month_day_timepoint;
    };

    static tm* LocalTime()
    {
        time_t now = NowTimestamp();
        return localtime(&now);
    }

    static int SecondToNextTimePoint(const SecondTimePoint &timepoint)
    {
        tm* local_time = LocalTime();

        if (timepoint.GetSecond() <= local_time->tm_sec)
            local_time->tm_min += 1;
        local_time->tm_sec = timepoint.GetSecond();

        return static_cast<int>(mktime(local_time) - NowTimestamp());
    }

    static int SecondToNextTimePoint(const MinuteTimePoint &timepoint)
    {
        tm* local_time = LocalTime();

        if (timepoint.GetMinute() <= local_time->tm_min)
            local_time->tm_hour += 1;
        local_time->tm_sec = timepoint.GetSecond();
        local_time->tm_min = timepoint.GetMinute();

        return mktime(local_time) - NowTimestamp();
    }

    static int SecondToNextTimePoint(const WeekDayTimePoint &timepoint)
    {
        tm* local_time = LocalTime();

        if (timepoint.GetWeek() <= local_time->tm_wday)
            local_time->tm_wday += 7;
        local_time->tm_sec = timepoint.GetSecond();
        local_time->tm_min = timepoint.GetMinute();
        local_time->tm_hour = timepoint.GetHour();

        return mktime(local_time) - NowTimestamp();
    }

    static int SecondToNextTimePoint(const MonthDayTimePoint &timepoint)
    {
        tm* local_time = LocalTime();

        if (timepoint.GetMonthDay() <= local_time->tm_mday)
            local_time->tm_mon += 1;
        local_time->tm_sec = timepoint.GetSecond();
        local_time->tm_min = timepoint.GetMinute();
        local_time->tm_hour = timepoint.GetHour();
        local_time->tm_mday = timepoint.GetMonthDay();

        return mktime(local_time) - NowTimestamp();
    }
};

template<time_t (*NowFunc)(time_t *)>
const char* TimeUtil<NowFunc>::week_name[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", };