#include <gtkmm.h>
#include <iostream>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  auto builder = Gtk::Builder::create();
  builder->add_from_file("assets/app.glade");

  Gtk::Window* win = nullptr;

  builder->get_widget("win", win);

  auto run = app->run(*win);

  delete win;

  return run;
}