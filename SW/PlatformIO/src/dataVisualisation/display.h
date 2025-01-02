#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

namespace DataVisualisation {

    class Display {
        public:
            static void setup();
            static void clear();
            static void showNumber(int number);
    };
}
