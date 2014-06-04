/*
	Title: CharlesLib.
	Brief: Clases para crear archivos en formato BMP.
	Author: Carlos Manuel Rodriguez y Martinez.
	License: GPLv3.
*/

#ifndef __bmpWriter
#define __bmpWriter

#include <fstream>
typedef short unsigned int uint16;
typedef unsigned int uint32;
typedef int int32;

struct BMPHeader
{
	uint16 identifier;
	uint32 size;
	uint16 appSpecific1;
	uint16 appSpecific2;
	uint32 bitmapData;
};

struct DIBHeader
{
	uint32 headerSize;
	int32 width;
	int32 height;
	uint16 nPlanes;
	uint16 colorDepth;
	uint32 compression;
	uint32 bmpBytes;
	int32 hRes;
	int32 vRes;
	uint32 nColors;
	uint32 nImpColors;
};

struct BMPPixel
{
public:
	char r, g, b;
	BMPPixel();
	BMPPixel(char mR, char mG, char mB);
};

typedef struct BMPPixel Color;

class BMPWriter		// Escribe BMP sin limitaciones de memoria que encontré en otras librerías.
{
	BMPHeader* myBmpHdr;
	DIBHeader* myDibHdr;
	std::ofstream file;
	unsigned int imageWidth;
	unsigned int imageHeight;
	unsigned int paddingBytes;
	int dataSize;
	unsigned int indexHeight;

public:
	BMPWriter(const char* filepath, unsigned int width, unsigned int height);
	~BMPWriter();
	void WriteLine(BMPPixel* data);
	void CloseBMP();
};

#endif
