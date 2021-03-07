
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("too long input problem") // קלט ארוך מדיי, עליו צריכה להיזרק שגיאה
{
    CHECK_THROWS(snowman(9123456789));
}
TEST_CASE("too short input problem") // קלט קצר מדיי, עליו צריכה להיזרק שגיאה
{
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(77));
    CHECK_THROWS(snowman(9));
}


TEST_CASE("'wrong numbers as input") // מספרים שלא אמורים להניב דבר כי הם לא חלק מתכנית ההדפסה
{
    CHECK_THROWS(snowman(434343434));
    CHECK_THROWS(snowman(434343334));
    CHECK_THROWS(snowman(77777777));
    CHECK_THROWS(snowman(24332535));
    CHECK_THROWS(snowman(75364969));
    CHECK_THROWS(snowman(6754435));
    CHECK_THROWS(snowman(13466575));
    CHECK_THROWS(snowman(89543445));
    CHECK_THROWS(snowman(788754345));
    CHECK_THROWS(snowman(677654536));
}


// עכשיו נבדוק מקרים בהם איש השלג יעבוד כמו שצריך
TEST_CASE("some working snowmans string checks")
 {
    CHECK(snowman(11111111)==string(" _===_\n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222)==string("  ---\n .....\n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(33333333)==string("   -\n  /_\\\n (O_O) \n/(> <)\\\n (___) "));
    CHECK(snowman(44444444)==string("  ---\n (_*_)\n (- -) \n (   ) \n (   ) "));
    CHECK(snowman(11114411)==string(" _===_\n (.,.) \n ( : ) \n ( : ) ")); // איש שלג קלאסי 
    CHECK(snowman(12344434)==string(" _===_\n (O.-) \n (> <) \n (   ) "));
    CHECK(snowman(12341234)==string(" _===_\n (O.-)/\n<(> <) \n (   ) ")); 
    CHECK(snowman(33232124)==string(" _\n /_\ \n \(o_O) \n (] [)> \n (   ) ")); // הדוגמא השניה מקובץ הדמו

   
}
