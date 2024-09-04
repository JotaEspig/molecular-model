#include "app.hpp"

int main() {
  App app{true};
  app.set_title("Bencke cria");
  app.set_height(600);
  app.set_width(600);
  app.main_loop();
  return 0;
}
