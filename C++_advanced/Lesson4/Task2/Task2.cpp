#include <Catch2/catch_test_macros.hpp>
#include <Catch2/catch_session.hpp>
#include <iostream>
#include "my_list.h"



TEST_CASE("test_add_delete")
{
    List* list = new List;
    SECTION("PushBack")
    {
        list->PushBack(5);
        list->PushBack(10);
        list->PushBack(20);
        CHECK(list->Size() == 3);
    }

    SECTION("PushFront")
    {
        list->PushBack(5);
        list->PushFront(30);
        CHECK(list->Size() == 2);
    }

    SECTION("PopBack")
    {
        list->PushBack(5);
        list->PushBack(10);
        list->PushBack(20);
        list->PushFront(30);
        list->PopBack();

        CHECK(list->Size() == 3);
    }

    SECTION("PopFront")
    {
        list->PushBack(5);
        list->PushBack(10);
        list->PushBack(20);
        list->PushFront(30);
        list->PopBack();
        list->PopFront();

        CHECK(list->Size() == 2);
    }

    SECTION("Exceptions")
    {
        REQUIRE_THROWS(list->PopBack());
        REQUIRE_THROWS(list->PopFront());
    }
};


int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}