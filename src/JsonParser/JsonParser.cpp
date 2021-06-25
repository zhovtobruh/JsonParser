#include"JsonParser.h"
#include<fstream>
#include<iostream>
#include<exception>

JsonParser::JsonParser(std::string json_file, std::string out_file)
      :root_tree(), print_to_file(false), out()
{
   std::ifstream inp;
   inp.open( json_file );
   if( !inp )
   {
      std::cout<<"Can not open file "<<
      json_file<<". Check that file exists. Exit."<<std::endl;
      exit(1);
   }
   inp.close();
   try{
     boost::property_tree::json_parser::read_json(json_file, root_tree);
   }catch( std::exception ex )
   {
     std::cout<<"Cannot parse json file "<<std::endl;
     std::cout<<ex.what()<<std::endl;
     std::cout<<"Exit."<<std::endl;
   }
   if(out_file == "std::cout")
   {
      print_to_file = false;
   }else{
      out.open(out_file);
      print_to_file = true;
   } 

}

JsonParser::~JsonParser()
{
   if(print_to_file) out.close();
}

void JsonParser::print()
{
  int root_size = root_tree.size();
  if( root_size == 0 )
  {
    std::string str = "Empy json file";
    this->print_str(str);
    return;
  }
  this->print_json(root_tree, "");

}


void JsonParser::print_str(std::string to_print)
{
   if(print_to_file)
   {
      out<<to_print<<std::endl;
    }else{
      std::cout<<to_print<<std::endl;
    }
}

void JsonParser::print_json(boost::property_tree::ptree& pt, std::string path)
{
  
   std::string data = pt.data();
   std::string str_count;
   std::string path_str;
   if( data != "" )
   {
     if (data == "null" ) data = "";
     std::string data_str = (path =="") ? data: path+"\t"+data;
     this->print_str(data_str);
     return;
   }
   boost::property_tree::ptree child; 
   int count = 0;
   for(auto iter = pt.begin(); iter != pt.end(); iter++)
   {
     std::string key = iter->first; 
     child = iter->second;
     //std::cout<<" Key "<<key<<std::endl;
     if(key  == "")
     {
       str_count = std::to_string(count);
       path_str = path+"["+str_count+"]";
       this->print_json(child,path_str);
       count++;
     
     }else{
       path_str = (path == "") ? key: path+"."+key ;
       this->print_json(child,path_str);
     
     } 
     
  
   }

}; 
