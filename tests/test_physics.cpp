#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "../src/Physics.h"

struct TestCase 
{
    std::string testName;
    double velocity;
    double angle;
    double expectedRange;
};

bool checkClosePercentage(const std::string& testName, double expected, double actual, double allowedPercentError)
{
    if (expected == 0.0) 
    {
        return std::abs(actual) < 0.00001; 
    }

    double percentDifference = (std::abs(actual - expected) / expected) * 100.0;
    
    if (percentDifference < allowedPercentError)
    {
        std::cout << "PASS: " << testName << " (Error: " << percentDifference << "%)\n";
        return true;
    }
    else
    {
        std::cout << "FAIL: " << testName << " (expected " << expected 
                  << ", got " << actual << " | Error: " << percentDifference << "%)\n";
        return false;
    }
}

int main() 
{ 
    std::vector<TestCase> testCases = {
        {"Range: 20m/s, 45deg", 20.0, 45.0, 40.77},
        {"Range: 25m/s, 45deg", 25.0, 45.0, 63.71},
        {"Range: 35m/s, 45deg", 35.0, 45.0, 124.87},
        {"Range: 50m/s, 30deg", 50.0, 30.0, 220.70},
        {"Range: 100m/s, 45deg", 100.0, 45.0, 1019.37},
        {"Range: 150m/s, 45deg", 150.0, 45.0, 2293.58},
        {"Range: 200m/s, 35deg", 200.0, 35.0, 3831.32}
    };
    
    double allowedPercentError = 0.1; 
    int passedCount = 0;
    int failedCount = 0;
    std::cout << "--- RUNNING PERCENTAGE-BASED TESTS ---\n";
    for (const auto& test : testCases)
    {
        double actualRange = Physics::range(test.velocity, test.angle, Physics::GRAVITY);
        
        if (checkClosePercentage(test.testName, test.expectedRange, actualRange, allowedPercentError)) 
        {
            passedCount++;
        } 
        else 
        {
            failedCount++;
        }
    }
    std::cout << "\n--- TEST SUMMARY ---\n";
    std::cout << "Total Tests Run: " << testCases.size() << "\n";
    std::cout << "Passed: " << passedCount << "\n";
    std::cout << "Failed: " << failedCount << "\n";

    if (failedCount == 0) 
    {
        std::cout << "SUCCESS: All tests passed within the " << allowedPercentError << "% margin!\n";
    } 
    else 
    {
        std::cout << "WARNING: Some tests failed outside the " << allowedPercentError << "% margin.\n";
    }
}