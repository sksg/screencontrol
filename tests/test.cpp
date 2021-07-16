#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <screencontrol.hpp>

TEST_CASE( "List all screens", "[list screens]" ) {
    list_screens();
}