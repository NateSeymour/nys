#include <gtest/gtest.h>

#include "parser/TriggerParser.h"

using namespace std::chrono;

class TriggerParserFixture : public ::testing::Test
{
protected:
    TriggerParser parser;
};

TEST_F(TriggerParserFixture, SimpleInterval)
{
    time_point<system_clock> start_time;
    time_point<system_clock> trigger_time;

    start_time = std::chrono::system_clock::now();

    trigger_time = this->parser.Parse("every 10 minutes", start_time);
    ASSERT_TRUE(trigger_time == start_time + 10min);

    trigger_time = this->parser.Parse("every 3 hours", start_time);
    ASSERT_TRUE(trigger_time == start_time + 3h);

    trigger_time = this->parser.Parse("every 6 seconds", start_time);
    ASSERT_TRUE(trigger_time == start_time + 6s);

    trigger_time = this->parser.Parse("every 8 days", start_time);
    ASSERT_TRUE(trigger_time == start_time + days(8));

    trigger_time = this->parser.Parse("every 1 minute", start_time);
    ASSERT_TRUE(trigger_time == start_time + 1min);
}