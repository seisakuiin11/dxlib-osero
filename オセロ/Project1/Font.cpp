#include "OriginalClass.h"
#include "DxLib.h"

Font::Font()
{
}

Font::~Font()
{
}

int* Font::GetFontGosic() {
	int FH[30 + 1];
	for (int i = 0; i < 30 + 1; i++)
	{
		FH[i] = CreateFontToHandle("‚l‚r@ƒSƒVƒbƒN", i, 6, DX_FONTTYPE_NORMAL);
	}
	return FH;
}

int* Font::GetFontMintyo() {
	int FH[30 + 1];
	for (int i = 0; i < 30 + 1; i++)
	{
		FH[i] = CreateFontToHandle("‚l‚r@–¾’©", i, 6, DX_FONTTYPE_NORMAL);
	}
	return FH;
}