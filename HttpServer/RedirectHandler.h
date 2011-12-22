////////////////////////////////////////////////////////////////////////////////
/// @brief redirect handler
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2010-2011 triagens GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Copyright 2011, triagens GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_FYN_HTTP_SERVER_REDIRECT_HANDLER_H
#define TRIAGENS_FYN_HTTP_SERVER_REDIRECT_HANDLER_H 1

#include <Basics/Common.h>

#include "Rest/HttpHandler.h"

namespace triagens {
  namespace rest {

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief redirect handler
    ////////////////////////////////////////////////////////////////////////////////

    class RedirectHandler : public HttpHandler {
      public:

        ////////////////////////////////////////////////////////////////////////////////
        /// @brief factory methods
        ////////////////////////////////////////////////////////////////////////////////

        static HttpHandler* create (HttpRequest* request, void* redirect) {
          char const* rd = reinterpret_cast<char const*>(redirect);

          return new RedirectHandler(request, rd);
        }

      public:

        ////////////////////////////////////////////////////////////////////////////////
        /// @brief constructor
        ////////////////////////////////////////////////////////////////////////////////

        RedirectHandler (HttpRequest* request, string const& redirect);

      public:

        ////////////////////////////////////////////////////////////////////////////////
        /// {@inheritDoc}
        ////////////////////////////////////////////////////////////////////////////////

        bool isDirect () {
          return true;
        }

        ////////////////////////////////////////////////////////////////////////////////
        /// {@inheritDoc}
        ////////////////////////////////////////////////////////////////////////////////

        status_e execute ();

        ////////////////////////////////////////////////////////////////////////////////
        /// {@inheritDoc}
        ////////////////////////////////////////////////////////////////////////////////

        void handleError (basics::TriagensError const&);

      private:
        string _redirect;
    };
  }
}

#endif
