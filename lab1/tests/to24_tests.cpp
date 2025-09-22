#include "to24.h"
#include <gtest/gtest.h>


TEST(To24Tests, BasicExamples) {
ASSERT_TRUE(to24("8:00 pm") == "2000");
ASSERT_TRUE(to24("08:00 PM") == "2000");
ASSERT_TRUE(to24("12:00 am") == "0000");
ASSERT_TRUE(to24("12:00 pm") == "1200");
ASSERT_TRUE(to24("1:05 am") == "0105");
}


TEST(To24Tests, InvalidInputs) {
ASSERT_TRUE(to24("25:00 pm") == "");
ASSERT_TRUE(to24("9:60 am") == "");
ASSERT_TRUE(to24("hello") == "");
}


int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
