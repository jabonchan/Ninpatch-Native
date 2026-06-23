#include "windows.h"
#include <cstdint>
#include "./lz4/lib/lz4.h"

extern "C" __declspec(dllexport) int LZ4_Compress(
    const uint8_t* src,
    int srcSize,
    uint8_t* dst,
    int dstCapacity
) {
    if (!src || !dst || srcSize < 0 || dstCapacity < 0)
        return 0;

    return LZ4_compress_default(
        reinterpret_cast<const char*>(src),
        reinterpret_cast<char*>(dst),
        srcSize,
        dstCapacity
    );
}

extern "C" __declspec(dllexport)  int LZ4_MaxCompressedSize(int srcSize) {
    return LZ4_compressBound(srcSize);
}
