///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Console.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Console FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef ControlMonadEffConsoleFFI_HH
#define ControlMonadEffConsoleFFI_HH

#include "PureScript/PureScript.hh"
#include <iostream>

namespace Control_Monad_Eff_Console {

  using namespace PureScript;

  inline auto log(const any& s) -> any {
    return [=]() -> any {
      std::cout << s.cast<string>() << std::endl;
      return Prelude::unit;
    };
  }

  inline auto error(const any& s) -> any {
    return [=]() -> any {
      std::cerr << s.cast<string>() << std::endl;
      return Prelude::unit;
    };
  }

}

#endif // ControlMonadEffConsoleFFI_HH
