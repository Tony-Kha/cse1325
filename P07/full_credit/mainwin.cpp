#include "mainwin.h"
#include <iostream>

std::string Mainwin::get_string(std::string prompt){
    std::string s = prompt;
    return s;
}

int Mainwin::get_int(std::string prompt){
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }
}

double Mainwin::get_double(std::string prompt){
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }
}



void Mainwin::on_new_store_click(){
    delete store;
    std::string _store;
    store = new Store(_store);
}
void Mainwin::on_new_tool_click(){
    Gtk::Dialog dialog{"New Tool", *this};
    Gtk::Grid grid;
    
    Gtk::Label t_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(t_name, 0,0,1,1);
    grid.attach(e_name, 1,0,2,1);

    Gtk::Label t_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(t_price, 0,1,1,1);
    grid.attach(e_price, 1,1,2,1);

    Gtk::Label t_desc{"Description"};
    Gtk::Entry e_desc;
    grid.attach(t_desc, 0,2,1,1);
    grid.attach(e_desc, 1,2,2,1);
    
    dialog.get_content_area()->add(grid);
    dialog.add_button("Enter", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_DELETE_EVENT);
    dialog.show_all();
    int response = dialog.run();
    while(response == Gtk::RESPONSE_OK){
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        if (e_price.get_text().size() == 0) {e_price.set_text("*required*"); continue;}
        if (e_desc.get_text().size() == 0) {e_desc.set_text("*required*"); continue;}
        Tool newtool = Tool(get_string(e_name.get_text()), get_double(e_price.get_text()), get_string(e_desc.get_text()));
        this->store->add_product(newtool);
        on_view_products_click();
    }
}
Exposure Mainwin::get_exposure(int num){
    while(true){
        switch(num){
            case 0: return Exposure::SHADE;
            case 1: return Exposure::PARTSUN;
            case 2: return Exposure::SUN;
            default: std::cerr<<"INVALID SELECTION\n"<<std::endl;
        }
    }
}
void Mainwin::on_new_plant_click(){
    Gtk::Dialog dialog{"New Plant", *this};
    Gtk::Grid grid;
    
    Gtk::Label t_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(t_name, 0,0,1,1);
    grid.attach(e_name, 1,0,2,1);

    Gtk::Label t_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(t_price, 0,1,1,1);
    grid.attach(e_price, 1,1,2,1);

    Gtk::Label t_desc{"Description"};
    Gtk::Entry e_desc;  
    grid.attach(t_desc, 0,2,1,1);
    grid.attach(e_desc, 1,2,2,1);

    Gtk::Label t_spec{"Species"};
    Gtk::Entry e_spec;
    grid.attach(t_spec, 0,3,1,1);
    grid.attach(e_spec, 1,3,2,1);

    Gtk::Label t_expo{"Exposure"};
    Gtk::ComboBoxText e_expo;
    e_expo.append("Shade");
    e_expo.append("Part Sun");
    e_expo.append("Sun");
    e_expo.set_active(0);
    grid.attach(t_expo, 0,4,1,1);
    grid.attach(e_expo, 1,4,1,1);

    dialog.get_content_area()->add(grid);
    dialog.add_button("Enter", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_DELETE_EVENT);
    dialog.show_all();
    int response = dialog.run();
    
    while(response == Gtk::RESPONSE_OK){
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        if (e_price.get_text().size() == 0) {e_price.set_text("*required*"); continue;}
        if (e_desc.get_text().size() == 0) {e_desc.set_text("*required*"); continue;}
        if (e_spec.get_text().size() == 0) {e_spec.set_text("*required*"); continue;}
        Plant newplant(get_string(e_name.get_text()), get_double(e_price.get_text()), get_string(e_desc.get_text()), get_string(e_spec.get_text()), get_exposure(e_expo.get_active_row_number()));
        this->store->add_product(newplant);
        on_view_products_click();
    }
}
Material Mainwin::get_material(int num){
    while(true){
        switch(num){
            case 0: return Material::RUBBER;
            case 1: return Material::PINE;
            case 2: return Material::CEDAR;
            case 3: return Material::HARDWOOD;
            default: std::cerr<<"INVALID SELECTION\n"<<std::endl;
        }
   
 }
}
void Mainwin::on_new_mulch_click(){
    Gtk::Dialog dialog{"New Mulch", *this};
    Gtk::Grid grid;
    
    Gtk::Label t_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(t_name, 0,0,1,1);
    grid.attach(e_name, 1,0,2,1);

    Gtk::Label t_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(t_price, 0,1,1,1);
    grid.attach(e_price, 1,1,2,1);

    Gtk::Label t_desc{"Description"};
    Gtk::Entry e_desc;
    grid.attach(t_desc, 0,2,1,1);
    grid.attach(e_desc, 1,2,2,1);

    Gtk::Label t_vol{"Volume (ft^3)"};
    Gtk::Entry e_vol;
    grid.attach(t_vol, 0,3,1,1);
    grid.attach(e_vol, 1,3,2,1);

    Gtk::Label t_mat{"Material"};
    Gtk::ComboBoxText e_mat;
    e_mat.append("Rubber");
    e_mat.append("Pine");
    e_mat.append("Cedar");
    e_mat.append("Hardwood");
    e_mat.set_active(0);
    grid.attach(t_mat, 0,4,1,1);
    grid.attach(e_mat, 1,4,1,1);

    dialog.get_content_area()->add(grid);
    dialog.add_button("Enter", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_DELETE_EVENT);
    dialog.show_all();
    int response = dialog.run();
    
    while(response == Gtk::RESPONSE_OK){
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        if (e_price.get_text().size() == 0) {e_price.set_text("*required*"); continue;}
        if (e_desc.get_text().size() == 0) {e_desc.set_text("*required*"); continue;}
        if (e_vol.get_text().size() == 0) {e_vol.set_text("*required*"); continue;}
        Mulch newmulch = Mulch(get_string(e_name.get_text()), get_double(e_price.get_text()), get_string(e_desc.get_text()), get_int(e_vol.get_text()), get_material(e_mat.get_active_row_number()));
        this->store->add_product(newmulch);
        on_view_products_click();
    }
}
void Mainwin::on_view_products_click(){
    std::ostringstream oss;
    for(int i=0; store->products(); i++){
        oss<<store->product(i)<<std::endl;
    }
    display->set_text(oss.str());
}
void Mainwin::on_quit_click(){close();}

Mainwin::Mainwin() : store{nullptr} {
    set_default_size(400,200);
    set_title("M A N G A");

    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

   // on_new_store_click();

    //      F I L E
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
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

    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);

    vbox->show_all();
    on_new_store_click();
}

Mainwin::~Mainwin() {}





