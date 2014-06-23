////////////////////////////////////////////////////////////////////////////////
/// @brief memory mapped files in posix
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2014 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
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
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Dr. Oreste Costa-Panaia
/// @author Copyright 2014, ArangoDB GmbH, Cologne, Germany
/// @author Copyright 2012-2013, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_BASICS_C_MEMORY__MAP__POSIX_H
#define ARANGODB_BASICS_C_MEMORY__MAP__POSIX_H 1

#include "BasicsC/common.h"

#ifdef TRI_HAVE_POSIX_MMAP

#include <sys/mman.h>

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/// @brief create a wrapper for MAP_ANONYMOUS / MAP_ANON
///
/// On MacOS, MAP_ANON is available but not MAP_ANONYMOUS, on Linux it seems to
/// be vice versa
////////////////////////////////////////////////////////////////////////////////

#ifdef MAP_ANONYMOUS
#define TRI_MMAP_ANONYMOUS MAP_ANONYMOUS
#elif MAP_ANON
#define TRI_MMAP_ANONYMOUS MAP_ANON
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------

// Local Variables:
// mode: outline-minor
// outline-regexp: "/// @brief\\|/// {@inheritDoc}\\|/// @page\\|// --SECTION--\\|/// @\\}"
// End:
