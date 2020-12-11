#include "queue.h"
#include "../gtest/gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> queue(5));
}

TEST(TQueue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int> queue(5));
}

TEST(TQueue, can_create_queue_with_different_types)
{
  ASSERT_NO_THROW(TQueue<int> queue_0(5));
  ASSERT_NO_THROW(TQueue<char> queue_1(5));
}

TEST(TQueue, cannot_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> queue(-5));
}

TEST(TQueue, can_create_copy_of_queue)
{
  TQueue<char> queue_0(5);
  for (int i = 0; i < queue_0.GetSize(); i++)
    queue_0.Put('a' + 1);

  ASSERT_NO_THROW(TQueue<char> queue_1(queue_0));
}

TEST(TQueue, end_copy_queue_equal_end_original_queue)
{
  TQueue<char> queue_0(5);
  for (int i = 0; i < queue_0.GetSize(); i++)
    queue_0.Put('a' + 1);
  TQueue<char> queue_1(queue_0);

  EXPECT_EQ(queue_0.Get(), queue_1.Get());
}

TEST(TQueue, can_put_elem)
{
  TQueue<int> queue(5);

  ASSERT_NO_THROW(queue.Put(-1));
}

TEST(TQueue, can_get_elem)
{
  TQueue<int> queue(5);
  queue.Put(-1);

  EXPECT_EQ(-1, queue.Get());
}

TEST(TQueue, can_assign_queue)
{
  TQueue<int> queue_0(5);
  TQueue<int> queue_1(5);
  for (int i = 0; i < queue_0.GetSize(); i++)
    queue_0.Put((int)i);

  ASSERT_NO_THROW(queue_1 = queue_0);
}

TEST(TQueue, end_result_assignemt_equal_end_original_queue)
{
  TQueue<int> queue_0(5);
  TQueue<int> queue_1(5);
  for (int i = 0; i < queue_0.GetSize(); i++)
    queue_0.Put(i);
  queue_1 = queue_0;

  EXPECT_EQ(queue_0.Get(), queue_1.Get());
}

TEST(TQueue, can_control_empty_of_queue)
{
  TQueue<int> queue(5);

  ASSERT_NO_THROW(queue.IsEmpty());
  EXPECT_EQ(1, queue.IsEmpty());
}

TEST(TQueue, can_control_full_of_queue)
{
  TQueue<int> queue(5);

  for (int i = 0; i < queue.GetSize(); i++)
    queue.Put(i);

  ASSERT_NO_THROW(queue.IsFull());
  EXPECT_EQ(1, queue.IsFull());
}

TEST(TQueue, ring_buffer)
{
  TQueue<int> queue(3);
  queue.Put(0);
  queue.Put(1);
  queue.Put(2);

  EXPECT_EQ(1, queue.IsFull());
  ASSERT_NO_THROW(queue.Put(3));
}

