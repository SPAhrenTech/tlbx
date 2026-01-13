/* Copyright (c) 2024 Big Ladder Software LLC. All rights reserved.
 * See the LICENSE file for additional terms and conditions. */

// unit test
#include "unit-test.hpp"

// tlbx
#include "cpx.hpp"

/*
 * cpx tests
 */
TEST(cpxTest, general)
{
    {
        cpx z(1., 2.);
        EXPECT_EQ(z.Re(), 1.);
        EXPECT_EQ(z.Im(), 2.);

        auto theta = atan2(z.Im(), z.Re());
        EXPECT_EQ(z.phase(), theta);
    }

  
}
