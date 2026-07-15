#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "random.h"

namespace example
{

TEST(random, get)
{
	random rnd;
	EXPECT_EQ(rnd.get(), (int)42);
}

}
