#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

int get_int(std::string prompt){
    while(true){
        try{
            return std::stoi(get_string(prompt));
        } catch(std::exception& e){
            std::cer<<"ERROR: "<<e.what()<<std::endl;
        }   
    }
}

double get_double(std::string prompt){
    while(true){
        try{
            return std::stod(get_string(prompt));
        } catch(std::exception& e){
            std::cerr<<"ERROR: "<<e.what()<<std::endl;
        }
    }
}

std::string get_string(std::string prompt){
    std::string s;
    std::cout<<prompt;
    std::getline(std::cin, s);
    return s;
}

void Mainwin::on_new_store_click(){
    delete store;
    store = new Store();
}
void Mainwin::on_new_tool_click(){
    new Tool(get_string("Name? "), get_double("Price? "), get_string("Description? "));
}
Exposure get_exposure(){
    while(true){
        switch(get_int("Select Exposure (1) Shade (2) Part Sun (3) Sun? ")){
            case 1: return Exposure::SHADE;
            case 2: return Exposure::PARTSUN;
            case 3: return Exposure::SUN;
            default: std::cerr<<"INVALID SELECTION\n"<<std::endl;
        }
    }
}
void Mainwin::on_new_plant_click(){
    new Plant(get_string("Name? "), get_double("Price? "), get_string("Description? "), get_string("Species? "), get_exposure());
}
Material get_material(){
    while(true){
        switch(get_int("Select Material (1) Rubber (2) Pine (3) Cedar (4) Hardwood? ")){
            case 1: return Material::RUBBER;
            case 2: return Material::PINE;
            case 3: return Material::CEDAR;
            case 4: return Material::HARDWOOD;
            default: std::cerr<<"INVALID SELECTION\n"<<std::endl;
        }
    }
}
void Mainwin::on_new_mulch_click(){
    new Mulch(get_string("Name? "), get_double("Price? "), get_string("Description? "), get_int("Volume (ft^3)? "), get_material());
}
void Mainwin::on_view_products_click(){
    
}
void Mainwin::on_quit_click(){close();}

Mainwin::Mainwin(){
    set_default_size(400,200);
    set_title("M A N G A");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Vbox);
    add(*vbox);

    Gtk::MenuBar *member = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*member, Gtk::PACK_SHRINK, 0);

    //      F I L E
    Gtk::MenuBar *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
        //  Q U I T
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //      I N S E R T
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);
        //  T O O L
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);
        //  P L A N T
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
        // M U L C H
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
    insertmenu->append(*menuitem_mulch);

    vbox->show_all();
    
    on_new_store_click();
}

Mainwin::~Mainwin(){}





