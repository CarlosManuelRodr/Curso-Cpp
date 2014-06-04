/*
	Title: CharlesLib BinaryOps.
	Brief: Funciones para operaciones binarias. Auxiliar de BMPWriter.
	Author: Carlos Manuel Rodriguez y Martinez.
	License: GPLv3.
*/

#ifndef _BinaryOps
#define _BinaryOps

typedef short unsigned int uint16;
typedef unsigned int uint32;
typedef int int32;

uint16 SwitchEndianess16(uint16 data);
uint32 SwitchEndianess32(uint32 data);
char* ToByte(void* ptr);
void BoolToChar(char& target, bool in);
void CharToBool(bool& target, char in);
void UInt32ToChar(char* target, uint32 in);
void CharToUInt32(uint32& target, char* in);

#endif
