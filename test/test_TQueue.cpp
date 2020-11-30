#include "Queue.h"

#include "../gtest/gtest.h"

TEST(TBitField, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> bf(3));
}
