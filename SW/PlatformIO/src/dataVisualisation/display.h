#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

namespace DataVisualisation {

    namespace Display { //change to namespace - no class needed - (just class if needed) // 4 byte less
        void setup();
        void clear();
        void showNumber(int number);
    };
}
