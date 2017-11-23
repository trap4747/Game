#include "Library.h"

// Экран начала новой игры
INT Coubu();
BOOL FirstRun();
VOID RunPawn(bool Run, bool posit);
int GetPositionX()
{
	RECT r;
	GetWindowRect(hWnd, &r);
	return r.left;
};
int GetPositionY()
{
	RECT r;
	GetWindowRect(hWnd, &r);
	return r.top;
};
VOID InitialPawn()
{
	pBufferVershin = NULL;
	pBufferBlack_pawn = NULL;
	pBufferWhite_pawn = NULL;
	float z = 0;
	for (int i = 0; i < QUANTITY_PAWN; i++)
	{
		Black_pawn_mas[i].SetTopLeftPointX(50.0f);
		Black_pawn_mas[i].SetTopLeftPointY(540.0f - z);
		Black_pawn_mas[i].SetBottomRightPointX(100.0f);
		Black_pawn_mas[i].SetBottomRightPointY(490.0f - z);
		Black_pawn_mas[i].SetPositionField(0);

		White_pawn_mas[i].SetTopLeftPointX(708.0f);
		White_pawn_mas[i].SetTopLeftPointY(78.0f + z);
		White_pawn_mas[i].SetBottomRightPointX(758.0f);
		White_pawn_mas[i].SetBottomRightPointY(27.0f + z);
		White_pawn_mas[i].SetPositionField(12);
		z += DISTANCE_HEIGHT;
	}
}
HRESULT InitialBufferVershin(int ram)
{
	CUSTOMVERTEX vertices2[]
	{
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ 0.0f, SCREEN_HEIGHT, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ SCREEN_WIDTH, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX GameBoard[]
	{
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ 0.0f, SCREEN_HEIGHT, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ SCREEN_WIDTH, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Regulations[]
	{
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ 0.0f, SCREEN_HEIGHT, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ SCREEN_WIDTH, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX GameOverWinBlack[]
	{
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ 0.0f, SCREEN_HEIGHT, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ SCREEN_WIDTH, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX GameOverWinWhite[]
	{
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ 0.0f, SCREEN_HEIGHT, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ SCREEN_WIDTH, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ SCREEN_WIDTH, SCREEN_HEIGHT, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Play[]
	{
		{ (float)x_y_key[1].x, (float)x_y_key[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)x_y_key[0].x - 50.0f, (float)x_y_key[1].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)x_y_key[0].x - 50.0f, (float)x_y_key[0].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)x_y_key[0].x - 50.0f, (float)x_y_key[0].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)x_y_key[1].x, (float)x_y_key[0].y + 20.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)x_y_key[1].x, (float)x_y_key[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Pravila[]
	{
		{ (float)x_y_key[3].x, (float)x_y_key[3].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)x_y_key[2].x - 50.0f, (float)x_y_key[3].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)x_y_key[2].x - 50.0f, (float)x_y_key[2].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)x_y_key[2].x - 50.0f, (float)x_y_key[2].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)x_y_key[3].x, (float)x_y_key[2].y + 20.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)x_y_key[3].x, (float)x_y_key[3].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Exit[]
	{
		{ (float)x_y_key[7].x, (float)x_y_key[7].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)x_y_key[6].x - 50.0f, (float)x_y_key[7].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)x_y_key[6].x - 50.0f, (float)x_y_key[6].y + 40.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)x_y_key[6].x - 50.0f, (float)x_y_key[6].y + 40.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)x_y_key[7].x, (float)x_y_key[6].y + 40.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)x_y_key[7].x, (float)x_y_key[7].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX One[]
	{
		{ (float)CubeOne[1].x, (float)CubeOne[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // А
		{ (float)CubeOne[0].x, (float)CubeOne[1].y, 0.5f, 1.0f, 0.0f, quantiti },  // В
		{ (float)CubeOne[0].x, (float)CubeOne[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)CubeOne[0].x, (float)CubeOne[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)CubeOne[1].x, (float)CubeOne[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)CubeOne[1].x, (float)CubeOne[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // A
	};
	CUSTOMVERTEX Two[]
	{
		{ (float)CubeTwo[1].x, (float)CubeTwo[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // А
		{ (float)CubeTwo[0].x, (float)CubeTwo[1].y, 0.5f, 1.0f, 0.0f, quantiti },  // В
		{ (float)CubeTwo[0].x, (float)CubeTwo[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)CubeTwo[0].x, (float)CubeTwo[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)CubeTwo[1].x, (float)CubeTwo[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)CubeTwo[1].x, (float)CubeTwo[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // A
	};
	CUSTOMVERTEX Three[]
	{
		{ (float)CubeThree[1].x, (float)CubeThree[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // А
		{ (float)CubeThree[0].x, (float)CubeThree[1].y, 0.5f, 1.0f, 0.0f, quantiti },  // В
		{ (float)CubeThree[0].x, (float)CubeThree[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)CubeThree[0].x, (float)CubeThree[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)CubeThree[1].x, (float)CubeThree[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)CubeThree[1].x, (float)CubeThree[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // A
	};
	CUSTOMVERTEX Four[]
	{
		{ (float)CubeFour[1].x, (float)CubeFour[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // А
		{ (float)CubeFour[0].x, (float)CubeFour[1].y, 0.5f, 1.0f, 0.0f, quantiti },  // В
		{ (float)CubeFour[0].x, (float)CubeFour[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)CubeFour[0].x, (float)CubeFour[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)CubeFour[1].x, (float)CubeFour[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)CubeFour[1].x, (float)CubeFour[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // A
	};
	CUSTOMVERTEX Five[]
	{
		{ (float)CubeFive[1].x, (float)CubeFive[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // А
		{ (float)CubeFive[0].x, (float)CubeFive[1].y, 0.5f, 1.0f, 0.0f, quantiti },  // В
		{ (float)CubeFive[0].x, (float)CubeFive[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)CubeFive[0].x, (float)CubeFive[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)CubeFive[1].x, (float)CubeFive[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)CubeFive[1].x, (float)CubeFive[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // A
	};
	CUSTOMVERTEX Six[]
	{
		{ (float)CubeSix[1].x, (float)CubeSix[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // А
		{ (float)CubeSix[0].x, (float)CubeSix[1].y, 0.5f, 1.0f, 0.0f, quantiti },  // В
		{ (float)CubeSix[0].x, (float)CubeSix[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)CubeSix[0].x, (float)CubeSix[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)CubeSix[1].x, (float)CubeSix[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)CubeSix[1].x, (float)CubeSix[1].y, 0.5f, 1.0f, 1.0f, quantiti },  // A
	};
	CUSTOMVERTEX Home[]
	{
		{ (float)Home_x_y[1].x, (float)Home_x_y[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)Home_x_y[0].x, (float)Home_x_y[1].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)Home_x_y[0].x, (float)Home_x_y[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)Home_x_y[0].x, (float)Home_x_y[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)Home_x_y[1].x, (float)Home_x_y[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)Home_x_y[1].x, (float)Home_x_y[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ (float)Home_x_y[3].x, (float)Home_x_y[3].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)Home_x_y[2].x, (float)Home_x_y[3].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)Home_x_y[2].x, (float)Home_x_y[2].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)Home_x_y[2].x, (float)Home_x_y[2].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)Home_x_y[3].x, (float)Home_x_y[2].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)Home_x_y[3].x, (float)Home_x_y[3].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Choice[]
	{
		{ (float)x_y_key[1].x, (float)x_y_key[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)x_y_key[0].x - 50.0f, (float)x_y_key[1].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)x_y_key[0].x - 50.0f, (float)x_y_key[0].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)x_y_key[0].x - 50.0f, (float)x_y_key[0].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)x_y_key[1].x, (float)x_y_key[0].y + 20.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)x_y_key[1].x, (float)x_y_key[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Block[]
	{
		{ (float)BlockText[1].x, (float)BlockText[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)BlockText[0].x - 50.0f, (float)BlockText[1].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)BlockText[0].x - 50.0f, (float)BlockText[0].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)BlockText[0].x - 50.0f, (float)BlockText[0].y + 20.0f, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)BlockText[1].x, (float)BlockText[0].y + 20.0f, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)BlockText[1].x, (float)BlockText[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Green[]
	{
		{ (float)GreenPosition[1].x, (float)GreenPosition[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ (float)GreenPosition[0].x, (float)GreenPosition[1].y, 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ (float)GreenPosition[0].x, (float)GreenPosition[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ (float)GreenPosition[0].x, (float)GreenPosition[0].y, 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ (float)GreenPosition[1].x, (float)GreenPosition[0].y, 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ (float)GreenPosition[1].x, (float)GreenPosition[1].y, 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX Black_pawn[]
	{

		{ Black_pawn_mas[0].GetBottomRightPointX(), Black_pawn_mas[0].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[0].GetTopLeftPointX(), Black_pawn_mas[0].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[0].GetTopLeftPointX(), Black_pawn_mas[0].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[0].GetTopLeftPointX(), Black_pawn_mas[0].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[0].GetBottomRightPointX(), Black_pawn_mas[0].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[0].GetBottomRightPointX(), Black_pawn_mas[0].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[1].GetBottomRightPointX(), Black_pawn_mas[1].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[1].GetTopLeftPointX(), Black_pawn_mas[1].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[1].GetTopLeftPointX(), Black_pawn_mas[1].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[1].GetTopLeftPointX(), Black_pawn_mas[1].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[1].GetBottomRightPointX(), Black_pawn_mas[1].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[1].GetBottomRightPointX(), Black_pawn_mas[1].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[2].GetBottomRightPointX(), Black_pawn_mas[2].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[2].GetTopLeftPointX(), Black_pawn_mas[2].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[2].GetTopLeftPointX(), Black_pawn_mas[2].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[2].GetTopLeftPointX(), Black_pawn_mas[2].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[2].GetBottomRightPointX(), Black_pawn_mas[2].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[2].GetBottomRightPointX(), Black_pawn_mas[2].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[3].GetBottomRightPointX(), Black_pawn_mas[3].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[3].GetTopLeftPointX(), Black_pawn_mas[3].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[3].GetTopLeftPointX(), Black_pawn_mas[3].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[3].GetTopLeftPointX(), Black_pawn_mas[3].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[3].GetBottomRightPointX(), Black_pawn_mas[3].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[3].GetBottomRightPointX(), Black_pawn_mas[3].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[4].GetBottomRightPointX(), Black_pawn_mas[4].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[4].GetTopLeftPointX(), Black_pawn_mas[4].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[4].GetTopLeftPointX(), Black_pawn_mas[4].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[4].GetTopLeftPointX(), Black_pawn_mas[4].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[4].GetBottomRightPointX(), Black_pawn_mas[4].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[4].GetBottomRightPointX(), Black_pawn_mas[4].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[5].GetBottomRightPointX(), Black_pawn_mas[5].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[5].GetTopLeftPointX(), Black_pawn_mas[5].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[5].GetTopLeftPointX(), Black_pawn_mas[5].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[5].GetTopLeftPointX(), Black_pawn_mas[5].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[5].GetBottomRightPointX(), Black_pawn_mas[5].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[5].GetBottomRightPointX(), Black_pawn_mas[5].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[6].GetBottomRightPointX(), Black_pawn_mas[6].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[6].GetTopLeftPointX(), Black_pawn_mas[6].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[6].GetTopLeftPointX(), Black_pawn_mas[6].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[6].GetTopLeftPointX(), Black_pawn_mas[6].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[6].GetBottomRightPointX(), Black_pawn_mas[6].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[6].GetBottomRightPointX(), Black_pawn_mas[6].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[7].GetBottomRightPointX(), Black_pawn_mas[7].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[7].GetTopLeftPointX(), Black_pawn_mas[7].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[7].GetTopLeftPointX(), Black_pawn_mas[7].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[7].GetTopLeftPointX(), Black_pawn_mas[7].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[7].GetBottomRightPointX(), Black_pawn_mas[7].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[7].GetBottomRightPointX(), Black_pawn_mas[7].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[8].GetBottomRightPointX(), Black_pawn_mas[8].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[8].GetTopLeftPointX(), Black_pawn_mas[8].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[8].GetTopLeftPointX(), Black_pawn_mas[8].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[8].GetTopLeftPointX(), Black_pawn_mas[8].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[8].GetBottomRightPointX(), Black_pawn_mas[8].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[8].GetBottomRightPointX(), Black_pawn_mas[8].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[9].GetBottomRightPointX(), Black_pawn_mas[9].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[9].GetTopLeftPointX(), Black_pawn_mas[9].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[9].GetTopLeftPointX(), Black_pawn_mas[9].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[9].GetTopLeftPointX(), Black_pawn_mas[9].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[9].GetBottomRightPointX(), Black_pawn_mas[9].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[9].GetBottomRightPointX(), Black_pawn_mas[9].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[10].GetBottomRightPointX(), Black_pawn_mas[10].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[10].GetTopLeftPointX(), Black_pawn_mas[10].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[10].GetTopLeftPointX(), Black_pawn_mas[10].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[10].GetTopLeftPointX(), Black_pawn_mas[10].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[10].GetBottomRightPointX(), Black_pawn_mas[10].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[10].GetBottomRightPointX(), Black_pawn_mas[10].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[11].GetBottomRightPointX(), Black_pawn_mas[11].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[11].GetTopLeftPointX(), Black_pawn_mas[11].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[11].GetTopLeftPointX(), Black_pawn_mas[11].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[11].GetTopLeftPointX(), Black_pawn_mas[11].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[11].GetBottomRightPointX(), Black_pawn_mas[11].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[11].GetBottomRightPointX(), Black_pawn_mas[11].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[12].GetBottomRightPointX(), Black_pawn_mas[12].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[12].GetTopLeftPointX(), Black_pawn_mas[12].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[12].GetTopLeftPointX(), Black_pawn_mas[12].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[12].GetTopLeftPointX(), Black_pawn_mas[12].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[12].GetBottomRightPointX(), Black_pawn_mas[12].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[12].GetBottomRightPointX(), Black_pawn_mas[12].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[13].GetBottomRightPointX(), Black_pawn_mas[13].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[13].GetTopLeftPointX(), Black_pawn_mas[13].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[13].GetTopLeftPointX(), Black_pawn_mas[13].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[13].GetTopLeftPointX(), Black_pawn_mas[13].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[13].GetBottomRightPointX(), Black_pawn_mas[13].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[13].GetBottomRightPointX(), Black_pawn_mas[13].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ Black_pawn_mas[14].GetBottomRightPointX(), Black_pawn_mas[14].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ Black_pawn_mas[14].GetTopLeftPointX(), Black_pawn_mas[14].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ Black_pawn_mas[14].GetTopLeftPointX(), Black_pawn_mas[14].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ Black_pawn_mas[14].GetTopLeftPointX(), Black_pawn_mas[14].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ Black_pawn_mas[14].GetBottomRightPointX(), Black_pawn_mas[14].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ Black_pawn_mas[14].GetBottomRightPointX(), Black_pawn_mas[14].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	CUSTOMVERTEX White_pawn[]
	{
		{ White_pawn_mas[0].GetBottomRightPointX(), White_pawn_mas[0].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[0].GetTopLeftPointX(), White_pawn_mas[0].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[0].GetTopLeftPointX(), White_pawn_mas[0].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[0].GetTopLeftPointX(), White_pawn_mas[0].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[0].GetBottomRightPointX(), White_pawn_mas[0].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[0].GetBottomRightPointX(), White_pawn_mas[0].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[1].GetBottomRightPointX(), White_pawn_mas[1].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[1].GetTopLeftPointX(), White_pawn_mas[1].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[1].GetTopLeftPointX(), White_pawn_mas[1].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[1].GetTopLeftPointX(), White_pawn_mas[1].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[1].GetBottomRightPointX(), White_pawn_mas[1].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[1].GetBottomRightPointX(), White_pawn_mas[1].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[2].GetBottomRightPointX(), White_pawn_mas[2].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[2].GetTopLeftPointX(), White_pawn_mas[2].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[2].GetTopLeftPointX(), White_pawn_mas[2].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[2].GetTopLeftPointX(), White_pawn_mas[2].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[2].GetBottomRightPointX(), White_pawn_mas[2].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[2].GetBottomRightPointX(), White_pawn_mas[2].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[3].GetBottomRightPointX(), White_pawn_mas[3].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[3].GetTopLeftPointX(), White_pawn_mas[3].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[3].GetTopLeftPointX(), White_pawn_mas[3].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[3].GetTopLeftPointX(), White_pawn_mas[3].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[3].GetBottomRightPointX(), White_pawn_mas[3].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[3].GetBottomRightPointX(), White_pawn_mas[3].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[4].GetBottomRightPointX(), White_pawn_mas[4].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[4].GetTopLeftPointX(), White_pawn_mas[4].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[4].GetTopLeftPointX(), White_pawn_mas[4].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[4].GetTopLeftPointX(), White_pawn_mas[4].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[4].GetBottomRightPointX(), White_pawn_mas[4].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[4].GetBottomRightPointX(), White_pawn_mas[4].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[5].GetBottomRightPointX(), White_pawn_mas[5].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[5].GetTopLeftPointX(), White_pawn_mas[5].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[5].GetTopLeftPointX(), White_pawn_mas[5].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[5].GetTopLeftPointX(), White_pawn_mas[5].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[5].GetBottomRightPointX(), White_pawn_mas[5].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[5].GetBottomRightPointX(), White_pawn_mas[5].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[6].GetBottomRightPointX(), White_pawn_mas[6].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[6].GetTopLeftPointX(), White_pawn_mas[6].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[6].GetTopLeftPointX(), White_pawn_mas[6].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[6].GetTopLeftPointX(), White_pawn_mas[6].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[6].GetBottomRightPointX(), White_pawn_mas[6].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[6].GetBottomRightPointX(), White_pawn_mas[6].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[7].GetBottomRightPointX(), White_pawn_mas[7].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[7].GetTopLeftPointX(), White_pawn_mas[7].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[7].GetTopLeftPointX(), White_pawn_mas[7].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[7].GetTopLeftPointX(), White_pawn_mas[7].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[7].GetBottomRightPointX(), White_pawn_mas[7].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[7].GetBottomRightPointX(), White_pawn_mas[7].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[8].GetBottomRightPointX(), White_pawn_mas[8].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[8].GetTopLeftPointX(), White_pawn_mas[8].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[8].GetTopLeftPointX(), White_pawn_mas[8].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[8].GetTopLeftPointX(), White_pawn_mas[8].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[8].GetBottomRightPointX(), White_pawn_mas[8].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[8].GetBottomRightPointX(), White_pawn_mas[8].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[9].GetBottomRightPointX(), White_pawn_mas[9].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[9].GetTopLeftPointX(), White_pawn_mas[9].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[9].GetTopLeftPointX(), White_pawn_mas[9].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[9].GetTopLeftPointX(), White_pawn_mas[9].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[9].GetBottomRightPointX(), White_pawn_mas[9].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[9].GetBottomRightPointX(), White_pawn_mas[9].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[10].GetBottomRightPointX(), White_pawn_mas[10].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[10].GetTopLeftPointX(), White_pawn_mas[10].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[10].GetTopLeftPointX(), White_pawn_mas[10].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[10].GetTopLeftPointX(), White_pawn_mas[10].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[10].GetBottomRightPointX(), White_pawn_mas[10].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[10].GetBottomRightPointX(), White_pawn_mas[10].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[11].GetBottomRightPointX(), White_pawn_mas[11].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[11].GetTopLeftPointX(), White_pawn_mas[11].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[11].GetTopLeftPointX(), White_pawn_mas[11].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[11].GetTopLeftPointX(), White_pawn_mas[11].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[11].GetBottomRightPointX(), White_pawn_mas[11].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[11].GetBottomRightPointX(), White_pawn_mas[11].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[12].GetBottomRightPointX(), White_pawn_mas[12].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[12].GetTopLeftPointX(), White_pawn_mas[12].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[12].GetTopLeftPointX(), White_pawn_mas[12].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[12].GetTopLeftPointX(), White_pawn_mas[12].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[12].GetBottomRightPointX(), White_pawn_mas[12].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[12].GetBottomRightPointX(), White_pawn_mas[12].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[13].GetBottomRightPointX(), White_pawn_mas[13].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[13].GetTopLeftPointX(), White_pawn_mas[13].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[13].GetTopLeftPointX(), White_pawn_mas[13].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[13].GetTopLeftPointX(), White_pawn_mas[13].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[13].GetBottomRightPointX(), White_pawn_mas[13].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[13].GetBottomRightPointX(), White_pawn_mas[13].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A

		{ White_pawn_mas[14].GetBottomRightPointX(), White_pawn_mas[14].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // А
		{ White_pawn_mas[14].GetTopLeftPointX(), White_pawn_mas[14].GetTopLeftPointY(), 0.5f, 1.0f, 0.0f, 1.0f },  // В
		{ White_pawn_mas[14].GetTopLeftPointX(), White_pawn_mas[14].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // С

		{ White_pawn_mas[14].GetTopLeftPointX(), White_pawn_mas[14].GetBottomRightPointY(), 0.5f, 1.0f, 0.0f, 0.0f },  // C
		{ White_pawn_mas[14].GetBottomRightPointX(), White_pawn_mas[14].GetBottomRightPointY(), 0.5f, 1.0f, 1.0f, 0.0f },  // D
		{ White_pawn_mas[14].GetBottomRightPointX(), White_pawn_mas[14].GetTopLeftPointY(), 0.5f, 1.0f, 1.0f, 1.0f },  // A
	};
	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferVershin, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferGameBoard, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferRegulations, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferPlay, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(12 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferHome, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(12 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferPravila, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferOne, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferTwo, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferThree, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferFour, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferGameOverWinBlack, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferGameOverWinWhite, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferGreen, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferFive, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferSix, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferExit, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferChoice, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferBlock, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(102 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferBlack_pawn, NULL)))
		return E_FAIL;

	if (FAILED(pDirect3DDevice->CreateVertexBuffer(102 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pBufferWhite_pawn, NULL)))
		return E_FAIL;

	VOID* pBV;
	if (pBufferVershin->Lock(0, sizeof(vertices2), (void**)&pBV, 0))
		return E_FAIL;

	memcpy(pBV, vertices2, sizeof(vertices2));
	pBufferVershin->Unlock();

	VOID* pHome;
	if (pBufferHome->Lock(0, sizeof(Home), (void**)&pHome, 0))
		return E_FAIL;

	memcpy(pHome, Home, sizeof(Home));
	pBufferHome->Unlock();

	VOID* pGameBoard;
	if (pBufferGameBoard->Lock(0, sizeof(GameBoard), (void**)&pGameBoard, 0))
		return E_FAIL;

	memcpy(pGameBoard, GameBoard, sizeof(GameBoard));
	pBufferGameBoard->Unlock();

	VOID* pPravila;
	if (pBufferPravila->Lock(0, sizeof(Pravila), (void**)&pPravila, 0))
		return E_FAIL;

	memcpy(pPravila, Pravila, sizeof(Pravila));
	pBufferPravila->Unlock();

	VOID* pRegulations;
	if (pBufferRegulations->Lock(0, sizeof(Regulations), (void**)&pRegulations, 0))
		return E_FAIL;

	memcpy(pRegulations, Regulations, sizeof(Regulations));
	pBufferRegulations->Unlock();

	VOID* pPlay;
	if (pBufferPlay->Lock(0, sizeof(Play), (void**)&pPlay, 0))
		return E_FAIL;

	memcpy(pPlay, Play, sizeof(Play));
	pBufferPlay->Unlock();

	VOID* pExit;
	if (pBufferExit->Lock(0, sizeof(Exit), (void**)&pExit, 0))
		return E_FAIL;

	memcpy(pExit, Exit, sizeof(Exit));
	pBufferExit->Unlock();

	VOID* pGameOverWinWhite;
	if (pBufferGameOverWinWhite->Lock(0, sizeof(GameOverWinWhite), (void**)&pGameOverWinWhite, 0))
		return E_FAIL;

	memcpy(pGameOverWinWhite, GameOverWinWhite, sizeof(GameOverWinWhite));
	pBufferGameOverWinWhite->Unlock();

	VOID* pGameOverWinBlack;
	if (pBufferGameOverWinBlack->Lock(0, sizeof(GameOverWinBlack), (void**)&pGameOverWinBlack, 0))
		return E_FAIL;

	memcpy(pGameOverWinBlack, GameOverWinBlack, sizeof(GameOverWinBlack));
	pBufferGameOverWinBlack->Unlock();

	VOID* pOne;
	if (pBufferOne->Lock(0, sizeof(One), (void**)&pOne, 0))
		return E_FAIL;

	memcpy(pOne, One, sizeof(One));
	pBufferOne->Unlock();

	VOID* pTwo;
	if (pBufferTwo->Lock(0, sizeof(Two), (void**)&pTwo, 0))
		return E_FAIL;

	memcpy(pTwo, Two, sizeof(Two));
	pBufferTwo->Unlock();

	VOID* pThree;
	if (pBufferThree->Lock(0, sizeof(Three), (void**)&pThree, 0))
		return E_FAIL;

	memcpy(pThree, Three, sizeof(Three));
	pBufferThree->Unlock();

	VOID* pFour;
	if (pBufferFour->Lock(0, sizeof(Four), (void**)&pFour, 0))
		return E_FAIL;

	memcpy(pFour, Four, sizeof(Four));
	pBufferFour->Unlock();

	VOID* pFive;
	if (pBufferFive->Lock(0, sizeof(Five), (void**)&pFive, 0))
		return E_FAIL;

	memcpy(pFive, Five, sizeof(Five));
	pBufferFive->Unlock();

	VOID* pSix;
	if (pBufferSix->Lock(0, sizeof(Six), (void**)&pSix, 0))
		return E_FAIL;

	memcpy(pSix, Six, sizeof(Six));
	pBufferSix->Unlock();

	VOID* pChoice;
	if (pBufferChoice->Lock(0, sizeof(Choice), (void**)&pChoice, 0))
		return E_FAIL;

	memcpy(pChoice, Choice, sizeof(Choice));
	pBufferChoice->Unlock();

	VOID* pBlock;
	if (pBufferBlock->Lock(0, sizeof(Block), (void**)&pBlock, 0))
		return E_FAIL;

	memcpy(pBlock, Block, sizeof(Block));
	pBufferBlock->Unlock();

	VOID* pGreen;
	if (pBufferGreen->Lock(0, sizeof(Green), (void**)&pGreen, 0))
		return E_FAIL;

	memcpy(pGreen, Green, sizeof(Green));
	pBufferGreen->Unlock();

	VOID* pBlack;
	if (pBufferBlack_pawn->Lock(0, sizeof(Black_pawn), (void**)&pBlack, 0))
		return E_FAIL;
	memcpy(pBlack, Black_pawn, sizeof(Black_pawn));
	pBufferBlack_pawn->Unlock();

	VOID* pWhite;
	if (pBufferWhite_pawn->Lock(0, sizeof(White_pawn), (void**)&pWhite, 0))
		return E_FAIL;
	memcpy(pWhite, White_pawn, sizeof(White_pawn));
	pBufferWhite_pawn->Unlock();

	return S_OK;
}
HRESULT InitialDirect3D(HWND hWnd, int ram)
{
	if (NULL == (pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	D3DDISPLAYMODE Display;
	if (FAILED(pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &Display)))
		return E_FAIL;

	D3DPRESENT_PARAMETERS Direct3DParametr;
	ZeroMemory(&Direct3DParametr, sizeof(Direct3DParametr));
	Direct3DParametr.Windowed = TRUE;
	Direct3DParametr.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Direct3DParametr.BackBufferFormat = Display.Format;
	Direct3DParametr.hDeviceWindow = hWnd;

	if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&Direct3DParametr, &pDirect3DDevice)))
	{
		return E_FAIL;
	}
	pMain = NULL;
	pPlay = NULL;
	pExit = NULL;
	pChoice = NULL;
	pGameBoard = NULL;
	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"Main.jpg", &pMain) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"Regulations.jpg", &pRegulations) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"Play.png", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pPlay) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"Home.png", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pHome) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"Exit.png", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pExit) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"Throw_Pawn.png", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pBlock) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"Pravila.png", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pPravila) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"Game_board.jpg", &pGameBoard) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"GameOverWinBlack.jpg", &pGameOverWinBlack) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"GameOverWinWhite.jpg", &pGameOverWinWhite) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"Choice.png", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pChoice) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"One.jpg", &pOne) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);
	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"Two.jpg", &pTwo) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);
	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"three.jpg", &pThree) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);
	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"Four.jpg", &pFour) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);
	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"Five.jpg", &pFive) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);
	if (D3DXCreateTextureFromFile(pDirect3DDevice, L"Six.jpg", &pSix) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"green.png", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pGreen) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"black_pawn.bmp", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pBlack_pawn) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	if (D3DXCreateTextureFromFileEx(pDirect3DDevice, L"white_pawn.bmp", 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0xFF000000,
		NULL, NULL, &pWhite_pawn) != D3D_OK)
		MessageBox(NULL, L"Texture error", L"Fatal error", NULL);

	pDirect3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	return S_OK;
}
VOID DeleteDirect3D()
{
	if (pFont != NULL)
		pFont->Release();

	if (pHome != NULL)
		pHome->Release();

	if (pPlay != NULL)
		pPlay->Release();

	if (pExit != NULL)
		pExit->Release();

	if (pMain != NULL)
		pMain->Release();

	if (pGreen != NULL)
		pGreen->Release();

	if (pGameBoard != NULL)
		pGameBoard->Release();

	if (pChoice != NULL)
		pChoice->Release();

	if (pBlack_pawn != NULL)
		pBlack_pawn->Release();

	if (pWhite_pawn != NULL)
		pWhite_pawn->Release();

	if (pGameOverWinBlack != NULL)
		pGameOverWinBlack->Release();

	if (pGameOverWinWhite != NULL)
		pGameOverWinWhite->Release();

	if (pBufferGreen != NULL)
		pBufferGreen->Release();

	if (pBufferHome != NULL)
		pBufferHome->Release();

	if (pBufferGameOverWinBlack != NULL)
		pBufferGameOverWinBlack->Release();

	if (pBufferGameOverWinWhite != NULL)
		pBufferGameOverWinWhite->Release();

	if (pBufferVershin != NULL)
		pBufferVershin->Release();

	if (pBufferBlack_pawn != NULL)
		pBufferBlack_pawn->Release();

	if (pBufferChoice != NULL)
		pBufferChoice->Release();

	if (pBufferGameBoard != NULL)
		pBufferGameBoard->Release();

	if (pBufferWhite_pawn != NULL)
		pBufferWhite_pawn->Release();

	if (pBufferPlay != NULL)
		pBufferPlay->Release();

	if (pBufferExit != NULL)
		pBufferExit->Release();

	if (pDirect3DDevice != NULL)
		pDirect3DDevice->Release();

	if (pDirect3D != NULL)
		pDirect3D->Release();
}
VOID RenderingDirect3D()
{
	if (pDirect3DDevice == NULL)     // Проверяем ошибки
		return;
	pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	pDirect3DDevice->BeginScene();

	if (ram == 0)
	{
		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pMain);
		pDirect3DDevice->SetStreamSource(0, pBufferVershin, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pPlay);
		pDirect3DDevice->SetStreamSource(0, pBufferPlay, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pPravila);
		pDirect3DDevice->SetStreamSource(0, pBufferPravila, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pExit);
		pDirect3DDevice->SetStreamSource(0, pBufferExit, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	}
	if (ram == 1)
	{
		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pGameBoard);
		pDirect3DDevice->SetStreamSource(0, pBufferGameBoard, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pBlock);
		pDirect3DDevice->SetStreamSource(0, pBufferBlock, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pBlack_pawn);
		pDirect3DDevice->SetStreamSource(0, pBufferBlack_pawn, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 34);

		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pWhite_pawn);
		pDirect3DDevice->SetStreamSource(0, pBufferWhite_pawn, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 34);

		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pGreen);
		pDirect3DDevice->SetStreamSource(0, pBufferGreen, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
		if (Home_3)
		{
			pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			pDirect3DDevice->SetTexture(0, pHome);
			pDirect3DDevice->SetStreamSource(0, pBufferHome, 0, sizeof(CUSTOMVERTEX));
			pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 4);

		}
		pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	}
	if (ram == 2)
	{
		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pGameOverWinBlack);
		pDirect3DDevice->SetStreamSource(0, pBufferGameOverWinBlack, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 32);
	}
	if (ram == 3)
	{
		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pGameOverWinWhite);
		pDirect3DDevice->SetStreamSource(0, pBufferGameOverWinWhite, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 32);
	}
	if (ram == 4)
	{
		pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		pDirect3DDevice->SetTexture(0, pRegulations);
		pDirect3DDevice->SetStreamSource(0, pBufferRegulations, 0, sizeof(CUSTOMVERTEX));
		pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
	switch (SideCube)
	{
	case 1:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pOne);
			  pDirect3DDevice->SetStreamSource(0, pBufferOne, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 2:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pTwo);
			  pDirect3DDevice->SetStreamSource(0, pBufferTwo, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 3:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pThree);
			  pDirect3DDevice->SetStreamSource(0, pBufferThree, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 4:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pFour);
			  pDirect3DDevice->SetStreamSource(0, pBufferFour, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 5:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pFive);
			  pDirect3DDevice->SetStreamSource(0, pBufferFive, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 6:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pSix);
			  pDirect3DDevice->SetStreamSource(0, pBufferSix, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	default:
		break;
	}

	switch (SideCube2)
	{
	case 1:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pOne);
			  pDirect3DDevice->SetStreamSource(0, pBufferOne, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 2:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pTwo);
			  pDirect3DDevice->SetStreamSource(0, pBufferTwo, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 3:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pThree);
			  pDirect3DDevice->SetStreamSource(0, pBufferThree, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 4:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pFour);
			  pDirect3DDevice->SetStreamSource(0, pBufferFour, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 5:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pFive);
			  pDirect3DDevice->SetStreamSource(0, pBufferFive, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	case 6:
	{
			  pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			  pDirect3DDevice->SetTexture(0, pSix);
			  pDirect3DDevice->SetStreamSource(0, pBufferSix, 0, sizeof(CUSTOMVERTEX));
			  pDirect3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
		break;
	default:
		break;
	}
	GetCursorPos(&Mouse);

	pDirect3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 36, 0, 12);
	pDirect3DDevice->EndScene();
	pDirect3DDevice->Present(NULL, NULL, NULL, NULL);

}
VOID DrawCoub()
{
	SideCube = mas[0];
	SideCube2 = mas[1];
	switch (SideCube)
	{
	case 1:
	{
			  CubeOne[0].x = x_y_CubeOne[0].x;
			  CubeOne[0].y = x_y_CubeOne[0].y;
			  CubeOne[1].x = x_y_CubeOne[1].x;
			  CubeOne[1].y = x_y_CubeOne[1].y;
	}
		break;
	case 2:
	{
			  CubeTwo[0].x = x_y_CubeOne[0].x;
			  CubeTwo[0].y = x_y_CubeOne[0].y;
			  CubeTwo[1].x = x_y_CubeOne[1].x;
			  CubeTwo[1].y = x_y_CubeOne[1].y;
	}
		break;
	case 3:
	{
			  CubeThree[0].x = x_y_CubeOne[0].x;
			  CubeThree[0].y = x_y_CubeOne[0].y;
			  CubeThree[1].x = x_y_CubeOne[1].x;
			  CubeThree[1].y = x_y_CubeOne[1].y;
	}
		break;
	case 4:
	{
			  CubeFour[0].x = x_y_CubeOne[0].x;
			  CubeFour[0].y = x_y_CubeOne[0].y;
			  CubeFour[1].x = x_y_CubeOne[1].x;
			  CubeFour[1].y = x_y_CubeOne[1].y;
	}
		break;
	case 5:
	{
			  CubeFive[0].x = x_y_CubeOne[0].x;
			  CubeFive[0].y = x_y_CubeOne[0].y;
			  CubeFive[1].x = x_y_CubeOne[1].x;
			  CubeFive[1].y = x_y_CubeOne[1].y;

	}
		break;
	case 6:
	{
			  CubeSix[0].x = x_y_CubeOne[0].x;
			  CubeSix[0].y = x_y_CubeOne[0].y;
			  CubeSix[1].x = x_y_CubeOne[1].x;
			  CubeSix[1].y = x_y_CubeOne[1].y;
	}
		break;
	default:
		break;
	}

	switch (SideCube2)
	{
	case 1:
	{
			  CubeOne[0].x = x_y_CubeTwo[0].x;
			  CubeOne[0].y = x_y_CubeTwo[0].y;
			  CubeOne[1].x = x_y_CubeTwo[1].x;
			  CubeOne[1].y = x_y_CubeTwo[1].y;
	}
		break;
	case 2:
	{
			  CubeTwo[0].x = x_y_CubeTwo[0].x;
			  CubeTwo[0].y = x_y_CubeTwo[0].y;
			  CubeTwo[1].x = x_y_CubeTwo[1].x;
			  CubeTwo[1].y = x_y_CubeTwo[1].y;
	}
		break;
	case 3:
	{
			  CubeThree[0].x = x_y_CubeTwo[0].x;
			  CubeThree[0].y = x_y_CubeTwo[0].y;
			  CubeThree[1].x = x_y_CubeTwo[1].x;
			  CubeThree[1].y = x_y_CubeTwo[1].y;
	}
		break;
	case 4:
	{
			  CubeFour[0].x = x_y_CubeTwo[0].x;
			  CubeFour[0].y = x_y_CubeTwo[0].y;
			  CubeFour[1].x = x_y_CubeTwo[1].x;
			  CubeFour[1].y = x_y_CubeTwo[1].y;
	}
		break;
	case 5:
	{
			  CubeFive[0].x = x_y_CubeTwo[0].x;
			  CubeFive[0].y = x_y_CubeTwo[0].y;
			  CubeFive[1].x = x_y_CubeTwo[1].x;
			  CubeFive[1].y = x_y_CubeTwo[1].y;

	}
		break;
	case 6:
	{
			  CubeSix[0].x = x_y_CubeTwo[0].x;
			  CubeSix[0].y = x_y_CubeTwo[0].y;
			  CubeSix[1].x = x_y_CubeTwo[1].x;
			  CubeSix[1].y = x_y_CubeTwo[1].y;
	}
		break;
	default:
		break;
	}
}
VOID BlockT()
{
	First = -1;
	if (Mouse.x - GetPositionX() >= BlockText[0].x && Mouse.x - GetPositionX() <= BlockText[1].x && Mouse.y - GetPositionY() >= BlockText[0].y + 50 && Mouse.y - GetPositionY() <= BlockText[1].y + 25)
	{
		for (int i = 0; i < 2; i++)
			mas[i] = Coubu();
		if (mas[0] != mas[1])
		{
			cub = false;
			SideCube = mas[0];
			SideCube2 = mas[1];
			quantiti = 1;
			DrawCoub();
		}
		if (mas[0] == mas[1])
		{
			cub = true;
			quantiti = 4;
			SideCube = mas[0];
			switch (SideCube)
			{
			case 1:
			{
					  CubeOne[0].x = x_y_CubeOne[0].x;
					  CubeOne[0].y = x_y_CubeOne[0].y;
					  CubeOne[1].x = x_y_CubeOne[1].x;
					  CubeOne[1].y = x_y_CubeOne[1].y + 75;
			}
				break;
			case 2:
			{
					  CubeTwo[0].x = x_y_CubeOne[0].x;
					  CubeTwo[0].y = x_y_CubeOne[0].y;
					  CubeTwo[1].x = x_y_CubeOne[1].x;
					  CubeTwo[1].y = x_y_CubeOne[1].y + 75;
			}
				break;
			case 3:
			{
					  CubeThree[0].x = x_y_CubeOne[0].x;
					  CubeThree[0].y = x_y_CubeOne[0].y;
					  CubeThree[1].x = x_y_CubeOne[1].x;
					  CubeThree[1].y = x_y_CubeOne[1].y + 75;
			}
				break;
			case 4:
			{
					  CubeFour[0].x = x_y_CubeOne[0].x;
					  CubeFour[0].y = x_y_CubeOne[0].y;
					  CubeFour[1].x = x_y_CubeOne[1].x;
					  CubeFour[1].y = x_y_CubeOne[1].y + 75;
			}
				break;
			case 5:
			{
					  CubeFive[0].x = x_y_CubeOne[0].x;
					  CubeFive[0].y = x_y_CubeOne[0].y;
					  CubeFive[1].x = x_y_CubeOne[1].x;
					  CubeFive[1].y = x_y_CubeOne[1].y + 75;

			}
				break;
			case 6:
			{
					  CubeSix[0].x = x_y_CubeOne[0].x;
					  CubeSix[0].y = x_y_CubeOne[0].y;
					  CubeSix[1].x = x_y_CubeOne[1].x;
					  CubeSix[1].y = x_y_CubeOne[1].y + 75;
			}
				break;
			default:
				break;
			}
			SideCube2 = 0;
		}
		BlockText[0].x = 0;
		BlockText[0].y = 0;

		BlockText[1].x = 0;
		BlockText[1].y = 0;
		df = false;
	}
	else
		First = 1;
	Work(msg, hWnd, windowsclass);
}
//VOID BlockT(int z)
//{
//	if (Mouse.x - GetPositionX() >= BlockText[0].x && Mouse.x - GetPositionX() <= BlockText[1].x && Mouse.y - GetPositionY() >= BlockText[0].y + 50 && Mouse.y - GetPositionY() <= BlockText[1].y + 25)
//	{
//		for (int i = 0; i < 2; i++)
//			//mas[i] = Coubu();
//			mas[i] = 6;
//		if (mas[0] != mas[1])
//		{
//			cub = false;
//			SideCube = mas[0];
//			SideCube2 = mas[1];
//			quantiti = 1;
//			DrawCoub();
//		}
//		if (mas[0] == mas[1])
//		{
//			cub = true;
//			quantiti = 4;
//			SideCube = mas[0];
//			switch (SideCube)
//			{
//			case 1:
//			{
//					  CubeOne[0].x = x_y_CubeOne[0].x;
//					  CubeOne[0].y = x_y_CubeOne[0].y;
//					  CubeOne[1].x = x_y_CubeOne[1].x;
//					  CubeOne[1].y = x_y_CubeOne[1].y + 75;
//			}
//				break;
//			case 2:
//			{
//					  CubeTwo[0].x = x_y_CubeOne[0].x;
//					  CubeTwo[0].y = x_y_CubeOne[0].y;
//					  CubeTwo[1].x = x_y_CubeOne[1].x;
//					  CubeTwo[1].y = x_y_CubeOne[1].y + 75;
//			}
//				break;
//			case 3:
//			{
//					  CubeThree[0].x = x_y_CubeOne[0].x;
//					  CubeThree[0].y = x_y_CubeOne[0].y;
//					  CubeThree[1].x = x_y_CubeOne[1].x;
//					  CubeThree[1].y = x_y_CubeOne[1].y + 75;
//			}
//				break;
//			case 4:
//			{
//					  CubeFour[0].x = x_y_CubeOne[0].x;
//					  CubeFour[0].y = x_y_CubeOne[0].y;
//					  CubeFour[1].x = x_y_CubeOne[1].x;
//					  CubeFour[1].y = x_y_CubeOne[1].y + 75;
//			}
//				break;
//			case 5:
//			{
//					  CubeFive[0].x = x_y_CubeOne[0].x;
//					  CubeFive[0].y = x_y_CubeOne[0].y;
//					  CubeFive[1].x = x_y_CubeOne[1].x;
//					  CubeFive[1].y = x_y_CubeOne[1].y + 75;
//
//			}
//				break;
//			case 6:
//			{
//					  CubeSix[0].x = x_y_CubeOne[0].x;
//					  CubeSix[0].y = x_y_CubeOne[0].y;
//					  CubeSix[1].x = x_y_CubeOne[1].x;
//					  CubeSix[1].y = x_y_CubeOne[1].y + 75;
//			}
//				break;
//			default:
//				break;
//			}
//			SideCube2 = 0;
//		}
//		BlockText[0].x = 0;
//		BlockText[0].y = 0;
//
//		BlockText[1].x = 0;
//		BlockText[1].y = 0;
//	}
//	else
//		First = 1;
//	Work(msg, hWnd, windowsclass);
//}
VOID Click_Button(int z)
{
	if (z == 0)
	{
		ram = 1;
		for (int i = 0; i < 8; i++)
		{
			x_y_key[i].x = x_y_key[i].y = NULL;
		}
	}
}
INT Coubu()
{
	return rand() % 5 + 1;
}
VOID GoHome(int NumberPawn, bool ColorPawn)
{
	if (!ColorPawn)
	{
		int ram = 0, z = 0;
		for (int i = 0; i < 15; i++)
		{
			if (Black_pawn_mas[i].GetPositionField() == 24)
				ram++;
		}
		for (int i = 0; i < ram + 1; i++)
		{
			Black_pawn_mas[NumberPawn].SetBottomRightPointX(50.0);
			Black_pawn_mas[NumberPawn].SetBottomRightPointY(27.0f + z);
			Black_pawn_mas[NumberPawn].SetTopLeftPointX(0.0);
			Black_pawn_mas[NumberPawn].SetTopLeftPointY(78.0f + z);
			z += 25;
		}
	}
	else
	{
		int ram = 0, z = 0;
		for (int i = 0; i < 15; i++)
		{
			if (White_pawn_mas[i].GetPositionField() == 25)
				ram++;
		}
		for (int i = 0; i < ram + 1; i++)
		{
			White_pawn_mas[NumberPawn].SetBottomRightPointX(800.0f);
			White_pawn_mas[NumberPawn].SetBottomRightPointY(490.0f - z);
			White_pawn_mas[NumberPawn].SetTopLeftPointX(755.0f);
			White_pawn_mas[NumberPawn].SetTopLeftPointY(540.0f - z);
			z += 25;
		}
	}
}
VOID OptionMenu()
{
	if (Mouse.x - GetPositionX() >= x_y_key[0].x - 40 && Mouse.x - GetPositionX() <= x_y_key[1].x + 5 && Mouse.y - GetPositionY() >= x_y_key[0].y + 50 && Mouse.y - GetPositionY() <= x_y_key[1].y + 25)
	{
		Click_Button(0);
		flag = 1;
		Go = true;
		First = 0;
		All_Field.SetOnePawn(0, 15);
		All_Field.SetOnePawn(12, -15);
		BlockText[0].x = 350;
		BlockText[0].y = 175;

		BlockText[1].x = 500;
		BlockText[1].y = 250;
		Work(msg, hWnd, windowsclass);

	}
	if (Mouse.x - GetPositionX() >= x_y_key[2].x - 40 && Mouse.x - GetPositionX() <= x_y_key[3].x + 5 && Mouse.y - GetPositionY() >= x_y_key[2].y + 50 && Mouse.y - GetPositionY() <= x_y_key[3].y + 25)
	{
		ram = 4;
		for (int i = 0; i < 8; i++)
		{
			x_y_key[i].x = x_y_key[i].y = NULL;
		}
	}
	if (Mouse.x - GetPositionX() >= x_y_key[6].x - 40 && Mouse.x - GetPositionX() <= x_y_key[7].x + 5 && Mouse.y - GetPositionY() >= x_y_key[6].y + 70 && Mouse.y - GetPositionY() <= x_y_key[7].y + 25)
	{
		PostQuitMessage(0);
		exit(0);
	}
}
FLOAT Motion(FLOAT PositionXorY, FLOAT Position, int NewPosition)
{
	if ((Position + (float)NewPosition) < 12)
	{
		if (Position < 12)
		{
			for (int i = (int)Position; i < (int)Position + NewPosition; i++)
			{
				PositionXorY += Move_Right[i];
			}
		}
		else if (Position < 24 && Position >= 12)
		{
			int z = 0;
			float buf = 0;
			for (int i = (int)Position + 1; i < 24; i++)
			{
				PositionXorY -= Move_Left[i];
				z++;
			}
			buf = (float)NewPosition - z - 1;
			for (int i = 0; i < buf; i++)
			{
				PositionXorY += Move_Right[i];
			}
		}
	}
	else if ((Position + (float)NewPosition) >= 24)
	{
		int z = 0;
		for (int i = (int)Position + 1 - 12; i < 24 - 12; i++)
		{
			PositionXorY -= Move_Left[i - 1];
			z++;
		}
		for (int i = 0; i < (float)NewPosition - z - 1; i++)
		{
			PositionXorY += Move_Right[i];
		}
	}
	else if ((Position + (float)NewPosition) >= 12)
	{
		if (Position < 24 && Position >= 12)
		{
			Position -= 12;
			for (int i = (int)Position; i < (int)Position + (float)NewPosition; i++)
			{
				PositionXorY -= Move_Left[i];
			}
		}
		else if (Position < 12)
		{
			int z = 0;
			float buf = 0;
			for (int i = (int)Position + 1; i < 12; i++)
			{
				PositionXorY += Move_Right[i];
				z++;
			}
			buf = (float)NewPosition - z - 1;
			for (int i = 0; i < buf; i++)
			{
				PositionXorY -= Move_Left[i];
			}
		}
	}
	return PositionXorY;
}
BOOL FirstRun()
{
	First = 1;
	if (Mouse.x - GetPositionX() >= BlockText[0].x && Mouse.x - GetPositionX() <= BlockText[1].x && Mouse.y - GetPositionY() >= BlockText[0].y + 50 && Mouse.y - GetPositionY() <= BlockText[1].y + 25)
	{
		while (true)
		{
			for (int i = 0; i < 2; i++)
				mas[i] = Coubu();

			if (mas[0] > mas[1])
			{
				DrawCoub();
				return false;
			}
			else if (mas[0] < mas[1])
			{
				DrawCoub();
				return true;
			}
		}
	}
	else
		First = 0;
}
int kysh()
{
	if (mas[0] == mas[1])
	{
		return 4;
	}
	else
	{
		return 2;
	}
}
BOOL SixPawn(bool ColorPawn, int Position, int NewPosition)
{
	int ram = 0;
	if (!ColorPawn)
	{
		for (int i = 0; i < 24; i++)
		{
			if (i == Position && All_Field.ReturnOnePawn(i) == 1)
			{
				ram = 0;
			}
			else if (i == NewPosition && All_Field.ReturnOnePawn(i) >= 0)
			{
				ram++;
			}
			else if (All_Field.ReturnOnePawn(i) > 0)
			{
				ram++;
			}
			else if (All_Field.ReturnOnePawn(i) <= 0)
			{
				ram = 0;
			}

			if (ram == 6)
			{
				if (i < 12)
				{
					for (int j = i; j < 12; j++)
					{
						if (All_Field.ReturnOnePawn(j) < 0)
							return true;
					}
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < 24; i++)
		{
			if (i == Position && All_Field.ReturnOnePawn(i) == -1)
			{
				ram = 0;
			}
			else if (i == NewPosition && All_Field.ReturnOnePawn(i) <= 0)
			{
				ram++;
			}
			else if (All_Field.ReturnOnePawn(i) < 0)
			{
				ram++;
			}
			else if (All_Field.ReturnOnePawn(i) >= 0)
			{
				ram = 0;
			}


			if (ram == 6)
			{
				if (i < 24 && i >= 12)
				{
					for (int j = i; j < 24; j++)
					{
						if (All_Field.ReturnOnePawn(j) > 0)
							return true;
					}
					return false;
				}
			}
		}
		return true;
	}
}
VOID TestProgress(bool ColorPawn)
{
	not = not_run;
	if (!ColorPawn)
	{
		int i;
		for (i = 15;  i >= not_run; i--)
		{
			for (int z = 0; z < 2; z++)
			{
				if (All_Field.ReturnOnePawn(Black_pawn_mas[i].GetPositionField() + mas[z]) < 0  && mas[z] != 0)
					not++;
				/*if (head && Black_pawn_mas[i].GetPositionField() == 0 && mas[z] != 0)
					ram++;*/
			}
		}
		if (not == 30)
		{
			MessageBox(NULL, L"Пропуск ходa черных.", L"Пропуск ход", MB_OK);
			Run = true;
			head = false;
			BlockText[0].x = 350;
			BlockText[0].y = 175;

			BlockText[1].x = 500;
			BlockText[1].y = 250;
			//BlockT();
			//RunPawn(Run, posit);
		}
	}
	else
	{
		int ram = 0, i;
		for (i = 0; i < 15; i++)
		{
			for (int z = 0; z < 2; z++)
			{
				if (All_Field.ReturnOnePawn(White_pawn_mas[i].GetPositionField() + mas[z]) > 0 && mas[z] != 0)
					ram++;
				if (head && White_pawn_mas[i].GetPositionField() == 12 && mas[z] != 0)
					ram++;
			}
		}
		if (ram == 30)
		{
			MessageBox(NULL, L"Пропуск ходa белих.", L"Пропуск ход", MB_OK);
			Run = false;
			head = false;
			BlockText[0].x = 350;
			BlockText[0].y = 175;

			BlockText[1].x = 500;
			BlockText[1].y = 250;
			//BlockT();

			
		}
	}
}
BOOL TestKush()
{
	if (mas[0] == 6 && mas[1] == 6)
		return true;
	else if (mas[0] == 4 && mas[1] == 4)
		return true;
	else if (mas[0] == 3 && mas[1] == 3)
		return true;
	else
		return false;
}
VOID NormalRendering(bool ColorPawn, int NumberPawn, int z)
{
	if (!ColorPawn)
	{
		if (Black_pawn_mas[NumberPawn].GetPositionField() < 24 && Black_pawn_mas[NumberPawn].GetPositionField() >= 12)
		{
			for (int i = 14; i >= 0; i--)
			{
				if (NumberPawn != i)
				{
					if (All_Field.ReturnOnePawn(Black_pawn_mas[NumberPawn].GetPositionField()) == -1)
						break;
					if (Black_pawn_mas[NumberPawn].GetPositionField() == 12)
						break;
					if (Black_pawn_mas[NumberPawn].GetPositionField() == Black_pawn_mas[i].GetPositionField()
						&& NumberPawn < i)
					{
						Pawn l;
						l = Black_pawn_mas[NumberPawn];
						Black_pawn_mas[NumberPawn] = Black_pawn_mas[i];
						Black_pawn_mas[i] = l;
					}
				}
			}
		}
		else if (Black_pawn_mas[NumberPawn].GetPositionField() < 12)
		{

			for (int i = 14; i >= 0; i--)
			{
				if (NumberPawn != i)
				{
					if (All_Field.ReturnOnePawn(Black_pawn_mas[NumberPawn].GetPositionField()) == 1)
						break;
					if (Black_pawn_mas[NumberPawn].GetPositionField() == 0)
						break;
					if (Black_pawn_mas[NumberPawn].GetPositionField() == Black_pawn_mas[i].GetPositionField()
						&& NumberPawn < i)
					{
						Pawn l;
						l = Black_pawn_mas[NumberPawn];
						Black_pawn_mas[NumberPawn] = Black_pawn_mas[i];
						Black_pawn_mas[i] = l;
					}
				}
			}
		}
	}
	else
	{
		if (White_pawn_mas[NumberPawn].GetPositionField() < 24 && White_pawn_mas[NumberPawn].GetPositionField() >= 12)
		{
			for (int i = 14; i >= 0; i--)
			{
				if (NumberPawn != i)
				{
					if (All_Field.ReturnOnePawn(White_pawn_mas[NumberPawn].GetPositionField()) == -1)
						break;
					if (White_pawn_mas[NumberPawn].GetPositionField() == 12)
						break;
					if (White_pawn_mas[NumberPawn].GetPositionField() == White_pawn_mas[i].GetPositionField()
						&& NumberPawn < i)
					{
						Pawn l;
						l = White_pawn_mas[NumberPawn];
						White_pawn_mas[NumberPawn] = White_pawn_mas[i];
						White_pawn_mas[i] = l;
					}
				}
			}
		}
		else if (White_pawn_mas[NumberPawn].GetPositionField() < 12)
		{
			for (int i = 14; i >= 0; i--)
			{
				if (NumberPawn != i)
				{
					if (All_Field.ReturnOnePawn(White_pawn_mas[NumberPawn].GetPositionField()) == -1)
						break;
					if (White_pawn_mas[NumberPawn].GetPositionField() == 12)
						break;
					if (White_pawn_mas[NumberPawn].GetPositionField() == White_pawn_mas[i].GetPositionField()
						&& NumberPawn < i)
					{
						Pawn l;
						l = White_pawn_mas[NumberPawn];
						White_pawn_mas[NumberPawn] = White_pawn_mas[i];
						White_pawn_mas[i] = l;
					}
				}
			}
		}
	}
}
VOID Cub(bool cub, int z)
{
	int p;
	if (cub)
	{
		p = mas[z];
		mas[z] = 0;
		CubeOne[1].y -= 25;
		CubeTwo[1].y -= 25;
		CubeThree[1].y -= 25;
		CubeFour[1].y -= 25;
		CubeFive[1].y -= 25;
		CubeSix[1].y -= 25;
		quantiti--;
		if (quantiti == 0)
		{
			CubeSix[0].x = 0;
			CubeSix[0].y = 0;

			CubeSix[1].x = 0;
			CubeSix[1].y = 0;

			CubeFive[0].x = 0;
			CubeFive[0].y = 0;

			CubeFive[1].x = 0;
			CubeFive[1].y = 0;

			CubeFour[0].x = 0;
			CubeFour[0].y = 0;

			CubeFour[1].x = 0;
			CubeFour[1].y = 0;

			CubeThree[0].x = 0;
			CubeThree[0].y = 0;

			CubeThree[1].x = 0;
			CubeThree[1].y = 0;

			CubeThree[0].x = 0;
			CubeThree[0].y = 0;

			CubeThree[1].x = 0;
			CubeThree[1].y = 0;

			CubeTwo[0].x = 0;
			CubeTwo[0].y = 0;

			CubeTwo[1].x = 0;
			CubeTwo[1].y = 0;

			CubeOne[0].x = 0;
			CubeOne[0].y = 0;

			CubeOne[1].x = 0;
			CubeOne[1].y = 0;

			BlockText[0].x = 350;
			BlockText[0].y = 175;

			BlockText[1].x = 500;
			BlockText[1].y = 250;
		}
		CubeSix[1].y = x_y_CubeOne[1].y + 25;
		if (!Stop)
		{
			if (z == 1 && kysh() == 4)
			{
				z = 0;
				mas[0] = p;
				mas[1] = p;
				Stop = true;
				kol = 2;
			}
		}
		else
		{
			k++;
		}
		if (k == 2 && Stop)
		{
			Stop = false;
			k = 0;

		}
	}
	else
	{

		switch (mas[z])
		{
		case 1:
		{
				  CubeOne[0].x = 0;
				  CubeOne[0].y = 0;

				  CubeOne[1].x = 0;
				  CubeOne[1].y = 0;
		}
			break;
		case 2:
		{
				  CubeTwo[0].x = 0;
				  CubeTwo[0].y = 0;

				  CubeTwo[1].x = 0;
				  CubeTwo[1].y = 0;
		}
			break;
		case 3:
		{
				  CubeThree[0].x = 0;
				  CubeThree[0].y = 0;

				  CubeThree[1].x = 0;
				  CubeThree[1].y = 0;
		}
			break;
		case 4:
		{
				  CubeFour[0].x = 0;
				  CubeFour[0].y = 0;

				  CubeFour[1].x = 0;
				  CubeFour[1].y = 0;
		}
			break;
		case 5:
		{
				  CubeFive[0].x = 0;
				  CubeFive[0].y = 0;

				  CubeFive[1].x = 0;
				  CubeFive[1].y = 0;

		}
			break;
		case 6:
		{
				  CubeSix[0].x = 0;
				  CubeSix[0].y = 0;

				  CubeSix[1].x = 0;
				  CubeSix[1].y = 0;
		}
			break;
		default:
			break;

		}
		mas[z] = 0;
		if ((mas[0] || mas[1]) == 0)
		{
			BlockText[0].x = 350;
			BlockText[0].y = 175;

			BlockText[1].x = 500;
			BlockText[1].y = 250;
		}
	}
}
VOID RunPawn(bool Rune, bool Poisition)
{
	int i;
	if ((mas[0] || mas[1]) == 0)
	{
		head = false;
		if (kush)
			kush = !kush;
		else
		{
			HeadKush = 1;
			HeadKush1 = 1;
			HeadKush2 = 1;
			HeadKush3 = 1;
		}
		
		if (!Run && falag_3 && ram == 1)
			MessageBox(NULL, L"Ход черных.", L"Ход", MB_OK);
		else if (Run && falag_3 && ram == 1)
			MessageBox(NULL, L"Ход Белых.", L"Ход", MB_OK);
		BlockT();
	}
	
	if (!Rune)
	{
		TestProgress(false);
		if (!StartRun)
		{
			for (i = QUANTITY_PAWN - 1; i >= 0; i--)
			{
				if (Mouse.x - GetPositionX() >= Black_pawn_mas[i].GetTopLeftPointX() && Mouse.x - GetPositionX() <= Black_pawn_mas[i].GetBottomRightPointX()
					&& Mouse.y - GetPositionY() >= Black_pawn_mas[i].GetBottomRightPointY() + 35 && Mouse.y - GetPositionY() <= Black_pawn_mas[i].GetTopLeftPointY() + 35)
				{

					Black_pawn_mas[i].SetActiviti(true);
					StartRun = true;

					if (Black_pawn_mas[i].GetPositionField() < 24 && Black_pawn_mas[i].GetPositionField() >= 12)
					{
						for (int j = QUANTITY_PAWN - 1; j >= 0; j--)
						{
							if (j != i)
							{
								if (Black_pawn_mas[i].GetTopLeftPointX() == Black_pawn_mas[j].GetTopLeftPointX() && Black_pawn_mas[i].GetBottomRightPointX() == Black_pawn_mas[j].GetBottomRightPointX()
									&& Black_pawn_mas[i].GetBottomRightPointY() <= Black_pawn_mas[j].GetBottomRightPointY() && Black_pawn_mas[i].GetTopLeftPointY() <= Black_pawn_mas[j].GetTopLeftPointY()
									&& Black_pawn_mas[i].GetPositionField() == Black_pawn_mas[j].GetPositionField())
								{
									Black_pawn_mas[i].SetActiviti(false);
									StartRun = false;
									break;
								}
							}
						}
					}
					else if (Black_pawn_mas[i].GetPositionField() < 12)
					{
						for (int j = QUANTITY_PAWN - 1; j >= 0; j--)
						{
							if (j != i)
							{
								if (Black_pawn_mas[i].GetTopLeftPointX() == Black_pawn_mas[j].GetTopLeftPointX() && Black_pawn_mas[i].GetBottomRightPointX() == Black_pawn_mas[j].GetBottomRightPointX()
									&& Black_pawn_mas[i].GetBottomRightPointY() >= Black_pawn_mas[j].GetBottomRightPointY() && Black_pawn_mas[i].GetTopLeftPointY() >= Black_pawn_mas[j].GetTopLeftPointY()
									&& Black_pawn_mas[i].GetPositionField() == Black_pawn_mas[j].GetPositionField())
								{
									Black_pawn_mas[i].SetActiviti(false);
									StartRun = false;
									break;
								}
							}
						}
					}
					if (head && Black_pawn_mas[i].GetPositionField() == 0)
					{
						Black_pawn_mas[i].SetActiviti(false);
						StartRun = false;
						break;
					}
					activ = i;
					GreenPosition[0].x = (long)Black_pawn_mas[i].GetTopLeftPointX();
					GreenPosition[0].y = (long)Black_pawn_mas[i].GetBottomRightPointY();

					GreenPosition[1].x = (long)Black_pawn_mas[i].GetBottomRightPointX();
					GreenPosition[1].y = (long)Black_pawn_mas[i].GetTopLeftPointY();
					break;
				}
			}
		}
		else
		{
			bool Over = false;
			for (i = QUANTITY_PAWN - 1; i >= 0; i--)
			{
				for (int z = 0; z < 2; z++)
				{
					if (Black_pawn_mas[i].GetActiviti()
						&& All_Field.ReturnOnePawn(Black_pawn_mas[i].GetPositionField() + mas[z]) >= 0
						&& mas[z] != 0
						&& (Mouse.x - GetPositionX() >= Motion(Black_pawn_mas[i].GetTopLeftPointX(), Black_pawn_mas[i].GetPositionField(), mas[z]) && Mouse.x - GetPositionX() <= Motion(Black_pawn_mas[i].GetBottomRightPointX(), Black_pawn_mas[i].GetPositionField(), mas[z])
						|| Mouse.x - GetPositionX() >= 0 && Mouse.x - GetPositionX() <= 45))
					{
						if (activ != i)
						{
							break;
						}
						if (Black_pawn_mas[i].GetPositionField() + mas[z] < 12 && Mouse.y - GetPositionY() >= 0 && Mouse.y - GetPositionY() <= 300)
							continue;
						if (Black_pawn_mas[i].GetPositionField() + mas[z] >= 12 && Mouse.y - GetPositionY() >= 300 && Mouse.y - GetPositionY() <= 600)
							continue;
						falag_3 = false;
						int home = 0, buf = 0;
						for (int j = 0; j < 15; j++)
						{
							if (Black_pawn_mas[j].GetPositionField() >= 18 && Black_pawn_mas[j].GetPositionField() < 24)
							{
								home++;
							}
							if (Black_pawn_mas[j].GetPositionField() == 24)
							{
								buf++;
							}
						}
						if (home == 15 - buf)
						{
							Home_3 = true;
							if (Black_pawn_mas[i].GetPositionField() + mas[z] >= 24 && Mouse.x - GetPositionX() >= 0 && Mouse.x - GetPositionX() <= 45)
							{
								if ((Black_pawn_mas[i].GetPositionField() + mas[z] > 24) && Mouse.x - GetPositionX() >= 0 && Mouse.x - GetPositionX() <= 45)
								{
									for (int j = 0; j < 15; j++)
									{
										if (Black_pawn_mas[i].GetPositionField() > Black_pawn_mas[j].GetPositionField())
										{
											Black_pawn_mas[i].SetActiviti(false);
											StartRun = false;
											return;
										}
									}
								}
								GoHome(i, false);
								All_Field.SetOnePawn(Black_pawn_mas[i].GetPositionField(), All_Field.ReturnOnePawn(Black_pawn_mas[i].GetPositionField()) - 1);
								Black_pawn_mas[i].SetPositionField(24);
								kol--;
								Cub(cub, z);
								GreenPosition[0].x = 0;
								GreenPosition[0].y = 0;

								GreenPosition[1].x = 0;
								GreenPosition[1].y = 0;
								Over = true;
								break;
							}
							else if (Black_pawn_mas[i].GetPositionField() < 24 && Black_pawn_mas[i].GetPositionField() >= 12
								&& Mouse.x - GetPositionX() >= Motion(Black_pawn_mas[i].GetTopLeftPointX(), Black_pawn_mas[i].GetPositionField(), mas[z]) && Mouse.x - GetPositionX() <= Motion(Black_pawn_mas[i].GetBottomRightPointX(), Black_pawn_mas[i].GetPositionField(), mas[z]))
							{
								Black_pawn_mas[i].MoveLeft(i, false, z);

								All_Field.SetOnePawn(Black_pawn_mas[i].GetPositionField(), All_Field.ReturnOnePawn(Black_pawn_mas[i].GetPositionField()) - 1);
								All_Field.SetOnePawn(Black_pawn_mas[i].GetPositionField() + mas[z], All_Field.ReturnOnePawn(Black_pawn_mas[i].GetPositionField() + mas[z]) + 1);
								Black_pawn_mas[i].SetPositionField(Black_pawn_mas[i].GetPositionField() + mas[z]);
								kol--;
								Cub(cub, z);
								GreenPosition[0].x = 0;
								GreenPosition[0].y = 0;

								GreenPosition[1].x = 0;
								GreenPosition[1].y = 0;
								Over = true;
								break;
							}

						}
						else
						{
							if (!SixPawn(false, Black_pawn_mas[i].GetPositionField(), Black_pawn_mas[i].GetPositionField() + mas[z]))
							{
								GreenPosition[0].x = 0;
								GreenPosition[0].y = 0;

								GreenPosition[1].x = 0;
								GreenPosition[1].y = 0;
								break;
							}
							if (Mouse.x - GetPositionX() >= 0 && Mouse.x - GetPositionX() <= 45)
								break;
							if (Black_pawn_mas[i].GetPositionField() == 0)
							{
								head = true;
								if (TestKush() && HeadKush == 0 && !OneRun)
								{
									HeadKush = 1;
									head = false;
								}
							}

							if (Black_pawn_mas[i].GetPositionField() < 12)
							{
								Black_pawn_mas[i].MoveRight(i, false, z);
							}
							else if (Black_pawn_mas[i].GetPositionField() < 24 && Black_pawn_mas[i].GetPositionField() >= 12)
								Black_pawn_mas[i].MoveLeft(i, false, z);

							All_Field.SetOnePawn(Black_pawn_mas[i].GetPositionField(), All_Field.ReturnOnePawn(Black_pawn_mas[i].GetPositionField()) - 1);
							All_Field.SetOnePawn(Black_pawn_mas[i].GetPositionField() + mas[z], All_Field.ReturnOnePawn(Black_pawn_mas[i].GetPositionField() + mas[z]) + 1);
							Black_pawn_mas[i].SetPositionField(Black_pawn_mas[i].GetPositionField() + mas[z]);
							kol--;
							Cub(cub, z);
							NormalRendering(false, i, z);
							GreenPosition[0].x = 0;
							GreenPosition[0].y = 0;

							GreenPosition[1].x = 0;
							GreenPosition[1].y = 0;
							Over = true;
							break;
						}
					}
					else
					{
						GreenPosition[0].x = 0;
						GreenPosition[0].y = 0;

						GreenPosition[1].x = 0;
						GreenPosition[1].y = 0;
					}
				}
				if (Over)
					break;
				if (i == 0)
					break;
			}
			Black_pawn_mas[i].SetActiviti(false);
			StartRun = false;

			int sum = 0;
			for (int i = 0; i < 15; i++)
			{
				if (Black_pawn_mas[i].GetPositionField() == 24)
				{
					sum++;
				}
				if (sum == 15)
				{
					CubeSix[0].x = 0;
					CubeSix[0].y = 0;

					CubeSix[1].x = 0;
					CubeSix[1].y = 0;

					CubeFive[0].x = 0;
					CubeFive[0].y = 0;

					CubeFive[1].x = 0;
					CubeFive[1].y = 0;

					CubeFour[0].x = 0;
					CubeFour[0].y = 0;

					CubeFour[1].x = 0;
					CubeFour[1].y = 0;

					CubeThree[0].x = 0;
					CubeThree[0].y = 0;

					CubeThree[1].x = 0;
					CubeThree[1].y = 0;

					CubeThree[0].x = 0;
					CubeThree[0].y = 0;

					CubeThree[1].x = 0;
					CubeThree[1].y = 0;

					CubeTwo[0].x = 0;
					CubeTwo[0].y = 0;

					CubeTwo[1].x = 0;
					CubeTwo[1].y = 0;

					CubeOne[0].x = 0;
					CubeOne[0].y = 0;

					CubeOne[1].x = 0;
					CubeOne[1].y = 0;
					ram = 2;
					
				}
			}
			if (kol == 0)
			{
				kol = 2;
				falag_3 = true;
				Run = true;
			}
			Work(msg, hWnd, windowsclass);
		}
	}
	else
	{
		if (!StartRun)
		{
			for (i = QUANTITY_PAWN - 1; i >= 0; i--)
			{
				if (Mouse.x - GetPositionX() >= White_pawn_mas[i].GetTopLeftPointX() && Mouse.x - GetPositionX() <= White_pawn_mas[i].GetBottomRightPointX()
					&& Mouse.y - GetPositionY() >= White_pawn_mas[i].GetBottomRightPointY() + 35 && Mouse.y - GetPositionY() <= White_pawn_mas[i].GetTopLeftPointY() + 35)
				{
					White_pawn_mas[i].SetActiviti(true);
					StartRun = true;
					if (White_pawn_mas[i].GetPositionField() < 12)
					{
						for (int j = QUANTITY_PAWN - 1; j >= 0; j--)
						{
							if (j != i)
							{
								if (White_pawn_mas[i].GetTopLeftPointX() == White_pawn_mas[j].GetTopLeftPointX() && White_pawn_mas[i].GetBottomRightPointX() == White_pawn_mas[j].GetBottomRightPointX()
									&& White_pawn_mas[i].GetBottomRightPointY() >= White_pawn_mas[j].GetBottomRightPointY() && White_pawn_mas[i].GetTopLeftPointY() >= White_pawn_mas[j].GetTopLeftPointY()
									&& White_pawn_mas[i].GetPositionField() == White_pawn_mas[j].GetPositionField())
								{
									White_pawn_mas[i].SetActiviti(false);
									StartRun = false;
									break;
								}
							}
						}
					}
					else if (White_pawn_mas[i].GetPositionField() < 24 && White_pawn_mas[i].GetPositionField() >= 12)
					{
						for (int j = QUANTITY_PAWN - 1; j >= 0; j--)
						{
							if (j != i)
							{
								if (White_pawn_mas[i].GetTopLeftPointX() == White_pawn_mas[j].GetTopLeftPointX() && White_pawn_mas[i].GetBottomRightPointX() == White_pawn_mas[j].GetBottomRightPointX()
									&& White_pawn_mas[i].GetBottomRightPointY() <= White_pawn_mas[j].GetBottomRightPointY() && White_pawn_mas[i].GetTopLeftPointY() <= White_pawn_mas[j].GetTopLeftPointY()
									&& White_pawn_mas[i].GetPositionField() == White_pawn_mas[j].GetPositionField())
								{
									White_pawn_mas[i].SetActiviti(false);
									StartRun = false;
									break;
								}
							}
						}
					}
					if (head && White_pawn_mas[i].GetPositionField() == 12)
					{
						White_pawn_mas[i].SetActiviti(false);
						StartRun = false;
						break;
					}
					activ = i;
					GreenPosition[0].x = (long)White_pawn_mas[i].GetTopLeftPointX();
					GreenPosition[0].y = (long)White_pawn_mas[i].GetBottomRightPointY();

					GreenPosition[1].x = (long)White_pawn_mas[i].GetBottomRightPointX();
					GreenPosition[1].y = (long)White_pawn_mas[i].GetTopLeftPointY();
					break;
				}
			}

		}
		else
		{
			int i;
			bool Over = false;
			for (i = QUANTITY_PAWN - 1; i >= 0; i--)
			{
				for (int z = 0; z < 2; z++)
				{
					int buf = White_pawn_mas[i].GetPositionField() + mas[z];
					if (buf >= 24)
						buf -= 24;

					if (White_pawn_mas[i].GetActiviti()
						&& All_Field.ReturnOnePawn(buf) <= 0
						&& mas[z] != 0
						&& (Mouse.x - GetPositionX() >= Motion(White_pawn_mas[i].GetTopLeftPointX(), White_pawn_mas[i].GetPositionField(), mas[z]) && Mouse.x - GetPositionX() <= Motion(White_pawn_mas[i].GetBottomRightPointX(), White_pawn_mas[i].GetPositionField(), mas[z])
						|| Mouse.x - GetPositionX() >= 755 && Mouse.x - GetPositionX() <= 800))
					{
						if (activ != i)
						{
							break;
						}
						if (White_pawn_mas[i].GetPositionField() + mas[z] >= 12 && White_pawn_mas[i].GetPositionField() + mas[z] < 24 && Mouse.y - GetPositionY() >= 300 && Mouse.y - GetPositionY() <= 600)
							continue;
						if (White_pawn_mas[i].GetPositionField() + mas[z] > 24 && Mouse.y - GetPositionY() >= 0 && Mouse.y - GetPositionY() <= 300)
							continue;
						if (White_pawn_mas[i].GetPositionField() + mas[z] < 12 && Mouse.y - GetPositionY() >= 0 && Mouse.y - GetPositionY() <= 300)
							continue;
						if (!SixPawn(true, White_pawn_mas[i].GetPositionField(), White_pawn_mas[i].GetPositionField() + mas[z]))
						{
							GreenPosition[0].x = 0;
							GreenPosition[0].y = 0;

							GreenPosition[1].x = 0;
							GreenPosition[1].y = 0;
							break;
						}
						falag_3 = false;
						int home = 0, buf = 0;
						for (int j = 0; j < 15; j++)
						{
							if (White_pawn_mas[j].GetPositionField() >= 6 && White_pawn_mas[j].GetPositionField() < 12)
							{
								home++;
							}
							if (White_pawn_mas[j].GetPositionField() >= 25)
							{
								buf++;
							}
						}
						if (home == 15 - buf)
						{
							Home_3 = true;
							if (White_pawn_mas[i].GetPositionField() + mas[z] >= 12 && Mouse.x - GetPositionX() >= 755 && Mouse.x - GetPositionX() <= 800)
							{
								if ((White_pawn_mas[i].GetPositionField() + mas[z] > 12) && Mouse.x - GetPositionX() >= 755 && Mouse.x - GetPositionX() <= 800)
								{
									for (int j = 0; j < 15; j++)
									{
										if (White_pawn_mas[i].GetPositionField() > White_pawn_mas[j].GetPositionField())
										{
											White_pawn_mas[i].SetActiviti(false);
											StartRun = false;
											return;
										}
									}
								}
								GoHome(i, true);
								All_Field.SetOnePawn(White_pawn_mas[i].GetPositionField(), All_Field.ReturnOnePawn(White_pawn_mas[i].GetPositionField()) + 1);
								White_pawn_mas[i].SetPositionField(25);
								kol--;
								Cub(cub, z);
								GreenPosition[0].x = 0;
								GreenPosition[0].y = 0;

								GreenPosition[1].x = 0;
								GreenPosition[1].y = 0;
								Over = true;
								break;
							}
							else if (White_pawn_mas[i].GetPositionField() < 12 && White_pawn_mas[i].GetPositionField() >= 6
								&& Mouse.x - GetPositionX() >= Motion(White_pawn_mas[i].GetTopLeftPointX(), White_pawn_mas[i].GetPositionField(), mas[z]) && Mouse.x - GetPositionX() <= Motion(White_pawn_mas[i].GetBottomRightPointX(), White_pawn_mas[i].GetPositionField(), mas[z]))
							{
								White_pawn_mas[i].MoveLeft(i, true, z);

								All_Field.SetOnePawn(White_pawn_mas[i].GetPositionField(), All_Field.ReturnOnePawn(White_pawn_mas[i].GetPositionField()) + 1);
								All_Field.SetOnePawn(White_pawn_mas[i].GetPositionField() + mas[z], All_Field.ReturnOnePawn(White_pawn_mas[i].GetPositionField() + mas[z]) - 1);
								White_pawn_mas[i].SetPositionField(White_pawn_mas[i].GetPositionField() + mas[z]);
								kol--;
								Cub(cub, z);
								GreenPosition[0].x = 0;
								GreenPosition[0].y = 0;

								GreenPosition[1].x = 0;
								GreenPosition[1].y = 0;
								Over = true;
								break;
							}

						}
						else
						{
							if (Mouse.x - GetPositionX() >= 755 && Mouse.x - GetPositionX() <= 800)
								break;

							if (White_pawn_mas[i].GetPositionField() == 12)
							{
								head = true;
								if (TestKush() && HeadKush3 == 0 && !OneRun)
								{
									HeadKush3 = 1;
									head = false;
								}
							}
							if (White_pawn_mas[i].GetPositionField() < 12)
								White_pawn_mas[i].MoveRight(i, true, z);
							else if (White_pawn_mas[i].GetPositionField() < 24 && White_pawn_mas[i].GetPositionField() >= 12)
								White_pawn_mas[i].MoveLeft(i, true, z);

							All_Field.SetOnePawn(White_pawn_mas[i].GetPositionField(), All_Field.ReturnOnePawn(White_pawn_mas[i].GetPositionField()) + 1);
							if (White_pawn_mas[i].GetPositionField() + mas[z] >= 24)
							{
								All_Field.SetOnePawn(White_pawn_mas[i].GetPositionField() + mas[z] - 24, All_Field.ReturnOnePawn(White_pawn_mas[i].GetPositionField() + mas[z] - 24) - 1);
								White_pawn_mas[i].SetPositionField(White_pawn_mas[i].GetPositionField() + mas[z] - 24);
							}
							else
							{
								All_Field.SetOnePawn(White_pawn_mas[i].GetPositionField() + mas[z], All_Field.ReturnOnePawn(White_pawn_mas[i].GetPositionField() + mas[z]) - 1);
								White_pawn_mas[i].SetPositionField(White_pawn_mas[i].GetPositionField() + mas[z]);
							}

							kol--;
							Cub(cub, z);
							NormalRendering(true, i, z);
							GreenPosition[0].x = 0;
							GreenPosition[0].y = 0;

							GreenPosition[1].x = 0;
							GreenPosition[1].y = 0;
							Over = true;
							break;
						}
					}
					else
					{
						GreenPosition[0].x = 0;
						GreenPosition[0].y = 0;

						GreenPosition[1].x = 0;
						GreenPosition[1].y = 0;
					}
				}
				if (Over)
					break;
				if (i == 0)
					break;
			}
			White_pawn_mas[i].SetActiviti(false);
			StartRun = false;

			int sum = 0;
			for (int i = 0; i < 15; i++)
			{
				if (White_pawn_mas[i].GetPositionField() == 25)
					sum++;
				if (sum == 15)
				{
					CubeSix[0].x = 0;
					CubeSix[0].y = 0;

					CubeSix[1].x = 0;
					CubeSix[1].y = 0;

					CubeFive[0].x = 0;
					CubeFive[0].y = 0;

					CubeFive[1].x = 0;
					CubeFive[1].y = 0;

					CubeFour[0].x = 0;
					CubeFour[0].y = 0;

					CubeFour[1].x = 0;
					CubeFour[1].y = 0;

					CubeThree[0].x = 0;
					CubeThree[0].y = 0;

					CubeThree[1].x = 0;
					CubeThree[1].y = 0;

					CubeThree[0].x = 0;
					CubeThree[0].y = 0;

					CubeThree[1].x = 0;
					CubeThree[1].y = 0;

					CubeTwo[0].x = 0;
					CubeTwo[0].y = 0;

					CubeTwo[1].x = 0;
					CubeTwo[1].y = 0;

					CubeOne[0].x = 0;
					CubeOne[0].y = 0;

					CubeOne[1].x = 0;
					CubeOne[1].y = 0;
					ram = 3;
				}
			}
			if (kol == 0)
			{
				kol = 2;
				falag_3 = true;
				Run = false;
			}
			Work(msg, hWnd, windowsclass);
		}
	}
	Work(msg, hWnd, windowsclass);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
					   DeleteDirect3D();
					   PostQuitMessage(0);
					   exit(0);

	} break;
	case WM_LBUTTONDOWN:
	{
						   if (!Go)
						   {
							   OptionMenu();
								if (flag2)
								{
									ram = 0;
									x_y_key[0] = { 350, 100 };
									x_y_key[1] = { 500, 180 };
									x_y_key[6] = { 350, 400 };
									x_y_key[7] = { 500, 500 };
								}
							   flag2 = true;
						   }
						   else
						   {
							   if (!First)
							   {
								   Run = FirstRun();
								   Work(msg, hWnd, windowsclass);
							   }
							 
							   if (First != -1)
							   {
								   if (!Run && falag_3 && ram == 1)
									   MessageBox(NULL, L"Ход черных.", L"Ход", MB_OK);
								   else if (Run && falag_3 && ram == 1)
									   MessageBox(NULL, L"Ход Белых.", L"Ход", MB_OK);
								   BlockT();
							   }
						   }

						   
							RunPawn(Run, posit);
						   break;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
VOID Work(MSG msg, HWND hWnd, WNDCLASSEX windowsclass)
{
	if (SUCCEEDED(InitialBufferVershin(ram)))
	{
		SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE)&~WS_MAXIMIZEBOX&~WS_MINIMIZEBOX);
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			RenderingDirect3D();
		}
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand((unsigned)time(NULL));
	ZeroMemory(&windowsclass, sizeof(WNDCLASSEX));
	windowsclass.cbSize = sizeof(WNDCLASSEX);
	windowsclass.style = CS_HREDRAW | CS_VREDRAW;
	windowsclass.lpfnWndProc = WindowProc;
	windowsclass.cbClsExtra = 0;
	windowsclass.cbWndExtra = 0;
	windowsclass.hInstance = hInstance;
	windowsclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowsclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowsclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowsclass.lpszMenuName = NULL;
	windowsclass.lpszClassName = L"WindowClass";
	windowsclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&windowsclass))
		return(0);

	if (!(hWnd = CreateWindowEx(NULL, L"WindowClass", L"Нарды", WS_OVERLAPPEDWINDOW, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL, hInstance, NULL)))
		return 0;

	InitialPawn();
	if (SUCCEEDED(InitialDirect3D(hWnd, ram)))
	{
		Work(msg, hWnd, windowsclass);
	}
	return 0;
}