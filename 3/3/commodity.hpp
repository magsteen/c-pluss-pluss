#include <string>

namespace commodity
{
    class Commodity {
    public:
        Commodity(const std::string &name_, unsigned int id, double price_);
        
        const std::string &get_name() const;
        unsigned int get_id() const;
        double get_price() const;
        double get_price(double quantity) const;
        double set_price(double price_);
        double get_price_with_sales_tax(double quantity) const;

    private:
        std::string name;
        unsigned int id;
        double price;
    };
}
