#ifndef VESSEL__VISIBILITY_CONTROL_H_
#define VESSEL__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define VESSEL_EXPORT __attribute__ ((dllexport))
    #define VESSEL_IMPORT __attribute__ ((dllimport))
  #else
    #define VESSEL_EXPORT __declspec(dllexport)
    #define VESSEL_IMPORT __declspec(dllimport)
  #endif
  #ifdef VESSEL_BUILDING_LIBRARY
    #define VESSEL_PUBLIC VESSEL_EXPORT
  #else
    #define VESSEL_PUBLIC VESSEL_IMPORT
  #endif
  #define VESSEL_PUBLIC_TYPE VESSEL_PUBLIC
  #define VESSEL_LOCAL
#else
  #define VESSEL_EXPORT __attribute__ ((visibility("default")))
  #define VESSEL_IMPORT
  #if __GNUC__ >= 4
    #define VESSEL_PUBLIC __attribute__ ((visibility("default")))
    #define VESSEL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define VESSEL_PUBLIC
    #define VESSEL_LOCAL
  #endif
  #define VESSEL_PUBLIC_TYPE
#endif

#endif  // VESSEL__VISIBILITY_CONTROL_H_
