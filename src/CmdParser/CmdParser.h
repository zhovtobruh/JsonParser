#include<string> 
#include<boost/program_options.hpp> 


class CmdParser
{ 
  public:
    CmdParser( int arg_counter = 0, char** argv = nullptr );
    ~CmdParser();
    std::string get_input_file();
    std::string get_output_file();
    void parse_cla();
  private:
    std::string inp_file;
    std::string out_file;
    int opt_size; 
    char** arg_opts;
};
