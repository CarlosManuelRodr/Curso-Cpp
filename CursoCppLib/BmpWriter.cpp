#include <fstream>
#include "BmpWriter.h"
#include <string>
#include "BinaryOps.h"
using namespace std;

BMPPixel::BMPPixel()
{

}
BMPPixel::BMPPixel(char mR, char mG, char mB)
{
	r = mR;
	g = mG;
	b = mB;
}

BMPWriter::BMPWriter(const char* filepath, unsigned int width, unsigned int height)
{
	// Crea encabezado
	indexHeight = 0;
	imageWidth = width;
	imageHeight = height;
	dataSize = width*height;
	myBmpHdr = new BMPHeader;	// Para ver lo que sucede en la memoria (depuracion).
	myDibHdr = new DIBHeader;

	myBmpHdr->identifier = SwitchEndianess16(0x424d);	// Windows
	myBmpHdr->appSpecific1 = 0x0000;
	myBmpHdr->appSpecific2 = 0x0000;

	myDibHdr->width = width;
	myDibHdr->height = height;
	myDibHdr->nPlanes = SwitchEndianess16(0x0100);
	myDibHdr->colorDepth = SwitchEndianess16(0x1800);
	myDibHdr->compression = 0x00000000;
	myDibHdr->bmpBytes = SwitchEndianess32(0x10000000);
	myDibHdr->hRes = SwitchEndianess32(0x130B0000);
	myDibHdr->vRes = SwitchEndianess32(0x130B0000);
	myDibHdr->nColors = 0x00000000;
	myDibHdr->nImpColors = 0x00000000;

	unsigned int bmpSize = 0;
	unsigned int offsetData = 54;
	paddingBytes = imageWidth % 4;
	// Calcula tamaño de archivo
	bmpSize += 14;		//BMPHeader size. Manual por culpa del puto struct padding..
	bmpSize += 40;		//DIBHeader size
	bmpSize += 3*width*height;
	bmpSize += imageHeight*paddingBytes;
	myBmpHdr->size = bmpSize;
	myBmpHdr->bitmapData = offsetData;
	myDibHdr->headerSize = 40;		//DIBHeader size

	// Escribe encabezado
	file.open( filepath, ios::out | ios::binary );
	file.write( ToByte(&myBmpHdr->identifier), 2 );
	file.write( ToByte(&myBmpHdr->size), 4);
	file.write( ToByte(&myBmpHdr->appSpecific1), 2 );
	file.write( ToByte(&myBmpHdr->appSpecific2), 2 );
	file.write( ToByte(&myBmpHdr->bitmapData), 4 );
	file.write( ToByte(&myDibHdr->headerSize), 4 );
	file.write( ToByte(&myDibHdr->width), 4 );
	file.write( ToByte(&myDibHdr->height), 4 );
	file.write( ToByte(&myDibHdr->nPlanes), 2 );
	file.write( ToByte(&myDibHdr->colorDepth), 2 );
	file.write( ToByte(&myDibHdr->compression), 4 );
	file.write( ToByte(&myDibHdr->bmpBytes), 4 );
	file.write( ToByte(&myDibHdr->hRes), 4 );
	file.write( ToByte(&myDibHdr->vRes), 4 );
	file.write( ToByte(&myDibHdr->nColors), 4 );
	file.write( ToByte(&myDibHdr->nImpColors), 4 );
}
BMPWriter::~BMPWriter()
{
	delete myBmpHdr;
	delete myDibHdr;
}
void BMPWriter::WriteLine(BMPPixel* data)
{
	// Escribe línea de BMP. Evita problemas de otras librerías donde el
	// sistema no puede reservar suficiente memoria en un BMP demasiado grande.
	if(indexHeight < imageHeight)
	{
		for(unsigned int i=0; i<imageWidth; i++)
		{
			file.write(&data[i].b, 1);
			file.write(&data[i].g, 1);
			file.write(&data[i].r, 1);
		}
		if(paddingBytes == 1)
		{
			char padding = 0x00;
			file.write(ToByte(&padding), 1);
		}
		if(paddingBytes == 2)
		{
			short padding = 0x0000;
			file.write(ToByte(&padding), 2);
		}
		if(paddingBytes == 3)
		{
			unsigned int padding = 0x00000000;
			file.write(ToByte(&padding), 3);
		}
	}
	indexHeight++;
}
void BMPWriter::CloseBMP()
{
	file.close();
}
