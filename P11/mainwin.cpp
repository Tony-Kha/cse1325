#include "mainwin.h"

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}} {

    set_default_size(640, 480);
    set_title("Manga Magic");

    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //     N E W
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);

    //      S A V E 
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //      S A V E   A S
    Gtk::MenuItem *menuitem_saveAs = Gtk::manage(new Gtk::MenuItem("_Save as", true));
    menuitem_saveAs->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveAs);

    //      O P E N
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //      Q U I T
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //      H E L P
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //      A B O U T
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    //      I N S E R T
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //           T O O L
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);

    //           P L A N T
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
    
        //           M U L C H
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
    insertmenu->append(*menuitem_mulch);

        //          C U S T O M E R
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_new_customer_click();});
    insertmenu->append(*menuitem_customer);

    //          O R D E R 
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_new_order_click();});
    insertmenu->append(*menuitem_order);

    //          V I E W
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //      P R O D U C T S
    Gtk::MenuItem *menuitem_products = Gtk::manage(new Gtk::MenuItem("_Products", true));
    menuitem_products->signal_activate().connect([this] {this->on_view_products_click();});
    viewmenu->append(*menuitem_products);

    //      C U S T O M E R S
    Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
    menuitem_customers->signal_activate().connect([this] {this->on_view_customers_click();});
    viewmenu->append(*menuitem_customers);

    //      O R D E R S
    Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menuitem_orders->signal_activate().connect([this] {this->on_view_orders_click();});
    viewmenu->append(*menuitem_orders);

    //      T O O L B A R
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //      N E W S T O R E
    Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_store_button->set_tooltip_markup("Create a new store, discarding any in progress");
    new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
    toolbar->append(*new_store_button);

    //      O P E N
    Gtk::ToolButton *open_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_store_button->set_tooltip_markup("Open a store file");
    open_store_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_store_button);

    //      S A V E
    Gtk::ToolButton *save_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_store_button->set_tooltip_markup("Save the current store");
    save_store_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_store_button);

    //      S A V E A S
    Gtk::ToolButton *save_as_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_store_button->set_tooltip_markup("Save store as another file");
    save_as_store_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as_store_button);

    //      I N S E R T C
    Gtk::Image* insert_customer_button_image = Gtk::manage(new Gtk::Image{"insertCustomer.png"});
    Gtk::ToolButton *insert_customer_button = Gtk::manage(new Gtk::ToolButton(*insert_customer_button_image));
    insert_customer_button->set_tooltip_markup("Insert new customer");
    insert_customer_button->signal_clicked().connect([this] {this->on_new_customer_click();});
    toolbar->append(*insert_customer_button);

    //      I N S E R T O
    Gtk::Image* insert_order_button_image = Gtk::manage(new Gtk::Image{"insertOrder.png"});
    Gtk::ToolButton *insert_order_button = Gtk::manage(new Gtk::ToolButton(*insert_order_button_image));
    insert_order_button->set_tooltip_markup("Insert new order");
    insert_order_button->signal_clicked().connect([this] {this->on_new_order_click();});
    toolbar->append(*insert_order_button);

    //      I N S E R T T
    Gtk::Image* insert_tool_button_image = Gtk::manage(new Gtk::Image{"insertTool.png"});
    Gtk::ToolButton *insert_tool_button = Gtk::manage(new Gtk::ToolButton(*insert_tool_button_image));
    insert_tool_button->set_tooltip_markup("Insert new tool");
    insert_tool_button->signal_clicked().connect([this] {this->on_new_tool_click();});
    toolbar->append(*insert_tool_button);

    //      I N S E R T P
    Gtk::Image* insert_plant_button_image = Gtk::manage(new Gtk::Image{"insertPlant.png"});
    Gtk::ToolButton *insert_plant_button = Gtk::manage(new Gtk::ToolButton(*insert_plant_button_image));
    insert_plant_button->set_tooltip_markup("Insert new plant");
    insert_plant_button->signal_clicked().connect([this] {this->on_new_plant_click();});
    toolbar->append(*insert_plant_button);

    //      I N S E R T M
    Gtk::Image* insert_mulch_button_image = Gtk::manage(new Gtk::Image{"insertMulch.png"});
    Gtk::ToolButton *insert_mulch_button = Gtk::manage(new Gtk::ToolButton(*insert_mulch_button_image));
    insert_mulch_button->set_tooltip_markup("Insert new mulch");
    insert_mulch_button->signal_clicked().connect([this] {this->on_new_mulch_click();});
    toolbar->append(*insert_mulch_button);

    //      V I E W C
    Gtk::Image* view_customers_button_image = Gtk::manage(new Gtk::Image{"viewCustomers.png"});
    Gtk::ToolButton *view_customers_button = Gtk::manage(new Gtk::ToolButton(*view_customers_button_image));
    view_customers_button->set_tooltip_markup("View all customers");
    view_customers_button->signal_clicked().connect([this] {this->on_view_customers_click();});
    toolbar->append(*view_customers_button);

    //      V I E W O
    Gtk::Image* view_orders_button_image = Gtk::manage(new Gtk::Image{"viewOrders.png"});
    Gtk::ToolButton *view_orders_button = Gtk::manage(new Gtk::ToolButton(*view_orders_button_image));
    view_orders_button->set_tooltip_markup("View all orders");
    view_orders_button->signal_clicked().connect([this] {this->on_view_orders_click();});
    toolbar->append(*view_orders_button);

    //      V I E W P
    Gtk::Image* view_plants_button_image = Gtk::manage(new Gtk::Image{"viewPlants.png"});
    Gtk::ToolButton *view_plants_button = Gtk::manage(new Gtk::ToolButton(*view_plants_button_image));
    view_plants_button->set_tooltip_markup("View all plants");
    view_plants_button->signal_clicked().connect([this] {this->on_view_products_click();});
    toolbar->append(*view_plants_button);

    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);
    
    vbox->show_all();

    on_new_store_click();
}

Mainwin::~Mainwin() { }

void Mainwin::on_new_store_click() {
    delete store;
    store = new Store{"Store"};
}

void Mainwin::on_save_click(){
    try{    
        std::ofstream ofs{store->get_filename()};
        store->save(ofs);
    }catch(std::exception e){
        Gtk::MessageDialog{*this, "Unable to save store"}.run();
    }
}

void Mainwin::on_save_as_click(){
    Gtk::FileChooserDialog dialog("Please choose a file",
        Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_store = Gtk::FileFilter::create();
    filter_store->set_name("STORE files");
    filter_store->add_pattern("*.store");
    dialog.add_filter(filter_store);
    
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.store");

    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);
    int result = dialog.run();

    if(result == 1){
        store->set_filename(dialog.get_filename());
        on_save_click();
    }
}

void Mainwin::on_open_click(){
    Gtk::FileChooserDialog dialog("Please choose a file",
        Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_store = Gtk::FileFilter::create();
    filter_store->set_name("STORE files");
    filter_store->add_pattern("*.store");
    dialog.add_filter(filter_store);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.store");

    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);
    int result = dialog.run();

    if(result == 1){
        try{
            delete store;
            std::ifstream ifs{dialog.get_filename()};
            store = new Store{ifs};
            on_view_products_click();
        }catch(std::exception& e){
            Gtk::MessageDialog{*this, "Unable to open store"}.run();
        }
    }
}

void Mainwin::on_new_tool_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}

void Mainwin::on_new_plant_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        std::string species = get_string("Species?");
        double d = get_double("Exposure? (1) Shade (2) Part Sun (3) Sun");
        Exposure exposure = (d==1.0) ? Exposure::SHADE : ((d==3.0) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}

void Mainwin::on_new_mulch_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        int volume = get_int("Volume (ft³)?");
        int i = get_int("Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
        Material material;
        if(i == 1)       material = Material::RUBBER;
        else if (i == 2) material = Material::PINE;
        else if (i == 3) material = Material::CEDAR;
        else             material = Material::HARDWOOD;
        store->add_product(*(new Mulch{name, price, description, volume, material}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}

void Mainwin::on_new_customer_click() {
    Gtk::Dialog dialog{"Insert Customer", *this};

    Gtk::Grid grid;
    
    Gtk::Label t_name{"Name"};
    Gtk::Entry e_name;
    e_name.set_placeholder_text("First Name, Last Name");
    grid.attach(t_name, 0,0,1,1);
    grid.attach(e_name, 1,0,2,1);

    Gtk::Label t_phone{"Phone"};
    Gtk::Entry e_phone;
    e_phone.set_placeholder_text("xxx-xxx-xxxx");
    grid.attach(t_phone, 0,1,1,1);
    grid.attach(e_phone, 1,1,2,1);

    Gtk::Label t_email{"Email"};
    Gtk::Entry e_email;
    e_email.set_placeholder_text("xxx@domain.com");
    grid.attach(t_email, 0,2,1,1);
    grid.attach(e_email, 1,2,2,1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Insert", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    
    int response;
    
    dialog.show_all();

    if((response = dialog.run()) == Gtk::RESPONSE_OK){
        store->add_customer(*(new Customer{e_name.get_text(), e_phone.get_text(), e_email.get_text()}));
        on_view_customers_click();
    }    
}

void Mainwin::on_new_order_click(){
    int orderNum;
    std::ostringstream oss;

    Gtk::Dialog dialog{"Order for which custoemr?", *this};
    Gtk::ComboBoxText customer_list;
    for(int i=0; i<store->customers(); ++i){
        oss.str("");
        oss << store->customer(i);
        customer_list.append(oss.str());
    }
    customer_list.set_active(0);
    dialog.get_content_area()->add(customer_list);

    dialog.add_button("Start Order", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    
    dialog.show_all();
    
    if(dialog.run() == Gtk::RESPONSE_CANCEL) return;
    else{
    
        orderNum = store->add_order(store->customer(customer_list.get_active_row_number()));
    
        Gtk::MessageDialog oDialog{*this, "Add to Order " + std::to_string(orderNum)};
        Gtk::HBox qbox;
        Gtk::Label quan{"Quantity"};
        qbox.add(quan);
        Gtk::SpinButton quantity;
        quantity.set_range(1.0, 99.0);
        quantity.set_increments(1.0, 5.0);
        qbox.add(quantity);
        oDialog.get_content_area()->add(qbox);

        Gtk::ComboBoxText product_list;
        for(int i=0; i<store->products(); ++i){
            oss.str("");
            oss << store->product(i);
            product_list.append(oss.str());
        }
        oDialog.get_content_area()->add(product_list);

        oDialog.add_button("Add to order", 1);
        oDialog.add_button("Order complete", 0);

        while(true){
            oss.str("");
            oss << *store->_orders[orderNum];
            oDialog.set_secondary_text(oss.str());
            oDialog.show_all();
            
            if(oDialog.run() == 1)
                store->add_item(orderNum, store->product(product_list.get_active_row_number()), static_cast<int>(quantity.get_value()));
            else
                break;
        }
    }

    on_view_orders_click();
}

void Mainwin::on_view_products_click() {
    std::string s = "Current Products\n----------------\n\n";
    for(int i=0; i<store->products(); ++i) {
        std::ostringstream oss;
        oss << store->product(i) << '\n';
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin::on_view_customers_click(){
    std::string s = "Current Customers\n----------------\n\n";
    for(int i=0; i<store->customers(); ++i) {
        std::ostringstream oss;
        oss << store->customer(i) << '\n';
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin::on_view_orders_click(){
    std::string s = "Current Orders\n----------------\n\n";
    for(int i=0; i<store->_orders.size(); ++i) {
        std::ostringstream oss;
        oss << *store->_orders[i] << '\n';
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin::on_about_click(){
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this);
    dialog.set_program_name("Store");
    auto logo = Gdk::Pixbuf::create_from_file("store.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Tony Kha (also prof Rice)"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"Logo by clipartmax.com, licensed for personal use https://www.clipartmax.com/middle/m2i8N4d3H7G6K9A0_retail-shops-retail-store-vector-png/ \nIcons by: "};
    artists.push_back("https://www.thenounproject.com/term/new-user/70749/ \n");
    artists.push_back("https://www.kindpng.com/imgv/iiTmxbw_shopping-cart-png-download-image-shopping-cart-svg/ \n");
    artists.push_back("https://www.pngwing.com/en/free-png-moyeb \n");
    artists.push_back("https://www.cleanpng.com/png-plant-computer-icons-botany-2463193/preview.html \n");
    artists.push_back("https://www.getsoil.com/products/mulches/ \n");
    artists.push_back("https://favpng.com/png_view/membership-users-group-computer-icons-png/kHhDb9NE \n");
    artists.push_back("https://favpng.com/png_view/receipt-receipt-invoice-png/cuZCZ3Xg \n");
    artists.push_back("https://www.klipartz.com/en/sticker-png-polbb \n");
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_quit_click() {
    close();
}

std::string Mainwin::get_string(std::string prompt) {
    EntryDialog edialog(*this, "<big>New Product</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text(prompt, true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}
