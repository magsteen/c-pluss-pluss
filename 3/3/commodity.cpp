#include "commodity.hpp"

const float TAX = 1.25;

namespace commodity
{
    Commodity::Commodity(const std::string &name_, unsigned int id_, double price_) 
        : name(name_), id(id_), price(price_) {}

    const std::string &Commodity::get_name() const {
        return name;
    }

    unsigned int Commodity::get_id() const {
        return id;
    }

    double Commodity::get_price() const {
        return price;
    }

    double Commodity::get_price(double quantity) const {
        return price * quantity;
    }

    double Commodity::set_price(double price_) {
        price = price_;
    }

    double Commodity::get_price_with_sales_tax(double quantity) const {
        return price * quantity * TAX;
    }
}
