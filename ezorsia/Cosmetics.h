#pragma once
#include <windows.h>

namespace Cosmetics {
    // Memory Addresses
    extern const DWORD dwHairFaceUncap1;
    extern const DWORD dwHairFaceUncap2;
    extern const int dwHairFaceUncapNOPs;
    extern const DWORD dwHairFaceUncapCapRetn;
    extern const DWORD dwHairFaceUncapFaceRetn;
    extern const DWORD dwHairFaceUncapHairRetn;
    extern const DWORD dwHairFaceUncapRetn;

    // Function Declarations
    void HairFaceIdUncap1();
    void HairFaceIdUncap2();
    void ApplyEdits();
}