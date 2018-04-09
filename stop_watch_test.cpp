//#include "stop_watch.hpp"
#include <iostream>

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
    try
    {
        bool passing = true;

        //passing = validate(1, 1, "one equals one") && passing;
        //passing = validate(1, 2, "one equals two") && passing;

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
