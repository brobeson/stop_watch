#ifndef STOP_WATCH_H
#define STOP_WATCH_H

#include <chrono>

/// \todo should there be a reset method?
template <class Duration>
class stop_watch final
{
private:
    using clock = std::chrono::steady_clock;
    using time_point = clock::time_point;

public:
    using duration = Duration;
    using count_type = std::size_t;

    stop_watch() = default;
    stop_watch(const stop_watch&) = default;
    stop_watch(stop_watch&&) = default;

    stop_watch& operator=(const stop_watch&) = default;
    stop_watch& operator=(stop_watch&&) = default;

    ~stop_watch() = default;

    /// \name operations
    /// \{

    void start()
    {
        m_laps = 0u;
        m_start = clock::now();
    }

    void stop()
    {
        m_duration = std::chrono::duration_cast<duration>(clock::now() - m_start);
        lap();
    }

    void lap() { ++m_laps; }

    /// \}

    /// \name accessors
    /// \{

    duration get() const { return m_duration; }
    duration average() const { return get() / lap_count(); }
    count_type lap_count() const { return m_laps; }

    /// \}

private:
    count_type m_laps = 0u;
    time_point m_start;
    duration m_duration;
};

using ms_watch = stop_watch<std::chrono::milliseconds>;
using us_watch = stop_watch<std::chrono::microseconds>;

#endif
