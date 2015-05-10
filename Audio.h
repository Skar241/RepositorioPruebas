/*
*
*  pasos para el correcto funcionamiento:
*	1.  Incluir las librerias:  
*
*		#include "windows.h"
*       #include "mmsystem.h"
*
*   2.  sigue los siguientes pasos para agregarar winmm.lib a Visual Studio 2010:
*
*		a.  click derecho sobre la solución y selecciona "Property".
*
*		b. en la parte izquierda de la ventana "Property", selecciona "Linker" y ahí selecciona "Input"
*
*		c. en el panel derecho, escribe "winmm.lib" en la columna "Additional Dependencies".
*
*		d.  Click "Apply" y después en "OK".
*
*	Documentación completa en:
*		https://msdn.microsoft.com/en-us/library/windows/desktop/dd743680%28v=vs.85%29.aspx
*/
#include <Windows.h>
#include <MMSystem.h>

void setAudio(){
	PlaySound(TEXT("Lago.wav"),NULL, SND_LOOP | SND_ASYNC);
}