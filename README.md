# Lossless-Data-Compression
A simple data compression software to compress big text files based on huffman algorithm.
### Project build on UNIX
1. To compress a textfile:
 - compile
  * g++ huffmanencode.cpp
  * ./a.out
  * Then enter the file path which has to be compressed
  * The compressed file is saved as orgfilenamecompressed.dat
2. To decompress a file
 - compile
  * g++ huffmandecode.cpp
  * ./a.out
  * give the filepath for .dat file
  * The file will be restored as orgfilenameexpanded.txt
