begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMFUNCTIONS_WCE_H
end_ifndef
begin_define
DECL|macro|QPLATFORMFUNCTIONS_WCE_H
define|#
directive|define
name|QPLATFORMFUNCTIONS_WCE_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qfunctions_wince.h>
end_include
begin_define
DECL|macro|UNDER_NT
define|#
directive|define
name|UNDER_NT
end_define
begin_include
include|#
directive|include
file|<wingdi.h>
end_include
begin_include
include|#
directive|include
file|<objidl.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|WM_MOUSELEAVE
end_ifndef
begin_define
DECL|macro|WM_MOUSELEAVE
define|#
directive|define
name|WM_MOUSELEAVE
value|0x02A3
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_TOUCH
end_ifndef
begin_define
DECL|macro|WM_TOUCH
define|#
directive|define
name|WM_TOUCH
value|0x0240
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_GETOBJECT
end_ifndef
begin_define
DECL|macro|WM_GETOBJECT
define|#
directive|define
name|WM_GETOBJECT
value|0x003D
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|GetWindowLongPtr
define|#
directive|define
name|GetWindowLongPtr
value|GetWindowLong
end_define
begin_define
DECL|macro|SetWindowLongPtr
define|#
directive|define
name|SetWindowLongPtr
value|SetWindowLong
end_define
begin_define
DECL|macro|GWLP_USERDATA
define|#
directive|define
name|GWLP_USERDATA
value|GWL_USERDATA
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|CWP_SKIPINVISIBLE
end_ifndef
begin_define
DECL|macro|CWP_SKIPINVISIBLE
define|#
directive|define
name|CWP_SKIPINVISIBLE
value|0x0001
end_define
begin_define
DECL|macro|findPlatformWindowAt
define|#
directive|define
name|findPlatformWindowAt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|findPlatformWindowAt(a, b)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|CS_OWNDC
end_ifndef
begin_define
DECL|macro|CS_OWNDC
define|#
directive|define
name|CS_OWNDC
value|0x0020
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HWND_MESSAGE
end_ifndef
begin_define
DECL|macro|HWND_MESSAGE
define|#
directive|define
name|HWND_MESSAGE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|CAPTUREBLT
end_ifndef
begin_define
DECL|macro|CAPTUREBLT
define|#
directive|define
name|CAPTUREBLT
value|(DWORD)0x40000000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|SW_SHOWMINIMIZED
define|#
directive|define
name|SW_SHOWMINIMIZED
value|SW_MINIMIZE
end_define
begin_define
DECL|macro|SW_SHOWMINNOACTIVE
define|#
directive|define
name|SW_SHOWMINNOACTIVE
value|SW_MINIMIZE
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|ChildWindowFromPointEx
end_ifndef
begin_define
DECL|macro|ChildWindowFromPointEx
define|#
directive|define
name|ChildWindowFromPointEx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|ChildWindowFromPoint(a, b)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|CF_DIBV5
end_ifndef
begin_define
DECL|macro|CF_DIBV5
define|#
directive|define
name|CF_DIBV5
value|17
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_MOUSEACTIVATE
end_ifndef
begin_define
DECL|macro|WM_MOUSEACTIVATE
define|#
directive|define
name|WM_MOUSEACTIVATE
value|0x0021
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_CHILDACTIVATE
end_ifndef
begin_define
DECL|macro|WM_CHILDACTIVATE
define|#
directive|define
name|WM_CHILDACTIVATE
value|0x0022
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_PARENTNOTIFY
end_ifndef
begin_define
DECL|macro|WM_PARENTNOTIFY
define|#
directive|define
name|WM_PARENTNOTIFY
value|0x0210
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_ENTERIDLE
end_ifndef
begin_define
DECL|macro|WM_ENTERIDLE
define|#
directive|define
name|WM_ENTERIDLE
value|0x0121
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_GETMINMAXINFO
end_ifndef
begin_define
DECL|macro|WM_GETMINMAXINFO
define|#
directive|define
name|WM_GETMINMAXINFO
value|0x0024
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_WINDOWPOSCHANGING
end_ifndef
begin_define
DECL|macro|WM_WINDOWPOSCHANGING
define|#
directive|define
name|WM_WINDOWPOSCHANGING
value|0x0046
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCMOUSEMOVE
end_ifndef
begin_define
DECL|macro|WM_NCMOUSEMOVE
define|#
directive|define
name|WM_NCMOUSEMOVE
value|0x00A0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCMBUTTONDBLCLK
end_ifndef
begin_define
DECL|macro|WM_NCMBUTTONDBLCLK
define|#
directive|define
name|WM_NCMBUTTONDBLCLK
value|0x00A
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCCREATE
end_ifndef
begin_define
DECL|macro|WM_NCCREATE
define|#
directive|define
name|WM_NCCREATE
value|0x0081
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCCALCSIZE
end_ifndef
begin_define
DECL|macro|WM_NCCALCSIZE
define|#
directive|define
name|WM_NCCALCSIZE
value|0x0083
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCACTIVATE
end_ifndef
begin_define
DECL|macro|WM_NCACTIVATE
define|#
directive|define
name|WM_NCACTIVATE
value|0x0086
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCMOUSELEAVE
end_ifndef
begin_define
DECL|macro|WM_NCMOUSELEAVE
define|#
directive|define
name|WM_NCMOUSELEAVE
value|0x02A2
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCLBUTTONDOWN
end_ifndef
begin_define
DECL|macro|WM_NCLBUTTONDOWN
define|#
directive|define
name|WM_NCLBUTTONDOWN
value|0x00A1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCLBUTTONUP
end_ifndef
begin_define
DECL|macro|WM_NCLBUTTONUP
define|#
directive|define
name|WM_NCLBUTTONUP
value|0x00A2
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCPAINT
end_ifndef
begin_define
DECL|macro|WM_NCPAINT
define|#
directive|define
name|WM_NCPAINT
value|0x0085
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_NCHITTEST
end_ifndef
begin_define
DECL|macro|WM_NCHITTEST
define|#
directive|define
name|WM_NCHITTEST
value|0x0084
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_THEMECHANGED
end_ifndef
begin_define
DECL|macro|WM_THEMECHANGED
define|#
directive|define
name|WM_THEMECHANGED
value|0x031A
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_DISPLAYCHANGE
end_ifndef
begin_define
DECL|macro|WM_DISPLAYCHANGE
define|#
directive|define
name|WM_DISPLAYCHANGE
value|0x007E
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|VREFRESH
end_ifndef
begin_define
DECL|macro|VREFRESH
define|#
directive|define
name|VREFRESH
value|116
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SM_SWAPBUTTON
end_ifndef
begin_define
DECL|macro|SM_SWAPBUTTON
define|#
directive|define
name|SM_SWAPBUTTON
value|23
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// application defines
end_comment
begin_define
DECL|macro|SPI_SETNONCLIENTMETRICS
define|#
directive|define
name|SPI_SETNONCLIENTMETRICS
value|72
end_define
begin_define
DECL|macro|SPI_SETICONTITLELOGFONT
define|#
directive|define
name|SPI_SETICONTITLELOGFONT
value|0x0022
end_define
begin_define
DECL|macro|WM_ACTIVATEAPP
define|#
directive|define
name|WM_ACTIVATEAPP
value|0x001c
end_define
begin_define
DECL|macro|SW_PARENTCLOSING
define|#
directive|define
name|SW_PARENTCLOSING
value|1
end_define
begin_define
DECL|macro|SW_OTHERMAXIMIZED
define|#
directive|define
name|SW_OTHERMAXIMIZED
value|2
end_define
begin_define
DECL|macro|SW_PARENTOPENING
define|#
directive|define
name|SW_PARENTOPENING
value|3
end_define
begin_define
DECL|macro|SW_OTHERRESTORED
define|#
directive|define
name|SW_OTHERRESTORED
value|4
end_define
begin_define
DECL|macro|GET_XBUTTON_WPARAM
define|#
directive|define
name|GET_XBUTTON_WPARAM
parameter_list|(
name|wParam
parameter_list|)
value|(HIWORD(wParam))
end_define
begin_comment
comment|// drag n drop
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CFSTR_PERFORMEDDROPEFFECT
end_ifndef
begin_define
DECL|macro|CFSTR_PERFORMEDDROPEFFECT
define|#
directive|define
name|CFSTR_PERFORMEDDROPEFFECT
value|TEXT("Performed DropEffect")
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWidget
end_comment
begin_define
DECL|macro|SW_SHOWMINIMIZED
define|#
directive|define
name|SW_SHOWMINIMIZED
value|SW_MINIMIZE
end_define
begin_comment
comment|// QRegion
end_comment
begin_define
DECL|macro|ALTERNATE
define|#
directive|define
name|ALTERNATE
value|0
end_define
begin_define
DECL|macro|WINDING
define|#
directive|define
name|WINDING
value|1
end_define
begin_comment
comment|// QFontEngine
end_comment
begin_typedef
DECL|struct|_FIXED
typedef|typedef
struct|struct
name|_FIXED
block|{
DECL|member|fract
name|WORD
name|fract
decl_stmt|;
DECL|member|value
name|short
name|value
decl_stmt|;
block|}
DECL|typedef|FIXED
name|FIXED
typedef|;
end_typedef
begin_typedef
DECL|struct|tagPOINTFX
typedef|typedef
struct|struct
name|tagPOINTFX
block|{
DECL|member|x
name|FIXED
name|x
decl_stmt|;
DECL|member|y
name|FIXED
name|y
decl_stmt|;
block|}
DECL|typedef|POINTFX
name|POINTFX
typedef|;
end_typedef
begin_typedef
DECL|struct|_MAT2
typedef|typedef
struct|struct
name|_MAT2
block|{
DECL|member|eM11
name|FIXED
name|eM11
decl_stmt|;
DECL|member|eM12
name|FIXED
name|eM12
decl_stmt|;
DECL|member|eM21
name|FIXED
name|eM21
decl_stmt|;
DECL|member|eM22
name|FIXED
name|eM22
decl_stmt|;
block|}
DECL|typedef|MAT2
name|MAT2
typedef|;
end_typedef
begin_typedef
DECL|struct|_GLYPHMETRICS
typedef|typedef
struct|struct
name|_GLYPHMETRICS
block|{
DECL|member|gmBlackBoxX
name|UINT
name|gmBlackBoxX
decl_stmt|;
DECL|member|gmBlackBoxY
name|UINT
name|gmBlackBoxY
decl_stmt|;
DECL|member|gmptGlyphOrigin
name|POINT
name|gmptGlyphOrigin
decl_stmt|;
DECL|member|gmCellIncX
name|short
name|gmCellIncX
decl_stmt|;
DECL|member|gmCellIncY
name|short
name|gmCellIncY
decl_stmt|;
block|}
DECL|typedef|GLYPHMETRICS
name|GLYPHMETRICS
typedef|;
end_typedef
begin_typedef
DECL|struct|tagTTPOLYGONHEADER
typedef|typedef
struct|struct
name|tagTTPOLYGONHEADER
block|{
DECL|member|cb
name|DWORD
name|cb
decl_stmt|;
DECL|member|dwType
name|DWORD
name|dwType
decl_stmt|;
DECL|member|pfxStart
name|POINTFX
name|pfxStart
decl_stmt|;
block|}
DECL|typedef|TTPOLYGONHEADER
name|TTPOLYGONHEADER
typedef|;
end_typedef
begin_typedef
DECL|struct|tagTTPOLYCURVE
typedef|typedef
struct|struct
name|tagTTPOLYCURVE
block|{
DECL|member|wType
name|WORD
name|wType
decl_stmt|;
DECL|member|cpfx
name|WORD
name|cpfx
decl_stmt|;
DECL|member|apfx
name|POINTFX
name|apfx
index|[
literal|1
index|]
decl_stmt|;
block|}
DECL|typedef|TTPOLYCURVE
name|TTPOLYCURVE
typedef|;
end_typedef
begin_define
DECL|macro|GGO_NATIVE
define|#
directive|define
name|GGO_NATIVE
value|2
end_define
begin_define
DECL|macro|GGO_GLYPH_INDEX
define|#
directive|define
name|GGO_GLYPH_INDEX
value|0x0080
end_define
begin_define
DECL|macro|TT_PRIM_LINE
define|#
directive|define
name|TT_PRIM_LINE
value|1
end_define
begin_define
DECL|macro|TT_PRIM_QSPLINE
define|#
directive|define
name|TT_PRIM_QSPLINE
value|2
end_define
begin_define
DECL|macro|TT_PRIM_CSPLINE
define|#
directive|define
name|TT_PRIM_CSPLINE
value|3
end_define
begin_define
DECL|macro|ANSI_VAR_FONT
define|#
directive|define
name|ANSI_VAR_FONT
value|12
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|OleInitialize
end_ifndef
begin_define
DECL|macro|OleInitialize
define|#
directive|define
name|OleInitialize
parameter_list|(
name|a
parameter_list|)
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETSNAPTODEFBUTTON
end_ifndef
begin_define
DECL|macro|SPI_GETSNAPTODEFBUTTON
define|#
directive|define
name|SPI_GETSNAPTODEFBUTTON
value|95
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WS_EX_LAYERED
end_ifndef
begin_define
DECL|macro|WS_EX_LAYERED
define|#
directive|define
name|WS_EX_LAYERED
value|0x00080000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Clipboard --------------------------------------------------------
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WM_CHANGECBCHAIN
end_ifndef
begin_define
DECL|macro|WM_CHANGECBCHAIN
define|#
directive|define
name|WM_CHANGECBCHAIN
value|0x030D
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_DRAWCLIPBOARD
end_ifndef
begin_define
DECL|macro|WM_DRAWCLIPBOARD
define|#
directive|define
name|WM_DRAWCLIPBOARD
value|0x0308
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|IsIconic
specifier|inline
name|bool
name|IsIconic
parameter_list|(
name|HWND
comment|/*hWnd*/
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function
begin_function
DECL|function|AddFontResourceExW
specifier|inline
name|int
name|AddFontResourceExW
parameter_list|(
name|LPCWSTR
comment|/*name*/
parameter_list|,
name|DWORD
comment|/*fl*/
parameter_list|,
name|PVOID
comment|/*res*/
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|RemoveFontResourceExW
specifier|inline
name|bool
name|RemoveFontResourceExW
parameter_list|(
name|LPCWSTR
comment|/*name*/
parameter_list|,
name|DWORD
comment|/*fl*/
parameter_list|,
name|PVOID
comment|/*pdv*/
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|OleUninitialize
specifier|inline
name|void
name|OleUninitialize
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|GetGlyphOutline
specifier|inline
name|DWORD
name|GetGlyphOutline
parameter_list|(
name|HDC
comment|/*hdc*/
parameter_list|,
name|UINT
comment|/*uChar*/
parameter_list|,
name|INT
comment|/*fuFormat*/
parameter_list|,
name|GLYPHMETRICS
modifier|*
comment|/*lpgm*/
parameter_list|,
name|DWORD
comment|/*cjBuffer*/
parameter_list|,
name|LPVOID
comment|/*pvBuffer*/
parameter_list|,
name|CONST
name|MAT2
modifier|*
comment|/*lpmat2*/
parameter_list|)
block|{
return|return
name|GDI_ERROR
return|;
block|}
end_function
begin_function
DECL|function|GetAncestor
specifier|inline
name|HWND
name|GetAncestor
parameter_list|(
name|HWND
name|hWnd
parameter_list|,
name|UINT
comment|/*gaFlags*/
parameter_list|)
block|{
return|return
name|GetParent
argument_list|(
name|hWnd
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|GA_PARENT
end_ifndef
begin_define
DECL|macro|GA_PARENT
define|#
directive|define
name|GA_PARENT
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETFONTSMOOTHINGTYPE
end_ifndef
begin_define
DECL|macro|SPI_SETFONTSMOOTHINGTYPE
define|#
directive|define
name|SPI_SETFONTSMOOTHINGTYPE
value|0x200B
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETFONTSMOOTHINGTYPE
end_ifndef
begin_define
DECL|macro|SPI_GETFONTSMOOTHINGTYPE
define|#
directive|define
name|SPI_GETFONTSMOOTHINGTYPE
value|0x200A
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|FE_FONTSMOOTHINGCLEARTYPE
end_ifndef
begin_define
DECL|macro|FE_FONTSMOOTHINGCLEARTYPE
define|#
directive|define
name|FE_FONTSMOOTHINGCLEARTYPE
value|0x0002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|DEVICE_FONTTYPE
end_ifndef
begin_define
DECL|macro|DEVICE_FONTTYPE
define|#
directive|define
name|DEVICE_FONTTYPE
value|0x0002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|RASTER_FONTTYPE
end_ifndef
begin_define
DECL|macro|RASTER_FONTTYPE
define|#
directive|define
name|RASTER_FONTTYPE
value|0x0001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_DISPLAYCHANGE
end_ifndef
begin_define
DECL|macro|WM_DISPLAYCHANGE
define|#
directive|define
name|WM_DISPLAYCHANGE
value|0x007E
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|BOOL
name|qt_wince_ChangeClipboardChain
parameter_list|(
name|HWND
name|hWndRemove
parameter_list|,
comment|// handle to window to remove
name|HWND
name|hWndNewNext
comment|// handle to next window
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|ChangeClipboardChain
define|#
directive|define
name|ChangeClipboardChain
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|qt_wince_ChangeClipboardChain(a,b);
end_define
begin_function_decl
name|HWND
name|qt_wince_SetClipboardViewer
parameter_list|(
name|HWND
name|hWndNewViewer
comment|// handle to clipboard viewer window
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|SetClipboardViewer
define|#
directive|define
name|SetClipboardViewer
parameter_list|(
name|a
parameter_list|)
value|qt_wince_SetClipboardViewer(a)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINCE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMFUNCTIONS_WCE_H
end_comment
end_unit
