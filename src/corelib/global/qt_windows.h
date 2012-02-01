begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_WINDOWS_H
end_ifndef
begin_define
DECL|macro|QT_WINDOWS_H
define|#
directive|define
name|QT_WINDOWS_H
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_BOR
argument_list|)
end_if
begin_comment
comment|// Borland's windows.h does not set these correctly, resulting in
end_comment
begin_comment
comment|// unusable WinSDK standard dialogs
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WINVER
end_ifndef
begin_define
DECL|macro|WINVER
define|#
directive|define
name|WINVER
value|0x400
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WINNT
end_ifndef
begin_define
DECL|macro|_WIN32_WINNT
define|#
directive|define
name|_WIN32_WINNT
value|0x400
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MINGW
argument_list|)
end_if
begin_comment
comment|// mingw's windows.h does not set _WIN32_WINNT, resulting breaking compilation
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WINVER
end_ifndef
begin_define
DECL|macro|WINVER
define|#
directive|define
name|WINVER
value|0x500
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|NOMINMAX
define|#
directive|define
name|NOMINMAX
end_define
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_WCE
end_ifdef
begin_include
include|#
directive|include
file|<ceconfig.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// already defined when compiled with WINVER>= 0x0500
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETMENUANIMATION
end_ifndef
begin_define
DECL|macro|SPI_SETMENUANIMATION
define|#
directive|define
name|SPI_SETMENUANIMATION
value|0x1003
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETMENUFADE
end_ifndef
begin_define
DECL|macro|SPI_SETMENUFADE
define|#
directive|define
name|SPI_SETMENUFADE
value|0x1013
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETCOMBOBOXANIMATION
end_ifndef
begin_define
DECL|macro|SPI_SETCOMBOBOXANIMATION
define|#
directive|define
name|SPI_SETCOMBOBOXANIMATION
value|0x1005
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETTOOLTIPANIMATION
end_ifndef
begin_define
DECL|macro|SPI_SETTOOLTIPANIMATION
define|#
directive|define
name|SPI_SETTOOLTIPANIMATION
value|0x1017
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETTOOLTIPFADE
end_ifndef
begin_define
DECL|macro|SPI_SETTOOLTIPFADE
define|#
directive|define
name|SPI_SETTOOLTIPFADE
value|0x1019
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_SETUIEFFECTS
end_ifndef
begin_define
DECL|macro|SPI_SETUIEFFECTS
define|#
directive|define
name|SPI_SETUIEFFECTS
value|0x103F
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETMENUANIMATION
end_ifndef
begin_define
DECL|macro|SPI_GETMENUANIMATION
define|#
directive|define
name|SPI_GETMENUANIMATION
value|0x1002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETMENUFADE
end_ifndef
begin_define
DECL|macro|SPI_GETMENUFADE
define|#
directive|define
name|SPI_GETMENUFADE
value|0x1012
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETCOMBOBOXANIMATION
end_ifndef
begin_define
DECL|macro|SPI_GETCOMBOBOXANIMATION
define|#
directive|define
name|SPI_GETCOMBOBOXANIMATION
value|0x1004
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETTOOLTIPANIMATION
end_ifndef
begin_define
DECL|macro|SPI_GETTOOLTIPANIMATION
define|#
directive|define
name|SPI_GETTOOLTIPANIMATION
value|0x1016
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETTOOLTIPFADE
end_ifndef
begin_define
DECL|macro|SPI_GETTOOLTIPFADE
define|#
directive|define
name|SPI_GETTOOLTIPFADE
value|0x1018
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETUIEFFECTS
end_ifndef
begin_define
DECL|macro|SPI_GETUIEFFECTS
define|#
directive|define
name|SPI_GETUIEFFECTS
value|0x103E
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETKEYBOARDCUES
end_ifndef
begin_define
DECL|macro|SPI_GETKEYBOARDCUES
define|#
directive|define
name|SPI_GETKEYBOARDCUES
value|0x100A
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETGRADIENTCAPTIONS
end_ifndef
begin_define
DECL|macro|SPI_GETGRADIENTCAPTIONS
define|#
directive|define
name|SPI_GETGRADIENTCAPTIONS
value|0x1008
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|IDC_HAND
end_ifndef
begin_define
DECL|macro|IDC_HAND
define|#
directive|define
name|IDC_HAND
value|MAKEINTRESOURCE(32649)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_MOUSEWHEEL
end_ifndef
begin_define
DECL|macro|WM_MOUSEWHEEL
define|#
directive|define
name|WM_MOUSEWHEEL
value|0x020A
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|WM_MOUSEHWHEEL
end_ifndef
begin_define
DECL|macro|WM_MOUSEHWHEEL
define|#
directive|define
name|WM_MOUSEHWHEEL
value|0x020E
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|ETO_PDY
end_ifndef
begin_define
DECL|macro|ETO_PDY
define|#
directive|define
name|ETO_PDY
value|0x2000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|COLOR_GRADIENTACTIVECAPTION
end_ifndef
begin_define
DECL|macro|COLOR_GRADIENTACTIVECAPTION
define|#
directive|define
name|COLOR_GRADIENTACTIVECAPTION
value|27
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|COLOR_GRADIENTINACTIVECAPTION
end_ifndef
begin_define
DECL|macro|COLOR_GRADIENTINACTIVECAPTION
define|#
directive|define
name|COLOR_GRADIENTINACTIVECAPTION
value|28
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// already defined when compiled with WINVER>= 0x0600
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETFLATMENU
end_ifndef
begin_define
DECL|macro|SPI_GETFLATMENU
define|#
directive|define
name|SPI_GETFLATMENU
value|0x1022
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|CS_DROPSHADOW
end_ifndef
begin_define
DECL|macro|CS_DROPSHADOW
define|#
directive|define
name|CS_DROPSHADOW
value|0x00020000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|CLEARTYPE_QUALITY
end_ifndef
begin_define
DECL|macro|CLEARTYPE_QUALITY
define|#
directive|define
name|CLEARTYPE_QUALITY
value|5
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|LR_DEFAULTSIZE
end_ifndef
begin_define
DECL|macro|LR_DEFAULTSIZE
define|#
directive|define
name|LR_DEFAULTSIZE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|LR_SHARED
end_ifndef
begin_define
DECL|macro|LR_SHARED
define|#
directive|define
name|LR_SHARED
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_WINCE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_WINDOWS_H
end_comment
end_unit
