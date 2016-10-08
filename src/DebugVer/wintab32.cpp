// wintab32_.cpp : wintab32_のエントリポイント
//

#include <windows.h>

DECLARE_HANDLE(HCTX);		/* context handle */

//FARPROC p_WTInfoA;
typedef unsigned int (*D_WTInfoA)(unsigned int, unsigned int, LPVOID);
D_WTInfoA p_WTInfoA;
//FARPROC p_WTOpenA;
typedef HCTX (*D_WTOpenA)(HWND, LPVOID, BOOL);
D_WTOpenA p_WTOpenA;
//FARPROC p_WTClose;
typedef BOOL (*D_WTClose)(HCTX);
D_WTClose p_WTClose;
FARPROC p_WTPacketsGet;
//FARPROC p_WTPacket;
typedef BOOL (*D_WTPacket)(HCTX, unsigned int, LPVOID);
D_WTPacket p_WTPacket;
FARPROC p_WTEnable;
//FARPROC p_WTOverlap;
typedef BOOL (*D_WTOverlap)(HCTX, BOOL);
D_WTOverlap p_WTOverlap;
FARPROC p_WTConfig;
FARPROC p_WTGetA;
FARPROC p_WTSetA;
FARPROC p_WTExtGet;
FARPROC p_WTExtSet;
FARPROC p_WTSave;
FARPROC p_WTRestore;
//FARPROC p_WTPacketsPeek;
FARPROC p_WTDataGet;
FARPROC p_WTDataPeek;
FARPROC p_WTQueueSizeGet;
//FARPROC p_WTQueueSizeSet;
typedef BOOL (*D_WTQueueSizeSet)(HCTX, int);
D_WTQueueSizeSet p_WTQueueSizeSet;
FARPROC p_WTMgrOpen;
FARPROC p_WTMgrClose;
FARPROC p_WTMgrContextEnum;
FARPROC p_WTMgrContextOwner;
FARPROC p_WTMgrDefContext;
FARPROC p_WTMgrDeviceConfig;
FARPROC p_WTMgrExt;
FARPROC p_WTMgrCsrEnable;
FARPROC p_WTMgrCsrButtonMap;
FARPROC p_WTMgrCsrPressureBtnMarks;
FARPROC p_WTMgrCsrPressureResponse;
FARPROC p_WTMgrCsrExt;
FARPROC p_WTQueuePacketsEx;
FARPROC p_WTMgrCsrPressureBtnMarksEx;
FARPROC p_WTMgrConfigReplaceExA;
FARPROC p_WTMgrPacketHookExA;
FARPROC p_WTMgrPacketUnhook;
FARPROC p_WTMgrPacketHookNext;
FARPROC p_WTMgrDefContextEx;
FARPROC p_WTInfoW;
FARPROC p_WTOpenW;
FARPROC p_WTGetW;
FARPROC p_WTSetW;
FARPROC p_WTMgrConfigReplaceExW;
FARPROC p_WTMgrPacketHookExW;

typedef int (*D_WTPacketsPeek)(HCTX, int, LPVOID);
D_WTPacketsPeek p_WTPacketsPeek;

HINSTANCE h_original;

BOOL APIENTRY DllMain( HANDLE hModule, 
                    DWORD  ul_reason_for_call, 
                    LPVOID lpReserved
                  )
{
 switch( ul_reason_for_call )
 {
 case DLL_PROCESS_ATTACH:
     h_original = LoadLibrary( "WINTAB32_.dll" );
     if ( h_original == NULL )
         return FALSE;
       //p_WTInfoA = GetProcAddress( h_original, "WTInfoA" );
       p_WTInfoA = (D_WTInfoA)GetProcAddress( h_original, "WTInfoA" );
       //p_WTOpenA = GetProcAddress( h_original, "WTOpenA" );
       p_WTOpenA = (D_WTOpenA)GetProcAddress( h_original, "WTOpenA" );
       //p_WTClose = GetProcAddress( h_original, "WTClose" );
       p_WTClose = (D_WTClose)GetProcAddress( h_original, "WTClose" );
       p_WTPacketsGet = GetProcAddress( h_original, "WTPacketsGet" );
       //p_WTPacket = GetProcAddress( h_original, "WTPacket" );
       p_WTPacket = (D_WTPacket)GetProcAddress( h_original, "WTPacket" );
       p_WTEnable = GetProcAddress( h_original, "WTEnable" );
       //p_WTOverlap = GetProcAddress( h_original, "WTOverlap" );
       p_WTOverlap = (D_WTOverlap)GetProcAddress( h_original, "WTOverlap" );
       p_WTConfig = GetProcAddress( h_original, "WTConfig" );
       p_WTGetA = GetProcAddress( h_original, "WTGetA" );
       p_WTSetA = GetProcAddress( h_original, "WTSetA" );
       p_WTExtGet = GetProcAddress( h_original, "WTExtGet" );
       p_WTExtSet = GetProcAddress( h_original, "WTExtSet" );
       p_WTSave = GetProcAddress( h_original, "WTSave" );
       p_WTRestore = GetProcAddress( h_original, "WTRestore" );
       p_WTPacketsPeek = (D_WTPacketsPeek)GetProcAddress( h_original, "WTPacketsPeek" );
       p_WTDataGet = GetProcAddress( h_original, "WTDataGet" );
       p_WTDataPeek = GetProcAddress( h_original, "WTDataPeek" );
       p_WTQueueSizeGet = GetProcAddress( h_original, "WTQueueSizeGet" );
       //p_WTQueueSizeSet = GetProcAddress( h_original, "WTQueueSizeSet" );
       p_WTQueueSizeSet = (D_WTQueueSizeSet)GetProcAddress( h_original, "WTQueueSizeSet" );
       p_WTMgrOpen = GetProcAddress( h_original, "WTMgrOpen" );
       p_WTMgrClose = GetProcAddress( h_original, "WTMgrClose" );
       p_WTMgrContextEnum = GetProcAddress( h_original, "WTMgrContextEnum" );
       p_WTMgrContextOwner = GetProcAddress( h_original, "WTMgrContextOwner" );
       p_WTMgrDefContext = GetProcAddress( h_original, "WTMgrDefContext" );
       p_WTMgrDeviceConfig = GetProcAddress( h_original, "WTMgrDeviceConfig" );
       p_WTMgrExt = GetProcAddress( h_original, "WTMgrExt" );
       p_WTMgrCsrEnable = GetProcAddress( h_original, "WTMgrCsrEnable" );
       p_WTMgrCsrButtonMap = GetProcAddress( h_original, "WTMgrCsrButtonMap" );
       p_WTMgrCsrPressureBtnMarks = GetProcAddress( h_original, "WTMgrCsrPressureBtnMarks" );
       p_WTMgrCsrPressureResponse = GetProcAddress( h_original, "WTMgrCsrPressureResponse" );
       p_WTMgrCsrExt = GetProcAddress( h_original, "WTMgrCsrExt" );
       p_WTQueuePacketsEx = GetProcAddress( h_original, "WTQueuePacketsEx" );
       p_WTMgrCsrPressureBtnMarksEx = GetProcAddress( h_original, "WTMgrCsrPressureBtnMarksEx" );
       p_WTMgrConfigReplaceExA = GetProcAddress( h_original, "WTMgrConfigReplaceExA" );
       p_WTMgrPacketHookExA = GetProcAddress( h_original, "WTMgrPacketHookExA" );
       p_WTMgrPacketUnhook = GetProcAddress( h_original, "WTMgrPacketUnhook" );
       p_WTMgrPacketHookNext = GetProcAddress( h_original, "WTMgrPacketHookNext" );
       p_WTMgrDefContextEx = GetProcAddress( h_original, "WTMgrDefContextEx" );
       p_WTInfoW = GetProcAddress( h_original, "WTInfoW" );
       p_WTOpenW = GetProcAddress( h_original, "WTOpenW" );
       p_WTGetW = GetProcAddress( h_original, "WTGetW" );
       p_WTSetW = GetProcAddress( h_original, "WTSetW" );
       p_WTMgrConfigReplaceExW = GetProcAddress( h_original, "WTMgrConfigReplaceExW" );
       p_WTMgrPacketHookExW = GetProcAddress( h_original, "WTMgrPacketHookExW" );
     break;
 case DLL_THREAD_ATTACH:
     break;
 case DLL_THREAD_DETACH:
     break;
 case DLL_PROCESS_DETACH:
     FreeLibrary( h_original );
     break;
 default:
     break;
 }
 return TRUE;
 }


EXTERN_C int _fltused = 0;
typedef DWORD FIX32;				/* fixed-point arithmetic type */
typedef DWORD WTPKT;			/* packet mask */
	#define FRAC(x)		LOWORD(x)
#define FIX_DOUBLE(x) ((double)(INT(x))+((double)FRAC(x)/65536))
#define LCNAMELEN		40
typedef struct tagLOGCONTEXTA {
	char	lcName[LCNAMELEN];
	UINT	lcOptions;
	UINT	lcStatus;
	UINT	lcLocks;
	UINT	lcMsgBase;
	UINT	lcDevice;
	UINT	lcPktRate;
	WTPKT	lcPktData;
	WTPKT	lcPktMode;
	WTPKT	lcMoveMask;
	DWORD	lcBtnDnMask;
	DWORD	lcBtnUpMask;
	LONG	lcInOrgX;
	LONG	lcInOrgY;
	LONG	lcInOrgZ;
	LONG	lcInExtX;
	LONG	lcInExtY;
	LONG	lcInExtZ;
	LONG	lcOutOrgX;
	LONG	lcOutOrgY;
	LONG	lcOutOrgZ;
	LONG	lcOutExtX;
	LONG	lcOutExtY;
	LONG	lcOutExtZ;
	FIX32	lcSensX;
	FIX32	lcSensY;
	FIX32	lcSensZ;
	BOOL	lcSysMode;
	int	lcSysOrgX;
	int	lcSysOrgY;
	int	lcSysExtX;
	int	lcSysExtY;
	FIX32	lcSysSensX;
	FIX32	lcSysSensY;
} LOGCONTEXTA, *PLOGCONTEXTA, NEAR *NPLOGCONTEXTA, FAR *LPLOGCONTEXTA;

//__declspec( naked ) void d_WTInfoA() { _asm{ jmp p_WTInfoA } }

UINT WINAPI WTInfoA(UINT wCategory, UINT nIndex, LPVOID lpOutput)
{
  BOOL ret = p_WTInfoA(wCategory, nIndex, lpOutput);
  char *buf = (char *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);
  wsprintf(buf, "WTInfoA: wCategory=%u, nIndex=%u, lpOutput=0x%08X, ret=%s\n", wCategory, nIndex, lpOutput, ret?"Success":"Fail");
  OutputDebugStringA(buf);
  
  if(wCategory==3 && nIndex==0)
  {
  LPLOGCONTEXTA lpCon = (LPLOGCONTEXTA)lpOutput;
  wsprintf(buf, "   lcName=%s\n   lcOptions=%u\n   lcStatus=%u\n   lcLocks=%u\n   lcMsgBase=%u\n   lcDevice=%u\n   lcPktRate=%u\n   lcPktData=0x%08X\n   lcPktMode=0x%08X\n   lcMoveMask=0x%08X\n   lcBtnDnMask=0x%08X\n   lcBtnUpMask=0x%08X\n   lcInOrgX=%d\n   lcInOrgY=%d\n   lcInOrgZ=%d\n   lcInExtX=%d\n   lcInExtY=%d\n   lcInExtZ=%d\n   lcOutOrgX=%d\n   lcOutOrgY=%d\n   lcOutOrgZ=%d\n   lcOutExtX=%d\n   lcOutExtY=%d\n   lcOutExtZ=%d\n   lcSensX=%u\n   lcSensY=%u\n   lcSensZ=%u\n   lcSysMode=%s\n   lcSysOrgX=%d\n   lcSysOrgY=%d\n   lcSysExtX=%d\n   lcSysExtY=%d\n   lcSysSensX=%u\n   lcSysSensY=%u\n", lpCon->lcName, lpCon->lcOptions, lpCon->lcStatus, lpCon->lcLocks, lpCon->lcMsgBase, lpCon->lcDevice, lpCon->lcPktRate, lpCon->lcPktData, lpCon->lcPktMode, lpCon->lcMoveMask, lpCon->lcBtnDnMask, lpCon->lcBtnUpMask, lpCon->lcInOrgX, lpCon->lcInOrgY, lpCon->lcInOrgZ, lpCon->lcInExtX, lpCon->lcInExtY, lpCon->lcInExtZ, lpCon->lcOutOrgX, lpCon->lcOutOrgY, lpCon->lcOutOrgZ, lpCon->lcOutExtX, lpCon->lcOutExtY, lpCon->lcOutExtZ, (lpCon->lcSensX), (lpCon->lcSensY), (lpCon->lcSensZ), (lpCon->lcSysMode)?"TRUE":"FALSE", lpCon->lcSysOrgX, lpCon->lcSysOrgY, lpCon->lcSysExtX, lpCon->lcSysExtY, (lpCon->lcSysSensX), (lpCon->lcSysSensY));
  OutputDebugStringA(buf);
  }
  HeapFree(GetProcessHeap(), 0, buf);
  return ret;
}

	#define CXO_SYSTEM		0x0001
//__declspec( naked ) void d_WTOpenA() { _asm{ jmp p_WTOpenA } }

HCTX WINAPI WTOpenA(HWND hWnd, LPVOID lpLogCtx, BOOL fEnable)
{
  LPLOGCONTEXTA lpCon = (LPLOGCONTEXTA)lpLogCtx;
  if(lstrcmp(lpCon->lcName, "Azel WinTab")==0)
  {
    lpCon->lcOutExtX=lpCon->lcInExtX;
    lpCon->lcOutExtY=lpCon->lcInExtY;
  }
  HCTX ret = p_WTOpenA(hWnd, lpLogCtx, fEnable);
  char *buf = (char *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);
  unsigned char *pL = (unsigned char *)lpLogCtx;
  wsprintf(buf, "WTOpenA: hWnd=0x%08X, lpLogCtx=0x%08X, fEnable=%s, lcPktData=0x%08X, lcPktMode=0x%08X, ret=%s\n", hWnd, lpLogCtx, fEnable?"TRUE":"FALSE", *((DWORD*)(pL+64)), *((DWORD*)(pL+68)), ret?"Success":"Fail");
  OutputDebugStringA(buf);
  wsprintf(buf, "   lcName=%s\n   lcOptions=%u\n   lcStatus=%u\n   lcLocks=%u\n   lcMsgBase=%u\n   lcDevice=%u\n   lcPktRate=%u\n   lcPktData=0x%08X\n   lcPktMode=0x%08X\n   lcMoveMask=0x%08X\n   lcBtnDnMask=0x%08X\n   lcBtnUpMask=0x%08X\n   lcInOrgX=%d\n   lcInOrgY=%d\n   lcInOrgZ=%d\n   lcInExtX=%d\n   lcInExtY=%d\n   lcInExtZ=%d\n   lcOutOrgX=%d\n   lcOutOrgY=%d\n   lcOutOrgZ=%d\n   lcOutExtX=%d\n   lcOutExtY=%d\n   lcOutExtZ=%d\n   lcSensX=%u\n   lcSensY=%u\n   lcSensZ=%u\n   lcSysMode=%s\n   lcSysOrgX=%d\n   lcSysOrgY=%d\n   lcSysExtX=%d\n   lcSysExtY=%d\n   lcSysSensX=%u\n   lcSysSensY=%u\n", lpCon->lcName, lpCon->lcOptions, lpCon->lcStatus, lpCon->lcLocks, lpCon->lcMsgBase, lpCon->lcDevice, lpCon->lcPktRate, lpCon->lcPktData, lpCon->lcPktMode, lpCon->lcMoveMask, lpCon->lcBtnDnMask, lpCon->lcBtnUpMask, lpCon->lcInOrgX, lpCon->lcInOrgY, lpCon->lcInOrgZ, lpCon->lcInExtX, lpCon->lcInExtY, lpCon->lcInExtZ, lpCon->lcOutOrgX, lpCon->lcOutOrgY, lpCon->lcOutOrgZ, lpCon->lcOutExtX, lpCon->lcOutExtY, lpCon->lcOutExtZ, (lpCon->lcSensX), (lpCon->lcSensY), (lpCon->lcSensZ), (lpCon->lcSysMode)?"TRUE":"FALSE", lpCon->lcSysOrgX, lpCon->lcSysOrgY, lpCon->lcSysExtX, lpCon->lcSysExtY, (lpCon->lcSysSensX), (lpCon->lcSysSensY));
  OutputDebugStringA(buf);
  HeapFree(GetProcessHeap(), 0, buf);
  return ret;
}

//__declspec( naked ) void d_WTClose() { _asm{ jmp p_WTClose } }

BOOL WINAPI WTClose(HCTX hCtx)
{
  BOOL ret = p_WTClose(hCtx);
  char *buf = (char *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);
  wsprintf(buf, "WTClose: hCtx=0x%08X, ret=%s\n", hCtx, ret?"Success":"Fail");
  OutputDebugStringA(buf);
  HeapFree(GetProcessHeap(), 0, buf);
  return ret;
}

__declspec( naked ) void d_WTPacketsGet() { _asm{ jmp p_WTPacketsGet } }
//__declspec( naked ) void d_WTPacket() { _asm{ jmp p_WTPacket } }

BOOL WINAPI WTPacket(HCTX hCtx, UINT wSerial, LPVOID lpPkt)
{
  BOOL ret = p_WTPacket(hCtx, wSerial, lpPkt);
  char *buf = (char *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);
  DWORD *dw = (DWORD*)lpPkt;
  wsprintf(buf, "WTPacket: wSerial=%u, lpPkt=0x%08X, p0=0x%08X, p1=0x%08X, p2=0x%08X, p3=0x%08X, p4=0x%08X, ret=%s\n", wSerial, lpPkt, *dw, *(dw+1), *(dw+2), *(dw+3), *(dw+4), ret?"Success":"Fail");
  OutputDebugStringA(buf);
  HeapFree(GetProcessHeap(), 0, buf);
  return ret;
}

__declspec( naked ) void d_WTEnable() { _asm{ jmp p_WTEnable } }
//__declspec( naked ) void d_WTOverlap() { _asm{ jmp p_WTOverlap } }

BOOL WINAPI WTOverlap(HCTX hCtx, BOOL fToTop)
{
  BOOL ret = p_WTOverlap(hCtx, fToTop);
  char *buf = (char *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);
  wsprintf(buf, "WTOverlap: %s, ret=%s\n", fToTop?"TRUE":"FALSE", ret?"Success":"Fail");
  OutputDebugStringA(buf);
  HeapFree(GetProcessHeap(), 0, buf);
  return ret;
}

__declspec( naked ) void d_WTConfig() { _asm{ jmp p_WTConfig } }
__declspec( naked ) void d_WTGetA() { _asm{ jmp p_WTGetA } }
__declspec( naked ) void d_WTSetA() { _asm{ jmp p_WTSetA } }
__declspec( naked ) void d_WTExtGet() { _asm{ jmp p_WTExtGet } }
__declspec( naked ) void d_WTExtSet() { _asm{ jmp p_WTExtSet } }
__declspec( naked ) void d_WTSave() { _asm{ jmp p_WTSave } }
__declspec( naked ) void d_WTRestore() { _asm{ jmp p_WTRestore } }
//__declspec( naked ) void d_WTPacketsPeek() { _asm{ jmp p_WTPacketsPeek } }
__declspec( naked ) void d_WTDataGet() { _asm{ jmp p_WTDataGet } }
__declspec( naked ) void d_WTDataPeek() { _asm{ jmp p_WTDataPeek } }
__declspec( naked ) void d_WTQueueSizeGet() { _asm{ jmp p_WTQueueSizeGet } }
//__declspec( naked ) void d_WTQueueSizeSet() { _asm{ jmp p_WTQueueSizeSet } }

BOOL WINAPI WTQueueSizeSet(HCTX hCtx, int nPkts)
{
  BOOL ret = p_WTQueueSizeSet(hCtx, nPkts);
  char *buf = (char *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);
  wsprintf(buf, "WTQueueSizeSet: nPkts=%i, ret=%s\n", nPkts, ret?"Success":"Fail");
  OutputDebugStringA(buf);
  HeapFree(GetProcessHeap(), 0, buf);
  return ret;
}

__declspec( naked ) void d_WTMgrOpen() { _asm{ jmp p_WTMgrOpen } }
__declspec( naked ) void d_WTMgrClose() { _asm{ jmp p_WTMgrClose } }
__declspec( naked ) void d_WTMgrContextEnum() { _asm{ jmp p_WTMgrContextEnum } }
__declspec( naked ) void d_WTMgrContextOwner() { _asm{ jmp p_WTMgrContextOwner } }
__declspec( naked ) void d_WTMgrDefContext() { _asm{ jmp p_WTMgrDefContext } }
__declspec( naked ) void d_WTMgrDeviceConfig() { _asm{ jmp p_WTMgrDeviceConfig } }
__declspec( naked ) void d_WTMgrExt() { _asm{ jmp p_WTMgrExt } }
__declspec( naked ) void d_WTMgrCsrEnable() { _asm{ jmp p_WTMgrCsrEnable } }
__declspec( naked ) void d_WTMgrCsrButtonMap() { _asm{ jmp p_WTMgrCsrButtonMap } }
__declspec( naked ) void d_WTMgrCsrPressureBtnMarks() { _asm{ jmp p_WTMgrCsrPressureBtnMarks } }
__declspec( naked ) void d_WTMgrCsrPressureResponse() { _asm{ jmp p_WTMgrCsrPressureResponse } }
__declspec( naked ) void d_WTMgrCsrExt() { _asm{ jmp p_WTMgrCsrExt } }
__declspec( naked ) void d_WTQueuePacketsEx() { _asm{ jmp p_WTQueuePacketsEx } }
__declspec( naked ) void d_WTMgrCsrPressureBtnMarksEx() { _asm{ jmp p_WTMgrCsrPressureBtnMarksEx } }
__declspec( naked ) void d_WTMgrConfigReplaceExA() { _asm{ jmp p_WTMgrConfigReplaceExA } }
__declspec( naked ) void d_WTMgrPacketHookExA() { _asm{ jmp p_WTMgrPacketHookExA } }
__declspec( naked ) void d_WTMgrPacketUnhook() { _asm{ jmp p_WTMgrPacketUnhook } }
__declspec( naked ) void d_WTMgrPacketHookNext() { _asm{ jmp p_WTMgrPacketHookNext } }
__declspec( naked ) void d_WTMgrDefContextEx() { _asm{ jmp p_WTMgrDefContextEx } }
__declspec( naked ) void d_WTInfoW() { _asm{ jmp p_WTInfoW } }
__declspec( naked ) void d_WTOpenW() { _asm{ jmp p_WTOpenW } }
__declspec( naked ) void d_WTGetW() { _asm{ jmp p_WTGetW } }
__declspec( naked ) void d_WTSetW() { _asm{ jmp p_WTSetW } }
__declspec( naked ) void d_WTMgrConfigReplaceExW() { _asm{ jmp p_WTMgrConfigReplaceExW } }
__declspec( naked ) void d_WTMgrPacketHookExW() { _asm{ jmp p_WTMgrPacketHookExW } }


int WINAPI WTPacketsPeek(HCTX hCtx, int cMaxPkts, LPVOID lpPkts)
{
  if(hCtx==NULL || lpPkts==NULL)return 0;
  return p_WTPacketsPeek(hCtx, cMaxPkts, lpPkts);
}
