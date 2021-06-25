#include"CmdParser.h"
#include"JsonParser.h" 
#include<iostream> 

int main(int argc, char* argv[] )
{
   CmdParser parser(argc, argv);
   parser.parse_cla();
   std::string inp_file = parser.get_input_file();
   std::string out_file = parser.get_output_file();
   std::cout<<"Parced options:\n"<<
       "Input json file - "<<inp_file<<std::endl<<
       "Output file - "<<out_file<<std::endl;
       
   JsonParser jParser(inp_file, out_file);
   jParser.print();
   
   
   return 0; 
}

