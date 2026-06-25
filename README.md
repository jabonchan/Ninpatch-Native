# Ninpatch-Native

LZ4 Wrapper for [UDXPatcher](https://github.com/jabonchan/UDXPatcher).
Must be distributed along UDXPatcher, inside the assets folder next to the executable

---

# Building

Open the Visual Studio project, making sure lz4 repository is located next to the source code. Then build using Visual Studio's compiling feature.

---

# Documentation

`Ninpatch-Native.dll` exposes two functions:

### `LZ4_Compress`

Compresses a block of data using the LZ4 compression algorithm.

#### Parameters

| Parameter     | Description                                                                                        |
| ------------- | -------------------------------------------------------------------------------------------------- |
| `src`         | Pointer to the input buffer containing the data to compress.                                       |
| `srcSize`     | Size of the input buffer in bytes.                                                                 |
| `dst`         | Pointer to the output buffer that will receive the compressed data.                                |
| `dstCapacity` | Size of the output buffer in bytes. The buffer must be large enough to hold the compressed result. |

#### Return Value

Returns the number of bytes written to `dst` on success.

#### Notes

* The output buffer should generally be allocated using `LZ4_compressBound(srcSize)` to ensure sufficient space for the compressed data.
* This function is a wrapper around `LZ4_compress_default()`.

---

### `LZ4_MaxCompressedSize`

Returns the maximum possible size of compressed data for a given input size.

#### Parameters

| Parameter | Description                                   |
| --------- | --------------------------------------------- |
| `srcSize` | Size of the uncompressed input data in bytes. |

#### Return Value

Returns the maximum number of bytes that may be required to store the compressed output.

#### Notes

* Use this value to allocate a destination buffer before calling `LZ4_Compress()`.
* The actual compressed size is usually smaller than the value returned by this function.
* This function is a wrapper around `LZ4_compressBound()`.

---

# Dependencies and Credits

 - [jabonchan](https://github.com/jabonchan): Developer
 - [lz4](https://github.com/lz4/lz4). Read [LZ4_LICENSE](./LZ4_LICENSE)
