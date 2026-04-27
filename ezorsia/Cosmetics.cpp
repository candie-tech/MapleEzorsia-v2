#include "stdafx.h"
#include "Cosmetics.h"
#include "Memory.h"

namespace Cosmetics {
    // Define the memory addresses
    const DWORD dwHairFaceUncap1 = 0x005C94F3;
    const DWORD dwHairFaceUncap2 = 0x009ACA9B;
    const int dwHairFaceUncapNOPs = 18;
    const DWORD dwHairFaceUncapCapRetn = 0x005C9505;
    const DWORD dwHairFaceUncapFaceRetn = 0x005C95BF;
    const DWORD dwHairFaceUncapHairRetn = 0x005C958D;
    const DWORD dwHairFaceUncapRetn = 0x009ACAAD;

    // Implement the assembly hooks
    __declspec(naked) void HairFaceIdUncap1() {
        __asm {
            cmp eax, 0x2
            je FACE_RET
            cmp eax, 0x5
            je FACE_RET
            cmp eax, 0x3
            je HAIR_RET
            cmp eax, 0x4
            je HAIR_RET
            cmp eax, 0x6
            je HAIR_RET
            cmp eax, 0x7
            je HAIR_RET
            jmp CAP_RET
            FACE_RET :
            jmp dword ptr[dwHairFaceUncapFaceRetn]
                HAIR_RET :
                jmp dword ptr[dwHairFaceUncapHairRetn]
                CAP_RET :
                jmp dword ptr[dwHairFaceUncapCapRetn]
        }
    }

    __declspec(naked) void HairFaceIdUncap2() {
        __asm {
            cmp eax, 0x2
            je FACE_RET
            cmp eax, 0x5
            je FACE_RET
            cmp eax, 0x3
            je HAIR_RET
            cmp eax, 0x4
            je HAIR_RET
            cmp eax, 0x6
            je HAIR_RET
            cmp eax, 0x7
            je HAIR_RET
            jmp SKIN_RET
            FACE_RET :
            mov eax, 0x0
                mov ecx, 0x0
                jmp JMP_RET
                HAIR_RET :
            mov eax, 0x1
                mov ecx, 0x1
                jmp JMP_RET
                SKIN_RET :
            mov eax, 0x2
                mov ecx, 0x2
                jmp JMP_RET
                JMP_RET :
            jmp dword ptr[dwHairFaceUncapRetn]
        }
    }

    // Apply the Memory CodeCaves
    void ApplyEdits() {
        Memory::CodeCave(HairFaceIdUncap1, dwHairFaceUncap1, dwHairFaceUncapNOPs);
        Memory::CodeCave(HairFaceIdUncap2, dwHairFaceUncap2, dwHairFaceUncapNOPs);
    }
}