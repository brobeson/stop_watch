#ifndef STOP_WATCH_H
#define STOP_WATCH_H

class stop_watch final
{
public:
    using duration = std::chrono::microseconds;
    using count_type = std::size_t;

    stop_watch() = default;
    stop_watch(const stop_watch&) = default;
    stop_watch(stop_watch&&) = default;

    stop_watch& operator=(const stop_watch&) = default;
    stop_watch& operator=(stop_watch&&) = default;

    ~stop_watch() = default;

    /// \name operations
    /// \{

    void start();
    void stop();
    void lap();

    /// \}

    /// \name accessors
    /// \{

    duration get() const;
    duration average() const;
    count_type lap_count() const;

    /// \}

private:
    count_type m_laps = 0u;
    time_point m_start;
    duration m_run_time;
};


int main()
{
    stop_watch watch;
    watch.start();
    std::this_thread::sleep_for(20_s);
    watch.stop();
    std::cout << "Ran for " << watch.get().count() << " seconds.\n";
    return EXIT_SUCCESS;
}

#endif
