#include <gmock/gmock.h>
#include <string>
using namespace std;
using namespace testing;

class Soundex{
public:
    std::string encode(const std::string& word) const {
        return zeroPad(word);
    }

    private:
        std::string zeroPad(const std::string& word) const {
            return word + "000";
        }
};

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
    Soundex soundex;

    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, testing::Eq("A000"));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}