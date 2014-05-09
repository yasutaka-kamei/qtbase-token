begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscursor.h"
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWindowsScreenData
name|QWindowsScreenData
operator|::
name|QWindowsScreenData
parameter_list|()
member_init_list|:
name|dpi
argument_list|(
literal|96
argument_list|,
literal|96
argument_list|)
member_init_list|,
name|depth
argument_list|(
literal|32
argument_list|)
member_init_list|,
name|format
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
member_init_list|,
name|flags
argument_list|(
name|VirtualDesktop
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|LandscapeOrientation
argument_list|)
member_init_list|,
name|refreshRateHz
argument_list|(
literal|60
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|deviceDPI
specifier|static
specifier|inline
name|QDpi
name|deviceDPI
parameter_list|(
name|HDC
name|hdc
parameter_list|)
block|{
return|return
name|QDpi
argument_list|(
name|GetDeviceCaps
argument_list|(
name|hdc
argument_list|,
name|LOGPIXELSX
argument_list|)
argument_list|,
name|GetDeviceCaps
argument_list|(
name|hdc
argument_list|,
name|LOGPIXELSY
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_function
DECL|function|monitorDPI
specifier|static
specifier|inline
name|QDpi
name|monitorDPI
parameter_list|(
name|HMONITOR
name|hMonitor
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|shcoredll
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|UINT
name|dpiX
decl_stmt|;
name|UINT
name|dpiY
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|QWindowsContext
operator|::
name|shcoredll
operator|.
name|getDpiForMonitor
argument_list|(
name|hMonitor
argument_list|,
literal|0
argument_list|,
operator|&
name|dpiX
argument_list|,
operator|&
name|dpiY
argument_list|)
argument_list|)
condition|)
return|return
name|QDpi
argument_list|(
name|dpiX
argument_list|,
name|dpiY
argument_list|)
return|;
block|}
return|return
name|QDpi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !Q_OS_WINCE
end_comment
begin_function
DECL|function|deviceSizeMM
specifier|static
specifier|inline
name|QSizeF
name|deviceSizeMM
parameter_list|(
specifier|const
name|QSize
modifier|&
name|pixels
parameter_list|,
specifier|const
name|QDpi
modifier|&
name|dpi
parameter_list|)
block|{
specifier|const
name|qreal
name|inchToMM
init|=
literal|25.4
decl_stmt|;
specifier|const
name|qreal
name|h
init|=
name|qreal
argument_list|(
name|pixels
operator|.
name|width
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|dpi
operator|.
name|first
argument_list|)
operator|*
name|inchToMM
decl_stmt|;
specifier|const
name|qreal
name|v
init|=
name|qreal
argument_list|(
name|pixels
operator|.
name|height
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|dpi
operator|.
name|second
argument_list|)
operator|*
name|inchToMM
decl_stmt|;
return|return
name|QSizeF
argument_list|(
name|h
argument_list|,
name|v
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|deviceDPI
specifier|static
specifier|inline
name|QDpi
name|deviceDPI
parameter_list|(
specifier|const
name|QSize
modifier|&
name|pixels
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|physicalSizeMM
parameter_list|)
block|{
specifier|const
name|qreal
name|inchToMM
init|=
literal|25.4
decl_stmt|;
specifier|const
name|qreal
name|h
init|=
name|qreal
argument_list|(
name|pixels
operator|.
name|width
argument_list|()
argument_list|)
operator|/
operator|(
name|qreal
argument_list|(
name|physicalSizeMM
operator|.
name|width
argument_list|()
argument_list|)
operator|/
name|inchToMM
operator|)
decl_stmt|;
specifier|const
name|qreal
name|v
init|=
name|qreal
argument_list|(
name|pixels
operator|.
name|height
argument_list|()
argument_list|)
operator|/
operator|(
name|qreal
argument_list|(
name|physicalSizeMM
operator|.
name|height
argument_list|()
argument_list|)
operator|/
name|inchToMM
operator|)
decl_stmt|;
return|return
name|QDpi
argument_list|(
name|h
argument_list|,
name|v
argument_list|)
return|;
block|}
end_function
begin_typedef
DECL|typedef|WindowsScreenDataList
typedef|typedef
name|QList
argument_list|<
name|QWindowsScreenData
argument_list|>
name|WindowsScreenDataList
typedef|;
end_typedef
begin_comment
comment|// from QDesktopWidget, taking WindowsScreenDataList as LPARAM
end_comment
begin_function
DECL|function|monitorEnumCallback
name|BOOL
name|QT_WIN_CALLBACK
name|monitorEnumCallback
parameter_list|(
name|HMONITOR
name|hMonitor
parameter_list|,
name|HDC
parameter_list|,
name|LPRECT
parameter_list|,
name|LPARAM
name|p
parameter_list|)
block|{
name|MONITORINFOEX
name|info
decl_stmt|;
name|memset
argument_list|(
operator|&
name|info
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|MONITORINFOEX
argument_list|)
argument_list|)
expr_stmt|;
name|info
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|MONITORINFOEX
argument_list|)
expr_stmt|;
if|if
condition|(
name|GetMonitorInfo
argument_list|(
name|hMonitor
argument_list|,
operator|&
name|info
argument_list|)
operator|==
name|FALSE
condition|)
return|return
name|TRUE
return|;
name|WindowsScreenDataList
modifier|*
name|result
init|=
cast|reinterpret_cast
argument_list|<
name|WindowsScreenDataList
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
decl_stmt|;
name|QWindowsScreenData
name|data
decl_stmt|;
name|data
operator|.
name|geometry
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|info
operator|.
name|rcMonitor
operator|.
name|left
argument_list|,
name|info
operator|.
name|rcMonitor
operator|.
name|top
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|info
operator|.
name|rcMonitor
operator|.
name|right
operator|-
literal|1
argument_list|,
name|info
operator|.
name|rcMonitor
operator|.
name|bottom
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|data
operator|.
name|name
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|info
operator|.
name|szDevice
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|.
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"WinDisc"
argument_list|)
condition|)
block|{
name|data
operator|.
name|flags
operator||=
name|QWindowsScreenData
operator|::
name|LockScreen
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|Q_OS_WINCE
comment|//Windows CE, just supports one Display and expects to get only DISPLAY,
comment|//instead of DISPLAY0 and so on, which are passed by info.szDevice
name|HDC
name|hdc
init|=
name|CreateDC
argument_list|(
name|TEXT
argument_list|(
literal|"DISPLAY"
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
else|#
directive|else
name|HDC
name|hdc
init|=
name|CreateDC
argument_list|(
name|info
operator|.
name|szDevice
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|hdc
condition|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|QDpi
name|dpi
init|=
name|monitorDPI
argument_list|(
name|hMonitor
argument_list|)
decl_stmt|;
name|data
operator|.
name|dpi
operator|=
name|dpi
operator|.
name|first
condition|?
name|dpi
else|:
name|deviceDPI
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
else|#
directive|else
name|data
operator|.
name|dpi
operator|=
name|deviceDPI
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|data
operator|.
name|depth
operator|=
name|GetDeviceCaps
argument_list|(
name|hdc
argument_list|,
name|BITSPIXEL
argument_list|)
expr_stmt|;
name|data
operator|.
name|format
operator|=
name|data
operator|.
name|depth
operator|==
literal|16
condition|?
name|QImage
operator|::
name|Format_RGB16
else|:
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
name|data
operator|.
name|physicalSizeMM
operator|=
name|QSizeF
argument_list|(
name|GetDeviceCaps
argument_list|(
name|hdc
argument_list|,
name|HORZSIZE
argument_list|)
argument_list|,
name|GetDeviceCaps
argument_list|(
name|hdc
argument_list|,
name|VERTSIZE
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|int
name|refreshRate
init|=
name|GetDeviceCaps
argument_list|(
name|hdc
argument_list|,
name|VREFRESH
argument_list|)
decl_stmt|;
if|if
condition|(
name|refreshRate
operator|>
literal|1
condition|)
comment|// 0,1 means hardware default.
name|data
operator|.
name|refreshRateHz
operator|=
name|refreshRate
expr_stmt|;
name|DeleteDC
argument_list|(
name|hdc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"%s: Unable to obtain handle for monitor '%s', defaulting to %g DPI."
argument_list|,
name|__FUNCTION__
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|info
operator|.
name|szDevice
argument_list|)
argument_list|)
argument_list|,
name|data
operator|.
name|dpi
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
comment|// CreateDC() failed
block|}
comment|// not lock screen
name|data
operator|.
name|geometry
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|info
operator|.
name|rcMonitor
operator|.
name|left
argument_list|,
name|info
operator|.
name|rcMonitor
operator|.
name|top
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|info
operator|.
name|rcMonitor
operator|.
name|right
operator|-
literal|1
argument_list|,
name|info
operator|.
name|rcMonitor
operator|.
name|bottom
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|data
operator|.
name|availableGeometry
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|info
operator|.
name|rcWork
operator|.
name|left
argument_list|,
name|info
operator|.
name|rcWork
operator|.
name|top
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|info
operator|.
name|rcWork
operator|.
name|right
operator|-
literal|1
argument_list|,
name|info
operator|.
name|rcWork
operator|.
name|bottom
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|data
operator|.
name|orientation
operator|=
name|data
operator|.
name|geometry
operator|.
name|height
argument_list|()
operator|>
name|data
operator|.
name|geometry
operator|.
name|width
argument_list|()
condition|?
name|Qt
operator|::
name|PortraitOrientation
else|:
name|Qt
operator|::
name|LandscapeOrientation
expr_stmt|;
comment|// EnumDisplayMonitors (as opposed to EnumDisplayDevices) enumerates only
comment|// virtual desktop screens.
name|data
operator|.
name|flags
operator||=
name|QWindowsScreenData
operator|::
name|VirtualDesktop
expr_stmt|;
if|if
condition|(
name|info
operator|.
name|dwFlags
operator|&
name|MONITORINFOF_PRIMARY
condition|)
block|{
name|data
operator|.
name|flags
operator||=
name|QWindowsScreenData
operator|::
name|PrimaryScreen
expr_stmt|;
comment|// QPlatformIntegration::screenAdded() documentation specifies that first
comment|// added screen will be the primary screen, so order accordingly.
comment|// Note that the side effect of this policy is that there is no way to change primary
comment|// screen reported by Qt, unless we want to delete all existing screens and add them
comment|// again whenever primary screen changes.
name|result
operator|->
name|prepend
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|result
operator|->
name|append
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
return|return
name|TRUE
return|;
block|}
end_function
begin_function
DECL|function|monitorData
specifier|static
specifier|inline
name|WindowsScreenDataList
name|monitorData
parameter_list|()
block|{
name|WindowsScreenDataList
name|result
decl_stmt|;
name|EnumDisplayMonitors
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|monitorEnumCallback
argument_list|,
operator|(
name|LPARAM
operator|)
operator|&
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|operator <<
specifier|static
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QWindowsScreenData
modifier|&
name|d
parameter_list|)
block|{
name|QDebug
name|nospace
init|=
name|dbg
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|nospace
operator|<<
literal|"Screen "
operator|<<
name|d
operator|.
name|name
operator|<<
literal|' '
operator|<<
name|d
operator|.
name|geometry
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|d
operator|.
name|geometry
operator|.
name|height
argument_list|()
operator|<<
literal|'+'
operator|<<
name|d
operator|.
name|geometry
operator|.
name|x
argument_list|()
operator|<<
literal|'+'
operator|<<
name|d
operator|.
name|geometry
operator|.
name|y
argument_list|()
operator|<<
literal|" avail: "
operator|<<
name|d
operator|.
name|availableGeometry
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|d
operator|.
name|availableGeometry
operator|.
name|height
argument_list|()
operator|<<
literal|'+'
operator|<<
name|d
operator|.
name|availableGeometry
operator|.
name|x
argument_list|()
operator|<<
literal|'+'
operator|<<
name|d
operator|.
name|availableGeometry
operator|.
name|y
argument_list|()
operator|<<
literal|" physical: "
operator|<<
name|d
operator|.
name|physicalSizeMM
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|d
operator|.
name|physicalSizeMM
operator|.
name|height
argument_list|()
operator|<<
literal|" DPI: "
operator|<<
name|d
operator|.
name|dpi
operator|.
name|first
operator|<<
literal|'x'
operator|<<
name|d
operator|.
name|dpi
operator|.
name|second
operator|<<
literal|" Depth: "
operator|<<
name|d
operator|.
name|depth
operator|<<
literal|" Format: "
operator|<<
name|d
operator|.
name|format
expr_stmt|;
if|if
condition|(
name|d
operator|.
name|flags
operator|&
name|QWindowsScreenData
operator|::
name|PrimaryScreen
condition|)
name|nospace
operator|<<
literal|" primary"
expr_stmt|;
if|if
condition|(
name|d
operator|.
name|flags
operator|&
name|QWindowsScreenData
operator|::
name|VirtualDesktop
condition|)
name|nospace
operator|<<
literal|" virtual desktop"
expr_stmt|;
if|if
condition|(
name|d
operator|.
name|flags
operator|&
name|QWindowsScreenData
operator|::
name|LockScreen
condition|)
name|nospace
operator|<<
literal|" lock screen"
expr_stmt|;
return|return
name|dbg
return|;
block|}
end_function
begin_comment
comment|// Return the cursor to be shared by all screens (virtual desktop).
end_comment
begin_function
DECL|function|sharedCursor
specifier|static
specifier|inline
name|QSharedPointer
argument_list|<
name|QWindowsCursor
argument_list|>
name|sharedCursor
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
if|if
condition|(
specifier|const
name|QScreen
modifier|*
name|primaryScreen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
specifier|const
name|QWindowsScreen
operator|*
argument_list|>
argument_list|(
name|primaryScreen
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|windowsCursor
argument_list|()
return|;
endif|#
directive|endif
return|return
name|QSharedPointer
argument_list|<
name|QWindowsCursor
argument_list|>
argument_list|(
operator|new
name|QWindowsCursor
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QWindowsScreen     \brief Windows screen.     \sa QWindowsScreenManager     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsScreen
name|QWindowsScreen
operator|::
name|QWindowsScreen
parameter_list|(
specifier|const
name|QWindowsScreenData
modifier|&
name|data
parameter_list|)
member_init_list|:
name|m_data
argument_list|(
name|data
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
member_init_list|,
name|m_cursor
argument_list|(
name|sharedCursor
argument_list|()
argument_list|)
endif|#
directive|endif
block|{ }
end_constructor
begin_function_decl
name|Q_GUI_EXPORT
name|QPixmap
name|qt_pixmapFromWinHBITMAP
parameter_list|(
name|HBITMAP
name|bitmap
parameter_list|,
name|int
name|hbitmapFormat
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|grabWindow
name|QPixmap
name|QWindowsScreen
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
specifier|const
block|{
name|RECT
name|r
decl_stmt|;
name|HWND
name|hwnd
init|=
name|window
condition|?
operator|(
name|HWND
operator|)
name|window
else|:
name|GetDesktopWindow
argument_list|()
decl_stmt|;
name|GetClientRect
argument_list|(
name|hwnd
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
if|if
condition|(
name|width
operator|<
literal|0
condition|)
name|width
operator|=
name|r
operator|.
name|right
operator|-
name|r
operator|.
name|left
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|0
condition|)
name|height
operator|=
name|r
operator|.
name|bottom
operator|-
name|r
operator|.
name|top
expr_stmt|;
comment|// Create and setup bitmap
name|HDC
name|display_dc
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|HDC
name|bitmap_dc
init|=
name|CreateCompatibleDC
argument_list|(
name|display_dc
argument_list|)
decl_stmt|;
name|HBITMAP
name|bitmap
init|=
name|CreateCompatibleBitmap
argument_list|(
name|display_dc
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|HGDIOBJ
name|null_bitmap
init|=
name|SelectObject
argument_list|(
name|bitmap_dc
argument_list|,
name|bitmap
argument_list|)
decl_stmt|;
comment|// copy data
name|HDC
name|window_dc
init|=
name|GetDC
argument_list|(
name|hwnd
argument_list|)
decl_stmt|;
name|BitBlt
argument_list|(
name|bitmap_dc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|window_dc
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|SRCCOPY
operator||
name|CAPTUREBLT
argument_list|)
expr_stmt|;
comment|// clean up all but bitmap
name|ReleaseDC
argument_list|(
name|hwnd
argument_list|,
name|window_dc
argument_list|)
expr_stmt|;
name|SelectObject
argument_list|(
name|bitmap_dc
argument_list|,
name|null_bitmap
argument_list|)
expr_stmt|;
name|DeleteDC
argument_list|(
name|bitmap_dc
argument_list|)
expr_stmt|;
specifier|const
name|QPixmap
name|pixmap
init|=
name|qt_pixmapFromWinHBITMAP
argument_list|(
name|bitmap
argument_list|)
decl_stmt|;
name|DeleteObject
argument_list|(
name|bitmap
argument_list|)
expr_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|display_dc
argument_list|)
expr_stmt|;
return|return
name|pixmap
return|;
block|}
end_function
begin_comment
comment|/*!     \brief Find a top level window taking the flags of ChildWindowFromPointEx. */
end_comment
begin_function
DECL|function|findTopLevelAt
name|QWindow
modifier|*
name|QWindowsScreen
operator|::
name|findTopLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|,
name|unsigned
name|flags
parameter_list|)
block|{
name|QWindow
modifier|*
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QPlatformWindow
modifier|*
name|bw
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|findPlatformWindowAt
argument_list|(
name|GetDesktopWindow
argument_list|()
argument_list|,
name|point
argument_list|,
name|flags
argument_list|)
condition|)
name|result
operator|=
name|QWindowsWindow
operator|::
name|topLevelOf
argument_list|(
name|bw
operator|->
name|window
argument_list|()
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|point
operator|<<
name|flags
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|windowAt
name|QWindow
modifier|*
name|QWindowsScreen
operator|::
name|windowAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|screenPoint
parameter_list|,
name|unsigned
name|flags
parameter_list|)
block|{
name|QWindow
modifier|*
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QPlatformWindow
modifier|*
name|bw
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|findPlatformWindowAt
argument_list|(
name|GetDesktopWindow
argument_list|()
argument_list|,
name|screenPoint
argument_list|,
name|flags
argument_list|)
condition|)
name|result
operator|=
name|bw
operator|->
name|window
argument_list|()
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|screenPoint
operator|<<
literal|" returns "
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|windowUnderMouse
name|QWindow
modifier|*
name|QWindowsScreen
operator|::
name|windowUnderMouse
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
return|return
name|QWindowsScreen
operator|::
name|windowAt
argument_list|(
name|QWindowsCursor
operator|::
name|mousePosition
argument_list|()
argument_list|,
name|flags
argument_list|)
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|screenOf
name|QWindowsScreen
modifier|*
name|QWindowsScreen
operator|::
name|screenOf
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|)
block|{
if|if
condition|(
name|w
condition|)
if|if
condition|(
specifier|const
name|QScreen
modifier|*
name|s
init|=
name|w
operator|->
name|screen
argument_list|()
condition|)
if|if
condition|(
name|QPlatformScreen
modifier|*
name|pscr
init|=
name|s
operator|->
name|handle
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
name|QWindowsScreen
operator|*
argument_list|>
argument_list|(
name|pscr
argument_list|)
return|;
if|if
condition|(
specifier|const
name|QScreen
modifier|*
name|ps
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
condition|)
if|if
condition|(
name|QPlatformScreen
modifier|*
name|ppscr
init|=
name|ps
operator|->
name|handle
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
name|QWindowsScreen
operator|*
argument_list|>
argument_list|(
name|ppscr
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \brief Determine siblings in a virtual desktop system.      Self is by definition a sibling, else collect all screens     within virtual desktop. */
end_comment
begin_function
DECL|function|virtualSiblings
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|QWindowsScreen
operator|::
name|virtualSiblings
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|result
decl_stmt|;
if|if
condition|(
name|m_data
operator|.
name|flags
operator|&
name|QWindowsScreenData
operator|::
name|VirtualDesktop
condition|)
block|{
foreach|foreach
control|(
name|QWindowsScreen
modifier|*
name|screen
decl|,
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|screenManager
argument_list|()
operator|.
name|screens
argument_list|()
control|)
if|if
condition|(
name|screen
operator|->
name|data
argument_list|()
operator|.
name|flags
operator|&
name|QWindowsScreenData
operator|::
name|VirtualDesktop
condition|)
name|result
operator|.
name|push_back
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|result
operator|.
name|push_back
argument_list|(
cast|const_cast
argument_list|<
name|QWindowsScreen
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \brief Notify QWindowSystemInterface about changes of a screen and synchronize data. */
end_comment
begin_function
DECL|function|handleChanges
name|void
name|QWindowsScreen
operator|::
name|handleChanges
parameter_list|(
specifier|const
name|QWindowsScreenData
modifier|&
name|newData
parameter_list|)
block|{
name|m_data
operator|.
name|physicalSizeMM
operator|=
name|newData
operator|.
name|physicalSizeMM
expr_stmt|;
if|if
condition|(
name|m_data
operator|.
name|geometry
operator|!=
name|newData
operator|.
name|geometry
condition|)
block|{
name|m_data
operator|.
name|geometry
operator|=
name|newData
operator|.
name|geometry
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenGeometryChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|newData
operator|.
name|geometry
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_data
operator|.
name|availableGeometry
operator|!=
name|newData
operator|.
name|availableGeometry
condition|)
block|{
name|m_data
operator|.
name|availableGeometry
operator|=
name|newData
operator|.
name|availableGeometry
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenAvailableGeometryChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|newData
operator|.
name|availableGeometry
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|qFuzzyCompare
argument_list|(
name|m_data
operator|.
name|dpi
operator|.
name|first
argument_list|,
name|newData
operator|.
name|dpi
operator|.
name|first
argument_list|)
operator|||
operator|!
name|qFuzzyCompare
argument_list|(
name|m_data
operator|.
name|dpi
operator|.
name|second
argument_list|,
name|newData
operator|.
name|dpi
operator|.
name|second
argument_list|)
condition|)
block|{
name|m_data
operator|.
name|dpi
operator|=
name|newData
operator|.
name|dpi
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenLogicalDotsPerInchChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|newData
operator|.
name|dpi
operator|.
name|first
argument_list|,
name|newData
operator|.
name|dpi
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_data
operator|.
name|orientation
operator|!=
name|newData
operator|.
name|orientation
condition|)
block|{
name|m_data
operator|.
name|orientation
operator|=
name|newData
operator|.
name|orientation
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenOrientationChange
argument_list|(
name|screen
argument_list|()
argument_list|,
name|newData
operator|.
name|orientation
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \class QWindowsScreenManager     \brief Manages a list of QWindowsScreen.      Listens for changes and notifies QWindowSystemInterface about changed/     added/deleted screens.      \sa QWindowsScreen     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsScreenManager
name|QWindowsScreenManager
operator|::
name|QWindowsScreenManager
parameter_list|()
member_init_list|:
name|m_lastDepth
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_lastHorizontalResolution
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_lastVerticalResolution
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \brief Triggers synchronization of screens (WM_DISPLAYCHANGE).      Subsequent events are compressed since WM_DISPLAYCHANGE is sent to     each top level window. */
end_comment
begin_function
DECL|function|handleDisplayChange
name|bool
name|QWindowsScreenManager
operator|::
name|handleDisplayChange
parameter_list|(
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
block|{
specifier|const
name|int
name|newDepth
init|=
operator|(
name|int
operator|)
name|wParam
decl_stmt|;
specifier|const
name|WORD
name|newHorizontalResolution
init|=
name|LOWORD
argument_list|(
name|lParam
argument_list|)
decl_stmt|;
specifier|const
name|WORD
name|newVerticalResolution
init|=
name|HIWORD
argument_list|(
name|lParam
argument_list|)
decl_stmt|;
if|if
condition|(
name|newDepth
operator|!=
name|m_lastDepth
operator|||
name|newHorizontalResolution
operator|!=
name|m_lastHorizontalResolution
operator|||
name|newVerticalResolution
operator|!=
name|m_lastVerticalResolution
condition|)
block|{
name|m_lastDepth
operator|=
name|newDepth
expr_stmt|;
name|m_lastHorizontalResolution
operator|=
name|newHorizontalResolution
expr_stmt|;
name|m_lastVerticalResolution
operator|=
name|newVerticalResolution
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
literal|"Depth="
operator|<<
name|newDepth
operator|<<
literal|", resolution "
operator|<<
name|newHorizontalResolution
operator|<<
literal|'x'
operator|<<
name|newVerticalResolution
expr_stmt|;
name|handleScreenChanges
argument_list|()
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|indexOfMonitor
specifier|static
specifier|inline
name|int
name|indexOfMonitor
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QWindowsScreen
modifier|*
argument_list|>
modifier|&
name|screens
parameter_list|,
specifier|const
name|QString
modifier|&
name|monitorName
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|screens
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|screens
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|data
argument_list|()
operator|.
name|name
operator|==
name|monitorName
condition|)
return|return
name|i
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|indexOfMonitor
specifier|static
specifier|inline
name|int
name|indexOfMonitor
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QWindowsScreenData
argument_list|>
modifier|&
name|screenData
parameter_list|,
specifier|const
name|QString
modifier|&
name|monitorName
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|screenData
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|screenData
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|name
operator|==
name|monitorName
condition|)
return|return
name|i
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|removeScreen
name|void
name|QWindowsScreenManager
operator|::
name|removeScreen
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
literal|"Removing Monitor:"
operator|<<
name|m_screens
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|->
name|data
argument_list|()
expr_stmt|;
name|QScreen
modifier|*
name|screen
init|=
name|m_screens
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|->
name|screen
argument_list|()
decl_stmt|;
name|QScreen
modifier|*
name|primaryScreen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
decl_stmt|;
comment|// QTBUG-38650: When a screen is disconnected, Windows will automatically
comment|// move the Window to another screen. This will trigger a geometry change
comment|// event, but unfortunately after the screen destruction signal. To prevent
comment|// QtGui from automatically hiding the QWindow, pretend all Windows move to
comment|// the primary screen first (which is likely the correct, final screen).
if|if
condition|(
name|screen
operator|!=
name|primaryScreen
condition|)
block|{
name|unsigned
name|movedWindowCount
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|QWindow
modifier|*
name|w
decl|,
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
control|)
block|{
if|if
condition|(
name|w
operator|->
name|screen
argument_list|()
operator|==
name|screen
operator|&&
name|w
operator|->
name|handle
argument_list|()
operator|&&
name|w
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleWindowScreenChanged
argument_list|(
name|w
argument_list|,
name|primaryScreen
argument_list|)
expr_stmt|;
operator|++
name|movedWindowCount
expr_stmt|;
block|}
block|}
if|if
condition|(
name|movedWindowCount
condition|)
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
block|}
operator|delete
name|m_screens
operator|.
name|takeAt
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \brief Synchronizes the screen list, adds new screens, removes deleted     ones and propagates resolution changes to QWindowSystemInterface. */
end_comment
begin_function
DECL|function|handleScreenChanges
name|bool
name|QWindowsScreenManager
operator|::
name|handleScreenChanges
parameter_list|()
block|{
comment|// Look for changed monitors, add new ones
name|WindowsScreenDataList
name|newDataList
init|=
name|monitorData
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|lockScreen
init|=
name|newDataList
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
operator|(
name|newDataList
operator|.
name|front
argument_list|()
operator|.
name|flags
operator|&
name|QWindowsScreenData
operator|::
name|LockScreen
operator|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QWindowsScreenData
modifier|&
name|newData
decl|,
name|newDataList
control|)
block|{
specifier|const
name|int
name|existingIndex
init|=
name|indexOfMonitor
argument_list|(
name|m_screens
argument_list|,
name|newData
operator|.
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|existingIndex
operator|!=
operator|-
literal|1
condition|)
block|{
name|m_screens
operator|.
name|at
argument_list|(
name|existingIndex
argument_list|)
operator|->
name|handleChanges
argument_list|(
name|newData
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QWindowsScreen
modifier|*
name|newScreen
init|=
operator|new
name|QWindowsScreen
argument_list|(
name|newData
argument_list|)
decl_stmt|;
name|m_screens
operator|.
name|push_back
argument_list|(
name|newScreen
argument_list|)
expr_stmt|;
name|QWindowsIntegration
operator|::
name|instance
argument_list|()
operator|->
name|emitScreenAdded
argument_list|(
name|newScreen
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
literal|"New Monitor: "
operator|<<
name|newData
expr_stmt|;
block|}
comment|// exists
block|}
comment|// for new screens.
comment|// Remove deleted ones but keep main monitors if we get only the
comment|// temporary lock screen to avoid window recreation (QTBUG-33062).
if|if
condition|(
operator|!
name|lockScreen
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|m_screens
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|indexOfMonitor
argument_list|(
name|newDataList
argument_list|,
name|m_screens
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|data
argument_list|()
operator|.
name|name
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|removeScreen
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
comment|// for existing screens
block|}
comment|// not lock screen
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
