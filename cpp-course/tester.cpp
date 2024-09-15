#include <iostream>
#include <sstream>
#include <ctime>

struct Date {
    int year, month, day;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

Date parseDate(const std::string& dateStr) {
    int year, month, day;
    char sep;  // To discard the ':' characters
    std::istringstream(dateStr) >> year >> sep >> month >> sep >> day;
    return Date(year, month, day);
}

// Helper function to calculate the difference in days
int daysBetween(const Date& date1, const Date& date2) {
    std::tm tm1 = {0, 0, 0, date1.day, date1.month - 1, date1.year - 1900};  // months are 0-based in std::tm
    std::tm tm2 = {0, 0, 0, date2.day, date2.month - 1, date2.year - 1900};  // years since 1900

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    const int seconds_per_day = 60 * 60 * 24;

    // Return difference in days, positive if date1 > date2, negative if date1 < date2
    return static_cast<int>(std::difftime(time1, time2) / seconds_per_day);
}

int dateDifference(const std::string& date1, const std::string& date2) {
    Date d1 = parseDate(date1);
    Date d2 = parseDate(date2);

    return daysBetween(d2, d1);  // Switch d1 and d2 to get correct sign
}

int main() {
    std::string date1 = "2024-10-01";
    std::string date2 = "2026-10-01";

    int diff = dateDifference(date2, date1);
    std::cout << "Difference in days: " << diff << std::endl;  // Expected output should be -1

    return 0;
}
