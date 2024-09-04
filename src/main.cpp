#include "app.hpp"

int main() {
    App app{true};
    app.set_title("Bencke cria");
    app.set_window_size(600, 600);
    app.main_loop();
    return 0;
}
