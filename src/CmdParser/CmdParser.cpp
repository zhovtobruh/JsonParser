#include"CmdParser.h"
#include<iostream>
namespace po = boost::program_options;

CmdParser::CmdParser( int arg_counter, char** argv )
            :inp_file(), out_file(), arg_opts(nullptr), opt_size(arg_counter)
{
   if( arg_counter == 1)
   {
     std::cout<<"Input file name should be provided. Exit.\n";
     std::cout<<"For program usage run with options -h or --help \n";
     exit(1);
   
   }
   arg_opts = new char*[ opt_size];
   for(int i = 0; i < arg_counter; i++)
   {
     arg_opts[i] =  argv[i] ;
   }

}

void CmdParser::parse_cla()
{
    po::options_description desc("Allowed options");
    std::string inp, out;
    desc.add_options()
     ("help,h", "produce help message")
     ("input_file,i",   po::value<std::string>(&inp), "input file name with JSON data")
     ( "output_file,o", po::value<std::string>(&out)->default_value("std::cout"), "output file name");
  
     po::variables_map vm;
     po::store(po::parse_command_line(opt_size, arg_opts, desc), vm);
     po::notify( vm );  

     if (vm.count("help")) {
       std::cout << desc << "\n";
       exit(1);
     }
     inp_file = inp;
     out_file = out;
}

CmdParser::~CmdParser()
{
   delete[] arg_opts;
}

std::string CmdParser::get_input_file()
{
   return inp_file; 
}

std::string CmdParser::get_output_file()
{
   return out_file;
}
