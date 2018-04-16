#include "stop_watch.h"
#include <iostream>
#include <thread>

std::ostream& operator<<(std::ostream& stream, const std::chrono::seconds& s)
{
    stream << s.count() << "s";
    return stream;
}

/**
 * \brief Compare two values for equality.
 * \tparam T The type of the values to compare. T must meet the requirements of
 * [EqualityComparable](http://en.cppreference.com/w/cpp/concept/EqualityComparable).
 * \param[in] actual The value calculated by the functionality being tested.
 * \param[in] expected The value that is expected to be calculated by the functionality being
 * tested.
 * \param[in] test_name A short description of the test, for use in output.
 * \retval true Indicates that \a actual is equal to \a expected, and the test passes.
 * \retval false Indicates that \a actual is not equal to \a expected, and the test fails.
 * \throws Nothing.
 */
template <class T>
bool validate(const T& actual, const T& expected, const std::string& test_name)
{
    if (actual == expected)
    {
        std::cout << "[ pass ] " << test_name << std::endl;
        return true;
    }

    std::cerr << "[ fail ] " << test_name << "\n"
        << "         actual:   " << actual << "\n"
        << "         expected: " << expected << std::endl;
    return false;
}

int main(int argc, char* argv[])
{
    using namespace std::literals::chrono_literals;
    try
    {
        bool passing = true;

        stop_watch watch;
        watch.start();
        std::this_thread::sleep_for(2s);
        watch.stop();
        passing = validate(watch.get(), 2s, "start/stop");

        watch.start();
        std::this_thread::sleep_for(1s);
        watch.lap();
        std::this_thread::sleep_for(1s);
        watch.lap();
        std::this_thread::sleep_for(1s);
        watch.stop();
        passing = validate(watch.lap_count(), static_cast<stop_watch::count_type>(3), "3 laps") && passing;
        passing = validate(watch.average(), 1s, "1s average") && passing;

        if (passing)
            return EXIT_SUCCESS;
        return EXIT_FAILURE;
    }
    catch (const std::exception& error)
    {
        std::cerr << "[ fail ] caught an unexpected exception:\n"
                  << "         " << error.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "[ fail ] caught an unexpected and unknown exception\n";
        return EXIT_FAILURE;
    }
}
