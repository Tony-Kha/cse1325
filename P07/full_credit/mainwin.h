#ifndef _MAINWIN_H
#define _MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window{
    private:       
        Store *store;
        Gtk::Label *display;
        int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
        Exposure get_exposure(int num);
        Material get_material(int num);
    protected:
        void on_new_store_click();
        void on_new_tool_click();
        void on_new_plant_click();
        void on_new_mulch_click();
        void on_view_products_click();
        void on_quit_click();
    public:
        Mainwin();
        virtual ~Mainwin();
};

#endif
