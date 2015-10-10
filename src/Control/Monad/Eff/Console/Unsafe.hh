///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unsafe.hh
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
#ifndef ControlMonadEffConsoleUnsafeFFI_HH
#define ControlMonadEffConsoleUnsafeFFI_HH

#include "PureScript/PureScript.hh"
#include <iostream>

namespace Control_Monad_Eff_Console_Unsafe {

  using namespace PureScript;

  inline auto logAny(const any& s) -> any {
    return [=]() -> any {
      std::cout << s.cast<string>() << std::endl;
      return Prelude::unit;
    };
  }

  inline auto errorAny(const any& s) -> any {
    return [=]() -> any {
      std::cerr << s.cast<string>() << std::endl;
      return Prelude::unit;
    };
  }

}

#endif // ControlMonadEffConsoleUnsafeFFI_HH
