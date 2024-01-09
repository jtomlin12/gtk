#include <gtkmm.h>
#include <iostream>

extern const unsigned char _binary_app_glade_start[];
extern const unsigned char _binary_app_glade_end[];

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  auto builder = Gtk::Builder::create();
  builder->add_from_string(std::string{_binary_app_glade_start, _binary_app_glade_end});

  Gtk::Window* win = nullptr;

  builder->get_widget("win", win);

  auto run = app->run(*win);

  delete win;

  return run;
}