begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"nativewindowdump.h"
end_include
begin_include
include|#
directive|include
file|"qwindowdump.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_namespace
DECL|namespace|QtDiag
namespace|namespace
name|QtDiag
block|{
DECL|struct|DumpContext
struct|struct
name|DumpContext
block|{
DECL|function|DumpContext
name|DumpContext
parameter_list|()
member_init_list|:
name|indentation
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|indentation
name|int
name|indentation
decl_stmt|;
DECL|member|stream
name|QSharedPointer
argument_list|<
name|QTextStream
argument_list|>
name|stream
decl_stmt|;
block|}
struct|;
DECL|macro|debugWinStyle
define|#
directive|define
name|debugWinStyle
parameter_list|(
name|str
parameter_list|,
name|style
parameter_list|,
name|styleConstant
parameter_list|)
define|\
value|if (style& styleConstant) \     str<< ' '<< #styleConstant;
DECL|function|formatNativeWindow
specifier|static
name|void
name|formatNativeWindow
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|QTextStream
modifier|&
name|str
parameter_list|)
block|{
name|str
operator|<<
name|hex
operator|<<
name|showbase
operator|<<
name|quintptr
argument_list|(
name|hwnd
argument_list|)
operator|<<
name|noshowbase
operator|<<
name|dec
expr_stmt|;
name|RECT
name|rect
decl_stmt|;
if|if
condition|(
name|GetWindowRect
argument_list|(
name|hwnd
argument_list|,
operator|&
name|rect
argument_list|)
condition|)
block|{
name|str
operator|<<
literal|' '
operator|<<
operator|(
name|rect
operator|.
name|right
operator|-
name|rect
operator|.
name|left
operator|)
operator|<<
literal|'x'
operator|<<
operator|(
name|rect
operator|.
name|bottom
operator|-
name|rect
operator|.
name|top
operator|)
operator|<<
literal|'+'
operator|<<
name|rect
operator|.
name|left
operator|<<
literal|'+'
operator|<<
name|rect
operator|.
name|top
expr_stmt|;
block|}
if|if
condition|(
name|IsWindowVisible
argument_list|(
name|hwnd
argument_list|)
condition|)
name|str
operator|<<
literal|" [visible]"
expr_stmt|;
name|str
operator|<<
name|hex
operator|<<
name|showbase
expr_stmt|;
if|if
condition|(
specifier|const
name|LONG_PTR
name|style
init|=
name|GetWindowLongPtr
argument_list|(
name|hwnd
argument_list|,
name|GWL_STYLE
argument_list|)
condition|)
block|{
name|str
operator|<<
literal|" style="
operator|<<
name|style
expr_stmt|;
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_OVERLAPPED
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_POPUP
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_MINIMIZE
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_CHILD
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_VISIBLE
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_DISABLED
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_CLIPSIBLINGS
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_CLIPCHILDREN
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_MAXIMIZE
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_CAPTION
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_BORDER
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_DLGFRAME
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_VSCROLL
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_HSCROLL
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_SYSMENU
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_THICKFRAME
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_GROUP
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_TABSTOP
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_MINIMIZEBOX
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|style
argument_list|,
argument|WS_MAXIMIZEBOX
argument_list|)
block|}
if|if
condition|(
specifier|const
name|LONG_PTR
name|exStyle
init|=
name|GetWindowLongPtr
argument_list|(
name|hwnd
argument_list|,
name|GWL_EXSTYLE
argument_list|)
condition|)
block|{
name|str
operator|<<
literal|" exStyle="
operator|<<
name|exStyle
expr_stmt|;
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_DLGMODALFRAME
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_NOPARENTNOTIFY
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_TOPMOST
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_ACCEPTFILES
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_TRANSPARENT
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_MDICHILD
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_TOOLWINDOW
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_WINDOWEDGE
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_CLIENTEDGE
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_CONTEXTHELP
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_RIGHT
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_LEFT
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_RTLREADING
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_LTRREADING
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_LEFTSCROLLBAR
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_RIGHTSCROLLBAR
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_CONTROLPARENT
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_STATICEDGE
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_APPWINDOW
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_LAYERED
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_NOINHERITLAYOUT
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_NOREDIRECTIONBITMAP
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_LAYOUTRTL
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_COMPOSITED
argument_list|)
name|debugWinStyle
argument_list|(
argument|str
argument_list|,
argument|exStyle
argument_list|,
argument|WS_EX_NOACTIVATE
argument_list|)
block|}
name|str
operator|<<
name|noshowbase
operator|<<
name|dec
expr_stmt|;
name|wchar_t
name|buf
index|[
literal|512
index|]
decl_stmt|;
if|if
condition|(
name|GetWindowText
argument_list|(
name|hwnd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|)
argument_list|)
condition|)
name|str
operator|<<
literal|" title=\""
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buf
argument_list|)
operator|<<
literal|'"'
expr_stmt|;
if|if
condition|(
name|GetClassName
argument_list|(
name|hwnd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|)
argument_list|)
condition|)
name|str
operator|<<
literal|" class=\""
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buf
argument_list|)
operator|<<
literal|'"'
expr_stmt|;
name|str
operator|<<
literal|'\n'
expr_stmt|;
block|}
specifier|static
name|void
name|dumpNativeWindowRecursion
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|DumpContext
modifier|*
name|dc
parameter_list|)
function_decl|;
DECL|function|dumpWindowEnumChildProc
name|BOOL
name|CALLBACK
name|dumpWindowEnumChildProc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
block|{
name|dumpNativeWindowRecursion
argument_list|(
name|hwnd
argument_list|,
cast|reinterpret_cast
argument_list|<
name|DumpContext
operator|*
argument_list|>
argument_list|(
name|lParam
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
DECL|function|dumpNativeWindowRecursion
specifier|static
name|void
name|dumpNativeWindowRecursion
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|DumpContext
modifier|*
name|dc
parameter_list|)
block|{
name|indentStream
argument_list|(
operator|*
name|dc
operator|->
name|stream
argument_list|,
name|dc
operator|->
name|indentation
argument_list|)
expr_stmt|;
name|formatNativeWindow
argument_list|(
name|hwnd
argument_list|,
operator|*
name|dc
operator|->
name|stream
argument_list|)
expr_stmt|;
name|DumpContext
name|nextLevel
init|=
operator|*
name|dc
decl_stmt|;
name|nextLevel
operator|.
name|indentation
operator|+=
literal|2
expr_stmt|;
name|EnumChildWindows
argument_list|(
name|hwnd
argument_list|,
name|dumpWindowEnumChildProc
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPARAM
argument_list|>
argument_list|(
operator|&
name|nextLevel
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* recurse by Z order, same result */
DECL|function|dumpNativeWindowRecursionByZ
specifier|static
name|void
name|dumpNativeWindowRecursionByZ
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|DumpContext
modifier|*
name|dc
parameter_list|)
block|{
name|indentStream
argument_list|(
operator|*
name|dc
operator|->
name|stream
argument_list|,
name|dc
operator|->
name|indentation
argument_list|)
expr_stmt|;
name|formatNativeWindow
argument_list|(
name|hwnd
argument_list|,
operator|*
name|dc
operator|->
name|stream
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|HWND
name|topChild
init|=
name|GetTopWindow
argument_list|(
name|hwnd
argument_list|)
condition|)
block|{
name|DumpContext
name|nextLevel
init|=
operator|*
name|dc
decl_stmt|;
name|nextLevel
operator|.
name|indentation
operator|+=
literal|2
expr_stmt|;
for|for
control|(
name|HWND
name|child
init|=
name|topChild
init|;
name|child
condition|;
name|child
operator|=
name|GetNextWindow
argument_list|(
name|child
argument_list|,
name|GW_HWNDNEXT
argument_list|)
control|)
name|dumpNativeWindowRecursionByZ
argument_list|(
name|child
argument_list|,
operator|&
name|nextLevel
argument_list|)
expr_stmt|;
block|}
block|}
DECL|typedef|WIdVector
typedef|typedef
name|QVector
argument_list|<
name|WId
argument_list|>
name|WIdVector
typedef|;
DECL|function|dumpNativeWindows
specifier|static
name|void
name|dumpNativeWindows
parameter_list|(
specifier|const
name|WIdVector
modifier|&
name|wins
parameter_list|)
block|{
name|DumpContext
name|dc
decl_stmt|;
name|QString
name|s
decl_stmt|;
name|dc
operator|.
name|stream
operator|=
name|QSharedPointer
argument_list|<
name|QTextStream
argument_list|>
argument_list|(
operator|new
name|QTextStream
argument_list|(
operator|&
name|s
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|WId
name|win
decl|,
name|wins
control|)
name|dumpNativeWindowRecursion
argument_list|(
cast|reinterpret_cast
argument_list|<
name|HWND
argument_list|>
argument_list|(
name|win
argument_list|)
argument_list|,
operator|&
name|dc
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>
literal|0x050000
name|qDebug
argument_list|()
operator|.
name|noquote
argument_list|()
operator|<<
name|s
expr_stmt|;
else|#
directive|else
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|qPrintable
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
DECL|function|dumpNativeWindows
name|void
name|dumpNativeWindows
parameter_list|(
name|WId
name|rootIn
parameter_list|)
block|{
specifier|const
name|WId
name|root
init|=
name|rootIn
condition|?
name|rootIn
else|:
cast|reinterpret_cast
argument_list|<
name|WId
argument_list|>
argument_list|(
name|GetDesktopWindow
argument_list|()
argument_list|)
decl_stmt|;
name|dumpNativeWindows
argument_list|(
name|WIdVector
argument_list|(
literal|1
argument_list|,
name|root
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|findQtTopLevelEnumChildProc
name|BOOL
name|CALLBACK
name|findQtTopLevelEnumChildProc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
block|{
name|WIdVector
modifier|*
name|v
init|=
cast|reinterpret_cast
argument_list|<
name|WIdVector
operator|*
argument_list|>
argument_list|(
name|lParam
argument_list|)
decl_stmt|;
name|wchar_t
name|buf
index|[
literal|512
index|]
decl_stmt|;
if|if
condition|(
name|GetClassName
argument_list|(
name|hwnd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|wcsstr
argument_list|(
name|buf
argument_list|,
literal|L"Qt"
argument_list|)
condition|)
name|v
operator|->
name|append
argument_list|(
cast|reinterpret_cast
argument_list|<
name|WId
argument_list|>
argument_list|(
name|hwnd
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|TRUE
return|;
block|}
DECL|function|findQtTopLevels
specifier|static
name|WIdVector
name|findQtTopLevels
parameter_list|()
block|{
name|WIdVector
name|result
decl_stmt|;
name|EnumChildWindows
argument_list|(
name|GetDesktopWindow
argument_list|()
argument_list|,
name|findQtTopLevelEnumChildProc
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPARAM
argument_list|>
argument_list|(
operator|&
name|result
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|dumpNativeQtTopLevels
name|void
name|dumpNativeQtTopLevels
parameter_list|()
block|{
name|dumpNativeWindows
argument_list|(
name|findQtTopLevels
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace QtDiag
end_comment
end_unit
