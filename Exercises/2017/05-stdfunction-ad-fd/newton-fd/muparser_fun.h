#ifndef HAVE_MUPARSER_FUN_H
#  define HAVE_MUPARSER_FUN_H

#include <muParser.h>
#include <memory>
#include <string>

class muparser_fun
{
private :

  double var;
  mu::Parser p;
  
public :

  muparser_fun (const muparser_fun & m)
    : p (m.p)
  { p.DefineVar ("x", &var); };
    
  muparser_fun (const std::string & s)
  {
    try
      {
        p.DefineVar ("x", &var);
        p.SetExpr (s);
      }
    catch (mu::Parser::exception_type &e)
      { std::cerr << e.GetMsg () << std::endl; }
  };

  double operator() (double x)
  {
    double y;
    var = x;
    try
      { y = p.Eval (); }
    catch (mu::Parser::exception_type &e)
      { std::cerr << e.GetMsg () << std::endl; }
    return (y);
  };

};

#endif
