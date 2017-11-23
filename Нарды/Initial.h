#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define QUANTITY_PAWN 15
#define DISTANCE_HEIGHT 25.0

LPDIRECT3D9 pDirect3D = NULL;
LPDIRECT3DDEVICE9 pDirect3DDevice = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferVershin = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferGameBoard = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferPlay = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferHome = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferRegulations = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferGreen = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferPravila = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferExit = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferOne = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferTwo = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferThree= NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferFour = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferFive = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferSix = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferChoice = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferBlock= NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferGameOverWinBlack = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferGameOverWinWhite = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferBlack_pawn = NULL;
LPDIRECT3DVERTEXBUFFER9 pBufferWhite_pawn = NULL;
LPDIRECT3DTEXTURE9 pMain;
LPDIRECT3DTEXTURE9 pGameBoard;
LPDIRECT3DTEXTURE9 pGameOverWinBlack;
LPDIRECT3DTEXTURE9 pGameOverWinWhite;
LPDIRECT3DTEXTURE9 pRegulations;
LPDIRECT3DTEXTURE9 pPlay;
LPDIRECT3DTEXTURE9 pHome;
LPDIRECT3DTEXTURE9 pPravila;
LPDIRECT3DTEXTURE9 pExit;
LPDIRECT3DTEXTURE9 pGreen;
LPDIRECT3DTEXTURE9 pOne;
LPDIRECT3DTEXTURE9 pTwo;
LPDIRECT3DTEXTURE9 pThree;
LPDIRECT3DTEXTURE9 pFour;
LPDIRECT3DTEXTURE9 pFive;
LPDIRECT3DTEXTURE9 pSix;
LPDIRECT3DTEXTURE9 pChoice;
LPDIRECT3DTEXTURE9 pBlock;
LPDIRECT3DTEXTURE9 pBlack_pawn;
LPDIRECT3DTEXTURE9 pWhite_pawn;
LPD3DXFONT pFont = NULL;
IDirectInput8* di;           // объект DirectInput
IDirectInputDevice8* didev;  // устройство DirectInput
LPVOID pDI;

POINT Mouse;
RECT Rect;
HFONT hFont;
MSG msg;
HWND hWnd;
WNDCLASSEX windowsclass;
POINT x_y_key[] = { { 350, 100 }, { 500, 180 }, { 350, 200 }, { 500, 300 }, { 350, 250 }, { 500, 300 }, { 350, 400 }, { 500, 500 } };
POINT BlockText[] = { { 0, 0 }, { 0, 0 } }, x_y_CubeOne[] = { { 370, 100 }, { 425, 150 } }, x_y_CubeTwo[] = { { 370, 160 }, { 425, 210 } };
POINT CubeOne[] = { { 0, 0 }, { 0, 0 } }, CubeTwo[] = { { 0, 0 }, { 0, 0 } }, CubeThree[] = { { 0, 0 }, { 0, 0 } }, CubeFour[] = { { 0, 0 }, { 0, 0 } };
POINT CubeFive[] = { { 0, 0 }, { 0, 0 } }, CubeSix[] = { { 0, 0 }, { 0, 0 } }, GreenPosition[] = { { 0, 0 }, { 0, 0 } }, Home_x_y[] = { { 0, 10 }, { 45, 55 }, { 755, 10 }, { 800, 55 } };
int a, b, v, c, k = 0, xPos, yPos, ram = 0, kol = 2, SideCube = 0, SideCube2 = 0, buf = 0, First = -1, HeadKush = 0, HeadKush1 = 0, HeadKush2 = 0, HeadKush3 = 0, activ = 0, not_run = 15, not = 0;

bool flag = false, Go = false, StartRun = false, BottomToTop = false, Run, swap = false, posit = false, Stop = false, cub = false;
bool head = false, kush = true, OneRun = false, falag_3 = true, test = false, Home_3 = false, flag2 = false, df = false;

float quantiti = 1;

VOID Work(MSG msg, HWND hWnd, WNDCLASSEX windowsclass);

struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	FLOAT tu, tv;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_TEX1)


Pawn Black_pawn_mas[QUANTITY_PAWN];
Pawn White_pawn_mas[QUANTITY_PAWN];
