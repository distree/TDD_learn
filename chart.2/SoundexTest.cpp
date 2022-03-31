#include <gmock/gmock.h>
#include <string>
#include "Soundex.h"
using namespace std;
using namespace testing;

class SoundexEncoding: public Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
    auto encoded = soundex.encode("A");
    ASSERT_EQ(encoded, std::string("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits){
    auto encoded = soundex.encode("I");
    ASSERT_EQ(encoded, std::string("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits){
    ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter){
    ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoreVowelLikeLetters){
    ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants){
    ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}