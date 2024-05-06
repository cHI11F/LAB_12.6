#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.6/LAB_12.6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestQueueOperations)
        {
            QueueList list_queue;
            QueueArray array_queue;
            QueueTwoStacks two_stacks_queue;

            // Перевірка додавання елементів
            list_queue.enqueue(1);
            array_queue.enqueue(1);
            two_stacks_queue.enqueue(1);

            Assert::AreEqual(1, list_queue.size());
            Assert::AreEqual(1, array_queue.size());
            Assert::AreEqual(1, two_stacks_queue.size());

            // Перевірка вилучення елементів
            Assert::AreEqual(1, list_queue.dequeue());
            Assert::AreEqual(1, array_queue.dequeue());
            Assert::AreEqual(1, two_stacks_queue.dequeue());

            Assert::AreEqual(0, list_queue.size());
            Assert::AreEqual(0, array_queue.size());
            Assert::AreEqual(0, two_stacks_queue.size());

            // Перевірка чи черга порожня
            Assert::IsTrue(list_queue.is_empty());
            Assert::IsTrue(array_queue.is_empty());
            Assert::IsTrue(two_stacks_queue.is_empty());
        }
    };
}
