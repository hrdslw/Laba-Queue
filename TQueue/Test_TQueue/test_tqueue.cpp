#include "../TQueue/TQueue.h"

#include "gtest.h"


TEST(TQueue, can_create_queue_with_pozitive_length)
{
	ASSERT_NO_THROW(TQueue<int> s(1));
}
TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> s(-1));
}
TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> a(3);
	ASSERT_NO_THROW(TQueue<int> s(a));
}
TEST(TQueue, can_assign_queues)
{
	TQueue<int> a(1);
	TQueue<int> s(2);
	ASSERT_NO_THROW(a = s);
}
TEST(TQueue, assign_operator_change_size)
{
	TQueue<int> a(7);
	TQueue<int> s(9);
	a = s;
	EXPECT_EQ(9, a.GetMaxSize());
}
TEST(TQueue, assigned_queues_are_equal)
{
	TQueue<int> a(2);
	TQueue<int> s(3);
	a = s;
	for (int i = 0; i < 3; i++)
	{
		a.Push(i);
		s.Push(i);
	}
	EXPECT_EQ(a.GetMaxSize(), s.GetMaxSize());
	EXPECT_EQ(a.GetTail(), s.GetTail());
	EXPECT_EQ(a.GetHead(), s.GetHead());
	EXPECT_EQ(a.GetCurSize(), s.GetCurSize());
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(a.Pop(), s.Pop());
	}
}
TEST(TQueue, assigned_queues_have_different_memories)
{
	TQueue<int> a(2);
	TQueue<int> s(3);
	a = s;
	a.Push(1);
	s.Push(2);
	EXPECT_NE(a.Pop(), s.Pop());
}
TEST(TQueue, copied_queue_has_own_memory)
{
	TQueue<int> a(4);
	TQueue<int> s(a);
	s.Push(1);
	ASSERT_NO_THROW(a.IsEmpty());
	ASSERT_NO_THROW(s.IsEmpty());
	EXPECT_NE(a.IsEmpty(), s.IsEmpty());
}
TEST(TQueue, can_push_elem_in_empty_queue)
{
	TQueue<int> a(5);
	ASSERT_TRUE(a.IsEmpty());
	ASSERT_NO_THROW(a.Push(1));
}
TEST(TQueue, cant_push_elem_in_full_queue)
{
	TQueue<int> a(1);
	a.Push(1);
	ASSERT_ANY_THROW(a.Push(1));
}
TEST(TQueue, can_pop_elem_from_not_empty_queue)
{
	TQueue<int> a(1);
	a.Push(1);
	ASSERT_NO_THROW(a.Pop());
}
TEST(TQueue, cant_pop_elem_from_empty_queue)
{
	TQueue<int> a(5);
	ASSERT_ANY_THROW(a.Pop());
}
TEST(TQueue, method_GetMaxSize_is_correct)
{
	TQueue<int> a(10);
	int i = a.GetMaxSize();
	EXPECT_EQ(i, a.GetMaxSize());
}
TEST(TQueue, method_GetHead_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	int i = a.GetHead();
	EXPECT_EQ(i, a.GetHead());
}
TEST(TQueue, method_GetTail_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	int i = a.GetTail();
	EXPECT_EQ(i, a.GetTail());
}
TEST(TQueue, method_GetCurSize_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	int i = a.GetCurSize();
	EXPECT_EQ(i, a.GetCurSize());
}
TEST(TQueue, method_Top_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	EXPECT_EQ(a.Pop(), a.Front());
}

