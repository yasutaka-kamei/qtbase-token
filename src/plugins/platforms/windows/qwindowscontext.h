begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSCONTEXT_H
define|#
directive|define
name|QWINDOWSCONTEXT_H
end_define
begin_include
include|#
directive|include
file|"qtwindowsglobal.h"
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_struct_decl
struct_decl|struct
name|IBindCtx
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|_SHSTOCKICONINFO
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformScreen
name|class
name|QPlatformScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsScreenManager
name|class
name|QWindowsScreenManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsWindow
name|class
name|QWindowsWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsMimeConverter
name|class
name|QWindowsMimeConverter
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QWindowCreationContext
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|QWindowsContextPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_struct
DECL|struct|QWindowsUser32DLL
struct|struct
name|QWindowsUser32DLL
block|{
name|QWindowsUser32DLL
argument_list|()
expr_stmt|;
specifier|inline
name|void
name|init
parameter_list|()
function_decl|;
specifier|inline
name|bool
name|initTouch
parameter_list|()
function_decl|;
DECL|typedef|RegisterTouchWindow
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|RegisterTouchWindow
function_decl|)
parameter_list|(
name|HWND
parameter_list|,
name|ULONG
parameter_list|)
function_decl|;
DECL|typedef|GetTouchInputInfo
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|GetTouchInputInfo
function_decl|)
parameter_list|(
name|HANDLE
parameter_list|,
name|UINT
parameter_list|,
name|PVOID
parameter_list|,
name|int
parameter_list|)
function_decl|;
DECL|typedef|CloseTouchInputHandle
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|CloseTouchInputHandle
function_decl|)
parameter_list|(
name|HANDLE
parameter_list|)
function_decl|;
DECL|typedef|SetLayeredWindowAttributes
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SetLayeredWindowAttributes
function_decl|)
parameter_list|(
name|HWND
parameter_list|,
name|COLORREF
parameter_list|,
name|BYTE
parameter_list|,
name|DWORD
parameter_list|)
function_decl|;
DECL|typedef|UpdateLayeredWindow
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|UpdateLayeredWindow
function_decl|)
parameter_list|(
name|HWND
parameter_list|,
name|HDC
parameter_list|,
specifier|const
name|POINT
modifier|*
parameter_list|,
specifier|const
name|SIZE
modifier|*
parameter_list|,
name|HDC
parameter_list|,
specifier|const
name|POINT
modifier|*
parameter_list|,
name|COLORREF
parameter_list|,
specifier|const
name|BLENDFUNCTION
modifier|*
parameter_list|,
name|DWORD
parameter_list|)
function_decl|;
DECL|typedef|UpdateLayeredWindowIndirect
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|UpdateLayeredWindowIndirect
function_decl|)
parameter_list|(
name|HWND
parameter_list|,
specifier|const
name|UPDATELAYEREDWINDOWINFO
modifier|*
parameter_list|)
function_decl|;
DECL|typedef|IsHungAppWindow
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|IsHungAppWindow
function_decl|)
parameter_list|(
name|HWND
parameter_list|)
function_decl|;
comment|// Functions missing in Q_CC_GNU stub libraries.
DECL|member|setLayeredWindowAttributes
name|SetLayeredWindowAttributes
name|setLayeredWindowAttributes
decl_stmt|;
DECL|member|updateLayeredWindow
name|UpdateLayeredWindow
name|updateLayeredWindow
decl_stmt|;
comment|// Functions missing in older versions of Windows
DECL|member|updateLayeredWindowIndirect
name|UpdateLayeredWindowIndirect
name|updateLayeredWindowIndirect
decl_stmt|;
DECL|member|isHungAppWindow
name|IsHungAppWindow
name|isHungAppWindow
decl_stmt|;
comment|// Touch functions from Windows 7 onwards (also for use with Q_CC_MSVC).
DECL|member|registerTouchWindow
name|RegisterTouchWindow
name|registerTouchWindow
decl_stmt|;
DECL|member|getTouchInputInfo
name|GetTouchInputInfo
name|getTouchInputInfo
decl_stmt|;
DECL|member|closeTouchInputHandle
name|CloseTouchInputHandle
name|closeTouchInputHandle
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QWindowsShell32DLL
struct|struct
name|QWindowsShell32DLL
block|{
name|QWindowsShell32DLL
argument_list|()
expr_stmt|;
specifier|inline
name|void
name|init
parameter_list|()
function_decl|;
DECL|typedef|SHCreateItemFromParsingName
typedef|typedef
name|HRESULT
function_decl|(
name|WINAPI
modifier|*
name|SHCreateItemFromParsingName
function_decl|)
parameter_list|(
name|PCWSTR
parameter_list|,
name|IBindCtx
modifier|*
parameter_list|,
specifier|const
name|GUID
modifier|&
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
DECL|typedef|SHGetStockIconInfo
typedef|typedef
name|HRESULT
function_decl|(
name|WINAPI
modifier|*
name|SHGetStockIconInfo
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|_SHSTOCKICONINFO
modifier|*
parameter_list|)
function_decl|;
DECL|member|sHCreateItemFromParsingName
name|SHCreateItemFromParsingName
name|sHCreateItemFromParsingName
decl_stmt|;
DECL|member|sHGetStockIconInfo
name|SHGetStockIconInfo
name|sHGetStockIconInfo
decl_stmt|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINCE
end_comment
begin_decl_stmt
name|class
name|QWindowsContext
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsContext
argument_list|)
name|public
label|:
enum|enum
name|SystemInfoFlags
block|{
name|SI_RTL_Extensions
init|=
literal|0x1
block|,
name|SI_SupportsTouch
init|=
literal|0x2
block|}
enum|;
comment|// Verbose flag set by environment variable QT_QPA_VERBOSE
specifier|static
name|int
name|verboseIntegration
decl_stmt|;
specifier|static
name|int
name|verboseWindows
decl_stmt|;
specifier|static
name|int
name|verboseBackingStore
decl_stmt|;
specifier|static
name|int
name|verboseEvents
decl_stmt|;
specifier|static
name|int
name|verboseFonts
decl_stmt|;
specifier|static
name|int
name|verboseGL
decl_stmt|;
specifier|static
name|int
name|verboseOLE
decl_stmt|;
specifier|static
name|int
name|verboseInputMethods
decl_stmt|;
specifier|static
name|int
name|verboseDialogs
decl_stmt|;
specifier|static
name|int
name|verboseTheming
decl_stmt|;
name|explicit
name|QWindowsContext
parameter_list|()
function_decl|;
operator|~
name|QWindowsContext
argument_list|()
expr_stmt|;
name|int
name|defaultDPI
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|registerWindowClass
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
name|bool
name|isGL
parameter_list|)
function_decl|;
name|QString
name|registerWindowClass
parameter_list|(
name|QString
name|cname
parameter_list|,
name|WNDPROC
name|proc
parameter_list|,
name|unsigned
name|style
init|=
literal|0
parameter_list|,
name|HBRUSH
name|brush
init|=
literal|0
parameter_list|,
name|bool
name|icon
init|=
name|false
parameter_list|)
function_decl|;
name|HWND
name|createDummyWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|classNameIn
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|windowName
parameter_list|,
name|WNDPROC
name|wndProc
init|=
literal|0
parameter_list|,
name|DWORD
name|style
init|=
name|WS_OVERLAPPED
parameter_list|)
function_decl|;
name|HDC
name|displayContext
argument_list|()
specifier|const
expr_stmt|;
name|int
name|screenDepth
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QWindowsContext
modifier|*
name|instance
parameter_list|()
function_decl|;
specifier|static
name|QString
name|windowsErrorMessage
parameter_list|(
name|unsigned
name|long
name|errorCode
parameter_list|)
function_decl|;
name|void
name|addWindow
parameter_list|(
name|HWND
parameter_list|,
name|QWindowsWindow
modifier|*
name|w
parameter_list|)
function_decl|;
name|void
name|removeWindow
parameter_list|(
name|HWND
parameter_list|)
function_decl|;
name|QWindowsWindow
modifier|*
name|findClosestPlatformWindow
argument_list|(
name|HWND
argument_list|)
decl|const
decl_stmt|;
name|QWindowsWindow
modifier|*
name|findPlatformWindow
argument_list|(
name|HWND
argument_list|)
decl|const
decl_stmt|;
name|QWindow
modifier|*
name|findWindow
argument_list|(
name|HWND
argument_list|)
decl|const
decl_stmt|;
name|QWindowsWindow
modifier|*
name|findPlatformWindowAt
argument_list|(
name|HWND
name|parent
argument_list|,
specifier|const
name|QPoint
operator|&
name|screenPoint
argument_list|,
name|unsigned
name|cwex_flags
argument_list|)
decl|const
decl_stmt|;
name|QWindow
operator|*
name|windowUnderMouse
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|windowsProc
argument_list|(
name|HWND
name|hwnd
argument_list|,
name|UINT
name|message
argument_list|,
name|QtWindows
operator|::
name|WindowsEventType
name|et
argument_list|,
name|WPARAM
name|wParam
argument_list|,
name|LPARAM
name|lParam
argument_list|,
name|LRESULT
operator|*
name|result
argument_list|)
decl_stmt|;
name|QWindow
operator|*
name|keyGrabber
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setKeyGrabber
parameter_list|(
name|QWindow
modifier|*
name|hwnd
parameter_list|)
function_decl|;
name|void
name|setWindowCreationContext
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|QWindowCreationContext
operator|>
operator|&
name|ctx
argument_list|)
decl_stmt|;
comment|// Returns a combination of SystemInfoFlags
name|unsigned
name|systemInfo
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|useRTLExtensions
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
argument|const QKeyEvent *e
argument_list|)
specifier|const
expr_stmt|;
name|QWindowsMimeConverter
operator|&
name|mimeConverter
argument_list|()
specifier|const
expr_stmt|;
name|QWindowsScreenManager
modifier|&
name|screenManager
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|static
name|QWindowsUser32DLL
name|user32dll
decl_stmt|;
specifier|static
name|QWindowsShell32DLL
name|shell32dll
decl_stmt|;
endif|#
directive|endif
specifier|static
name|QByteArray
name|comErrorString
parameter_list|(
name|HRESULT
name|hr
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|handleFocusEvent
argument_list|(
name|QtWindows
operator|::
name|WindowsEventType
name|et
argument_list|,
name|QWindowsWindow
operator|*
name|w
argument_list|)
decl_stmt|;
name|void
name|unregisterWindowClasses
parameter_list|()
function_decl|;
name|QScopedPointer
operator|<
name|QWindowsContextPrivate
operator|>
name|d
expr_stmt|;
specifier|static
name|QWindowsContext
modifier|*
name|m_instance
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_extern
extern|extern
literal|"C"
name|LRESULT
name|QT_WIN_CALLBACK
name|qWindowsWndProc
parameter_list|(
name|HWND
parameter_list|,
name|UINT
parameter_list|,
name|WPARAM
parameter_list|,
name|LPARAM
parameter_list|)
function_decl|;
end_extern
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSCONTEXT_H
end_comment
end_unit
