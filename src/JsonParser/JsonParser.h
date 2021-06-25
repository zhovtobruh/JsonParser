#include <boost/property_tree/ptree.hpp>
#include<boost/property_tree/json_parser.hpp>
#include<string> 



class JsonParser{
  public:
    JsonParser(std::string json_file, std::string out_file);
    void print();
    ~JsonParser();
    
  private:
    boost::property_tree::ptree root_tree; 
    void print_json(boost::property_tree::ptree&, std::string); 
    void print_str(std::string to_print);
    bool print_to_file;
    std::ofstream out;
};
